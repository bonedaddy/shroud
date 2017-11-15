// wrapstrings.cpp
// This is generated code, do not edit
// #######################################################################
// Copyright (c) 2017, Lawrence Livermore National Security, LLC.
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
// wrapstrings.cpp
#include "wrapstrings.h"
#include <cstring>
#include <string>
#include "shroudrt.hpp"
#include "strings.hpp"

// splicer begin CXX_definitions
// splicer end CXX_definitions

extern "C" {

// splicer begin C_definitions
// splicer end C_definitions

// void passChar(char_scalar status+intent(in)+value)
// function_index=0
/**
 * \brief pass a single char argument as a scalar.
 *
 */
void STR_pass_char(char status)
{
// splicer begin function.pass_char
    passChar(status);
    return;
// splicer end function.pass_char
}

// char_scalar returnChar()
// function_index=1
/**
 * \brief return a char argument (non-pointer)
 *
 */
char STR_return_char()
{
// splicer begin function.return_char
    char SH_rv = returnChar();
    return SH_rv;
// splicer end function.return_char
}

// void returnChar(char_scalar * SH_F_rv+intent(out)+len(NSH_F_rv))
// function_index=18
/**
 * \brief return a char argument (non-pointer)
 *
 */
void STR_return_char_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.return_char_bufferify
    char SH_rv = returnChar();
    std::memset(SH_F_rv, ' ', NSH_F_rv);
    SH_F_rv[0] = SH_rv;
    return;
// splicer end function.return_char_bufferify
}

// void passCharPtr(char * dest+intent(out), const char * src+intent(in))
// function_index=2
/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 */
void STR_pass_char_ptr(char * dest, const char * src)
{
// splicer begin function.pass_char_ptr
    passCharPtr(dest, src);
    return;
// splicer end function.pass_char_ptr
}

// void passCharPtr(char * dest+intent(out)+len(Ndest), const char * src+intent(in)+len_trim(Lsrc))
// function_index=19
/**
 * \brief strcpy like behavior
 *
 * dest is marked intent(OUT) to override the intent(INOUT) default
 * This avoid a copy-in on dest.
 */
void STR_pass_char_ptr_bufferify(char * dest, int Ndest, const char * src, int Lsrc)
{
// splicer begin function.pass_char_ptr_bufferify
    char * SH_dest = new char [Ndest + 1];
    char * SH_src = new char [Lsrc + 1];
    std::strncpy(SH_src, src, Lsrc);
    SH_src[Lsrc] = '\0';
    passCharPtr(SH_dest, SH_src);
    shroud_FccCopy(dest, Ndest, SH_dest);
    delete [] SH_dest;
    delete [] SH_src;
    return;
// splicer end function.pass_char_ptr_bufferify
}

// void passCharPtrInOut(char * s+intent(inout))
// function_index=3
/**
 * \brief Change a string in-place
 *
 */
void STR_pass_char_ptr_in_out(char * s)
{
// splicer begin function.pass_char_ptr_in_out
    passCharPtrInOut(s);
    return;
// splicer end function.pass_char_ptr_in_out
}

// void passCharPtrInOut(char * s+intent(inout)+len(Ns)+len_trim(Ls))
// function_index=20
/**
 * \brief Change a string in-place
 *
 */
void STR_pass_char_ptr_in_out_bufferify(char * s, int Ls, int Ns)
{
// splicer begin function.pass_char_ptr_in_out_bufferify
    char * SH_s = new char [Ns + 1];
    std::strncpy(SH_s, s, Ls);
    SH_s[Ls] = '\0';
    passCharPtrInOut(SH_s);
    shroud_FccCopy(s, Ns, SH_s);
    delete [] SH_s;
    return;
// splicer end function.pass_char_ptr_in_out_bufferify
}

// const char * getChar1()+pure
// function_index=4
/**
 * \brief return a 'const char *' as character(*)
 *
 */
const char * STR_get_char1()
{
// splicer begin function.get_char1
    const char * SH_rv = getChar1();
    return SH_rv;
// splicer end function.get_char1
}

// void getChar1(char * SH_F_rv+intent(out)+len(NSH_F_rv))+pure
// function_index=21
/**
 * \brief return a 'const char *' as character(*)
 *
 */
void STR_get_char1_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_char1_bufferify
    const char * SH_rv = getChar1();
    if (SH_rv == NULL) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv);
    }
    return;
// splicer end function.get_char1_bufferify
}

// const char * getChar2()
// function_index=5
/**
 * \brief return 'const char *' with fixed size (len=30)
 *
 */
const char * STR_get_char2()
{
// splicer begin function.get_char2
    const char * SH_rv = getChar2();
    return SH_rv;
// splicer end function.get_char2
}

// void getChar2(char * SH_F_rv+intent(out)+len(NSH_F_rv))
// function_index=22
/**
 * \brief return 'const char *' with fixed size (len=30)
 *
 */
void STR_get_char2_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_char2_bufferify
    const char * SH_rv = getChar2();
    if (SH_rv == NULL) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv);
    }
    return;
// splicer end function.get_char2_bufferify
}

