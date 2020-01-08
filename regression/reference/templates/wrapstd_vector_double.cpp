// wrapstd_vector_double.cpp
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
#include "wrapstd_vector_double.h"
#include <cstddef>
#include <vector>

// splicer begin namespace.std.class.vector.CXX_definitions
// splicer end namespace.std.class.vector.CXX_definitions

extern "C" {

// splicer begin namespace.std.class.vector.C_definitions
// splicer end namespace.std.class.vector.C_definitions

TEM_vector_double * TEM_vector_double_ctor(TEM_vector_double * SHC_rv)
{
    // splicer begin namespace.std.class.vector.method.ctor
    std::vector<double> *SHCXX_rv = new std::vector<double>();
    SHC_rv->addr = static_cast<void *>(SHCXX_rv);
    SHC_rv->idtor = 0;
    return SHC_rv;
    // splicer end namespace.std.class.vector.method.ctor
}

void TEM_vector_double_dtor(TEM_vector_double * self)
{
    std::vector<double> *SH_this =
        static_cast<std::vector<double> *>(self->addr);
    // splicer begin namespace.std.class.vector.method.dtor
    delete SH_this;
    self->addr = NULL;
    return;
    // splicer end namespace.std.class.vector.method.dtor
}

void TEM_vector_double_push_back(TEM_vector_double * self,
    const double * value)
{
    std::vector<double> *SH_this =
        static_cast<std::vector<double> *>(self->addr);
    // splicer begin namespace.std.class.vector.method.push_back
    SH_this->push_back(*value);
    return;
    // splicer end namespace.std.class.vector.method.push_back
}

double * TEM_vector_double_at(TEM_vector_double * self, size_t n)
{
    std::vector<double> *SH_this =
        static_cast<std::vector<double> *>(self->addr);
    // splicer begin namespace.std.class.vector.method.at
    double & SHC_rv = SH_this->at(n);
    return &SHC_rv;
    // splicer end namespace.std.class.vector.method.at
}

}  // extern "C"
