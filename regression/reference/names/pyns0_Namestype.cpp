// pyns0_Namestype.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pytestnamesmodule.hpp"
// splicer begin namespace.ns0.class.Names.impl.include
// splicer end namespace.ns0.class.Names.impl.include

#ifdef __cplusplus
#define SHROUD_UNUSED(param)
#else
#define SHROUD_UNUSED(param) param
#endif

#if PY_MAJOR_VERSION >= 3
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif
// splicer begin namespace.ns0.class.Names.impl.C_definition
// splicer end namespace.ns0.class.Names.impl.C_definition
// splicer begin namespace.ns0.class.Names.impl.additional_methods
// splicer end namespace.ns0.class.Names.impl.additional_methods
static void
PY_Names_tp_del (PY_Names *self)
{
// splicer begin namespace.ns0.class.Names.type.del
    PY_SHROUD_release_memory(self->mydtor, self->myobj);
    self->myobj = nullptr;
// splicer end namespace.ns0.class.Names.type.del
}

static char PY_method1__doc__[] =
"documentation"
;

static PyObject *
PY_method1(
  PY_Names *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void method1()
// splicer begin namespace.ns0.class.Names.method.method1
    self->myobj->method1();
    Py_RETURN_NONE;
// splicer end namespace.ns0.class.Names.method.method1
}

static char PY_method2__doc__[] =
"documentation"
;

static PyObject *
PY_method2(
  PY_Names *self,
  PyObject *SHROUD_UNUSED(args),
  PyObject *SHROUD_UNUSED(kwds))
{
// void method2()
// splicer begin namespace.ns0.class.Names.method.method2
    self->myobj->method2();
    Py_RETURN_NONE;
// splicer end namespace.ns0.class.Names.method.method2
}
// splicer begin namespace.ns0.class.Names.impl.after_methods
// splicer end namespace.ns0.class.Names.impl.after_methods
static PyMethodDef PY_Names_methods[] = {
    {"method1", (PyCFunction)PY_method1, METH_NOARGS,
        PY_method1__doc__},
    {"method2", (PyCFunction)PY_method2, METH_NOARGS,
        PY_method2__doc__},
    // splicer begin namespace.ns0.class.Names.PyMethodDef
    // splicer end namespace.ns0.class.Names.PyMethodDef
    {NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

static char Names__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Names_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "testnames.ns0.Names",                       /* tp_name */
    sizeof(PY_Names),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)nullptr,                 /* tp_dealloc */
    (printfunc)nullptr,                   /* tp_print */
    (getattrfunc)nullptr,                 /* tp_getattr */
    (setattrfunc)nullptr,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    nullptr,                               /* tp_reserved */
#else
    (cmpfunc)nullptr,                     /* tp_compare */
#endif
    (reprfunc)nullptr,                    /* tp_repr */
    /* Method suites for standard classes */
    nullptr,                              /* tp_as_number */
    nullptr,                              /* tp_as_sequence */
    nullptr,                              /* tp_as_mapping */
    /* More standard operations (here for binary compatibility) */
    (hashfunc)nullptr,                    /* tp_hash */
    (ternaryfunc)nullptr,                 /* tp_call */
    (reprfunc)nullptr,                    /* tp_str */
    (getattrofunc)nullptr,                /* tp_getattro */
    (setattrofunc)nullptr,                /* tp_setattro */
    /* Functions to access object as input/output buffer */
    nullptr,                              /* tp_as_buffer */
    /* Flags to define presence of optional/expanded features */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    Names__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)nullptr,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)nullptr,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)nullptr,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)nullptr,                 /* tp_iter */
    (iternextfunc)nullptr,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_Names_methods,                             /* tp_methods */
    nullptr,                              /* tp_members */
    nullptr,                             /* tp_getset */
    nullptr,                              /* tp_base */
    nullptr,                              /* tp_dict */
    (descrgetfunc)nullptr,                /* tp_descr_get */
    (descrsetfunc)nullptr,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)0,                   /* tp_init */
    (allocfunc)nullptr,                  /* tp_alloc */
    (newfunc)nullptr,                    /* tp_new */
    (freefunc)nullptr,                   /* tp_free */
    (inquiry)nullptr,                     /* tp_is_gc */
    nullptr,                              /* tp_bases */
    nullptr,                              /* tp_mro */
    nullptr,                              /* tp_cache */
    nullptr,                              /* tp_subclasses */
    nullptr,                              /* tp_weaklist */
    (destructor)PY_Names_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)nullptr,                  /* tp_finalize */
#endif
};
