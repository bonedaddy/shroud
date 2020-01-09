! This file was automatically generated by SWIG (http://www.swig.org).
! Version 4.0.0
!
! Do not make changes to this file unless you know what you are doing--modify
! the SWIG interface file instead.
module cstruct
 use, intrinsic :: ISO_C_BINDING
 implicit none
 private

 ! DECLARATION CONSTRUCTS

 integer, parameter :: swig_cmem_own_bit = 0
 integer, parameter :: swig_cmem_rvalue_bit = 1
 integer, parameter :: swig_cmem_const_bit = 2
 type, bind(C) :: SwigClassWrapper
  type(C_PTR), public :: cptr = C_NULL_PTR
  integer(C_INT), public :: cmemflags = 0
 end type
 ! struct struct Cstruct1
 type, public :: Cstruct1
  type(SwigClassWrapper), public :: swigdata
 contains
  procedure :: set_ifield => swigf_Cstruct1_ifield_set
  procedure :: get_ifield => swigf_Cstruct1_ifield_get
  procedure :: set_dfield => swigf_Cstruct1_dfield_set
  procedure :: get_dfield => swigf_Cstruct1_dfield_get
  procedure :: release => swigf_release_Cstruct1
  procedure, private :: swigf_Cstruct1_op_assign__
  generic :: assignment(=) => swigf_Cstruct1_op_assign__
 end type Cstruct1
 interface Cstruct1
  module procedure swigf_create_Cstruct1
 end interface
 public :: acceptStructIn

! WRAPPER DECLARATIONS
interface
subroutine swigc_Cstruct1_ifield_set(farg1, farg2) &
bind(C, name="_wrap_Cstruct1_ifield_set")
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: farg1
integer(C_INT), intent(in) :: farg2
end subroutine

function swigc_Cstruct1_ifield_get(farg1) &
bind(C, name="_wrap_Cstruct1_ifield_get") &
result(fresult)
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: farg1
integer(C_INT) :: fresult
end function

subroutine swigc_Cstruct1_dfield_set(farg1, farg2) &
bind(C, name="_wrap_Cstruct1_dfield_set")
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: farg1
real(C_DOUBLE), intent(in) :: farg2
end subroutine

function swigc_Cstruct1_dfield_get(farg1) &
bind(C, name="_wrap_Cstruct1_dfield_get") &
result(fresult)
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: farg1
real(C_DOUBLE) :: fresult
end function

function swigc_new_Cstruct1() &
bind(C, name="_wrap_new_Cstruct1") &
result(fresult)
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: fresult
end function

subroutine swigc_delete_Cstruct1(farg1) &
bind(C, name="_wrap_delete_Cstruct1")
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper), intent(inout) :: farg1
end subroutine

subroutine swigc_Cstruct1_op_assign__(farg1, farg2) &
bind(C, name="_wrap_Cstruct1_op_assign__")
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper), intent(inout) :: farg1
type(SwigClassWrapper) :: farg2
end subroutine

function swigc_acceptStructIn(farg1) &
bind(C, name="_wrap_acceptStructIn") &
result(fresult)
use, intrinsic :: ISO_C_BINDING
import :: swigclasswrapper
type(SwigClassWrapper) :: farg1
real(C_DOUBLE) :: fresult
end function

end interface


contains
 ! MODULE SUBPROGRAMS
subroutine swigf_Cstruct1_ifield_set(self, ifield)
use, intrinsic :: ISO_C_BINDING
class(Cstruct1), intent(in) :: self
integer(C_INT), intent(in) :: ifield
type(SwigClassWrapper) :: farg1 
integer(C_INT) :: farg2 

farg1 = self%swigdata
farg2 = ifield
call swigc_Cstruct1_ifield_set(farg1, farg2)
end subroutine

function swigf_Cstruct1_ifield_get(self) &
result(swig_result)
use, intrinsic :: ISO_C_BINDING
integer(C_INT) :: swig_result
class(Cstruct1), intent(in) :: self
integer(C_INT) :: fresult 
type(SwigClassWrapper) :: farg1 

farg1 = self%swigdata
fresult = swigc_Cstruct1_ifield_get(farg1)
swig_result = fresult
end function

subroutine swigf_Cstruct1_dfield_set(self, dfield)
use, intrinsic :: ISO_C_BINDING
class(Cstruct1), intent(in) :: self
real(C_DOUBLE), intent(in) :: dfield
type(SwigClassWrapper) :: farg1 
real(C_DOUBLE) :: farg2 

farg1 = self%swigdata
farg2 = dfield
call swigc_Cstruct1_dfield_set(farg1, farg2)
end subroutine

function swigf_Cstruct1_dfield_get(self) &
result(swig_result)
use, intrinsic :: ISO_C_BINDING
real(C_DOUBLE) :: swig_result
class(Cstruct1), intent(in) :: self
real(C_DOUBLE) :: fresult 
type(SwigClassWrapper) :: farg1 

farg1 = self%swigdata
fresult = swigc_Cstruct1_dfield_get(farg1)
swig_result = fresult
end function

function swigf_create_Cstruct1() &
result(self)
use, intrinsic :: ISO_C_BINDING
type(Cstruct1) :: self
type(SwigClassWrapper) :: fresult 

fresult = swigc_new_Cstruct1()
self%swigdata = fresult
end function

subroutine swigf_release_Cstruct1(self)
use, intrinsic :: ISO_C_BINDING
class(Cstruct1), intent(inout) :: self
type(SwigClassWrapper) :: farg1 

farg1 = self%swigdata
if (btest(farg1%cmemflags, swig_cmem_own_bit)) then
call swigc_delete_Cstruct1(farg1)
endif
farg1%cptr = C_NULL_PTR
farg1%cmemflags = 0
self%swigdata = farg1
end subroutine

subroutine swigf_Cstruct1_op_assign__(self, other)
use, intrinsic :: ISO_C_BINDING
class(Cstruct1), intent(inout) :: self
type(Cstruct1), intent(in) :: other
type(SwigClassWrapper) :: farg1 
type(SwigClassWrapper) :: farg2 

farg1 = self%swigdata
farg2 = other%swigdata
call swigc_Cstruct1_op_assign__(farg1, farg2)
self%swigdata = farg1
end subroutine

function acceptStructIn(arg) &
result(swig_result)
use, intrinsic :: ISO_C_BINDING
real(C_DOUBLE) :: swig_result
type(Cstruct1), intent(in) :: arg
real(C_DOUBLE) :: fresult 
type(SwigClassWrapper) :: farg1 

farg1 = arg%swigdata
fresult = swigc_acceptStructIn(farg1)
swig_result = fresult
end function


end module
