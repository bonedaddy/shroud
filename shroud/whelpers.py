"""
Helper functions for C and Fortran wrappers.
"""

FccHeaders = """
#ifndef SHROUDRT_HPP_
#define SHROUDRT_HPP_

#ifdef __cplusplus
extern "C" {
#endif

void shroud_FccCopy(char *a, int la, const char *s);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif /* SHROUDRT_HPP_ */
"""

#
# C routines used by wrappers
#
# shroud_c_loc must be compiled by C but called by Fortran.
#

FccCSource = """
#ifdef __cplusplus
// Standard C++ headers
#include <cstring>
using namespace std;
extern "C" {
#else
#include <string.h>
#endif

void shroud_FccCopy(char *a, int la, const char *s)
{
   int ls,nm;
   ls = strlen(s);
   nm = ls < la ? ls : la;
   memcpy(a,s,nm);
   if(la > nm) { memset(a+nm,' ',la-nm);}
}

// equivalent to C_LOC
// called from Fortran
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=53945
// Work around a problem with gfortran 4.7 where C_LOC does not work
// with assumed shape array.  Passing the first element of the
// array to a function without an interface will force the compiler
// to use f77 semantics and pass the address of the data, essentially
// the same as C_LOC.
// XXX Pass the first element, not the entire array, to avoid getting
// XXX a copy of the array.
//
// The result must be an argument because some compilers (Intel)
// cannot return type(C_PTR)
void shroud_c_loc(void * addr, void ** out)
{
  *out = addr;
}
void shroud_c_loc_(void * addr, void ** out)
{
  *out = addr;
}


#ifdef __cplusplus
}  // extern \"C\"
#endif"""

#
# Fortran helper functions which may be added to a module.
#
# f_helpers = dictionary of helpers needed by this helper
# private   = names for PRIVATE statement 
# interface = code for INTERFACE
# source    = code for CONTAINS
#
#
FHelpers = dict(
    fstr=dict(
        f_helper=dict(strlen_ptr=True, strlen_arr=True),
        private=['fstr', 'fstr_ptr', 'fstr_arr'],
        interface="""
interface fstr
  module procedure fstr_ptr, fstr_arr
end interface""",
        source="""
! Convert a null-terminated C "char *" pointer to a Fortran string.
function fstr_ptr(s) result(fs)
  use, intrinsic :: iso_c_binding, only: c_char, c_ptr, c_f_pointer
  type(c_ptr), intent(in) :: s
  character(kind=c_char, len=strlen_ptr(s)) :: fs
  character(kind=c_char), pointer :: cptr(:)
  integer :: i
  call c_f_pointer(s, cptr, [len(fs)])
  do i=1, len(fs)
     fs(i:i) = cptr(i)
  enddo
end function fstr_ptr

! Convert a null-terminated array of characters to a Fortran string.
function fstr_arr(s) result(fs)
  use, intrinsic :: iso_c_binding, only : c_char, c_null_char
  character(kind=c_char, len=1), intent(in) :: s(*)
  character(kind=c_char, len=strlen_arr(s)) :: fs
  integer :: i
  do i = 1, len(fs)
     fs(i:i) = s(i)
  enddo
end function fstr_arr""",
        ),

    strlen_arr=dict(
        private=['strlen_arr'],
        source="""
! Count the characters in a null-terminated array.
pure function strlen_arr(s)
  use, intrinsic :: iso_c_binding, only : c_char, c_null_char
  character(kind=c_char, len=1), intent(in) :: s(*)
  integer :: i, strlen_arr
  i=1
  do
     if (s(i) == c_null_char) exit
     i = i+1
  enddo
  strlen_arr = i-1
end function strlen_arr"""
    ),

    strlen_ptr=dict(
        private=['strlen_ptr'],
        interface="""
interface
   pure function strlen_ptr(s) result(result) bind(c,name="strlen")
     use, intrinsic :: iso_c_binding
     integer(c_int) :: result
     type(c_ptr), value, intent(in) :: s
   end function strlen_ptr
end interface"""
        )
    )


# From fstr_mod.f
#  ! Convert a fortran string in 's' to a null-terminated array of characters.
#  pure function cstr(s)
#    use, intrinsic :: iso_c_binding, only : c_char, c_null_char
#    character(len=*), intent(in) :: s
#    character(kind=c_char, len=1) :: cstr(len_trim(s)+1)
#    integer :: i
#    if (len_trim(s) > 0) cstr = [ (s(i:i), i=1,len_trim(s)) ]
#    cstr(len_trim(s)+1) = c_null_char
#  end function cstr


