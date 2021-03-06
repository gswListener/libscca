/*
 * Memory allocation functions for testing
 *
 * Copyright (C) 2011-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _SCCA_TEST_MEMORY_H )
#define _SCCA_TEST_MEMORY_H

#include <common.h>

#if defined( __cplusplus )
extern "C" {
#endif

#if defined( HAVE_GNU_DL_DLSYM ) && defined( __GNUC__ ) && !defined( __clang__ )

#define HAVE_SCCA_TEST_MEMORY		1

extern int scca_test_malloc_attempts_before_fail;

extern int scca_test_memcpy_attempts_before_fail;

extern int scca_test_memset_attempts_before_fail;

extern int scca_test_realloc_attempts_before_fail;

#endif /* defined( HAVE_GNU_DL_DLSYM ) && defined( __GNUC__ ) && !defined( __clang__ ) */

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _SCCA_TEST_MEMORY_H ) */

