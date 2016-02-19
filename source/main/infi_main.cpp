#include "main/infi_gl.h"

#include "main/infi_error.h"
#include "main/infi_main.h"
#include "main/infi_displays.h"
#include "main/infi_time.h"

#include "core/infi_array.h"
#include "core/infi_queue.h"
#include "core/infi_heap.h"
#include "core/infi_map.h"
#include "core/infi_reserved_array.h"

#include "render/infi_gl_extensions.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_control.h"
#include "render/infi_texture.h"
#include "render/infi_format.h"
#include "render/infi_render.h"
#include "render/infi_standard_objects.h"

#include "text/infi_text.h"

#include <atomic>

namespace INFI {

struct infi_control_hook {
	INFI_ControlHook func;
	void* data;
	
	infi_control_hook() : func( NULL ), data( NULL ) { }
	infi_control_hook( INFI_ControlHook input, void* ptr )
		: func( input ), data( ptr ) { ; }
};
struct infi_window_queue_object {
	infi_window_t* win;
	
	uint32 flags;
	uint32 x, y;
	
	std::atomic<uint32> ready;
};

static bool prioritize_window( infi_window_t* const& a, infi_window_t* const& b ) {
	return ( a->frametime < b->frametime );
}

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------

// global state variables
struct {
	// working threads
	SDL_threadID thread_control;
	SDL_threadID thread_render;
	
	// is the cursor visible on all windows
	bool cursor_shown 		= true;
	
	// time the program started
	float64 init_time		= 0.0;
	
	// control flow flags
	bool control_stop		= false;
	bool control_running 	= false;
	
	// user defined events to occur before and after the main loop
	INFI_EarlyFunc 	early 	= NULL;
	INFI_InitFunc 	init 	= NULL;
	INFI_QuitFunc 	quit 	= NULL;
	
	// parameters passed to the init function
	infi_parameters_t params;
	infi_sleeper_t sync_init;
	infi_sleeper_t wait;
	
	// hooks that allow the render thread to communicate
	// with the control thread
	core::reserved_array_t<infi_control_hook> CONTROL_HOOKS;
	
} GLOBAL;

// structure that holds that data on the base GL state
struct {
	bool 				GLinitialized = false;
	bool 				GLenabled = false;
	SDL_Window* 		window = NULL;
	SDL_GLContext 		context = 0;
	
	uint32 window_count = 0;
	uint32 context_count = 0;
	
	// this is the window that is currently being run
	infi_window_t* CURRENT = NULL;

	// this is the window whose context is currently active
	infi_window_t* RENDER = NULL;

	// this is the window that has input focus
	infi_window_t* ACTIVE = NULL;
	
	SDL_mutex* create = NULL;
	SDL_mutex* destroy = NULL;

	// this queue is for windows that need to be initialized
	core::queue_t<infi_window_queue_object*> needs_window;
	core::queue_t<infi_window_queue_object*> needs_context;
	
	// this queue is for windows that need to be destroyed
	core::queue_t<infi_window_t*> destroy_control;
	
	// this priority queue determines which window needs
	// to be updated next
	core::heap_t<infi_window_t*,
				 prioritize_window> displays;
	
	core::map_t<uint32,infi_window_t*> winids;
	
