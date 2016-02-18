#include <cstdarg>
#include <cstdio>
#include <cstring>

#include "main/infi_types.h"
#include "main/infi_error.h"

namespace INFI {
	
	static const char* message_none = "No Error";
	
	static bool get_errors = true;
	
	static infi_error_t* errbuffer = NULL;
	static uint32 alloc = 0;
	static uint32 inuse = 0;
	static uint32 start = 0;
	static uint32 current = 0;
	
	static const char** errstack = NULL;
	static uint32 stalloc = 0;
	static uint32 stinuse = 0;
	
	static void realloc_buffer() {
		alloc = ( alloc == 0 ) ? 8 : alloc << 1;
		
		infi_error_t* nbuffer = new infi_error_t[alloc];
		memcpy( nbuffer, errbuffer, sizeof(infi_error_t) * inuse );
		
		start = 0;
		current = inuse;
		
		delete[] errbuffer;
		errbuffer = nbuffer;
	}
	static void realloc_stack() {
		stalloc = ( stalloc == 0 ) ? 8 : stalloc << 1;
		
		const char** nstack = new const char*[stalloc];
		memcpy( nstack, errstack, sizeof(const char*) * stinuse );
		
		delete[] errstack;
		errstack = nstack;
	}
	
	void InfiPushFunction( const char* fname ) {
		if ( stinuse == stalloc )
			realloc_stack();
		errstack[stinuse] = fname;
		++ stinuse;
	}
	void InfiPopFunction() {
		if ( stinuse != 0 )
			-- stinuse;
	}
	
	uint32 InfiGetFunctionDepth() {
		return stinuse;
	}
	const char* InfiGetFunctionName( uint32 index ) {
		if ( index >= stinuse )
			return NULL;
		return errstack[index];
	}
	
	static void push_error( const infi_error_t& err ) {
		if ( inuse == alloc )
			realloc_buffer();
		
		errbuffer[current] = err;
		current = (current + 1) % alloc;
		++ inuse;
	}
	static void pop_error( infi_error_t& err ) {
		err = errbuffer[start];
		start = (start + 1) % alloc;
		-- inuse;
	}
	static char* write_error( INFI_error_msg id, const char* format, va_list args ) {
		char* buffer = new char[1000];
		vsprintf( buffer, format, args );
		
		infi_error_t err;
			err.type = id;
			err.msg = buffer;
		
		push_error( err );
		
		return buffer;
	}
	
	void InfiSendError( INFI_error_msg id, const char* msg, ... ) {
		if ( !get_errors )
			return;
		
		va_list args;
		va_start( args, msg );
		write_error( id, msg, args );
		va_end( args );
		
		throw id;
	}
	
	void InfiSuppressErrors() {
		get_errors = false;
	}
	void InfiRecordErrors() {
		get_errors = true;
	}
	
	void InfiFreeError( infi_error_t& inout ) {
		if ( inout.msg != message_none )
			delete[] inout.msg;
		
		inout.type = INFI_NO_ERROR;
		inout.msg = message_none;
	}
	
	void InfiClearErrors() {
		for ( inuse=0;start!=current;++start ) {
			if ( errbuffer[start].msg != message_none )
				delete[] errbuffer[start].msg;	
		}
	}
	
	static bool no_error( infi_error_t& out ) {
		out.type = INFI_NO_ERROR;
		out.msg = message_none;
		return false;
	}
	bool InfiGetError( infi_error_t& out ) {
		if ( inuse == 0 )
			return no_error( out );
		pop_error( out );
		return true;
	}
	bool InfiPeekError( infi_error_t& out ) {
		if ( inuse == 0 )
			return no_error( out );
		out = errbuffer[start];
		return true;
	}
	
	const char* InfiErrorString( INFI_error_msg err ) {
		switch( err ) {
			case INFI_NO_ERROR:
				return "No Error"; break;
			
			case INFI_WARNING:
				return "Warning"; break;
			case INFI_IGNORE:
				return "Operation Ignored"; break;
			case INFI_UNIMPLEMENTED:
				return "Unimplemented Operation"; break;
			
			case INFI_SYSTEM_ERROR:
				return "Local Library Error"; break;
			case INFI_LIBRARY_ERROR:
				return "External Library Error"; break;
			case INFI_GL_ERROR:
				return "Graphics Library Error"; break;
			
			case INFI_NULL_DEREF_ERROR:
				return "Null Pointer Dereference"; break;
			case INFI_OVERFLOW_ERROR:
				return "Overflow Error"; break;
			case INFI_UNDERFLOW_ERROR:
				return "Underflow Error"; break;
			case INFI_INDEX_ERROR:
				return "Index Out Of Range"; break;
			case INFI_TYPE_ERROR:
				return "Incompatible Types"; break;
			case INFI_INIT_ERROR:
				return "Initialization Failed"; break;	
			case INFI_BINDING_ERROR:
				return "Binding Failed"; break;	
				
			case INFI_FILE_NOT_FOUND:
				return "File Was Not Found"; break;
			case INFI_CANNOT_READ_FILE:
				return "File Is Corrupted"; break;
			case INFI_UNSUPPORTED_TYPE:
				return "File Type Is Not Supported"; break;
				
			case INFI_LOAD_UNRESOLVED:
				return "Load Interrupted"; break;
			case INFI_LOAD_SUCCESSFUL:
				return "Load Was Successful"; break;
			case INFI_LOAD_UNSUCCESSFUL:
				return "Load Was Unsuccessful"; break;
				
			case INFI_SAVE_UNRESOLVED:
				return "Save Interrupted"; break;
			case INFI_SAVE_SUCCESSFUL:
				return "Save Was Successful"; break;
			case INFI_SAVE_UNSUCCESSFUL:
				return "Save Was Unsuccessful"; break;
				
			default:
				return "Unknown Error";
		}	
	}
	
}