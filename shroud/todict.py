# Copyright (c) 2018, Lawrence Livermore National Security, LLC.
# Produced at the Lawrence Livermore National Laboratory
# 
# LLNL-CODE-738041.
# All rights reserved.
#  
# This file is part of Shroud.  For details, see
# https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
#  
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#  
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the disclaimer below.
# 
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the disclaimer (as noted below)
#   in the documentation and/or other materials provided with the
#   distribution.
# 
# * Neither the name of the LLNS/LLNL nor the names of its contributors
#   may be used to endorse or promote products derived from this
#   software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
# LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
########################################################################

"""
Convert some data structures into a dictionary.
Useful for debugging and seralizing instances as json.
"""

from . import ast
from . import declast
from . import typemap
from . import util
from . import visitor

class ToDict(visitor.Visitor):
    """Convert to dictionary.
    """

    def visit_list(self, node):
        return [ self.visit(n) for n in node ]

    def visit_dict(self, node):
        return {key:self.visit(value) for (key,value) in node.items()}

######################################################################

    def visit_Ptr(self, node):
        d = dict(
            ptr = node.ptr,
            const = node.const,
#            volatile = node.volatile,
        )
        return d

    def visit_Declarator(self, node):
        d = dict(
            pointer = self.visit(node.pointer)
        )
        if node.name:
            d['name'] = node.name
        elif node.func:
            d['func'] = self.visit(node.func)
        return d

    def visit_Declaration(self, node):
        d = dict(
            specifier = node.specifier,
            const = node.const,
#            volatile = node.volatile,
#            node.array,
            attrs = node.attrs,
        )
        if node.declarator:
            # ctor and dtor have no declarator
            d['declarator'] = self.visit(node.declarator)
        if node.storage:
            d['storage'] = node.storage
        if node.params is not None:
            d['params'] = self.visit(node.params)
            d['fattrs'] = node.fattrs
            d['func_const'] = node.func_const
        else:
            if node.fattrs:
                raise RuntimeError("fattrs is not empty for non-function")
        if node.init is not None:
            d['init'] = node.init
        return d

    def visit_Identifier(self, node):
        d = dict(
            name = node.name,
        )
        if node.args != None:
            d['args'] = self.visit(node.args)
        return d

    def visit_BinaryOp(self, node):
        d = dict(
            left = self.visit(node.left),
            op = node.op,
            right = self.visit(node.right)
        )
        return d

    def visit_UnaryOp(self, node):
        d = dict(
            op = node.op,
            node = self.visit(node.node)
        )
        return d

    def visit_ParenExpr(self, node):
        d = dict(
            node = self.visit(node.node)
        )
        return d

    def visit_Constant(self, node):
        d = dict(
            value = node.value
        )
        return d

######################################################################

    def visit_Scope(self, node):
        d = {}
        skip = '_' + node.__class__.__name__ + '__'   # __name is skipped
        for key, value in node.__dict__.items():
            if not key.startswith(skip):
                d[key] = value
        return d

######################################################################

    def visit_Typedef(self, node):
        # only export non-default values
        a = {}
        for key, defvalue in node.defaults.items():
            value = getattr(node, key)
            if value is not defvalue:
                a[key] = value
        return a

######################################################################

    def visit_LibraryNode(self, node):
        d = dict(
            format=self.visit(node.fmtdict),
            options=self.visit(node.options),
        )

        for key in [ 'copyright', 'cxx_header',
                     'language', 'namespace' ]:
            value = getattr(node, key)
            if value:
                d[key] = value
        for key in [ 'classes', 'functions' ]:
            value = getattr(node, key)
            if value:
                d[key] = self.visit(value)
        return d

    def visit_ClassNode(self, node):
        d = dict(
            cxx_header=node.cxx_header,
            format = self.visit(node.fmtdict),
            name=node.name,
            options=self.visit(node.options),
        )
        for key in ['namespace', 'python']:
            value = getattr(node, key)
            if value:
                d[key] = value
        d['methods'] = self.visit(node.functions)
        return d

    def visit_FunctionNode(self, node):
        d = dict(
            ast=self.visit(node.ast),
            _function_index=node._function_index,
            decl=node.decl,
            format=self.visit(node.fmtdict),
            options=self.visit(node.options),
        )
        for key in [ '_fmtargs', '_fmtresult' ]:
            value = getattr(node, key)
            if value:
                d[key] = self.visit(value)
        for key in ['cxx_template', 'default_arg_suffix',
                    'declgen', 'doxygen', 
                    'fortran_generic', 'return_this',
                    'C_error_pattern', 'PY_error_pattern',
                    '_PTR_C_CXX_index', '_PTR_F_C_index',
                    '_CXX_return_templated',
                    '_cxx_overload',
                    '_default_funcs',
                    '_generated', '_has_default_arg',
                    '_nargs', '_overloaded']:
            value = getattr(node, key)
            if value:
                d[key] = value
        return d


def to_dict(node):
    """Convert node to a dictionary.
    Useful for debugging.
    """
    visitor = ToDict()
    return visitor.visit(node)

######################################################################

class PrintNode(visitor.Visitor):

    def param_list(self, node):
        n = [node.name, '(']
        for arg in node.args:
            n.append(self.visit(arg))
            n.append(',')
            n[-1] = ')'
        return ''.join(n)

    def visit_Identifier(self, node):
        if node.args == None:
            return node.name
        elif node.args:
            return self.param_list(node)
        else:
            return node.name+ '()'

    def visit_BinaryOp(self, node):
        return self.visit(node.left) + node.op + self.visit(node.right)

    def visit_UnaryOp(self, node):
        return node.op + self.visit(node.node)

    def visit_ParenExpr(self, node):
        return '(' + self.visit(node.node) + ')'

    def visit_Constant(self, node):
        return node.value


def print_node(node):
    """Convert node to original string.
    """
    visitor = PrintNode()
    return visitor.visit(node)