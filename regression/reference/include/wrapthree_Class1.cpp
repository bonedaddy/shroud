// wrapthree_Class1.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapthree_Class1.h"
#include "class_header.hpp"


extern "C" {


void LIB_three_Class1_method1(LIB_three_Class1 * self, int arg1)
{
    three::Class1 *SH_this = static_cast<three::Class1 *>(self->addr);
    SH_this->method1(arg1);
    return;
}

}  // extern "C"
