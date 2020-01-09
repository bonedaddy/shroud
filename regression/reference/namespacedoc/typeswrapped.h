// typeswrapped.h
// This is generated code, do not edit
// Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
// other Shroud Project Developers.
// See the top-level COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//
// For C users and C++ implementation

#ifndef TYPESWRAPPED_H
#define TYPESWRAPPED_H


#ifdef __cplusplus
extern "C" {
#endif

struct s_WWW_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_WWW_SHROUD_capsule_data WWW_SHROUD_capsule_data;

void WWW_SHROUD_memory_destructor(WWW_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESWRAPPED_H