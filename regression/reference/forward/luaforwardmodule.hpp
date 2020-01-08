// luaforwardmodule.hpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#ifndef LUAFORWARDMODULE_HPP
#define LUAFORWARDMODULE_HPP
#ifdef __cplusplus
extern "C" {
#endif
#include "forward.hpp"
#include "lua.h"
// splicer begin class.Class3.C_declaration
// splicer end class.Class3.C_declaration

typedef struct {
    forward::Class3 * self;
    // splicer begin class.Class3.C_object
    // splicer end class.Class3.C_object
} l_Class3_Type;
// splicer begin class.Class2.C_declaration
// splicer end class.Class2.C_declaration

typedef struct {
    forward::Class2 * self;
    // splicer begin class.Class2.C_object
    // splicer end class.Class2.C_object
} l_Class2_Type;

int luaopen_forward(lua_State *L);

#ifdef __cplusplus
}
#endif
#endif  /* LUAFORWARDMODULE_HPP */
