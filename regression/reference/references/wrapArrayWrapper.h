// wrapArrayWrapper.h
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrapArrayWrapper.h
 * \brief Shroud generated wrapper for ArrayWrapper class
 */
// For C users and C++ implementation

#ifndef WRAPARRAYWRAPPER_H
#define WRAPARRAYWRAPPER_H

#include "typesreferences.h"

// splicer begin class.ArrayWrapper.CXX_declarations
// splicer end class.ArrayWrapper.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin class.ArrayWrapper.C_declarations
// splicer end class.ArrayWrapper.C_declarations

REF_ArrayWrapper * REF_ArrayWrapper_ctor(REF_ArrayWrapper * SHC_rv);

void REF_ArrayWrapper_set_size(REF_ArrayWrapper * self, int size);

int REF_ArrayWrapper_get_size(const REF_ArrayWrapper * self);

void REF_ArrayWrapper_fill_size(REF_ArrayWrapper * self, int * size);

void REF_ArrayWrapper_allocate(REF_ArrayWrapper * self);

double * REF_ArrayWrapper_get_array(REF_ArrayWrapper * self);

double * REF_ArrayWrapper_get_array_bufferify(REF_ArrayWrapper * self,
    REF_SHROUD_array *DSHC_rv);

double * REF_ArrayWrapper_get_array_const(
    const REF_ArrayWrapper * self);

double * REF_ArrayWrapper_get_array_const_bufferify(
    const REF_ArrayWrapper * self, REF_SHROUD_array *DSHC_rv);

const double * REF_ArrayWrapper_get_array_c(REF_ArrayWrapper * self);

const double * REF_ArrayWrapper_get_array_c_bufferify(
    REF_ArrayWrapper * self, REF_SHROUD_array *DSHC_rv);

const double * REF_ArrayWrapper_get_array_const_c(
    const REF_ArrayWrapper * self);

const double * REF_ArrayWrapper_get_array_const_c_bufferify(
    const REF_ArrayWrapper * self, REF_SHROUD_array *DSHC_rv);

void REF_ArrayWrapper_fetch_array_ptr(REF_ArrayWrapper * self,
    double * * array, int * isize);

void REF_ArrayWrapper_fetch_array_ptr_bufferify(REF_ArrayWrapper * self,
    REF_SHROUD_array *Darray, int * isize);

void REF_ArrayWrapper_fetch_array_ref(REF_ArrayWrapper * self,
    double * * array, int * isize);

void REF_ArrayWrapper_fetch_array_ref_bufferify(REF_ArrayWrapper * self,
    REF_SHROUD_array *Darray, int * isize);

void REF_ArrayWrapper_fetch_void_ptr(REF_ArrayWrapper * self,
    void * * array);

#ifdef __cplusplus
}
#endif

#endif  // WRAPARRAYWRAPPER_H
