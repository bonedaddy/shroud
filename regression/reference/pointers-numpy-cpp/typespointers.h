// typespointers.h
// This is generated code, do not edit
// Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESPOINTERS_H
#define TYPESPOINTERS_H


#ifdef __cplusplus
extern "C" {
#endif

struct s_POI_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_POI_SHROUD_capsule_data POI_SHROUD_capsule_data;

void POI_SHROUD_memory_destructor(POI_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESPOINTERS_H
