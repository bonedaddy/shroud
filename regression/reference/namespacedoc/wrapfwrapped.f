! wrapfwrapped.f
! This is generated code, do not edit
! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfwrapped.f
!! \brief Shroud generated wrapper for outer namespace
!<
! splicer begin file_top
! splicer end file_top
module wrapped_mod
    ! splicer begin module_use
    ! splicer end module_use
    implicit none

    ! splicer begin module_top
    ! splicer end module_top

    interface

        subroutine inner3_worker3() &
                bind(C, name="WWW_inner3_worker3")
            implicit none
        end subroutine inner3_worker3

        subroutine worker() &
                bind(C, name="WWW_worker")
            implicit none
        end subroutine worker

        ! splicer begin additional_interfaces
        ! splicer end additional_interfaces

        subroutine inner4_worker4() &
                bind(C, name="WWW_inner4_worker4")
            implicit none
        end subroutine inner4_worker4
    end interface

contains

    ! splicer begin additional_functions
    ! splicer end additional_functions

end module wrapped_mod
