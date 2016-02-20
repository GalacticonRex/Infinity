#ifndef __INFI_MAIN_H__
#define __INFI_MAIN_H__

#include "main/infi_export.h"
#include "main/infi_parameters.h"
#include "main/infi_window.h"

namespace INFI {

typedef void (*INFI_EarlyFunc)();
typedef void (*INFI_InitFunc)(infi_parameters_t&);
typedef int32 (*INFI_QuitFunc)(void*);

typedef void (*INFI_ControlHook)( void*, const SDL_Event& );

// USE THESE FUNCTION TO BEGIN THE ENGINE
INFI_FUNCTION( int32, InfiMain, ( INFI_InitFunc ) );
INFI_FUNCTION( int32, InfiMain, ( INFI_InitFunc, INFI_QuitFunc ) );
INFI_FUNCTION( int32, InfiMain, ( INFI_EarlyFunc, INFI_InitFunc ) );
INFI_FUNCTION( int32, InfiMain, ( INFI_EarlyFunc, INFI_InitFunc, INFI_QuitFunc ) );

INFI_FUNCTION( uint32, InfiHookControl, ( INFI_ControlHook, void* = NULL ) );
INFI_FUNCTION( void, InfiUnHookControl, ( uint32 ) );

INFI_FUNCTION( infi_window_t*, InfiCurrentWindow, () );
INFI_FUNCTION( infi_window_t*, InfiRenderWindow, () );
INFI_FUNCTION( infi_window_t*, InfiActiveWindow, () );

// return the number of windows
INFI_FUNCTION( uint32, InfiWindowCount, () );

// returns the number of contexts that have been created
//	  over the lifetime of the program
// the minimum return value is 1, as a base context is
//	  included for pre-window rendering
INFI_FUNCTION( uint32, InfiContextCount, () );

INFI_FUNCTION( SDL_GLContext, InfiCurrentContext, () );

INFI_FUNCTION( void, InfiQuit, () );

}

#endif//__INFI_MAIN_H__