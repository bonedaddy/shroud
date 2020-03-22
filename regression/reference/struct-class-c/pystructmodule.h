// pystructmodule.h
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#ifndef PYSTRUCTMODULE_H
#define PYSTRUCTMODULE_H
#include <Python.h>
#include "struct.h"
// splicer begin header.include
// splicer end header.include

// utility functions
extern void PY_SHROUD_release_memory(int icontext, void *ptr);
extern void *PY_SHROUD_fetch_context(int icontext);
extern void PY_SHROUD_capsule_destructor(PyObject *cap);

// ------------------------------
extern PyTypeObject PY_Cstruct1_Type;
// splicer begin class.Cstruct1.C_declaration
// splicer end class.Cstruct1.C_declaration

// start object PY_Cstruct1
typedef struct {
PyObject_HEAD
    Cstruct1 * obj;
    int idtor;
    // splicer begin class.Cstruct1.C_object
    // splicer end class.Cstruct1.C_object
} PY_Cstruct1;
// end object PY_Cstruct1

extern const char *PY_Cstruct1_capsule_name;
PyObject *PP_Cstruct1_to_Object(Cstruct1 *addr);
int PP_Cstruct1_from_Object(PyObject *obj, void **addr);

// ------------------------------
extern PyTypeObject PY_Cstruct_ptr_Type;
// splicer begin class.Cstruct_ptr.C_declaration
// splicer end class.Cstruct_ptr.C_declaration

typedef struct {
PyObject_HEAD
    Cstruct_ptr * obj;
    int idtor;
    // Python objects for members.
    PyObject *cfield_obj;
    // splicer begin class.Cstruct_ptr.C_object
    // splicer end class.Cstruct_ptr.C_object
} PY_Cstruct_ptr;

extern const char *PY_Cstruct_ptr_capsule_name;
PyObject *PP_Cstruct_ptr_to_Object(Cstruct_ptr *addr);
int PP_Cstruct_ptr_from_Object(PyObject *obj, void **addr);

// ------------------------------
extern PyTypeObject PY_Cstruct_list_Type;
// splicer begin class.Cstruct_list.C_declaration
// splicer end class.Cstruct_list.C_declaration

typedef struct {
PyObject_HEAD
    Cstruct_list * obj;
    int idtor;
    // Python objects for members.
    PyObject *ivalue_obj;
    PyObject *dvalue_obj;
    PyObject *svalue_obj;
    // splicer begin class.Cstruct_list.C_object
    // splicer end class.Cstruct_list.C_object
} PY_Cstruct_list;

extern const char *PY_Cstruct_list_capsule_name;
PyObject *PP_Cstruct_list_to_Object(Cstruct_list *addr);
int PP_Cstruct_list_from_Object(PyObject *obj, void **addr);

// ------------------------------
extern PyTypeObject PY_Cstruct_numpy_Type;
// splicer begin class.Cstruct_numpy.C_declaration
// splicer end class.Cstruct_numpy.C_declaration

typedef struct {
PyObject_HEAD
    Cstruct_numpy * obj;
    int idtor;
    // Python objects for members.
    PyObject *ivalue_obj;
    PyObject *dvalue_obj;
    // splicer begin class.Cstruct_numpy.C_object
    // splicer end class.Cstruct_numpy.C_object
} PY_Cstruct_numpy;

extern const char *PY_Cstruct_numpy_capsule_name;
PyObject *PP_Cstruct_numpy_to_Object(Cstruct_numpy *addr);
int PP_Cstruct_numpy_from_Object(PyObject *obj, void **addr);
// ------------------------------

// splicer begin header.C_declaration
// splicer end header.C_declaration

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_cstruct(void);
#else
PyMODINIT_FUNC initcstruct(void);
#endif

#endif  /* PYSTRUCTMODULE_H */
