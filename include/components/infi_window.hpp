#ifndef __INFI_WINDOW_H__
#define __INFI_WINDOW_H__

#include <climits>
#include <atomic>
#include <vector>
#include <map>

#include "core/matrix.hpp"
#include "core/rgba.hpp"

#include "modules/infi_module_defs.hpp"

#include "components/infi_component_defs.hpp"
#include "components/infi_input_events.hpp"
#include "components/infi_renderable.hpp"
#include "components/infi_keyboard.hpp"
#include "components/infi_mouse.hpp"

#include "engine/infi_displays.hpp"
#include "engine/winmngr/infi_win_mngr_module.hpp"

#include "threads/infi_trigger.hpp"
#include "threads/infi_time_stream.hpp"

#include "render/gl/infi_gl_defs.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {

	const struct {
		operator int32 () const { return INT_MAX; }
		operator core::vec2i () const { return core::vec2i( INT_MAX, INT_MAX ); }
	} INFI_WINDOW_UNDEFINED;

	const struct {
		operator int32 () const { return INT_MIN; }
		operator core::vec2i () const { return core::vec2i( INT_MIN, INT_MIN ); }
	} INFI_WINDOW_CENTERED;

	struct infi_window_spec_t {
		core::vec2ui dimensions;
		core::vec2i position;
		core::vec2i hlimits;
		core::vec2i vlimits;

		core::vec2 anchor;
		core::vec2 relposition;

		uint32 frame_rate;
		uint32 target_display;

		bool fullscreen,
			 hidden,
			 borderless,
			 resizable,
			 builtin_ui;

		infi_window_spec_t();

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

	const uint32 INFI_WINDOW_TERMINATE 			= 0x00000001,
				 INFI_WINDOW_CLEAR_ON_REFRESH 	= 0x00000002,
				 INFI_WINDOW_SHOWN 				= 0x00000004,
				 INFI_WINDOW_INTERNAL_FOCUS 	= 0x00000008,
				 INFI_WINDOW_MOUSE_OVER 		= 0x00000010,
				 INFI_WINDOW_MINIMIZED 			= 0x00000020,
				 INFI_WINDOW_MAXIMIZED 			= 0x00000040,
				 INFI_WINDOW_RESTORED 			= ~INFI_WINDOW_MINIMIZED &
				 								  ~INFI_WINDOW_MAXIMIZED;

	struct infi_window_t : public does_not_copy {
	private:

		std::string			_winname;
		uint32				_id;
		core::vec2i 		_position;
		core::vec2			_anchor;
		core::vec2ui 		_dimensions;
		core::vec4i 		_limits;
		uint64				_counter;
		infi_time_stream_t	_stream;
		float64				_framerate;
		float64				_lastframe;
		core::rgba_t		_clearcolor;
		uint32				_flags;
		uint32				_build_flags;
		void*				_sdl;
		void*				_context;
		std::multiset<infi_renderable_t*, infi_renderable_t::compare>
							_renderables;
		infi_keyboard_t		_keyboard;
		infi_mouse_t		_mouse;
		infi_input_events_t _input;

		infi_win_mngr_module_t::bindRenderable& _renderable;

		struct __window_trigger : public infi_trigger_t {
			bool _flagged;
			__window_trigger();
			void Triggered(infi_trigger_t*, bool, void*);
		} _close;

		friend struct __window_trigger;
		friend struct infi_win_mngr_interpreter_t;
		friend struct infi_controller_t;

	protected:

		void __run_render( Render::infi_renderer_t& );
		void __update_locations();

		uint32& width() { return _dimensions.x; }
		uint32& height() { return _dimensions.y; }
		int32& x() { return _position.x; }
		int32& y() { return _position.y; }
		int32& hmax() { return _limits.x; }
		int32& hmin() { return _limits.y; }
		int32& vmax() { return _limits.z; }
		int32& vmin() { return _limits.w; }

	public:

		infi_trigger_t& close;
		infi_input_events_t& input;

		infi_window_t( const infi_display_list_t&, infi_win_mngr_module_t::bindRenderable&, const std::string&, const infi_window_spec_t& );
		~infi_window_t();

		const std::string& name() const { return _winname; }
		uint32 width() const { return _dimensions.x; }
		uint32 height() const { return _dimensions.y; }
		int32 x() const { return _position.x; }
		int32 y() const { return _position.y; }
		int32 hmax() const { return _limits.x; }
		int32 hmin() const { return _limits.y; }
		int32 vmax() const { return _limits.z; }
		int32 vmin() const { return _limits.w; }
		float64 frameRate() const { return _framerate; }
		infi_time_stream_t& timeStream() { return _stream; }

		void clearColor(const core::rgba_t& color) { _clearcolor = color; }
		void clearColor(float32 r, float32 g, float32 b, float32 a) { _clearcolor = core::rgba_t(r,g,b,a); }
		core::rgba_t& clearColor() { return _clearcolor; }
		const core::rgba_t& clearColor() const { return _clearcolor; }

		uint32 buildFlags() const { return _build_flags; }
		bool isClosing() const { return _close._flagged; }

		void createContext(Render::infi_gl_context_controller_t&);
		void deleteContext(Render::infi_gl_context_controller_t&);
		void makeCurrentContext(Render::infi_gl_context_controller_t&);
		void swapContext(Render::infi_gl_context_controller_t&);

		infi_keyboard_t& getKeys() { return _keyboard; }
		infi_mouse_t& getMouse() { return _mouse; }
		core::mat4 getProjection() const;

		operator core::vec2() const;

		infi_window_t& renderWith( infi_renderable_t* );
		infi_window_t& renderWith( infi_renderable_t& );

		infi_window_t& unRenderWith( infi_renderable_t* );
		infi_window_t& unRenderWith( infi_renderable_t& );

		friend struct infi_root_module_t;
	};
}

#endif//__INFI_WINDOW_H__
