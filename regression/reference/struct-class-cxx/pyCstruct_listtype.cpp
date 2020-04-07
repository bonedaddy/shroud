// pyCstruct_listtype.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "pystructmodule.hpp"
// splicer begin class.Cstruct_list.impl.include
// splicer end class.Cstruct_list.impl.include

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
// splicer begin class.Cstruct_list.impl.C_definition
// splicer end class.Cstruct_list.impl.C_definition
// splicer begin class.Cstruct_list.impl.additional_methods
// splicer end class.Cstruct_list.impl.additional_methods
static void
PY_Cstruct_list_tp_del (PY_Cstruct_list *self)
{
// splicer begin class.Cstruct_list.type.del
    PY_SHROUD_release_memory(self->idtor, self->obj);
    self->obj = nullptr;
    // Python objects for members.
    Py_XDECREF(self->ivalue_obj);
    Py_XDECREF(self->dvalue_obj);
    Py_XDECREF(self->svalue_obj);
// splicer end class.Cstruct_list.type.del
}

// Cstruct_list(int nitems +intent(in)+optional(0), int * ivalue +dimension(nitems+nitems)+intent(in)+optional(0), double * dvalue +dimension(nitems*TWO)+intent(in)+optional(0), char * * svalue +dimension(nitems)+intent(in)+optional(0)) +name(Cstruct_list_ctor)
// ----------------------------------------
// Argument:  nitems
// Requested: py_native_in
// Match:     py_default
// ----------------------------------------
// Argument:  ivalue
// Exact:     py_native_in_dimension_list
// ----------------------------------------
// Argument:  dvalue
// Exact:     py_native_in_dimension_list
// ----------------------------------------
// Argument:  svalue
// Exact:     py_char_**_in
static int
PY_Cstruct_list_tp_init(
  PY_Cstruct_list *self,
  PyObject *args,
  PyObject *kwds)
{
// splicer begin class.Cstruct_list.method.cstruct_list_ctor
    int nitems;
    STR_SHROUD_converter_value SHPy_ivalue;
    STR_SHROUD_converter_value SHPy_dvalue;
    STR_SHROUD_converter_value SHPy_svalue;
    const char *SHT_kwlist[] = {
        "nitems",
        "ivalue",
        "dvalue",
        "svalue",
        nullptr };

    nitems = 0;
    SHPy_ivalue.obj = nullptr;
    SHPy_ivalue.data = nullptr;
    SHPy_dvalue.obj = nullptr;
    SHPy_dvalue.data = nullptr;
    SHPy_svalue.obj = nullptr;
    SHPy_svalue.data = nullptr;
    if (!PyArg_ParseTupleAndKeywords(args, kwds,
        "|iO&O&O&:Cstruct_list_ctor", const_cast<char **>(SHT_kwlist), 
        &nitems, STR_SHROUD_get_from_object_int_list, &SHPy_ivalue,
        STR_SHROUD_get_from_object_double_list, &SHPy_dvalue,
        STR_SHROUD_get_from_object_charptr, &SHPy_svalue))
        return -1;

    self->obj = new Cstruct_list;
    if (self->obj == nullptr) {
        PyErr_NoMemory();
        return -1;
    }
    self->idtor = 3;
    // initialize fields
    Cstruct_list *SH_obj = self->obj;
    SH_obj->nitems = nitems;
    SH_obj->ivalue = static_cast<int *>(SHPy_ivalue.data);
    SH_obj->dvalue = static_cast<double *>(SHPy_dvalue.data);
    SH_obj->svalue = static_cast<char * *>(SHPy_svalue.data);
    self->ivalue_obj = SHPy_ivalue.obj;  // steal reference
    self->dvalue_obj = SHPy_dvalue.obj;  // steal reference
    self->svalue_obj = SHPy_svalue.obj;  // steal reference
    return 0;
// splicer end class.Cstruct_list.method.cstruct_list_ctor
}
// splicer begin class.Cstruct_list.impl.after_methods
// splicer end class.Cstruct_list.impl.after_methods

// Exact:     py_descr_native
static PyObject *PY_Cstruct_list_nitems_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    PyObject * rv = PyInt_FromLong(self->obj->nitems);
    return rv;
}

// Exact:     py_descr_native
static int PY_Cstruct_list_nitems_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    int rv = PyInt_AsLong(value);
    if (PyErr_Occurred()) {
        return -1;
    }
    self->obj->nitems = rv;
    return 0;
}

// Exact:     py_descr_native_*_list
static PyObject *PY_Cstruct_list_ivalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->ivalue == nullptr) {
        Py_RETURN_NONE;
    }
    if (self->ivalue_obj != nullptr) {
        Py_INCREF(self->ivalue_obj);
        return self->ivalue_obj;
    }
    PyObject *rv = STR_SHROUD_to_PyList_int(self->obj->ivalue, self->obj->nitems+self->obj->nitems);
    return rv;
}

// Exact:     py_descr_native_*_list
static int PY_Cstruct_list_ivalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    STR_SHROUD_converter_value cvalue;
    Py_XDECREF(self->ivalue_obj);
    if (STR_SHROUD_get_from_object_int_list(value, &cvalue) == 0) {
        self->obj->ivalue = nullptr;
        self->ivalue_obj = nullptr;
        // XXXX set error
        return -1;
    }
    self->obj->ivalue = static_cast<int *>(cvalue.data);
    self->ivalue_obj = cvalue.obj;  // steal reference
    return 0;
}

