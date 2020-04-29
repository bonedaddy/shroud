// pyCstruct_as_classtype.c
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.h"
// splicer begin class.Cstruct_as_class.impl.include
// splicer end class.Cstruct_as_class.impl.include

#ifdef __cplusplus
#define SHROUD_UNUSED(param)
#else
#define SHROUD_UNUSED(param) param
#endif

#if PY_MAJOR_VERSION >= 3
#define PyInt_AsLong PyLong_AsLong
#define PyInt_FromLong PyLong_FromLong
#define PyInt_FromSize_t PyLong_FromSize_t
#define PyString_FromString PyUnicode_FromString
#define PyString_FromStringAndSize PyUnicode_FromStringAndSize
#endif
// splicer begin class.Cstruct_as_class.impl.C_definition
// splicer end class.Cstruct_as_class.impl.C_definition
// splicer begin class.Cstruct_as_class.impl.additional_methods
// splicer end class.Cstruct_as_class.impl.additional_methods
static void
PY_Cstruct_as_class_tp_del (PY_Cstruct_as_class *self)
{
// splicer begin class.Cstruct_as_class.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = NULL;
// splicer end class.Cstruct_as_class.type.del
}

// Cstruct_as_class(int x1 +intent(in), int y1 +intent(in)) +name(Cstruct_as_class_ctor)
// ----------------------------------------
// Argument:  x1
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
// ----------------------------------------
// Argument:  y1
// Requested: py_ctor_native_scalar_numpy
// Match:     py_ctor_native
static int
PY_Cstruct_as_class_tp_init(
  PY_Cstruct_as_class *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin class.Cstruct_as_class.method.cstruct_as_class_ctor
    int x1 = 0;
    int y1 = 0;
    char *SHT_kwlist[] = {
        "x1",
        "y1",
        NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|ii:Cstruct_as_class_ctor", SHT_kwlist, &x1, &y1))
        return -1;

    self->obj = malloc(sizeof(Cstruct_as_class));
    if (self->obj == NULL) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 1;

    // post_call - initialize fields
    Cstruct_as_class *SH_obj = self->obj;
    SH_obj->x1 = x1;
    SH_obj->y1 = y1;

    return 0;
// splicer end class.Cstruct_as_class.method.cstruct_as_class_ctor
}
// splicer begin class.Cstruct_as_class.impl.after_methods
// splicer end class.Cstruct_as_class.impl.after_methods

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct_as_class_x1_getter(PY_Cstruct_as_class *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->x1);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct_as_class_x1_setter(PY_Cstruct_as_class *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->x1 = rv;
    return 0;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static PyObject *PY_Cstruct_as_class_y1_getter(PY_Cstruct_as_class *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->y1);
    return rv;
}

// Requested: py_descr_native_scalar
// Match:     py_descr_native
static int PY_Cstruct_as_class_y1_setter(PY_Cstruct_as_class *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->y1 = rv;
    return 0;
}

static PyGetSetDef PY_Cstruct_as_class_getset[] = {
    {(char *)"x1", (getter)PY_Cstruct_as_class_x1_getter,
        (setter)PY_Cstruct_as_class_x1_setter, NULL, NULL},
    {(char *)"y1", (getter)PY_Cstruct_as_class_y1_getter,
        (setter)PY_Cstruct_as_class_y1_setter, NULL, NULL},
    // splicer begin class.Cstruct_as_class.PyGetSetDef
    // splicer end class.Cstruct_as_class.PyGetSetDef
    {NULL}            /* sentinel */
};
static PyMethodDef PY_Cstruct_as_class_methods[] = {
    // splicer begin class.Cstruct_as_class.PyMethodDef
    // splicer end class.Cstruct_as_class.PyMethodDef
    {NULL,   (PyCFunction)NULL, 0, NULL}            /* sentinel */
};

static char Cstruct_as_class__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Cstruct_as_class_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "cstruct.Cstruct_as_class",                       /* tp_name */
    sizeof(PY_Cstruct_as_class),         /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* Methods to implement standard operations */
    (destructor)NULL,                 /* tp_dealloc */
    (printfunc)NULL,                   /* tp_print */
    (getattrfunc)NULL,                 /* tp_getattr */
    (setattrfunc)NULL,                 /* tp_setattr */
#if PY_MAJOR_VERSION >= 3
    NULL,                               /* tp_reserved */
#else
    (cmpfunc)NULL,                     /* tp_compare */
#endif
    (reprfunc)NULL,                    /* tp_repr */
    /* Method suites for standard classes */
    NULL,                              /* tp_as_number */
    NULL,                              /* tp_as_sequence */
    NULL,                              /* tp_as_mapping */
    /* More standard operations (here for binary compatibility) */
    (hashfunc)NULL,                    /* tp_hash */
    (ternaryfunc)NULL,                 /* tp_call */
    (reprfunc)NULL,                    /* tp_str */
    (getattrofunc)NULL,                /* tp_getattro */
    (setattrofunc)NULL,                /* tp_setattro */
    /* Functions to access object as input/output buffer */
    NULL,                              /* tp_as_buffer */
    /* Flags to define presence of optional/expanded features */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    Cstruct_as_class__doc__,         /* tp_doc */
    /* Assigned meaning in release 2.0 */
    /* call function for all accessible objects */
    (traverseproc)NULL,                /* tp_traverse */
    /* delete references to contained objects */
    (inquiry)NULL,                     /* tp_clear */
    /* Assigned meaning in release 2.1 */
    /* rich comparisons */
    (richcmpfunc)NULL,                 /* tp_richcompare */
    /* weak reference enabler */
    0,                              /* tp_weaklistoffset */
    /* Added in release 2.2 */
    /* Iterators */
    (getiterfunc)NULL,                 /* tp_iter */
    (iternextfunc)NULL,                /* tp_iternext */
    /* Attribute descriptor and subclassing stuff */
    PY_Cstruct_as_class_methods,                             /* tp_methods */
    NULL,                              /* tp_members */
    PY_Cstruct_as_class_getset,                             /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,                /* tp_descr_get */
    (descrsetfunc)NULL,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PY_Cstruct_as_class_tp_init,                   /* tp_init */
    (allocfunc)NULL,                  /* tp_alloc */
    (newfunc)NULL,                    /* tp_new */
    (freefunc)NULL,                   /* tp_free */
    (inquiry)NULL,                     /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor)PY_Cstruct_as_class_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)NULL,                  /* tp_finalize */
#endif
};