	render::infi_object_dump_t objdump;
	
} WINDOW;

// registered SDL events
const uint32 INFI_EVENT_REQ = 4;
uint32 INFI_SIGNAL_START = 0;
uint32 INFI_SIGNAL_CREATE = 0;
uint32 INFI_SIGNAL_DESTROY = 0;
uint32 INFI_SIGNAL_TERMINATE = 0;

struct {
	SDL_Event start;
	SDL_Event create;
	SDL_Event destroy;
	SDL_Event terminate;
} SIGNAL;

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------

// reads errors from error queue
// prints these errors in a readable format
static void infi_display_errors( const char* );

// set all global variables to their initial values
static void infi_initialize_states();

// get the initial input states
static void infi_fetch_initial_inputs();

// create SDL objects for engine use
static void infi_register_sdl_events();

// create and destroy control objects
static void infi_initialize_control();
static void infi_quit_control();

// create and destroy render objects
static void infi_initialize_render();
static int32 infi_quit_render();

// user defined entry points
static void infi_run_early();
static void infi_run_init();
static int32 infi_run_quit();

// main methods
static void infi_control_thread();
static int32 infi_render_thread( void* );

// control window operations
static void infi_win_swap_inputs( infi_window_t* );
static void infi_win_pipeline( infi_window_t* );
static void infi_win_render( infi_window_t* );

// create the window components
static void infi_gen_window_control();
static void infi_gen_window_render();

// destroy the window components
static void infi_del_window_control();
static void infi_del_window_render( infi_window_t* );

// set OpenGL flags
static void infi_enable_gl();

// handle events under SDL_WINDOWEVENT
static void infi_handle_window_ev( const SDL_Event&, float64 );
static void infi_handle_key_down_ev( const SDL_Event&, float64 );
static void infi_handle_key_up_ev( const SDL_Event&, float64 );
static void infi_handle_mouse_move_ev( const SDL_Event&, float64 );
static void infi_handle_mouse_down_ev( const SDL_Event&, float64 );
static void infi_handle_mouse_up_ev( const SDL_Event&, float64 );
static void infi_handle_mouse_wheel_ev( const SDL_Event&, float64 );

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------

infi_window_t* InfiCurrentWindow() {
	return WINDOW.CURRENT;
}
infi_window_t* InfiRenderWindow() {
	return WINDOW.RENDER;
}
infi_window_t* InfiActiveWindow() {
	return WINDOW.ACTIVE;
}

uint32 InfiHookControl( INFI_ControlHook hk, void* ptr ) {
	return GLOBAL.CONTROL_HOOKS.add( infi_control_hook( hk, ptr ) );
}
void InfiUnHookControl( uint32 hnd ) {
	GLOBAL.CONTROL_HOOKS.remove( hnd );
}

// return the number of windows
uint32 InfiWindowCount() {
	return WINDOW.window_count;
}

uint32 InfiContextCount() {
	return WINDOW.context_count;
}


int32 InfiMain( INFI_InitFunc ifunc ) {
	return InfiMain( NULL, ifunc, NULL );
}
int32 InfiMain( INFI_InitFunc ifunc, INFI_QuitFunc qfunc ) {
	return InfiMain( NULL, ifunc, qfunc );
}
int32 InfiMain( INFI_EarlyFunc efunc, INFI_InitFunc ifunc ) {
	return InfiMain( efunc, ifunc, NULL );
}
int32 InfiMain( INFI_EarlyFunc efunc, INFI_InitFunc ifunc, INFI_QuitFunc qfunc ) {
	InfiPushFunction( "InfiMain" );
	infi_initialize_states();
	
	GLOBAL.early = efunc;
	GLOBAL.init = ifunc;
	GLOBAL.quit = qfunc;
	
	try {
		
		InfiLInitTime();
		GLOBAL.init_time = InfiGetTime();
		
		infi_run_early();
		
		infi_initialize_control();
		
		SDL_CreateThread( infi_render_thread, "winhandle", NULL );
		infi_control_thread();
		
		infi_quit_control();
		
	} catch( INFI_error_msg i ) {
		
		infi_display_errors( "Main" );
		
	}
	
	InfiPopFunction();
	return 0;
}


infi_window_t* InfiCreateWindow( const infi_window_spec_t& spec ) {
	InfiPushFunction( "InfiCreateWindow" );
	
	infi_window_t* nwin = new infi_window_t;
	
	infi_window_queue_object* nobj = new infi_window_queue_object();
	nobj->win = nwin;
	
	nobj->flags = SDL_WINDOW_OPENGL;
	if ( spec.resizable )
		nobj->flags |= SDL_WINDOW_RESIZABLE;
	if ( spec.hidden )
		nobj->flags |= SDL_WINDOW_HIDDEN;
	if ( spec.borderless )
		nobj->flags |= SDL_WINDOW_BORDERLESS;
	
	nwin->name = spec.name;
	nwin->counter = 0;
	if ( spec.fullscreen ) {
		nobj->flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		nwin->dimensions.x = InfiGetDisplay(0).width;
		nwin->dimensions.x = InfiGetDisplay(0).height;
	} else
		nwin->dimensions = spec.dimensions;
	
	nwin->anchor = spec.anchor;
	nwin->frametime = InfiGetTime();
	nwin->framerate = 1./float64(spec.frame_rate);
	nwin->vmin() = spec.vlimits.y;
	nwin->vmax() = spec.vlimits.x;
	nwin->hmin() = spec.hlimits.y;
	nwin->hmax() = spec.hlimits.x;
	
	nwin->flags = INFI_WINDOW_CLEAR_ON_REFRESH;
	if ( !spec.hidden )	
		nwin->flags |= INFI_WINDOW_SHOWN;
	
	nwin->kfront = new infi_keyboard_t( INFI_KEYBOARD_SIZE );
	nwin->kback  = new infi_keyboard_t( INFI_KEYBOARD_SIZE );
	nwin->mfront = new infi_mouse_t( INFI_MOUSE_BUTTON_CAP );
	nwin->mback  = new infi_mouse_t( INFI_MOUSE_BUTTON_CAP );
	
	nwin->kfront->init_time = InfiGetTime();
	nwin->kback->init_time = InfiGetTime();
	
	nwin->extcount = 0;
	
	if ( spec.position.x >= 0 )
		nobj->x = spec.position.x;
	else if ( spec.position.x == INFI_WINDOW_CENTERED )
		nobj->x = SDL_WINDOWPOS_CENTERED;
	else
		nobj->x = SDL_WINDOWPOS_UNDEFINED;
	
	if ( spec.position.y >= 0 )
		nobj->y = spec.position.y;
	else if ( spec.position.y == INFI_WINDOW_CENTERED )
		nobj->y = SDL_WINDOWPOS_CENTERED;
	else
		nobj->y = SDL_WINDOWPOS_UNDEFINED;
	
	WINDOW.needs_window.push( nobj );
	
	SDL_PushEvent( &SIGNAL.create );
	
	InfiPopFunction();
	return nwin;
	
}

void InfiQuit() {
	// WHO KNOWS
}

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------

static void infi_display_errors( const char* label ) {
	infi_error_t err;
	
	std::cerr << "--- Errors in " << label << " ------------" << std::endl;
	while ( InfiGetError( err ) ) {
		const char* errch = InfiErrorString(err.type);
		core::string_t whsp( ' ', strlen(errch) + 3 );
		uint32 fdepth = InfiGetFunctionDepth();
		
		if ( fdepth == 0 ) {
			std::cerr << errch << " : " << std::endl;
		} else
			std::cerr << errch << " : -- " << InfiGetFunctionName( 0 ) << std::endl;
		for ( uint32 i=1;i<fdepth;++i )
			std::cerr << whsp << "-- " << InfiGetFunctionName( i ) << std::endl;
		std::cerr << whsp << err.msg << std::endl;
		
	}
	std::cerr << "-------------------------------" << std::endl;
}

static void infi_initialize_states() {
	GLOBAL.cursor_shown 	= true;
	GLOBAL.init_time		= 0.0;
	
	GLOBAL.control_stop		= false;
	GLOBAL.control_running 	= false;
	
	GLOBAL.early 	= NULL;
	GLOBAL.init 	= NULL;
	GLOBAL.quit 	= NULL;

	WINDOW.GLinitialized = false;
	WINDOW.GLenabled = false;
	WINDOW.window = NULL;
	WINDOW.context = 0;
	WINDOW.context_count = 0;
	WINDOW.CURRENT = NULL;
	WINDOW.RENDER = NULL;
	WINDOW.ACTIVE = NULL;
	WINDOW.create = NULL;
	WINDOW.destroy = NULL;
	
	INFI_SIGNAL_START = 0;
	INFI_SIGNAL_CREATE = 0;
	INFI_SIGNAL_DESTROY = 0;
	INFI_SIGNAL_TERMINATE = 0;
}


static void infi_initialize_control() {
	InfiPushFunction( "Initialize Control" );
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
		InfiSendError( INFI_LIBRARY_ERROR, "SDL could not initialize" );
	InfiLInitDisplays();
	
	infi_fetch_initial_inputs();
	infi_register_sdl_events();
	
	WINDOW.window = SDL_CreateWindow( "infinity base window",
									  0, 0, 1, 1, 
									  SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN );
	
	WINDOW.create = SDL_CreateMutex();
	WINDOW.destroy = SDL_CreateMutex();
	InfiPopFunction();
}

static void infi_fetch_initial_inputs() {
	SDL_PumpEvents();
}

static void infi_register_sdl_events() {
	InfiPushFunction( "Register SDL Events" );
	uint32 vals = SDL_RegisterEvents( INFI_EVENT_REQ );
	if ( vals == (uint32) -1 )
		InfiSendError( INFI_LIBRARY_ERROR, "SDL_RegisterEvents" );
	
	SDL_zero( SIGNAL.start );
	INFI_SIGNAL_START = vals + 0;
	SIGNAL.start.type = INFI_SIGNAL_START;
	
	SDL_zero( SIGNAL.create );
	INFI_SIGNAL_CREATE = vals + 1;
	SIGNAL.create.type = INFI_SIGNAL_CREATE;
	
	SDL_zero( SIGNAL.destroy );
	INFI_SIGNAL_DESTROY = vals + 2;
	SIGNAL.destroy.type = INFI_SIGNAL_DESTROY;
	
	SDL_zero( SIGNAL.terminate );
	INFI_SIGNAL_TERMINATE = vals + 3;
	SIGNAL.terminate.type = INFI_SIGNAL_TERMINATE;
	
	SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
	InfiPopFunction();
}

static void infi_quit_control() {
	SDL_DestroyMutex( WINDOW.create );
	SDL_DestroyMutex( WINDOW.destroy );
	SDL_DestroyWindow( WINDOW.window );
	std::cerr << "????" << std::endl;
	SDL_Quit();
	std::cerr << "????" << std::endl;
}


static void infi_initialize_render() {
	InfiPushFunction( "Initialize Render" );
	infi_enable_gl();
	WINDOW.GLenabled = true;
	
	render::InfiGLUpdateInfo();
		
	WINDOW.context_count = 1;
	uint32 temp = render::InfiGLCreateState();
	render::InfiGLChangeState( temp );
	
	render::InfiLInitRender();
	render::InfiLInitObjects();
	render::InfiLInitTextureClear();
	text::InfiLInitText();
	InfiPopFunction();
}

static int32 infi_quit_render() {
	InfiPushFunction( "Quit Render" );
	
	SDL_GL_MakeCurrent( WINDOW.window, WINDOW.context );
	render::InfiGLSendMessage( "GL Context Change" );
	WINDOW.RENDER = NULL;
	int32 ret = infi_run_quit();
	
	render::InfiLQuitRender();
	//render::InfiLQuitObjects();
	render::InfiLQuitTextureClear();
	text::InfiLQuitText();
	
	WINDOW.objdump.dump();
	WINDOW.GLenabled = false;
	SDL_GL_DeleteContext( WINDOW.context );
	SDL_PushEvent( &SIGNAL.terminate );
	
	std::cerr << "FINISHED ENDING" << std::endl;
	
	InfiPopFunction();
	
	return ret;
}

static void infi_run_early() {
	InfiPushFunction( "User Early Function" );
	if ( GLOBAL.early != NULL )
		GLOBAL.early();
	InfiPopFunction();
}
static void infi_run_init() {
	InfiPushFunction( "User Init Function" );
	GLOBAL.params.userdata = NULL;
	if ( GLOBAL.init != NULL )
		GLOBAL.init( GLOBAL.params );
	InfiPopFunction();
}
static int32 infi_run_quit() {
	InfiPushFunction( "User Quit Function" );
	if ( GLOBAL.quit != NULL ) {
		int32 temp = GLOBAL.quit( GLOBAL.params.userdata );
		InfiPopFunction();
		return temp;
	} else {
		InfiPopFunction();
		return 0;
	}
}

static void infi_control_thread() {
	GLOBAL.thread_control = SDL_ThreadID();
	
	try {
		
		SDL_Event ev;
		GLOBAL.control_running = true;
		for ( ;; ) {
			if ( !SDL_WaitEvent( &ev ) )
				InfiSendError( INFI_LIBRARY_ERROR,
							   "SDL_WaitEvent" );
			float64 dt = InfiGetTime();
			
			if ( ev.type == INFI_SIGNAL_TERMINATE ) {
				std::cerr << "Control Is Exitting" << std::endl;
				break;
			}
			
			else if ( ev.type == INFI_SIGNAL_START ) {
				std::cerr << "Control Is Ready" << std::endl;
				GLOBAL.sync_init.signal();
			}
			
			else if ( ev.type == INFI_SIGNAL_CREATE ) {
				if ( WINDOW.needs_window.empty() )
					InfiSendError( INFI_INIT_ERROR,
								   "Could not create window, none available" );
				infi_gen_window_control();
			}
			
			else if ( ev.type == INFI_SIGNAL_DESTROY ) {
				if ( WINDOW.destroy_control.empty() )
					InfiSendError( INFI_INIT_ERROR,
								   "Could not destroy window, none available" );
				infi_del_window_control();
			}
			
			else switch( ev.type ) {
				case SDL_WINDOWEVENT:
					infi_handle_window_ev( ev, dt );
					break;
				case SDL_KEYDOWN:
					infi_handle_key_down_ev( ev, dt );
					break;
				case SDL_KEYUP:
					infi_handle_key_up_ev( ev, dt );
					break;
				case SDL_MOUSEMOTION:
					infi_handle_mouse_move_ev( ev, dt );
					break;
				case SDL_MOUSEBUTTONDOWN:
					infi_handle_mouse_down_ev( ev, dt );
					break;
				case SDL_MOUSEBUTTONUP:
					infi_handle_mouse_up_ev( ev, dt );
					break;
				case SDL_MOUSEWHEEL:
					infi_handle_mouse_wheel_ev( ev, dt );
					break;
			}
			
			for ( uint32 i=0;i<GLOBAL.CONTROL_HOOKS.size();i++ )
				if ( GLOBAL.CONTROL_HOOKS.exists( i ) )
					GLOBAL.CONTROL_HOOKS[i].func( GLOBAL.CONTROL_HOOKS[i].data, ev );
		}
		
	} catch ( INFI_error_msg ) {
		
		infi_display_errors( "Control" );
		GLOBAL.control_running = false;
		
	}
	
	std::cerr << "WAH" << std::endl;
}
static int32 infi_render_thread( void* data ) {
	InfiPushFunction( "Window Component" );
	try {
		
		GLOBAL.thread_render = SDL_ThreadID();
		
		InfiLHighestCommonPixelFormat();
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
		
		WINDOW.context = SDL_GL_CreateContext( WINDOW.window );
		
		GLenum err;
		if ( !WINDOW.GLinitialized && (err=glewInit()) != GLEW_OK )
			InfiSendError( INFI_GL_ERROR,
						   "GL could not load extensions" );
		
		infi_initialize_render();
		
		infi_run_init();
		
		SDL_PushEvent( &SIGNAL.start );
		
		GLOBAL.sync_init.wait();
		std::cerr << "Render Is Ready" << std::endl;
		
		for ( ;; ) {
			if ( !GLOBAL.control_running ) {
				int32 ret = infi_quit_render();
				InfiPopFunction();
				return ret;
			}
			
			infi_gen_window_render();
			
			float64 next = NAN; // could make really large number
			float64 now = InfiGetTime();
			
			for ( infi_window_t* win = WINDOW.displays[0];
				  win->frametime <= now;
				  win = WINDOW.displays[0] ) {
				
				WINDOW.displays.remove();
				
				float64 current = InfiGetTime();
				
				win->elapsed = current - win->starttime;
				win->starttime = current;
				
				infi_win_pipeline( win );
				
				win->frametime += win->framerate;
				
				( win->flags & INFI_WINDOW_TERMINATE ) ? infi_del_window_render( win ) :
														 WINDOW.displays.insert( win );
				
				if ( WINDOW.window_count == 0 ) {
					int32 ret = infi_quit_render();
					InfiPopFunction();
					return ret;
				}
				
				else if ( WINDOW.displays.size() == 0 )
					break;
				
			}
			
			if ( WINDOW.displays.size() != 0 ) {
				next = ( std::isnan( next ) ) ? WINDOW.displays[0]->frametime - now :
												std::min( next, WINDOW.displays[0]->frametime - now );
				if ( next > 0.0 )
					GLOBAL.wait.wait( next );
			}
			
		}
		
	} catch ( INFI_error_msg ) {
		
		infi_display_errors( "Render" );
		SDL_PushEvent( &SIGNAL.terminate );
		
	}
	
	InfiPopFunction();
	
	// error if reached here
	return -1;
}

static void infi_win_swap_inputs( infi_window_t* win ) {
	win->mfront->reset();
	win->kfront->reset();
	
	win->kfront->syncWith( win->kback );
	win->mfront->syncWith( win->mback );
	
	infi_keyboard_t* k = win->kfront;
	infi_mouse_t* m = win->mfront;
	
	win->kfront = win->kback;
	win->mfront = win->mback;
	
	win->kback = k;
	win->mback = m;
	
	win->kfront->init_time = InfiGetTime();
}

#define OPERATION_LOOP( win, arr, func ) \
		InfiPushFunction( #func ); \
		for ( uint32 i=0;i<win->arr.size();++i ) { \
			InfiPushFunction( win->arr[i]->GetName() ); \
			win->arr[i]->func( win->elapsed ); \
			InfiPopFunction(); \
		} \
		InfiPopFunction();
		
static void infi_win_pipeline( infi_window_t* win ) {
	InfiPushFunction( win->name.source() );
	WINDOW.CURRENT = win;
	
	// find window sizes
	SDL_GetWindowPosition( win->sdl, (int32*) &(win->x()), (int32*) &(win->y()) );
	SDL_GetWindowSize( win->sdl, (int32*) &(win->width()), (int32*) &(win->height()) );
	
	infi_win_swap_inputs( win );
	
	OPERATION_LOOP( win, update, Update )
	OPERATION_LOOP( win, prerender, PreRender )
	
	infi_win_render( win );
	
	OPERATION_LOOP( win, postrender, PostRender )
	
	win->counter ++ ;
	InfiPopFunction();
}
static void infi_win_render( infi_window_t* win ) {
	InfiPushFunction( "Render" );
	SDL_GL_MakeCurrent( win->sdl, win->context );
	render::InfiGLSendMessage( "GL Context Change" );
	WINDOW.RENDER = win;
	
	render::InfiGLChangeState( win->glstate );
	
	if ( win->flags & INFI_WINDOW_CLEAR_ON_REFRESH ) {
		render::InfiGLClearColor( win->clearcolor.x,
								  win->clearcolor.y,
								  win->clearcolor.z,
								  win->clearcolor.w );
		render::InfiGLClear( GL_COLOR_BUFFER_BIT | 
							 GL_DEPTH_BUFFER_BIT | 
							 GL_STENCIL_BUFFER_BIT );
	}
	
	infi_renderable_t* start = win->renderable.start();
	for( ;start!=NULL;start=win->renderable.next() ) {
		InfiPushFunction( start->GetName() );
		start->Render( win->dimensions, win->elapsed );
		InfiPopFunction();
	}
	
	SDL_GL_SwapWindow( win->sdl );
	InfiPopFunction();
}

static void infi_enable_gl() {
	InfiPushFunction( "Enable OpenGL" );
	
	render::InfiGLEnable( GL_TEXTURE_2D );
	render::InfiGLEnable( GL_DEPTH_TEST );
	render::InfiGLEnable( GL_STENCIL_TEST );
	render::InfiGLEnable( GL_CULL_FACE );
	render::InfiGLDepthFunc( GL_LEQUAL );
	
	render::InfiGLClearColor(0.f, 0.f, 0.f, 1.f);
	render::InfiGLShadeModel( GL_SMOOTH );
	
	WINDOW.GLinitialized = true;
	
	InfiPopFunction();
}

static void infi_gen_window_control() {
	SDL_LockMutex( WINDOW.create );
	
	infi_window_queue_object* nobj = WINDOW.needs_window[0];
	
	infi_window_t* nwin = nobj->win;
	nwin->sdl = SDL_CreateWindow( nwin->name.source(),
								  nobj->x, 
								  nobj->y,
								  nwin->width(), 
								  nwin->height(), 
								  nobj->flags );
	if ( nwin->sdl == NULL ) {
		WINDOW.needs_window.pop();
		delete nobj;
		delete nwin;
		InfiSendError( INFI_INIT_ERROR, "Could not create window" );
	}
	
	if ( nobj->flags & SDL_WINDOW_RESIZABLE ) {
		if ( nwin->hmin() != INT_MAX || nwin->vmin() != INT_MAX )
			SDL_SetWindowMaximumSize( nwin->sdl, nwin->hmin(), nwin->vmin() );
		if ( nwin->hmax() != 0 || nwin->vmax() != 0 )
			SDL_SetWindowMinimumSize( nwin->sdl, nwin->hmax(), nwin->vmax() );
	}
	nwin->id = SDL_GetWindowID( nwin->sdl );
	SDL_GetWindowPosition( nwin->sdl, (int32*)&(nwin->x()), (int32*)&(nwin->y()) );
	WINDOW.winids[nwin->id] = nwin;
	++ WINDOW.window_count;
	
	WINDOW.needs_window.pop();
	WINDOW.needs_context.push( nobj );
	
	SDL_UnlockMutex( WINDOW.create );
}

static void infi_gen_window_render() {
	if ( SDL_TryLockMutex( WINDOW.create ) != 0 )
		return;
	
	if ( !WINDOW.needs_context.empty() ) {
		
		infi_window_queue_object* nobj = WINDOW.needs_context[0];
		
		infi_window_t* nwin = nobj->win;
		
		nwin->context = SDL_GL_CreateContext( nwin->sdl );
		nwin->objdump = new render::infi_object_dump_t;
		
		SDL_GL_MakeCurrent( nwin->sdl, nwin->context );
		render::InfiGLSendMessage( "GL Context Change" );
		WINDOW.RENDER = nwin;
		
		nwin->glstate = render::InfiGLCreateState();
		render::InfiGLChangeState( nwin->glstate );
		infi_enable_gl();
		
		WINDOW.context_count ++ ;
		WINDOW.needs_context.pop();
		
		delete nobj;
		
		if ( std::isfinite(nwin->framerate) ) {
			
			nwin->frametime = InfiGetTime();
			nwin->starttime = nwin->frametime;
			nwin->elapsed = 0;
			
			WINDOW.displays.insert( nwin );
			
		}
	}
	
	SDL_UnlockMutex( WINDOW.create );
}

static void infi_del_window_control() {
	SDL_LockMutex( WINDOW.destroy );
	
	infi_window_t* win = WINDOW.destroy_control[0];
	
	SDL_DestroyWindow( win->sdl );
	
	delete win->objdump;
	
	delete win->kfront;
	delete win->kback;
	delete win->mfront;
	delete win->mback;
	
	delete win;
	
	if ( WINDOW.ACTIVE == win )
		WINDOW.ACTIVE = NULL;
	
	WINDOW.destroy_control.pop();
	
	SDL_UnlockMutex( WINDOW.destroy );
}
static void infi_del_window_render( infi_window_t* win ) {
	SDL_LockMutex( WINDOW.destroy );
	
	WINDOW.winids.erase( win->id );
	-- WINDOW.window_count;
	
	SDL_GL_MakeCurrent( win->sdl, win->context );
	render::InfiGLSendMessage( "GL Context Change" );
	WINDOW.RENDER = win;
	
	std::cerr << "DUMPING!"<< std::endl;
	win->objdump->dump();
	
	SDL_GL_DeleteContext( win->context );
	render::InfiGLFreeState( win->glstate );
	
	WINDOW.destroy_control.push( win );
	SDL_PushEvent( &SIGNAL.destroy );
	
	SDL_UnlockMutex( WINDOW.destroy );
}

static void infi_handle_window_ev( const SDL_Event& ev, float64 dt ) {
	infi_window_t* wwin = WINDOW.winids[ev.window.windowID];
	if ( wwin != NULL ) {
		switch( ev.window.event ) {
			case( SDL_WINDOWEVENT_SHOWN ):
				break;
			case( SDL_WINDOWEVENT_HIDDEN ):
				break;
			case( SDL_WINDOWEVENT_EXPOSED ):
				break;
			case( SDL_WINDOWEVENT_MOVED ):
				break;
			case( SDL_WINDOWEVENT_RESIZED ):
				break;
			case( SDL_WINDOWEVENT_SIZE_CHANGED ):
				break;
			case( SDL_WINDOWEVENT_MINIMIZED ):
				wwin->flags |= INFI_WINDOW_MINIMIZED;
				break;
			case( SDL_WINDOWEVENT_MAXIMIZED ):
				wwin->flags |= INFI_WINDOW_MAXIMIZED;
				break;
			case( SDL_WINDOWEVENT_RESTORED ):
				wwin->flags &= INFI_WINDOW_RESTORED;
				break;
			case( SDL_WINDOWEVENT_ENTER ):
				wwin->flags |= INFI_WINDOW_MOUSE_OVER;
				wwin->mback->push_enter( dt );
				break;
			case( SDL_WINDOWEVENT_LEAVE ):
				wwin->flags &= ~INFI_WINDOW_MOUSE_OVER;
				wwin->mback->push_leave( dt );
				break;
			case( SDL_WINDOWEVENT_FOCUS_GAINED ):
				wwin->flags |= INFI_WINDOW_INTERNAL_FOCUS;
				WINDOW.ACTIVE = wwin;
				break;
			case( SDL_WINDOWEVENT_FOCUS_LOST ):
				wwin->flags &= ~INFI_WINDOW_INTERNAL_FOCUS;
				if ( WINDOW.ACTIVE == wwin )
					WINDOW.ACTIVE = NULL;
				break;
			case( SDL_WINDOWEVENT_CLOSE ):
				wwin->flags |= INFI_WINDOW_TERMINATE;
				break;
		}
	}
}

#define GET_MODS( mods ) \
		if( ev.key.keysym.mod & INFI_MOD_LSHIFT ) 	mods |= INFI_K_LSHIFT; \
		if( ev.key.keysym.mod & INFI_MOD_RSHIFT ) 	mods |= INFI_K_RSHIFT; \
		if( ev.key.keysym.mod & INFI_MOD_LCTRL ) 	mods |= INFI_K_LCTRL; \
		if( ev.key.keysym.mod & INFI_MOD_RCTRL ) 	mods |= INFI_K_RCTRL; \
		if( ev.key.keysym.mod & INFI_MOD_LALT ) 	mods |= INFI_K_LALT; \
		if( ev.key.keysym.mod & INFI_MOD_RALT ) 	mods |= INFI_K_RALT; \
		if( ev.key.keysym.mod & INFI_MOD_LGUI ) 	mods |= INFI_K_LGUI; \
		if( ev.key.keysym.mod & INFI_MOD_RGUI ) 	mods |= INFI_K_RGUI; \
		if( ev.key.keysym.mod & INFI_MOD_NUM ) 		mods |= INFI_K_NUMLOCK; \
		if( ev.key.keysym.mod & INFI_MOD_CAPS ) 	mods |= INFI_K_CAPSLOCK;

static void infi_handle_key_down_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL && ((int)ev.key.repeat == 0 ) ) {
		uint32 mods = 0;
		GET_MODS( mods )
		WINDOW.ACTIVE->kback->push_down( ev.key.keysym.scancode, mods, dt );
	}
}
static void infi_handle_key_up_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL ) {
		uint32 mods = 0;
		GET_MODS( mods )
		WINDOW.ACTIVE->kback->push_up( ev.key.keysym.scancode, mods, dt );
	}
}