// const char * getChar3()
// function_index=6
/**
 * \brief return a 'const char *' as argument
 *
 */
const char * STR_get_char3()
{
// splicer begin function.get_char3
    const char * SH_rv = getChar3();
    return SH_rv;
// splicer end function.get_char3
}

// void getChar3(char * output+intent(out)+len(Noutput))
// function_index=23
/**
 * \brief return a 'const char *' as argument
 *
 */
void STR_get_char3_bufferify(char * output, int Noutput)
{
// splicer begin function.get_char3_bufferify
    const char * SH_rv = getChar3();
    if (SH_rv == NULL) {
      std::memset(output, ' ', Noutput);
    } else {
      shroud_FccCopy(output, Noutput, SH_rv);
    }
    return;
// splicer end function.get_char3_bufferify
}

// const string & getString1()+pure
// function_index=7
/**
 * \brief return a 'const string&' as character(*)
 *
 */
const char * STR_get_string1()
{
// splicer begin function.get_string1
    const std::string & SH_rv = getString1();
    const char * XSH_rv = SH_rv.c_str();
    return XSH_rv;
// splicer end function.get_string1
}

// void getString1(string & SH_F_rv+intent(out)+len(NSH_F_rv))+pure
// function_index=25
/**
 * \brief return a 'const string&' as character(*)
 *
 */
void STR_get_string1_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_string1_bufferify
    const std::string & SH_rv = getString1();
    if (SH_rv.empty()) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv.c_str());
    }
    return;
// splicer end function.get_string1_bufferify
}

// const string & getString2()
// function_index=8
/**
 * \brief return 'const string&' with fixed size (len=30)
 *
 */
const char * STR_get_string2()
{
// splicer begin function.get_string2
    const std::string & SH_rv = getString2();
    // C_error_pattern
    if (SH_rv.empty()) {
        return NULL;
    }

    const char * XSH_rv = SH_rv.c_str();
    return XSH_rv;
// splicer end function.get_string2
}

// void getString2(string & SH_F_rv+intent(out)+len(NSH_F_rv))
// function_index=26
/**
 * \brief return 'const string&' with fixed size (len=30)
 *
 */
void STR_get_string2_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_string2_bufferify
    const std::string & SH_rv = getString2();
    if (SH_rv.empty()) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv.c_str());
    }
    return;
// splicer end function.get_string2_bufferify
}

// const string & getString3()
// function_index=9
/**
 * \brief return a 'const string&' as argument
 *
 */
const char * STR_get_string3()
{
// splicer begin function.get_string3
    const std::string & SH_rv = getString3();
    // C_error_pattern
    if (SH_rv.empty()) {
        return NULL;
    }

    const char * XSH_rv = SH_rv.c_str();
    return XSH_rv;
// splicer end function.get_string3
}

// void getString3(string & output+intent(out)+len(Noutput))
// function_index=27
/**
 * \brief return a 'const string&' as argument
 *
 */
void STR_get_string3_bufferify(char * output, int Noutput)
{
// splicer begin function.get_string3_bufferify
    const std::string & SH_rv = getString3();
    if (SH_rv.empty()) {
      std::memset(output, ' ', Noutput);
    } else {
      shroud_FccCopy(output, Noutput, SH_rv.c_str());
    }
    return;
// splicer end function.get_string3_bufferify
}

// const string & getString2_empty()
// function_index=10
/**
 * \brief Test returning empty string reference
 *
 */
const char * STR_get_string2_empty()
{
// splicer begin function.get_string2_empty
    const std::string & SH_rv = getString2_empty();
    // C_error_pattern
    if (SH_rv.empty()) {
        return NULL;
    }

    const char * XSH_rv = SH_rv.c_str();
    return XSH_rv;
// splicer end function.get_string2_empty
}

// void getString2_empty(string & SH_F_rv+intent(out)+len(NSH_F_rv))
// function_index=29
/**
 * \brief Test returning empty string reference
 *
 */
void STR_get_string2_empty_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_string2_empty_bufferify
    const std::string & SH_rv = getString2_empty();
    if (SH_rv.empty()) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv.c_str());
    }
    return;
// splicer end function.get_string2_empty_bufferify
}

// void getString5(string * SH_F_rv+intent(out)+len(NSH_F_rv))
// function_index=30
/**
 * \brief return a 'const string' as argument
 *
 */
void STR_get_string5_bufferify(char * SH_F_rv, int NSH_F_rv)
{
// splicer begin function.get_string5_bufferify
    const std::string SH_rv = getString5();
    if (SH_rv.empty()) {
      std::memset(SH_F_rv, ' ', NSH_F_rv);
    } else {
      shroud_FccCopy(SH_F_rv, NSH_F_rv, SH_rv.c_str());
    }
    return;
// splicer end function.get_string5_bufferify
}

// void getString6(string * output+intent(out)+len(Noutput))
// function_index=31
/**
 * \brief return a 'const string' as argument
 *
 */
