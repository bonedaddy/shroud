// wraptypes.cpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2018, Lawrence Livermore National Security, LLC.
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
#include "wraptypes.h"
#include <stdlib.h>
#include "types.hpp"
#include "typestypes.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// short short_func(short arg1 +intent(in)+value)
short TYP_short_func(short arg1)
{
// splicer begin function.short_func
    short SHC_rv = short_func(arg1);
    return SHC_rv;
// splicer end function.short_func
}

// int int_func(int arg1 +intent(in)+value)
int TYP_int_func(int arg1)
{
// splicer begin function.int_func
    int SHC_rv = int_func(arg1);
    return SHC_rv;
// splicer end function.int_func
}

// long long_func(long arg1 +intent(in)+value)
long TYP_long_func(long arg1)
{
// splicer begin function.long_func
    long SHC_rv = long_func(arg1);
    return SHC_rv;
// splicer end function.long_func
}

// long long long2_func(long long arg1 +intent(in)+value)
long long TYP_long2_func(long long arg1)
{
// splicer begin function.long2_func
    long long SHC_rv = long2_func(arg1);
    return SHC_rv;
// splicer end function.long2_func
}

// unsigned short ushort_func(unsigned short arg1 +intent(in)+value)
unsigned short TYP_ushort_func(unsigned short arg1)
{
// splicer begin function.ushort_func
    unsigned short SHC_rv = ushort_func(arg1);
    return SHC_rv;
// splicer end function.ushort_func
}

// unsigned int uint_func(unsigned int arg1 +intent(in)+value)
unsigned int TYP_uint_func(unsigned int arg1)
{
// splicer begin function.uint_func
    unsigned int SHC_rv = uint_func(arg1);
    return SHC_rv;
// splicer end function.uint_func
}

// unsigned long ulong_func(unsigned long arg1 +intent(in)+value)
unsigned long TYP_ulong_func(unsigned long arg1)
{
// splicer begin function.ulong_func
    unsigned long SHC_rv = ulong_func(arg1);
    return SHC_rv;
// splicer end function.ulong_func
}

// unsigned long long ulong_long_func(unsigned long long arg1 +intent(in)+value)
unsigned long long TYP_ulong_long_func(unsigned long long arg1)
{
// splicer begin function.ulong_long_func
    unsigned long long SHC_rv = ulong_long_func(arg1);
    return SHC_rv;
// splicer end function.ulong_long_func
}

// int8_t int8_func(int8_t arg1 +intent(in)+value)
int8_t TYP_int8_func(int8_t arg1)
{
// splicer begin function.int8_func
    int8_t SHC_rv = int8_func(arg1);
    return SHC_rv;
// splicer end function.int8_func
}

// int16_t int16_func(int16_t arg1 +intent(in)+value)
int16_t TYP_int16_func(int16_t arg1)
{
// splicer begin function.int16_func
    int16_t SHC_rv = int16_func(arg1);
    return SHC_rv;
// splicer end function.int16_func
}

// int32_t int32_func(int32_t arg1 +intent(in)+value)
int32_t TYP_int32_func(int32_t arg1)
{
// splicer begin function.int32_func
    int32_t SHC_rv = int32_func(arg1);
    return SHC_rv;
// splicer end function.int32_func
}

// int64_t int64_func(int64_t arg1 +intent(in)+value)
int64_t TYP_int64_func(int64_t arg1)
{
// splicer begin function.int64_func
    int64_t SHC_rv = int64_func(arg1);
    return SHC_rv;
// splicer end function.int64_func
}

// Release C++ allocated memory.
void TYP_SHROUD_memory_destructor(TYP_SHROUD_capsule_data *cap)
{
    cap->addr = NULL;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
