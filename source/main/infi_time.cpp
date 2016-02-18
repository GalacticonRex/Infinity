#include "main/infi_error.h"
#include "main/infi_time.h"

#include "core/infi_map.h"

#include "sdl/sdl.h"

namespace INFI {

static float64 frequency = 1000.0;

uint64 InfiTickTime() { return (uint64) SDL_GetTicks(); }

typedef core::map_t<uint32,float64>::iterator TimerLink;

static float64 current_time = 0;
static core::map_t<uint32,float64> timers;

void InfiSetTimer( uint32 id ) {
	if ( id == 0 ) {
		current_time = InfiGetTime();
	} else {
		TimerLink iter = timers.find( id );
		if ( iter == timers.end() ) {
			timers.insert( std::pair<uint32,float64>( id, InfiGetTime() ) );
		} else {
			iter->second = InfiGetTime();
		}
	}
}
float64 InfiReadTimer( uint32 id ) {
	InfiPushFunction( "InfiReadTimer" );
	float64 t = InfiGetTime();
	if ( id == 0 ) {
		float64 temp = t - current_time;
		InfiPopFunction();
		return temp;
	} else {
		TimerLink iter = timers.find( id );
		if ( iter == timers.end() ) {
			InfiSendError( INFI_INDEX_ERROR, "timer %d does not exist", id );
			return 0;
		} else {
			float64 temp = t - iter->second;
			InfiPopFunction();
			return temp;
		}
	}
}

#ifdef __WIN32__
	uint64 InfiLInitTime() { 
		LARGE_INTEGER li;
		QueryPerformanceFrequency( &li );
		frequency = (float64) li.QuadPart;
		return li.QuadPart;
	}
	float64 InfiGetTime() {
		LARGE_INTEGER li;
		QueryPerformanceCounter( &li );
		return (float64)li.QuadPart / frequency;
	}

	infi_sleeper_t::infi_sleeper_t() {
		ev = CreateEvent( NULL, TRUE, FALSE, "SleeperEvent" );
		ResetEvent( ev );
	}
	infi_sleeper_t::~infi_sleeper_t() { CloseHandle( ev ); }
	
	void infi_sleeper_t::wait() {
		(void) WaitForSingleObject( ev, INFINITE );
		ResetEvent( ev );
	}
	
	bool infi_sleeper_t::wait( float64 s ) {
		uint32 ms = s * 1000.0;
		uint32 tmp = WaitForSingleObject( ev, ms );
		ResetEvent( ev );
		return ( tmp == WAIT_OBJECT_0 );
	}
	
	void infi_sleeper_t::signal() {
		SetEvent( ev );
	}
	
#else
	uint64 InfiLInitTime() { 
		frequency = 1000.0;
		return 1000;
	}
	float64 InfiGetTime() { 
		return (float64)SDL_GetTicks() / frequency;
	}

	infi_sleeper_t::infi_sleeper_t() : ev(false) {  }
	infi_sleeper_t::~infi_sleeper_t() { }
	
	void infi_sleeper_t::wait() {
		ev = false;
		while ( !ev );
	}
	
	bool infi_sleeper_t::wait( float64 s ) {
		float64 ms = s / frequency;
		float64 t = InfiGetTime();
		ev = false;
		while ( InfiGetTime() < ms && !ev );
		return ev;
	}
	
	void infi_sleeper_t::signal() { ev = true; }

#endif // __WIN32__


}
