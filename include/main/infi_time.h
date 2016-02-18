#ifndef __INFI_TIME_H__
#define __INFI_TIME_H__

#include "main/infi_types.h"
#include "main/infi_export.h"

#ifdef __WIN32__
	#include <windows.h>
	#define NATIVE_SLEEPER HANDLE ev;
#else
	#define NATIVE_SLEEPER volatile bool ev;
#endif

namespace INFI {
	
	// initialize a high resolution counter
	INFI_FUNCTION( uint64, InfiLInitTime, () );
	
	// time in milliseconds
	INFI_FUNCTION( uint64, InfiTickTime, () );
	
	// time in seconds
	INFI_FUNCTION( float64, InfiGetTime, () );
	INFI_FUNCTION( float64, InfiGetProgramTime, () );
	
	INFI_FUNCTION( void, InfiSetTimer, ( uint32 = 0 ) );
	INFI_FUNCTION( float64, InfiReadTimer, ( uint32 = 0 ) );
	
	
	struct INFI_EXPORT infi_sleeper_t {
		
		// wait indefinitely
		void wait();
		
		// wait for a number of seconds
		// true if object signal, false if timeout
		bool wait( float64 );
		
		// stop the object if it is waiting
		void signal();
		
		infi_sleeper_t();
		~infi_sleeper_t();
		
		private:
			NATIVE_SLEEPER
			
	};
	
}

#endif//__INFI_TIME_H__
