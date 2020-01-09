// wrapUser1.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapUser1.h
 * \brief Shroud generated wrapper for User1 class
 */
// For C users and C++ implementation

#ifndef WRAPUSER1_H
#define WRAPUSER1_H

#include "typespreprocess.h"

// splicer begin class.User1.CXX_declarations
// splicer end class.User1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin class.User1.C_declarations
// splicer end class.User1.C_declarations

void PRE_User1_method1(PRE_User1 * self);

#if defined(USE_TWO)
void PRE_User1_method2(PRE_User1 * self);
#endif

#if defined(USE_THREE)
void PRE_User1_method3def_0(PRE_User1 * self);
#endif

#if defined(USE_THREE)
void PRE_User1_method3def_1(PRE_User1 * self, int i);
#endif

#ifdef __cplusplus
}
#endif

#endif  // WRAPUSER1_H
