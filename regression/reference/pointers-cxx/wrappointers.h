// wrappointers.h
// This file is generated by Shroud 0.12.1. Do not edit.
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
/**
 * \file wrappointers.h
 * \brief Shroud generated wrapper for pointers library
 */
// For C users and C++ implementation

#ifndef WRAPPOINTERS_H
#define WRAPPOINTERS_H

#include "typespointers.h"
#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif

// splicer begin CXX_declarations
// splicer end CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin C_declarations
// splicer end C_declarations

void POI_intargs_in(const int * arg);

void POI_intargs_inout(int * arg);

void POI_intargs_out(int * arg);

void POI_intargs(const int argin, int * arginout, int * argout);

void POI_cos_doubles(double * in, double * out, int sizein);

void POI_truncate_to_int(double * in, int * out, int sizein);

void POI_get_values(int * nvalues, int * values);

void POI_get_values2(int * arg1, int * arg2);

void POI_iota_allocatable(int nvar, int * values);

void POI_iota_dimension(int nvar, int * values);

void POI_sum(int len, const int * values, int * result);

void POI_fill_int_array(int * out);

void POI_increment_int_array(int * array, int sizein);

void POI_fill_with_zeros(double * x, int x_length);

int POI_accumulate(const int * arr, size_t len);

int POI_accept_char_array_in(char **names);

int POI_accept_char_array_in_bufferify(char *names, long Snames,
    int Nnames);

void POI_set_global_int(int value);

int POI_sum_fixed_array(void);

void POI_get_ptr_to_scalar(int * * nitems);

void POI_get_ptr_to_scalar_bufferify(POI_SHROUD_array *Dnitems);

void POI_get_ptr_to_fixed_array(int * * count);

void POI_get_ptr_to_fixed_array_bufferify(POI_SHROUD_array *Dcount);

void POI_get_ptr_to_dynamic_array(int * * count, int * ncount);

void POI_get_ptr_to_dynamic_array_bufferify(POI_SHROUD_array *Dcount,
    int * ncount);

void POI_get_ptr_to_func_array(int * * count);

void POI_get_ptr_to_func_array_bufferify(POI_SHROUD_array *Dcount);

void POI_get_ptr_to_const_scalar(const int * * nitems);

void POI_get_ptr_to_const_scalar_bufferify(POI_SHROUD_array *Dnitems);

void POI_get_ptr_to_fixed_const_array(const int * * count);

void POI_get_ptr_to_fixed_const_array_bufferify(
    POI_SHROUD_array *Dcount);

void POI_get_ptr_to_dynamic_const_array(const int * * count,
    int * ncount);

void POI_get_ptr_to_dynamic_const_array_bufferify(
    POI_SHROUD_array *Dcount, int * ncount);

void POI_get_raw_ptr_to_scalar(int * * nitems);

void POI_get_raw_ptr_to_scalar_bufferify(POI_SHROUD_array *Dnitems);

void POI_get_raw_ptr_to_scalar_force(int * * nitems);

void POI_get_raw_ptr_to_scalar_force_bufferify(
    POI_SHROUD_array *Dnitems);

void POI_get_raw_ptr_to_fixed_array(int * * count);

void POI_get_raw_ptr_to_fixed_array_bufferify(POI_SHROUD_array *Dcount);

void POI_get_raw_ptr_to_fixed_array_force(int * * count);

void POI_get_raw_ptr_to_fixed_array_force_bufferify(
    POI_SHROUD_array *Dcount);

void POI_get_raw_ptr_to_int2d(int * * * arg);

int POI_check_int2d(int **arg);

void POI_dimension_in(const int * arg);

void * POI_return_address1(int flag);

void * POI_return_address2(int flag);

void POI_fetch_void_ptr(void * * addr);

int * POI_return_int_ptr_to_scalar(void);

int * POI_return_int_ptr_to_fixed_array(void);

int * POI_return_int_ptr_to_fixed_array_bufferify(
    POI_SHROUD_array *DSHC_rv);

const int * POI_return_int_ptr_to_const_scalar(void);

const int * POI_return_int_ptr_to_fixed_const_array(void);

const int * POI_return_int_ptr_to_fixed_const_array_bufferify(
    POI_SHROUD_array *DSHC_rv);

int POI_return_int_scalar(void);

int * POI_return_int_raw(void);

int * POI_return_int_raw_with_args(const char * name);

int * * POI_return_raw_ptr_to_int2d(void);

#ifdef __cplusplus
}
#endif

#endif  // WRAPPOINTERS_H
