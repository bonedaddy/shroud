# Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
# other Shroud Project Developers.
# See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
#
# #######################################################################
#
#  Compile the python pointers module
#
include $(top)/regression/run/defaults.mk

INCLUDE = \
    -I$(top)/regression/reference/pointers-numpy-cxx \
    -I$(top)/regression/run/pointers \
    $(PYTHON_INC)

VPATH = \
    $(top)/regression/reference/pointers-numpy-cxx \
    $(top)/regression/run/pointers/python

OBJS = \
    pointers.o \
    pypointersmodule.o

CXXFLAGS += $(SHARED)

all : pointers.so simple

# Convert C file to C++
pointers.cpp : $(top)/regression/run/pointers/pointers.c
	cp $^ $@
pointers.o : pointers.cpp

pointers.so : $(OBJS)
	$(CXX) $(LD_SHARED) $^ -o $@ $(LIBS)

simple : testpython.o $(OBJS)
	$(CXX) -pthread -o $@ $^ $(PYTHON_LIB)
#	g++ -pthread -o $@ $^ $(PYTHON_LIB)

clean :
	rm -f *.so *.o simple
.PHONY : clean

print-debug:
	@echo PYTHON=$(PYTHON)
	@echo PYTHON_PREFIX=$(PYTHON_PREFIX)
	@echo PYTHON_VER=$(PYTHON_VER)