void STR_get_string6_bufferify(char * output, int Noutput)
{
// splicer begin function.get_string6_bufferify
    const std::string SH_rv = getString6();
    if (SH_rv.empty()) {
      std::memset(output, ' ', Noutput);
    } else {
      shroud_FccCopy(output, Noutput, SH_rv.c_str());
    }
    return;
// splicer end function.get_string6_bufferify
}

// void acceptStringConstReference(const std::string & arg1+intent(in))
// function_index=13
/**
 * \brief Accept a const string reference
 *
 * Save contents of arg1.
 * arg1 is assumed to be intent(IN) since it is const
 * Will copy in.
 */
void STR_accept_string_const_reference(const char * arg1)
{
// splicer begin function.accept_string_const_reference
    const std::string SH_arg1(arg1);
    acceptStringConstReference(SH_arg1);
    return;
// splicer end function.accept_string_const_reference
}

// void acceptStringConstReference(const std::string & arg1+intent(in)+len_trim(Larg1))
// function_index=33
/**
 * \brief Accept a const string reference
 *
 * Save contents of arg1.
 * arg1 is assumed to be intent(IN) since it is const
 * Will copy in.
 */
void STR_accept_string_const_reference_bufferify(const char * arg1, int Larg1)
{
// splicer begin function.accept_string_const_reference_bufferify
    const std::string SH_arg1(arg1, Larg1);
    acceptStringConstReference(SH_arg1);
    return;
// splicer end function.accept_string_const_reference_bufferify
}

// void acceptStringReferenceOut(std::string & arg1+intent(out))
// function_index=14
/**
 * \brief Accept a string reference
 *
 * Set out to a constant string.
 * arg1 is intent(OUT)
 * Must copy out.
 */
void STR_accept_string_reference_out(char * arg1)
{
// splicer begin function.accept_string_reference_out
    std::string SH_arg1;
    acceptStringReferenceOut(SH_arg1);
    strcpy(arg1, SH_arg1.c_str());
    return;
// splicer end function.accept_string_reference_out
}

// void acceptStringReferenceOut(std::string & arg1+intent(out)+len(Narg1))
// function_index=34
/**
 * \brief Accept a string reference
 *
 * Set out to a constant string.
 * arg1 is intent(OUT)
 * Must copy out.
 */
void STR_accept_string_reference_out_bufferify(char * arg1, int Narg1)
{
// splicer begin function.accept_string_reference_out_bufferify
    std::string SH_arg1;
    acceptStringReferenceOut(SH_arg1);
    shroud_FccCopy(arg1, Narg1, SH_arg1.c_str());
    return;
// splicer end function.accept_string_reference_out_bufferify
}

// void acceptStringReference(std::string & arg1+intent(inout))
// function_index=15
/**
 * \brief Accept a string reference
 *
 * Append "dog" to the end of arg1.
 * arg1 is assumed to be intent(INOUT)
 * Must copy in and copy out.
 */
void STR_accept_string_reference(char * arg1)
{
// splicer begin function.accept_string_reference
    std::string SH_arg1(arg1);
    acceptStringReference(SH_arg1);
    strcpy(arg1, SH_arg1.c_str());
    return;
// splicer end function.accept_string_reference
}

// void acceptStringReference(std::string & arg1+intent(inout)+len(Narg1)+len_trim(Larg1))
// function_index=35
/**
 * \brief Accept a string reference
 *
 * Append "dog" to the end of arg1.
 * arg1 is assumed to be intent(INOUT)
 * Must copy in and copy out.
 */
void STR_accept_string_reference_bufferify(char * arg1, int Larg1, int Narg1)
{
// splicer begin function.accept_string_reference_bufferify
    std::string SH_arg1(arg1, Larg1);
    acceptStringReference(SH_arg1);
    shroud_FccCopy(arg1, Narg1, SH_arg1.c_str());
    return;
// splicer end function.accept_string_reference_bufferify
}

// void explicit1(char * name+intent(in)+len_trim(AAlen))
// function_index=16
void STR_explicit1(char * name)
{
// splicer begin function.explicit1
    explicit1(name);
    return;
// splicer end function.explicit1
}

// void explicit1(char * name+intent(in)+len_trim(AAlen))
// function_index=36
void STR_explicit1_BUFFER(char * name, int AAlen)
{
// splicer begin function.explicit1_BUFFER
    char * SH_name = new char [AAlen + 1];
    std::strncpy(SH_name, name, AAlen);
    SH_name[AAlen] = '\0';
    explicit1(SH_name);
    delete [] SH_name;
    return;
// splicer end function.explicit1_BUFFER
}

// void explicit2(char * name+intent(out)+len(AAtrim))
// function_index=17
void STR_explicit2(char * name)
{
// splicer begin function.explicit2
    explicit2(name);
    return;
// splicer end function.explicit2
}

// void explicit2(char * name+intent(out)+len(AAtrim))
// function_index=37
void STR_explicit2_bufferify(char * name, int AAtrim)
{
// splicer begin function.explicit2_bufferify
    char * SH_name = new char [AAtrim + 1];
    explicit2(SH_name);
    shroud_FccCopy(name, AAtrim, SH_name);
    delete [] SH_name;
    return;
// splicer end function.explicit2_bufferify
}

}  // extern "C"
