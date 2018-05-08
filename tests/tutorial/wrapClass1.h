// wrapClass1.h
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-738041.
// All rights reserved.
//
// This file is part of Shroud.  For details, see
// https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the disclaimer below.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the disclaimer (as noted below)
//   in the documentation and/or other materials provided with the
//   distribution.
//
// * Neither the name of the LLNS/LLNL nor the names of its contributors
//   may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
// LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// #######################################################################
/**
 * \file wrapClass1.h
 * \brief Shroud generated wrapper for Class1 class
 */
// For C users and C++ implementation

#ifndef WRAPCLASS1_H
#define WRAPCLASS1_H

// splicer begin class.Class1.CXX_declarations
// splicer end class.Class1.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

//  DIRECTION
enum TUT_class1_DIRECTION {
    UP = 2,
    DOWN,
    LEFT = 100,
    RIGHT
};

// declaration of shadow types
struct s_TUT_class1 {
    void *addr;   /* address of C++ memory */
    int idtor;    /* index of destructor */
    int refcount; /* reference count */
};
typedef struct s_TUT_class1 TUT_class1;

// splicer begin class.Class1.C_declarations
// splicer end class.Class1.C_declarations

TUT_class1 * TUT_class1_new_default();

TUT_class1 * TUT_class1_new_flag(int flag);

void TUT_class1_delete(TUT_class1 * self);

int TUT_class1_method1(TUT_class1 * self);

bool TUT_class1_equivalent(const TUT_class1 * self,
    const TUT_class1 * obj2);

void TUT_class1_return_this(TUT_class1 * self);

TUT_class1 * TUT_class1_return_this_buffer(TUT_class1 * self,
    char * name);

TUT_class1 * TUT_class1_return_this_buffer_bufferify(TUT_class1 * self,
    char * name, int Lname);

int TUT_class1_direction_func(TUT_class1 * self, int arg);

int TUT_class1_get_m_flag(TUT_class1 * self);

int TUT_class1_get_test(TUT_class1 * self);

void TUT_class1_set_test(TUT_class1 * self, int val);

void TUT_SHROUD_array_destructor_function(TUT_class1 *cap, bool gc);

#ifdef __cplusplus
}
#endif

#endif  // WRAPCLASS1_H