// Exact:     py_descr_native_*_list
static PyObject *PY_Cstruct_list_dvalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->dvalue == nullptr) {
        Py_RETURN_NONE;
    }
    if (self->dvalue_obj != nullptr) {
        Py_INCREF(self->dvalue_obj);
        return self->dvalue_obj;
    }
    PyObject *rv = STR_SHROUD_to_PyList_double(self->obj->dvalue, self->obj->nitems*TWO);
    return rv;
}

// Exact:     py_descr_native_*_list
static int PY_Cstruct_list_dvalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    STR_SHROUD_converter_value cvalue;
    Py_XDECREF(self->dvalue_obj);
    if (STR_SHROUD_get_from_object_double_list(value, &cvalue) == 0) {
        self->obj->dvalue = nullptr;
        self->dvalue_obj = nullptr;
        // XXXX set error
        return -1;
    }
    self->obj->dvalue = static_cast<double *>(cvalue.data);
    self->dvalue_obj = cvalue.obj;  // steal reference
    return 0;
}

// Exact:     py_descr_char_**_list
static PyObject *PY_Cstruct_list_svalue_getter(PY_Cstruct_list *self,
    void *SHROUD_UNUSED(closure))
{
    if (self->obj->svalue == nullptr) {
        Py_RETURN_NONE;
    }
    if (self->svalue_obj != nullptr) {
        Py_INCREF(self->svalue_obj);
        return self->svalue_obj;
    }
    PyObject *rv = STR_SHROUD_to_PyList_char(self->obj->svalue, self->obj->nitems);
    return rv;
}

// Exact:     py_descr_char_**_list
static int PY_Cstruct_list_svalue_setter(PY_Cstruct_list *self, PyObject *value,
    void *SHROUD_UNUSED(closure))
{
    STR_SHROUD_converter_value cvalue;
    Py_XDECREF(self->svalue_obj);
    if (STR_SHROUD_get_from_object_charptr(value, &cvalue) == 0) {
        self->obj->svalue = nullptr;
        self->svalue_obj = nullptr;
        // XXXX set error
        return -1;
    }
    self->obj->svalue = static_cast<char **>(cvalue.data);
    self->svalue_obj = cvalue.obj;  // steal reference
    return 0;
}

static PyGetSetDef PY_Cstruct_list_getset[] = {
    {(char *)"nitems", (getter)PY_Cstruct_list_nitems_getter,
        (setter)PY_Cstruct_list_nitems_setter, nullptr, nullptr},
    {(char *)"ivalue", (getter)PY_Cstruct_list_ivalue_getter,
        (setter)PY_Cstruct_list_ivalue_setter, nullptr, nullptr},
    {(char *)"dvalue", (getter)PY_Cstruct_list_dvalue_getter,
        (setter)PY_Cstruct_list_dvalue_setter, nullptr, nullptr},
    {(char *)"svalue", (getter)PY_Cstruct_list_svalue_getter,
        (setter)PY_Cstruct_list_svalue_setter, nullptr, nullptr},
    // splicer begin class.Cstruct_list.PyGetSetDef
    // splicer end class.Cstruct_list.PyGetSetDef
    {nullptr}            /* sentinel */
};
static PyMethodDef PY_Cstruct_list_methods[] = {
    // splicer begin class.Cstruct_list.PyMethodDef
    // splicer end class.Cstruct_list.PyMethodDef
    {nullptr,   (PyCFunction)nullptr, 0, nullptr}            /* sentinel */
};

static char Cstruct_list__doc__[] =
"virtual class"
;

/* static */
PyTypeObject PY_Cstruct_list_Type = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "cstruct.Cstruct_list",                       /* tp_name */
    sizeof(PY_Cstruct_list),         /* tp_basicsize */
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
    Cstruct_list__doc__,         /* tp_doc */
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
    PY_Cstruct_list_methods,                             /* tp_methods */
    nullptr,                              /* tp_members */
    PY_Cstruct_list_getset,                             /* tp_getset */
    nullptr,                              /* tp_base */
    nullptr,                              /* tp_dict */
    (descrgetfunc)nullptr,                /* tp_descr_get */
    (descrsetfunc)nullptr,                /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc)PY_Cstruct_list_tp_init,                   /* tp_init */
    (allocfunc)nullptr,                  /* tp_alloc */
    (newfunc)nullptr,                    /* tp_new */
    (freefunc)nullptr,                   /* tp_free */
    (inquiry)nullptr,                     /* tp_is_gc */
    nullptr,                              /* tp_bases */
    nullptr,                              /* tp_mro */
    nullptr,                              /* tp_cache */
    nullptr,                              /* tp_subclasses */
    nullptr,                              /* tp_weaklist */
    (destructor)PY_Cstruct_list_tp_del,                 /* tp_del */
    0,                              /* tp_version_tag */
#if PY_MAJOR_VERSION >= 3
    (destructor)nullptr,                  /* tp_finalize */
#endif
};