cmake = """
# Setup Shroud
# This file defines:
#  SHROUD_FOUND - If Shroud was found

if(NOT SHROUD_EXECUTABLE)
    MESSAGE(FATAL_ERROR "Could not find Shroud. Shroud requires explicit SHROUD_EXECUTABLE.")
endif()

message(STATUS Found SHROUD: ${SHROUD_EXECUTABLE})

add_custom_target(generate)
set(SHROUD_FOUND TRUE)

#
# Setup targets to generate code.
#
# Each package can create their own ${PROJECT}_generate target
#  add_dependencies(generate  ${PROJECT}_generate)

##------------------------------------------------------------------------------
## add_shroud( YAML_INPUT_FILE file
##             DEPENDS_SOURCE file1 ... filen
##             DEPENDS_BINARY file1 ... filen
##             C_FORTRAN_OUTPUT_DIR dir
##             PYTHON_OUTPUT_DIR dir
##             LUA_OUTPUT_DIR dir
##             YAML_OUTPUT_DIR dir
## )
##
##  YAML_INPUT_FILE - yaml input file to shroud. Required.
##  DEPENDS_SOURCE  - splicer files in the source directory
##  DEPENDS_BINARY  - splicer files in the binary directory
##  C_FORTRAN_OUTPUT_DIR - directory for C and Fortran wrapper output files.
##  PYTHON_OUTPUT_DIR - directory for Python wrapper output files.
##  LUA_OUTPUT_DIR - directory for Lua wrapper output files.
##  YAML_OUTPUT_DIR - directory for YAML output files.
##                    Defaults to CMAKE_CURRENT_SOURCE_DIR
##
## Add a shroud target to generate wrappers.
##
##------------------------------------------------------------------------------

macro(add_shroud)

    # Decide where the output files should be written.
    # For now all files are written into the source directory.
    # This allows them to be source controlled and does not require a library user
    # to generate them.  All they have to do is compile them.
    #set(SHROUD_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})
    set(SHROUD_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

    set(options)
    set(singleValueArgs
        YAML_INPUT_FILE
        C_FORTRAN_OUTPUT_DIR
        PYTHON_OUTPUT_DIR
        LUA_OUTPUT_DIR
        YAML_OUTPUT_DIR
    )
    set(multiValueArgs DEPENDS_SOURCE DEPENDS_BINARY )

    ## parse the arguments to the macro
    cmake_parse_arguments(arg
         "${options}" "${singleValueArgs}" "${multiValueArgs}" ${ARGN})

    # make sure YAML_INPUT_FILE is defined
    if(NOT arg_YAML_INPUT_FILE)
      message(FATAL_ERROR "add_shroud macro must define YAML_INPUT_FILE")
    endif()

    if(arg_C_FORTRAN_OUTPUT_DIR)
      set(SHROUD_C_FORTRAN_OUTPUT_DIR --outdir-c-fortran ${arg_C_FORTRAN_OUTPUT_DIR})
    endif()

    if(arg_PYTHON_OUTPUT_DIR)
      set(SHROUD_PYTHON_OUTPUT_DIR --outdir-python ${arg_PYTHON_OUTPUT_DIR})
    endif()

    if(arg_LUA_OUTPUT_DIR)
      set(SHROUD_LUA_OUTPUT_DIR --outdir-lua ${arg_LUA_OUTPUT_DIR})
    endif()

    if(arg_YAML_OUTPUT_DIR)
      set(SHROUD_YAML_OUTPUT_DIR --outdir-yaml ${arg_YAML_OUTPUT_DIR})
    else()
      set(SHROUD_YAML_OUTPUT_DIR --outdir-yaml ${CMAKE_CURRENT_SOURCE_DIR})
    endif()

    # convert DEPENDS to full paths
    set(shroud_depends)
    foreach (_file ${arg_DEPENDS_SOURCE})
        list(APPEND shroud_depends "${CMAKE_CURRENT_SOURCE_DIR}/${_file}")
    endforeach ()
    foreach (_file ${arg_DEPENDS_BINARY})
        list(APPEND shroud_depends "${CMAKE_CURRENT_BINARY_DIR}/${_file}")
    endforeach ()

    get_filename_component(_basename ${arg_YAML_INPUT_FILE} NAME_WE)
    set(_timestamp  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.time)
    set(_cfiles     ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.cfiles)
    set(_ffiles     ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.ffiles)

    set(_cmd
        ${SHROUD_EXECUTABLE}
        --logdir ${CMAKE_CURRENT_BINARY_DIR}
        ${SHROUD_C_FORTRAN_OUTPUT_DIR}
        ${SHROUD_PYTHON_OUTPUT_DIR}
        ${SHROUD_LUA_OUTPUT_DIR}
        ${SHROUD_YAML_OUTPUT_DIR}
        # path controls where to search for splicer files listed in YAML_INPUT_FILE
        --path ${CMAKE_CURRENT_BINARY_DIR}
        --path ${CMAKE_CURRENT_SOURCE_DIR}
        --cfiles ${_cfiles}
        --ffiles ${_ffiles}
        ${CMAKE_CURRENT_SOURCE_DIR}/${arg_YAML_INPUT_FILE}
    )

    add_custom_command(
        OUTPUT  ${_timestamp}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${arg_YAML_INPUT_FILE} ${shroud_depends}
        COMMAND ${_cmd}
        COMMAND touch ${_timestamp}
        COMMENT "Running shroud ${arg_YAML_INPUT_FILE}"
        WORKING_DIRECTORY ${SHROUD_OUTPUT_DIR}
    )

    # Create target to process this Shroud file
    set(_shroud_target generate_${_basename})
    add_custom_target(${_shroud_target}
        DEPENDS ${_timestamp}
    )

    add_dependencies(generate ${_shroud_target})
endmacro(add_shroud)
"""
