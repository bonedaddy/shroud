// wrapcxxlibrary.cpp
// This file is generated by Shroud 0.12.1. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapcxxlibrary.h"
#include <cstdlib>
#include "cxxlibrary.hpp"
#include "typescxxlibrary.h"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

/**
 * Argument is modified by library, defaults to intent(inout).
 */
// ----------------------------------------
// Function:  int passStructByReference
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  Cstruct1 & arg +intent(inout)
// Requested: c_struct_&_inout
// Match:     c_struct
int CXX_pass_struct_by_reference(CXX_cstruct1 * arg)
{
    // splicer begin function.pass_struct_by_reference
    Cstruct1 * SHCXX_arg = static_cast<Cstruct1 *>(static_cast<void *>(
        arg));
    int SHC_rv = passStructByReference(*SHCXX_arg);
    return SHC_rv;
    // splicer end function.pass_struct_by_reference
}

/**
 * const defaults to intent(in)
 */
// ----------------------------------------
// Function:  int passStructByReferenceIn
// Requested: c_native_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  const Cstruct1 & arg +intent(in)
// Requested: c_struct_&_in
// Match:     c_struct
int CXX_pass_struct_by_reference_in(const CXX_cstruct1 * arg)
{
    // splicer begin function.pass_struct_by_reference_in
    const Cstruct1 * SHCXX_arg = static_cast<const Cstruct1 *>
        (static_cast<const void *>(arg));
    int SHC_rv = passStructByReferenceIn(*SHCXX_arg);
    return SHC_rv;
    // splicer end function.pass_struct_by_reference_in
}

// ----------------------------------------
// Function:  void passStructByReferenceInout
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  Cstruct1 & arg +intent(inout)
// Requested: c_struct_&_inout
// Match:     c_struct
void CXX_pass_struct_by_reference_inout(CXX_cstruct1 * arg)
{
    // splicer begin function.pass_struct_by_reference_inout
    Cstruct1 * SHCXX_arg = static_cast<Cstruct1 *>(static_cast<void *>(
        arg));
    passStructByReferenceInout(*SHCXX_arg);
    // splicer end function.pass_struct_by_reference_inout
}

// ----------------------------------------
// Function:  void passStructByReferenceOut
// Requested: c
// Match:     c_default
// ----------------------------------------
// Argument:  Cstruct1 & arg +intent(out)
// Requested: c_struct_&_out
// Match:     c_struct
void CXX_pass_struct_by_reference_out(CXX_cstruct1 * arg)
{
    // splicer begin function.pass_struct_by_reference_out
    Cstruct1 * SHCXX_arg = static_cast<Cstruct1 *>(static_cast<void *>(
        arg));
    passStructByReferenceOut(*SHCXX_arg);
    // splicer end function.pass_struct_by_reference_out
}

// ----------------------------------------
// Function:  bool defaultPtrIsNULL
// Requested: c_bool_scalar_result
// Match:     c_default
bool CXX_default_ptr_is_null_0(void)
{
    // splicer begin function.default_ptr_is_null_0
    bool SHC_rv = defaultPtrIsNULL();
    return SHC_rv;
    // splicer end function.default_ptr_is_null_0
}

// ----------------------------------------
// Function:  bool defaultPtrIsNULL
// Requested: c_bool_scalar_result
// Match:     c_default
// ----------------------------------------
// Argument:  double * data=nullptr +intent(in)+rank(1)
// Requested: c_native_*_in
// Match:     c_default
bool CXX_default_ptr_is_null_1(double * data)
{
    // splicer begin function.default_ptr_is_null_1
    bool SHC_rv = defaultPtrIsNULL(data);
    return SHC_rv;
    // splicer end function.default_ptr_is_null_1
}

// Release library allocated memory.
void CXX_SHROUD_memory_destructor(CXX_SHROUD_capsule_data *cap)
{
    cap->addr = nullptr;
    cap->idtor = 0;  // avoid deleting again
}

}  // extern "C"
