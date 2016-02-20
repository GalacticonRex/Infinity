#ifndef __INFI_WINDOW_H__
#define __INFI_WINDOW_H__

#define SDL_MAIN_HANDLED
#include "sdl/sdl.h"

#include <climits>

#include "core/infi_methods.h"
#include "core/infi_string.h"
#include "core/infi_array.h"
#include "core/infi_stack.h"
#include "core/infi_vector.h"

#include "main/infi_keyboard.h"
#include "main/infi_mouse.h"
#include "main/infi_extension.h"
#include "main/infi_renderable.h"

#include "render/infi_view_transform.h"

namespace INFI {
	
	const struct {
		operator int32 () const { return INT_MAX; }
		operator core::vec2i () const { return core::vec2i( INT_MAX, INT_MAX ); }
	} INFI_WINDOW_UNDEFINED;
	
	const struct {
		operator int32 () const { return INT_MIN; }
		operator core::vec2i () const { return core::vec2i( INT_MIN, INT_MIN ); }
	} INFI_WINDOW_CENTERED;
	
	struct infi_window_spec_t {
		core::string_t name;
		
		core::vec2ui dimensions;
		core::vec2i position;
		core::vec2i hlimits;
		core::vec2i vlimits;
		
		core::vec2 anchor;
		core::vec2 relposition;
		
		uint32 frame_rate;
		
		bool fullscreen,
			 hidden,
			 borderless,
			 resizable,
			 builtin_ui;
		
		// member methods 
		uint32& width() { return dimensions.x; }
		uint32& height() { return dimensions.y; }
		int32& x() { return position.x; }
		int32& y() { return position.y; }
		float32& xr() { return relposition.x; }
		float32& yr() { return relposition.y; }
		
		const uint32& width() const { return dimensions.x; }
		const uint32& height() const { return dimensions.y; }
		const int32& x() const { return position.x; }
		const int32& y() const { return position.y; }
		const float32& xr() const { return relposition.x; }
		const float32& yr() const { return relposition.y; }
		
		int32& hmax() { return hlimits.x; }
		int32& hmin() { return hlimits.y; }
		int32& vmax() { return vlimits.x; }
		int32& vmin() { return vlimits.y; }
		
		const int32& hmax() const { return hlimits.x; }
		const int32& hmin() const { return hlimits.y; }
		const int32& vmax() const { return vlimits.x; }
		const int32& vmin() const { return vlimits.y; }
		
		void lock_horizontal( int32 n )
			{ hlimits.x = n; hlimits.y = n; }
		void lock_vertical( int32 n )
			{ vlimits.x = n; vlimits.y = n; }
	};
	
	INFI_FUNCTION( void, InfiInitWindowSpec, ( infi_window_spec_t& ) );
	
	const uint32 INFI_WINDOW_TERMINATE 			= 0x00000001,
				 INFI_WINDOW_CLEAR_ON_REFRESH 	= 0x00000002,
				 INFI_WINDOW_SHOWN 				= 0x00000004,
				 INFI_WINDOW_INTERNAL_FOCUS 	= 0x00000008,
				 INFI_WINDOW_MOUSE_OVER 		= 0x00000010,
				 INFI_WINDOW_MINIMIZED 			= 0x00000020,
				 INFI_WINDOW_MAXIMIZED 			= 0x00000040,
				 INFI_WINDOW_RESTORED 			= ~INFI_WINDOW_MINIMIZED & 
				 								  ~INFI_WINDOW_MAXIMIZED;
	
	struct infi_window_t : render::infi_view_transform_t {
		
		core::string_t						name;
		uint32								id;
		uint32								glstate;
		
		core::vec2i 						position;
		core::vec2							anchor;
		core::vec2ui 						dimensions;
		core::vec4i 						limits;
		
		uint64								counter;
		
		float64								frametime;
		float64								framerate;
		float64 							starttime;
		float64 							elapsed;
		
		core::vec4							clearcolor;
		
		uint32								flags;
											
		infi_keyboard_t						*kfront,
											*kback;
		infi_mouse_t						*mfront,
											*mback;
		
		SDL_Window*							sdl;
		SDL_GLContext						context;
		
		// extensions
		uint32 extcount;
		core::array_t<infi_extension_t*> 			extmain;
		core::array_t<infi_extension_update_t*> 	update;
		core::array_t<infi_extension_prerender_t*> 	prerender;
		core::array_t<infi_extension_postrender_t*> postrender;
		core::rb_tree_t<infi_renderable_t> 			renderable;
		
		// member functions
		uint32& width() { return dimensions.x; }
		uint32& height() { return dimensions.y; }
		
		const uint32& width() const { return dimensions.x; }
		const uint32& height() const { return dimensions.y; }
		
		int32& x() { return position.x; }
		int32& y() { return position.y; }
		const int32& x() const { return position.x; }
		const int32& y() const { return position.y; }
		
		int32& hmax() { return limits.x; }
		int32& hmin() { return limits.y; }
		int32& vmax() { return limits.z; }
		int32& vmin() { return limits.w; }
		
		const int32& hmax() const { return limits.x; }
		const int32& hmin() const { return limits.y; }
		const int32& vmax() const { return limits.z; }
		const int32& vmin() const { return limits.w; }
		
		operator core::mat4() const {
			return core::OrthoMat4( core::vec2(), dimensions );
		}
	};
	
	INFI_FUNCTION( infi_window_t*, InfiCreateWindow, ( const core::vec2ui&, uint32=60 ) );
	INFI_FUNCTION( infi_window_t*, InfiCreateWindow, ( const core::string_t&, const core::vec2ui&, uint32=60 ) );
	INFI_FUNCTION( infi_window_t*, InfiCreateWindow, ( const infi_window_spec_t& ) );
	INFI_FUNCTION( void, InfiDestroyWindow, ( infi_window_t* ) );
	
	INFI_FUNCTION( infi_extension_t*, InfiExtendWindow, ( infi_window_t*, infi_extension_t* ) );
	
}

#endif//__INFI_WINDOW_H__