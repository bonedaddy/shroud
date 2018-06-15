! Copyright (c) 2017-2018, Lawrence Livermore National Security, LLC. 
! Produced at the Lawrence Livermore National Laboratory 
!
! LLNL-CODE-738041.
! All rights reserved. 
!
! This file is part of Shroud.  For details, see
! https://github.com/LLNL/shroud. Please also read shroud/LICENSE.
!
! Redistribution and use in source and binary forms, with or without
! modification, are permitted provided that the following conditions are
! met:
!
! * Redistributions of source code must retain the above copyright
!   notice, this list of conditions and the disclaimer below.
! 
! * Redistributions in binary form must reproduce the above copyright
!   notice, this list of conditions and the disclaimer (as noted below)
!   in the documentation and/or other materials provided with the
!   distribution.
!
! * Neither the name of the LLNS/LLNL nor the names of its contributors
!   may be used to endorse or promote products derived from this
!   software without specific prior written permission.
!
! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
! LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
! A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE
! LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR
! CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
! EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
! PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
! LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
! NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
! SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
!
! #######################################################################


! splicer begin class.ExClass1.module_top
top of module splicer  1
! splicer end class.ExClass1.module_top

! splicer begin class.ExClass1.component_part
  component part 1a
  component part 1b
! splicer end   class.ExClass1.component_part

! splicer begin class.ExClass1.type_bound_procedure_part
  type bound procedure part 1
! splicer end   class.ExClass1.type_bound_procedure_part

! splicer begin class.ExClass1.method.splicer_special
blah blah blah
! splicer end class.ExClass1.method.splicer_special

! splicer begin class.ExClass1.extra_methods
  insert extra methods here
! splicer end   class.ExClass1.extra_methods


! splicer begin class.ExClass2.module_top
top of module splicer  2
! splicer end class.ExClass2.module_top




# test a full path
! splicer begin  class.ExClass1.method.extra_method2
  ! extra method 2
! splicer end    class.ExClass1.method.extra_method2