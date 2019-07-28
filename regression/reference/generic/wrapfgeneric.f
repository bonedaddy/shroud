! wrapfgeneric.f
! This is generated code, do not edit
! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfgeneric.f
!! \brief Shroud generated wrapper for generic library
!<
! splicer begin file_top
! splicer end file_top
module generic_mod
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    interface

        function get_global_double() &
                result(SHT_rv) &
                bind(C, name="GetGlobalDouble")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE) :: SHT_rv
        end function get_global_double

        subroutine c_generic_real(arg) &
                bind(C, name="GenericReal")
            use iso_c_binding, only : C_DOUBLE
            implicit none
            real(C_DOUBLE), value, intent(IN) :: arg
        end subroutine c_generic_real

        function c_generic_real2(arg1, arg2) &
                result(SHT_rv) &
                bind(C, name="GenericReal2")
            use iso_c_binding, only : C_LONG
            implicit none
            integer(C_LONG), value, intent(IN) :: arg1
            integer(C_LONG), value, intent(IN) :: arg2
            integer(C_LONG) :: SHT_rv
        end function c_generic_real2

#if 0
        subroutine c_save_pointer(addr, type, asize) &
                bind(C, name="SavePointer")
            use iso_c_binding, only : C_INT, C_PTR, C_SIZE_T
            implicit none
            type(C_PTR), value, intent(IN) :: addr
            integer(C_INT), value, intent(IN) :: type
            integer(C_SIZE_T), value, intent(IN) :: asize
        end subroutine c_save_pointer
#endif

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces
    end interface

    interface generic_real
        module procedure generic_real_float
        module procedure generic_real_double
    end interface generic_real

    interface generic_real2
        module procedure generic_real2_all_int
        module procedure generic_real2_all_long
    end interface generic_real2

    interface save_pointer
#if 0
        module procedure save_pointer_float1d
#endif
#if 0
        module procedure save_pointer_float2d
#endif
    end interface save_pointer

contains

    ! void GenericReal(float arg +intent(in)+value)
    ! fortran_generic
    !>
    !! \brief Single argument generic
    !!
    !<
    subroutine generic_real_float(arg)
        use iso_c_binding, only : C_DOUBLE, C_FLOAT
        real(C_FLOAT), value, intent(IN) :: arg
        ! splicer begin function.generic_real_float
        call c_generic_real(real(arg, C_DOUBLE))
        ! splicer end function.generic_real_float
    end subroutine generic_real_float

    ! void GenericReal(double arg +intent(in)+value)
    ! fortran_generic
    !>
    !! \brief Single argument generic
    !!
    !<
    subroutine generic_real_double(arg)
        use iso_c_binding, only : C_DOUBLE
        real(C_DOUBLE), value, intent(IN) :: arg
        ! splicer begin function.generic_real_double
        call c_generic_real(arg)
        ! splicer end function.generic_real_double
    end subroutine generic_real_double

    ! long GenericReal2(int arg1 +intent(in)+value, int arg2 +intent(in)+value)
    ! fortran_generic
    !>
    !! \brief Two argument generic
    !!
    !! It is not possible to call the function with (int, long)
    !! or (long, int)
    !<
    function generic_real2_all_int(arg1, arg2) &
            result(SHT_rv)
        use iso_c_binding, only : C_INT, C_LONG
        integer(C_INT), value, intent(IN) :: arg1
        integer(C_INT), value, intent(IN) :: arg2
        integer(C_LONG) :: SHT_rv
        ! splicer begin function.generic_real2_all_int
        SHT_rv = c_generic_real2(int(arg1, C_LONG), int(arg2, C_LONG))
        ! splicer end function.generic_real2_all_int
    end function generic_real2_all_int

    ! long GenericReal2(long arg1 +intent(in)+value, long arg2 +intent(in)+value)
    ! fortran_generic
    !>
    !! \brief Two argument generic
    !!
    !! It is not possible to call the function with (int, long)
    !! or (long, int)
    !<
    function generic_real2_all_long(arg1, arg2) &
            result(SHT_rv)
        use iso_c_binding, only : C_LONG
        integer(C_LONG), value, intent(IN) :: arg1
        integer(C_LONG), value, intent(IN) :: arg2
        integer(C_LONG) :: SHT_rv
        ! splicer begin function.generic_real2_all_long
        SHT_rv = c_generic_real2(arg1, arg2)
        ! splicer end function.generic_real2_all_long
    end function generic_real2_all_long

#if 0
    ! void SavePointer(float * addr +dimension(:)+intent(in), int type +implied(1)+intent(in)+value, size_t asize +implied(size(addr))+intent(in)+value)
    ! fortran_generic
    subroutine save_pointer_float1d(addr)
        use iso_c_binding, only : C_FLOAT, C_INT, C_PTR, C_SIZE_T
        real(C_FLOAT), intent(IN) :: addr(:)
        integer(C_INT) :: type
        integer(C_SIZE_T) :: asize
        type = 1
        asize = size(addr,kind=C_SIZE_T)
        ! splicer begin function.save_pointer_float1d
        call c_save_pointer(addr, type, asize)
        ! splicer end function.save_pointer_float1d
    end subroutine save_pointer_float1d
#endif

#if 0
    ! void SavePointer(float * addr +dimension(:,:)+intent(in), int type +implied(1)+intent(in)+value, size_t asize +implied(size(addr))+intent(in)+value)
    ! fortran_generic
    subroutine save_pointer_float2d(addr)
        use iso_c_binding, only : C_FLOAT, C_INT, C_PTR, C_SIZE_T
        real(C_FLOAT), intent(IN) :: addr(:,:)
        integer(C_INT) :: type
        integer(C_SIZE_T) :: asize
        type = 1
        asize = size(addr,kind=C_SIZE_T)
        ! splicer begin function.save_pointer_float2d
        call c_save_pointer(addr, type, asize)
        ! splicer end function.save_pointer_float2d
    end subroutine save_pointer_float2d
#endif

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module generic_mod
