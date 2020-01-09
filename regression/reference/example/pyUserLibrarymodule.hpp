// pyUserLibrarymodule.hpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#ifndef PYUSERLIBRARYMODULE_HPP
#define PYUSERLIBRARYMODULE_HPP
#include <Python.h>
// splicer begin header.include
// splicer end header.include

// utility functions
extern void PP_SHROUD_release_memory(int icontext, void *ptr);
extern void *PP_SHROUD_fetch_context(int icontext);
extern void PP_SHROUD_capsule_destructor(PyObject *cap);

// ------------------------------
namespace example {
    namespace nested {
        class ExClass1;  // forward declare
    }
}
extern PyTypeObject PP_ExClass1_Type;
// splicer begin namespace.example::nested.class.ExClass1.C_declaration
// splicer end namespace.example::nested.class.ExClass1.C_declaration

typedef struct {
PyObject_HEAD
    example::nested::ExClass1 * obj;
    int idtor;
    // splicer begin namespace.example::nested.class.ExClass1.C_object
    // splicer end namespace.example::nested.class.ExClass1.C_object
} PP_ExClass1;

extern const char *PY_ExClass1_capsule_name;
PyObject *PP_ExClass1_to_Object(example::nested::ExClass1 *addr);
int PP_ExClass1_from_Object(PyObject *obj, void **addr);

// ------------------------------
namespace example {
    namespace nested {
        class ExClass2;  // forward declare
    }
}
extern PyTypeObject PP_ExClass2_Type;
// splicer begin namespace.example::nested.class.ExClass2.C_declaration
// splicer end namespace.example::nested.class.ExClass2.C_declaration

typedef struct {
PyObject_HEAD
    example::nested::ExClass2 * obj;
    int idtor;
    // splicer begin namespace.example::nested.class.ExClass2.C_object
    // splicer end namespace.example::nested.class.ExClass2.C_object
} PP_ExClass2;

extern const char *PY_ExClass2_capsule_name;
PyObject *PP_ExClass2_to_Object(example::nested::ExClass2 *addr);
int PP_ExClass2_from_Object(PyObject *obj, void **addr);
// ------------------------------

// splicer begin header.C_declaration
// splicer end header.C_declaration

extern PyObject *PP_error_obj;

#if PY_MAJOR_VERSION >= 3
extern "C" PyMODINIT_FUNC PyInit_userlibrary(void);
#else
extern "C" PyMODINIT_FUNC inituserlibrary(void);
#endif

#endif  /* PYUSERLIBRARYMODULE_HPP */
