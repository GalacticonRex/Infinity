#ifndef __INFI_ERROR_LOG_H__
#define __INFI_ERROR_LOG_H__

#include "main/infi_export.h"
#include "main/infi_types.h"

namespace INFI {
	
	typedef uint32 INFI_error_msg;
	const INFI_error_msg
		INFI_NO_ERROR 			= 001, // no error
		
		INFI_WARNING			= 101, // something happened that might have unintended consequences
		INFI_IGNORE				= 102, // something failed to occur because of certain state settings
		INFI_UNIMPLEMENTED		= 103, // a componenet of the engine is not yet ready
		
		INFI_SYSTEM_ERROR		= 201, // a problem occurred with the local OS API
		INFI_LIBRARY_ERROR		= 202, // a problem happened with one of the external libraries
		INFI_GL_ERROR 			= 203, // a problem happened with some component of the GL
		
		INFI_NULL_DEREF_ERROR	= 301, // attempted to dereference a null pointer
		INFI_OVERFLOW_ERROR		= 302, // stack overflow
		INFI_UNDERFLOW_ERROR	= 303, // stack underflow
		INFI_INDEX_ERROR		= 304, // an index went out of bounds
		INFI_TYPE_ERROR			= 305, // a parameter was passed that did not match previously specified types
		INFI_INIT_ERROR			= 306, // an error occured upon initialization of some object
		INFI_BINDING_ERROR		= 307, // an error occured upon binding of some object
		
		INFI_FILE_NOT_FOUND 	= 401, // a filename could not be found
		INFI_CANNOT_READ_FILE 	= 402, // a file was corrupted
		INFI_UNSUPPORTED_TYPE 	= 403, // the file type is not supported
		
		INFI_LOAD_SUCCESSFUL 	= 410, // import occurred without incident
		INFI_LOAD_UNRESOLVED 	= 411, // the import was interrupted
		INFI_LOAD_UNSUCCESSFUL 	= 412, // error occured during file import
		
		INFI_SAVE_SUCCESSFUL 	= 420, // export occurred without incident
		INFI_SAVE_UNRESOLVED 	= 421, // the export was interrupted
		INFI_SAVE_UNSUCCESSFUL 	= 422;  // error occured during file export
		
	INFI_FUNCTION( void, InfiPushFunction, ( const char* ) ); 
	INFI_FUNCTION( void, InfiPopFunction, () );
	
	INFI_FUNCTION( uint32, InfiGetFunctionDepth, () );
	INFI_FUNCTION( const char*, InfiGetFunctionName, ( uint32 ) );
	
	INFI_FUNCTION( void, InfiSendError, ( INFI_error_msg, const char*, ... ) );
	
	INFI_FUNCTION_( void, InfiSuppressErrors );
	INFI_FUNCTION_( void, InfiRecordErrors );
	
	struct infi_error_t {
		INFI_error_msg type;
		const char* msg;
	};
	
	INFI_FUNCTION( void, InfiFreeError, ( infi_error_t& ) );
	
	INFI_FUNCTION_( void, InfiClearErrors );
	INFI_FUNCTION( bool, InfiGetError, ( infi_error_t& ) );
	INFI_FUNCTION( bool, InfiPeekError, ( infi_error_t& ) );
	
	INFI_FUNCTION( const char*, InfiErrorString, ( INFI_error_msg ) );
}

#endif//__INFI_ERROR_LOG_H__