! wrapfwrapped_inner2.f
! This is generated code, do not edit
! Copyright (c) 2017-2019, Lawrence Livermore National Security, LLC and
! other Shroud Project Developers.
! See the top-level COPYRIGHT file for details.
!
! SPDX-License-Identifier: (BSD-3-Clause)
!
!>
!! \file wrapfwrapped_inner2.f
!! \brief Shroud generated wrapper for inner2 namespace
!<
! splicer begin namespace.inner2.file_top
! splicer end namespace.inner2.file_top
module wrapped_inner2_mod
    ! splicer begin namespace.inner2.module_use
    ! splicer end namespace.inner2.module_use
    implicit none

    ! splicer begin namespace.inner2.module_top
    ! splicer end namespace.inner2.module_top

    interface

        subroutine worker() &
                bind(C, name="WWW_inner2_worker")
            implicit none
        end subroutine worker

        ! splicer begin namespace.inner2.additional_interfaces
        ! splicer end namespace.inner2.additional_interfaces
    end interface

contains

    ! splicer begin namespace.inner2.additional_functions
    ! splicer end namespace.inner2.additional_functions

end module wrapped_inner2_mod
