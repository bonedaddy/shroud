/*
 * Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
 * other Shroud Project Developers.
 * See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (BSD-3-Clause)
 */

#include <wraptypes.h>

#include <assert.h>

void test_native_types(void)
{
  short rv_short = -1;
  rv_short = TYP_short_func(1);
  assert(rv_short == 1 && "TYP_short_func");
}

int main(int argc, char *argv[])
{
  test_native_types();

  return 0;
}

