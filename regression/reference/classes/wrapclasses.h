// wrapclasses.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapclasses.h
 * \brief Shroud generated wrapper for classes namespace
 */
// For C users and C++ implementation

#ifndef WRAPCLASSES_H
#define WRAPCLASSES_H

#include "typesclasses.h"

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

int CLA_direction_func(int arg);

void CLA_pass_class_by_value(CLA_Class1 arg);

int CLA_useclass(CLA_Class1 * arg);

CLA_Class1 * CLA_getclass2(CLA_Class1 * SHC_rv);

CLA_Class1 * CLA_getclass3(CLA_Class1 * SHC_rv);

CLA_Class1 * CLA_get_const_class_reference(CLA_Class1 * SHC_rv);

CLA_Class1 * CLA_get_class_reference(CLA_Class1 * SHC_rv);

CLA_Class1 * CLA_get_class_copy(int flag, CLA_Class1 * SHC_rv);

void CLA_set_global_flag(int arg);

int CLA_get_global_flag();

const char * CLA_last_function_called();

void CLA_last_function_called_bufferify(char * SHF_rv, int NSHF_rv);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCLASSES_H
