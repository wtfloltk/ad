/*
Copyright (C) 2001-2007 StrmnNrmn

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

#ifndef UTILITY_ALIGNMENT_H_
#define UTILITY_ALIGNMENT_H_

#if defined(DAEDALUS_W32)

	#if defined( _MSC_VER )

		#define ALIGNED_TYPE(type, type_name, alignval) __declspec(align(alignval)) type type_name
		#define ALIGNED_GLOBAL(type, var, alignval) __declspec(align(alignval)) type var
		#define ALIGNED_MEMBER(type, var, alignval) __declspec(align(alignval)) type var
		#define ALIGNED_EXTERN(type, var, alignval) extern  __declspec(align(alignval)) type var

	#elif defined( __GNUC__ )

		// GCC has __attribute__((aligned)) but it complains that the maximum alignment is 16
		#define ALIGNED_TYPE(type, type_name, alignval) type type_name
		#define ALIGNED_GLOBAL(type, var, alignval) __asm__(".balign " #alignval ) type var
		#define ALIGNED_MEMBER(type, var, alignval) __attribute__((aligned(alignval))) type var
		#define ALIGNED_EXTERN(type, var, alignval) extern type var

	#else

		#error "Unhandled compiler type"

	#endif

#elif defined( DAEDALUS_PSP ) || defined( DAEDALUS_PS3 ) || defined( DAEDALUS_VITA )

#define ALIGNED_TYPE(type, type_name, alignval) type __attribute__((aligned(alignval))) type_name
#define ALIGNED_GLOBAL(type, var, alignval) __attribute__((aligned(alignval))) type var
#define ALIGNED_MEMBER(type, var, alignval) __attribute__((aligned(alignval))) type var
#define ALIGNED_EXTERN(type, var, alignval) extern __attribute__((aligned(alignval))) type var

#elif defined( DAEDALUS_OSX ) || defined( DAEDALUS_LINUX ) || defined( DAEDALUS_CTR )

#define ALIGNED_TYPE(type, type_name, alignval) type __attribute__((aligned(alignval))) type_name
#define ALIGNED_GLOBAL(type, var, alignval) __attribute__((aligned(alignval))) type var
#define ALIGNED_MEMBER(type, var, alignval) __attribute__((aligned(alignval))) type var
#define ALIGNED_EXTERN(type, var, alignval) extern __attribute__((aligned(alignval))) type var

#else

	#warning "Unhandled Daedalus build type"

#endif // defined(DAEDALUS_W32)


#if !defined( ALIGNED_TYPE ) || !defined( ALIGNED_GLOBAL ) || !defined( ALIGNED_MEMBER )

#define ALIGNED_TYPE(type, type_name, alignval) type type_name
#define ALIGNED_GLOBAL(type, var, alignval) type var
#define ALIGNED_MEMBER(type, var, alignval) type var

#warning "Aligned types not supported"

#endif

#ifdef DAEDALUS_PSP

#define DATA_ALIGN	16
#define CACHE_ALIGN	64
#define PAGE_ALIGN	64

#else

// Pentium 4 has 64-byte cachelines
#define DATA_ALIGN	16
#define CACHE_ALIGN	64
#define PAGE_ALIGN	4096

#endif

#endif // UTILITY_ALIGNMENT_H_