static void infi_handle_mouse_move_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL )
		WINDOW.ACTIVE->mback->push_move( core::vec2i( ev.motion.x, WINDOW.ACTIVE->height() - ev.motion.y ),
										 core::vec2i( ev.motion.xrel, -ev.motion.yrel ), dt );
}
static void infi_handle_mouse_down_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL )
		WINDOW.ACTIVE->mback->push_down( ev.button.button, 0, dt );
}
static void infi_handle_mouse_up_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL )
		WINDOW.ACTIVE->mback->push_up( ev.button.button, 0, dt );
}
static void infi_handle_mouse_wheel_ev( const SDL_Event& ev, float64 dt ) {
	if ( WINDOW.ACTIVE != NULL )
		WINDOW.ACTIVE->mback->push_wheel( ev.wheel.x, ev.wheel.y, dt );
}

float64 InfiGetProgramTime() {
	return InfiGetTime() - GLOBAL.init_time;
}

namespace render {
	void infi_dump_vertex_array( infi_window_t* win, uint32 va ) {
		std::cerr << "DUMP VA " << win << std::endl;
		if ( win == NULL ) {
			WINDOW.objdump.add_vertex_array( va );
		} else {
			std::cerr << win->name << std::endl;
			win->objdump->add_vertex_array( va );
		}
	}
	void infi_dump_framebuffer( infi_window_t* win, uint32 fb ) {
		std::cerr << "DUMP FB " << win << std::endl;
		if ( win == NULL ) {
			WINDOW.objdump.add_framebuffer( fb );
		} else {
			win->objdump->add_framebuffer( fb );
		}
	}
}

}