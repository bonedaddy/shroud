! wrapfcxxlibrary.f
! This file is generated by Shroud 0.11.0. Do not edit.
! Copyright (c) 2017-2020, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfcxxlibrary.f
!! \brief Shroud generated wrapper for cxxlibrary library
!<
! splicer begin file_top
! splicer end file_top
module cxxlibrary_mod
    use iso_c_binding, only : C_DOUBLE, C_INT
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top


    type, bind(C) :: cstruct1
        integer(C_INT) :: ifield
        real(C_DOUBLE) :: dfield
    end type cstruct1

    interface

        ! ----------------------------------------
        ! Function:  int passStructByReference
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 & arg +intent(in)
        ! Requested: c_struct_&_in
        ! Match:     c_struct
        function pass_struct_by_reference(arg) &
                result(SHT_rv) &
                bind(C, name="CXX_pass_struct_by_reference")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct_by_reference

        ! ----------------------------------------
        ! Function:  int passStructByReferenceIn
        ! Requested: c_native_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  const Cstruct1 & arg +intent(in)
        ! Requested: c_struct_&_in
        ! Match:     c_struct
        function pass_struct_by_reference_in(arg) &
                result(SHT_rv) &
                bind(C, name="CXX_pass_struct_by_reference_in")
            use iso_c_binding, only : C_INT
            import :: cstruct1
            implicit none
            type(cstruct1), intent(IN) :: arg
            integer(C_INT) :: SHT_rv
        end function pass_struct_by_reference_in

        ! ----------------------------------------
        ! Function:  void passStructByReferenceInout
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 & arg +intent(inout)
        ! Requested: c_struct_&_inout
        ! Match:     c_struct
        subroutine pass_struct_by_reference_inout(arg) &
                bind(C, name="CXX_pass_struct_by_reference_inout")
            import :: cstruct1
            implicit none
            type(cstruct1), intent(INOUT) :: arg
        end subroutine pass_struct_by_reference_inout

        ! ----------------------------------------
        ! Function:  void passStructByReferenceOut
        ! Requested: c_unknown_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  Cstruct1 & arg +intent(out)
        ! Requested: c_struct_&_out
        ! Match:     c_struct
        subroutine pass_struct_by_reference_out(arg) &
                bind(C, name="CXX_pass_struct_by_reference_out")
            import :: cstruct1
            implicit none
            type(cstruct1), intent(OUT) :: arg
        end subroutine pass_struct_by_reference_out

        ! ----------------------------------------
        ! Function:  bool defaultPtrIsNULL
        ! Requested: c_bool_scalar_result
        ! Match:     c_default
        function c_default_ptr_is_null_0() &
                result(SHT_rv) &
                bind(C, name="CXX_default_ptr_is_null_0")
            use iso_c_binding, only : C_BOOL
            implicit none
            logical(C_BOOL) :: SHT_rv
        end function c_default_ptr_is_null_0

        ! ----------------------------------------
        ! Function:  bool defaultPtrIsNULL
        ! Requested: c_bool_scalar_result
        ! Match:     c_default
        ! ----------------------------------------
        ! Argument:  double * data=nullptr +intent(in)+rank(1)
        ! Requested: c_native_*_in
        ! Match:     c_default
        function c_default_ptr_is_null_1(data) &
                result(SHT_rv) &
                bind(C, name="CXX_default_ptr_is_null_1")
            use iso_c_binding, only : C_BOOL, C_DOUBLE
            implicit none
            real(C_DOUBLE), intent(IN) :: data(*)
            logical(C_BOOL) :: SHT_rv
        end function c_default_ptr_is_null_1

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface default_ptr_is_null
        module procedure default_ptr_is_null_0
        module procedure default_ptr_is_null_1
    end interface default_ptr_is_null

contains

    ! Generated by has_default_arg
    ! ----------------------------------------
    ! Function:  bool defaultPtrIsNULL
    ! bool defaultPtrIsNULL
    ! Requested: f_bool_scalar_result
    ! Match:     f_bool_result
    ! Requested: c_bool_scalar_result
    ! Match:     c_default
    function default_ptr_is_null_0() &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL
        logical :: SHT_rv
        ! splicer begin function.default_ptr_is_null_0
        SHT_rv = c_default_ptr_is_null_0()
        ! splicer end function.default_ptr_is_null_0
    end function default_ptr_is_null_0

    ! ----------------------------------------
    ! Function:  bool defaultPtrIsNULL
    ! bool defaultPtrIsNULL
    ! Requested: f_bool_scalar_result
    ! Match:     f_bool_result
    ! Requested: c_bool_scalar_result
    ! Match:     c_default
    ! ----------------------------------------
    ! Argument:  double * data=nullptr +intent(in)+rank(1)
    ! Requested: f_native_*_in
    ! Match:     f_default
    ! Requested: c_native_*_in
    ! Match:     c_default
    function default_ptr_is_null_1(data) &
            result(SHT_rv)
        use iso_c_binding, only : C_BOOL, C_DOUBLE
        real(C_DOUBLE), intent(IN) :: data(:)
        logical :: SHT_rv
        ! splicer begin function.default_ptr_is_null_1
        SHT_rv = c_default_ptr_is_null_1(data)
        ! splicer end function.default_ptr_is_null_1
    end function default_ptr_is_null_1

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module cxxlibrary_mod
