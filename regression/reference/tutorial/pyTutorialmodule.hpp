// pyTutorialmodule.hpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
// All rights reserved.
//
// This file is part of Shroud.  For details, see
// https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the disclaimer (as noted below)
//   in the documentation and/or other materials provided with the
//   distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
// LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// #######################################################################
#ifndef PYTUTORIALMODULE_HPP
#define PYTUTORIALMODULE_HPP
#include <Python.h>
// splicer begin header.include
// splicer end header.include

// forward declare classes
namespace tutorial {
    class struct1;
}
namespace tutorial {
    class Class1;
}
class Singleton;

extern PyTypeObject PY_Class1_Type;
extern PyTypeObject PY_Singleton_Type;

// splicer begin header.C_declaration
// splicer end header.C_declaration

// helper functions
extern const char *PY_Class1_capsule_name;
extern const char *PY_Singleton_capsule_name;
extern const char * PY_array_destructor_context[];
extern void PY_array_destructor_function(PyObject *cap);
PyObject *PP_Class1_to_Object(tutorial::Class1 *addr);
int PP_Class1_from_Object(PyObject *obj, void **addr);
PyObject *PP_Singleton_to_Object(Singleton *addr);
int PP_Singleton_from_Object(PyObject *obj, void **addr);

// splicer begin class.Class1.C_declaration
// splicer end class.Class1.C_declaration

typedef struct {
PyObject_HEAD
    tutorial::Class1 * obj;
    // splicer begin class.Class1.C_object
    // splicer end class.Class1.C_object
} PY_Class1;
// splicer begin class.Singleton.C_declaration
// splicer end class.Singleton.C_declaration

typedef struct {
PyObject_HEAD
    Singleton * obj;
    // splicer begin class.Singleton.C_object
    // splicer end class.Singleton.C_object
} PY_Singleton;

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
extern "C" PyMODINIT_FUNC PyInit_tutorial(void);
#else
extern "C" PyMODINIT_FUNC inittutorial(void);
#endif

#endif  /* PYTUTORIALMODULE_HPP */