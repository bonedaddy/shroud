// pytypesmodule.hpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#ifndef PYTYPESMODULE_HPP
#define PYTYPESMODULE_HPP
#include <Python.h>
#include "types.hpp"
// splicer begin header.include
// splicer end header.include

// splicer begin header.C_declaration
// splicer end header.C_declaration

extern PyObject *PY_error_obj;

#if PY_MAJOR_VERSION >= 3
extern "C" PyMODINIT_FUNC PyInit_shtypes(void);
#else
extern "C" PyMODINIT_FUNC initshtypes(void);
#endif

#endif  /* PYTYPESMODULE_HPP */
