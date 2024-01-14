/*
Copyright (C) 2008 StrmnNrmn

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#pragma once

#ifndef SYSPSP_INCLUDE_PLATFORM_H_
#define SYSPSP_INCLUDE_PLATFORM_H_


enum PspModel
{
    PSP_MODEL_STANDARD = 0,
    PSP_MODEL_SLIM_AND_LITE = 1,
    PSP_MODEL_BRITE = 8,
    PSP_MODEL_GO = 4,
    PSP_MODEL_STREET = 10
};
//
//	Make sure this platform is defined correctly
//
#ifndef DAEDALUS_PSP
#define DAEDALUS_PSP
#endif

#define DAEDALUS_ENABLE_DYNAREC
#define DAEDALUS_PSP_USE_ME
#define DAEDALUS_ENABLE_OS_HOOKS

#define DAEDALUS_ENDIAN_MODE DAEDALUS_ENDIAN_LITTLE

// We have a VFPU :)
#define DAEDALUS_PSP_USE_VFPU

#define DAEDALUS_EXPECT_LIKELY(c) __builtin_expect((c),1)
#define DAEDALUS_EXPECT_UNLIKELY(c) __builtin_expect((c),0)

#define DAEDALUS_ATTRIBUTE_NOINLINE __attribute__((noinline))

#define DAEDALUS_HALT			__asm__ __volatile__ ( "break" )

#define DAEDALUS_DYNAREC_HALT	SW(PspReg_R0, PspReg_R0, 0)

#define MAKE_UNCACHED_PTR(x)	(reinterpret_cast< void * >( reinterpret_cast<u32>( (x) ) | 0x40000000 ))

#define DAEDALUS_ATTRIBUTE_PURE   __attribute__((pure))
#define DAEDALUS_ATTRIBUTE_CONST   __attribute__((const))

#define __has_feature(x) 0

#endif // SYSPSP_INCLUDE_PLATFORM_H_
