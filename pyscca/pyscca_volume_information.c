/*
 * Python object definition of the libscca volume information
 *
 * Copyright (C) 2011-2015, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyscca_datetime.h"
#include "pyscca_error.h"
#include "pyscca_file.h"
#include "pyscca_integer.h"
#include "pyscca_libcerror.h"
#include "pyscca_libcstring.h"
#include "pyscca_libscca.h"
#include "pyscca_python.h"
#include "pyscca_unused.h"
#include "pyscca_volume_information.h"

PyMethodDef pyscca_volume_information_object_methods[] = {

	/* Functions to access the volume information values */

	{ "get_creation_time",
	  (PyCFunction) pyscca_volume_information_get_creation_time,
	  METH_NOARGS,
	  "get_creation_time() -> Datetime\n"
	  "\n"
	  "Returns the creation date and time." },

	{ "get_creation_time_as_integer",
	  (PyCFunction) pyscca_volume_information_get_creation_time_as_integer,
	  METH_NOARGS,
	  "get_creation_time_as_integer() -> Integer\n"
	  "\n"
	  "Returns the creation date and time as a 64-bit integer containing a FILETIME value." },

	{ "get_serial_number",
	  (PyCFunction) pyscca_volume_information_get_serial_number,
	  METH_NOARGS,
	  "get_serial_number() -> Integer\n"
	  "\n"
	  "Retrieves the serial number." },

	{ "get_device_path",
	  (PyCFunction) pyscca_volume_information_get_device_path,
	  METH_NOARGS,
	  "get_device_path() -> Unicode string or None\n"
	  "\n"
	  "Retrieves the device path." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyscca_volume_information_object_get_set_definitions[] = {

	{ "creation_time",
	  (getter) pyscca_volume_information_get_creation_time,
	  (setter) 0,
	  "The creation date and time.",
	  NULL },

	{ "serial_number",
	  (getter) pyscca_volume_information_get_serial_number,
	  (setter) 0,
	  "The serial number.",
	  NULL },

	{ "device_path",
	  (getter) pyscca_volume_information_get_device_path,
	  (setter) 0,
	  "The device path.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyscca_volume_information_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyscca.volume_information",
	/* tp_basicsize */
	sizeof( pyscca_volume_information_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyscca_volume_information_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyscca volume information object (wraps libscca_volume_information_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyscca_volume_information_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyscca_volume_information_object_get_set_definitions,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyscca_volume_information_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new volume information object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyscca_volume_information_new(
           libscca_volume_information_t *volume_information,
           pyscca_file_t *file_object )
{
	pyscca_volume_information_t *pyscca_volume_information = NULL;
	static char *function                                  = "pyscca_volume_information_new";

	if( volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information.",
		 function );

		return( NULL );
	}
	pyscca_volume_information = PyObject_New(
	                             struct pyscca_volume_information,
	                             &pyscca_volume_information_type_object );

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize volume information.",
		 function );

		goto on_error;
	}
	if( pyscca_volume_information_init(
	     pyscca_volume_information ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize volume information.",
		 function );

		goto on_error;
	}
	pyscca_volume_information->volume_information = volume_information;
	pyscca_volume_information->file_object        = file_object;

	Py_IncRef(
	 (PyObject *) pyscca_volume_information->file_object );

	return( (PyObject *) pyscca_volume_information );

on_error:
	if( pyscca_volume_information != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyscca_volume_information );
	}
	return( NULL );
}

/* Intializes a volume information object
 * Returns 0 if successful or -1 on error
 */
int pyscca_volume_information_init(
     pyscca_volume_information_t *pyscca_volume_information )
{
	static char *function = "pyscca_volume_information_init";

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information.",
		 function );

		return( -1 );
	}
	/* Make sure libscca volume information is set to NULL
	 */
	pyscca_volume_information->volume_information = NULL;

	return( 0 );
}

/* Frees a volume information object
 */
void pyscca_volume_information_free(
      pyscca_volume_information_t *pyscca_volume_information )
{
	libcerror_error_t *error    = NULL;
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyscca_volume_information_free";

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information.",
		 function );

		return;
	}
	if( pyscca_volume_information->volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information - missing libscca volume information.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyscca_volume_information );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( libscca_volume_information_free(
	     &( pyscca_volume_information->volume_information ),
	     &error ) != 1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to free libscca volume information.",
		 function );

		libcerror_error_free(
		 &error );
	}
	if( pyscca_volume_information->file_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyscca_volume_information->file_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyscca_volume_information );
}

/* Retrieves the creation date and time
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyscca_volume_information_get_creation_time(
           pyscca_volume_information_t *pyscca_volume_information,
           PyObject *arguments PYSCCA_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyscca_volume_information_get_creation_time";
	uint64_t filetime          = 0;
	int result                 = 0;

	PYSCCA_UNREFERENCED_PARAMETER( arguments )

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume information.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libscca_volume_information_get_creation_time(
	          pyscca_volume_information->volume_information,
	          &filetime,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve creation time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyscca_datetime_new_from_filetime(
	                    filetime );

	return( date_time_object );
}

/* Retrieves the creation date and time as an integer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyscca_volume_information_get_creation_time_as_integer(
           pyscca_volume_information_t *pyscca_volume_information,
           PyObject *arguments PYSCCA_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyscca_volume_information_get_creation_time_as_integer";
	uint64_t filetime        = 0;
	int result               = 0;

	PYSCCA_UNREFERENCED_PARAMETER( arguments )

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume information.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libscca_volume_information_get_creation_time(
	          pyscca_volume_information->volume_information,
	          &filetime,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve creation time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyscca_integer_unsigned_new_from_64bit(
	                  (uint64_t) filetime );

	return( integer_object );
}

/* Retrieves the serial number
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyscca_volume_information_get_serial_number(
           pyscca_volume_information_t *pyscca_volume_information,
           PyObject *arguments PYSCCA_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyscca_volume_information_get_serial_number";
	uint32_t serial_number   = 0;
	int result               = 0;

	PYSCCA_UNREFERENCED_PARAMETER( arguments )

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libscca_volume_information_get_serial_number(
	          pyscca_volume_information->volume_information,
	          &serial_number,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve serial number.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromUnsignedLong(
	         (unsigned long) serial_number ) );
}

/* Retrieves the device path
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyscca_volume_information_get_device_path(
           pyscca_volume_information_t *pyscca_volume_information,
           PyObject *arguments PYSCCA_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *device_path     = NULL;
	static char *function    = "pyscca_volume_information_get_device_path";
	size_t device_path_size  = 0;
	int result               = 0;

	PYSCCA_UNREFERENCED_PARAMETER( arguments )

	if( pyscca_volume_information == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid volume information.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libscca_volume_information_get_utf8_device_path_size(
	          pyscca_volume_information->volume_information,
	          &device_path_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve device path size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( device_path_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	device_path = (uint8_t *) PyMem_Malloc(
	                           sizeof( uint8_t ) * device_path_size );

	if( device_path == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create device path.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libscca_volume_information_get_utf8_device_path(
		  pyscca_volume_information->volume_information,
		  device_path,
		  device_path_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyscca_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve device path.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) device_path,
			 (Py_ssize_t) device_path_size - 1,
			 errors );

	PyMem_Free(
	 device_path );

	return( string_object );

on_error:
	if( device_path != NULL )
	{
		PyMem_Free(
		 device_path );
	}
	return( NULL );
}
