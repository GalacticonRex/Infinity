#include "depend/infi_sdl.hpp"
#include "engine/infi_root_module.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	infi_root_module_t::infi_root_module_t(infi_controller_t& ctrl, Render::infi_render_module_t::createContext& cc, infi_dispatch_terminate_t& t) :
		_active(nullptr),
		_window_count(0),
		_renderer(ctrl.createRenderer()),
		_keyboard(keycode::size),
		_mouse(mousebutton::size),
		_createContext(cc),
		_winMngrTerminate(t) {

		SDL_PumpEvents();

		uint32 vals = SDL_RegisterEvents( 5 );
		if ( vals == (uint32) -1 ) {
			//Error::define_scope __scope__("infi_root_module_t.ctor");
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Library,
				"SDL_RegisterEvents threw an error"
			);
		}

		SDL_Event* tempev;

		tempev = new SDL_Event();
		SDL_zero( *tempev );
		_signal_start = tempev;
		_value_start = vals + 0;
		((SDL_Event*)_signal_start)->type = _value_start;

		tempev = new SDL_Event();
		SDL_zero( *tempev );
		_signal_create = tempev;
		_value_create = vals + 1;
		((SDL_Event*)_signal_create)->type = _value_create;

		tempev = new SDL_Event();
		SDL_zero( *tempev );
		_signal_destroy = tempev;
		_value_destroy = vals + 2;
		((SDL_Event*)_signal_destroy)->type = _value_destroy;

		tempev = new SDL_Event();
		SDL_zero( *tempev );
		_signal_terminate = tempev;
		_value_terminate = vals + 3;
		((SDL_Event*)_signal_terminate)->type = _value_terminate;

		tempev = new SDL_Event();
		SDL_zero( *tempev );
		_signal_error = tempev;
		_value_error = vals + 4;
		((SDL_Event*)_signal_error)->type = _value_error;

		_window = (void*) SDL_CreateWindow( "infinity base window",
											0, 0, 1, 1,
											SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN );

		_input.setKeyboard(*this);
		_input.setMouse(*this);
	}
	infi_root_module_t::~infi_root_module_t() {
		SDL_DestroyWindow( (SDL_Window*) _window );

		delete (SDL_Event*) _signal_start;
		delete (SDL_Event*) _signal_create;
		delete (SDL_Event*) _signal_destroy;
		delete (SDL_Event*) _signal_terminate;
		delete (SDL_Event*) _signal_error;
	}

	void infi_root_module_t::signalStart() {
		SDL_PushEvent( (SDL_Event*) _signal_start );
	}
	void infi_root_module_t::signalError() {
		SDL_PushEvent( (SDL_Event*) _signal_error );
	}
	void infi_root_module_t::signalTerminate() {
		SDL_PushEvent( (SDL_Event*) _signal_terminate );
	}
	void infi_root_module_t::createWindow(infi_window_t* win) {
		_queue.push( win );
		SDL_PushEvent( (SDL_Event*) _signal_create );
	}
	void infi_root_module_t::destroyWindow(infi_window_t* win) {
		_queue.push( win );
		SDL_PushEvent( (SDL_Event*) _signal_destroy );
	}

	void* infi_root_module_t::baseWindow() const {
		return _window;
	}
	infi_window_t* infi_root_module_t::activeWindow() const {
		return _active;
	}
	infi_window_t* infi_root_module_t::getWindowByID(uint32 id) const {
		std::unordered_map<uint32, infi_window_t*>::const_iterator iter = _winids.find(id);
		if ( iter == _winids.end() )
			return nullptr;
		else
			return (*iter).second;
	}

	Render::infi_renderer_t& infi_root_module_t::renderer() {
		return _renderer;
	}
	const Render::infi_renderer_t& infi_root_module_t::renderer() const {
		return _renderer;
	}

	infi_input_events_t& infi_root_module_t::input() {
		return _input;
	}
	infi_keyboard_t& infi_root_module_t::getKeys() {
		return _keyboard;
	}
	infi_mouse_t& infi_root_module_t::getMouse() {
		return _mouse;
	}

	void infi_root_module_t::__run() {
		//Error::define_scope __scope__( "infi_root_module_t.run" );
		SDL_Event ev;

		for ( ;; ) {
			if ( !SDL_WaitEvent( &ev ) )
				Error::send<Error::Fatality::Method>(
					Error::Type::Library,
					"SDL_WaitEvent"
				);

			try {
				if ( ev.type == _value_terminate ) {

					break;

				} else if ( ev.type == _value_error) {

					return;

				} else if ( ev.type == _value_start ) {

					

				} else if ( ev.type == _value_create ) {

					std::lock_guard<std::mutex> lk(_window_create);
					infi_window_t* win = (infi_window_t*) _queue.front();
					_queue.pop();
					__gen_window_control(win);

				} else if ( ev.type == _value_destroy ) {

					std::lock_guard<std::mutex> lk(_window_destroy);
					infi_window_t* win = (infi_window_t*) _queue.front();
					_queue.pop();
					__del_window_control(win);

				} else switch( ev.type ) {

					case SDL_WINDOWEVENT: 		__handle_window_ev( &ev ); break;
					case SDL_KEYDOWN: 			__handle_key_down_ev( &ev ); break;
					case SDL_KEYUP: 			__handle_key_up_ev( &ev ); break;
					case SDL_MOUSEMOTION: 		__handle_mouse_move_ev( &ev ); break;
					case SDL_MOUSEBUTTONDOWN:	__handle_mouse_down_ev( &ev ); break;
					case SDL_MOUSEBUTTONUP: 	__handle_mouse_up_ev( &ev ); break;
					case SDL_MOUSEWHEEL: 		__handle_mouse_wheel_ev( &ev ); break;

				}
			} catch ( Error::message<Error::Fatality::Thread> e ) {
				//__WriteError__("Error encountered in [InputControl]");
				e.display(std::cerr);
				//__WriteError__("Restarting Input Control...");
			}
		}
	}

	void infi_root_module_t::__handle_window_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_window_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		infi_window_t* wwin = getWindowByID(ev.window.windowID);
		if ( wwin != nullptr ) {
			switch( ev.window.event ) {

				case SDL_WINDOWEVENT_SHOWN:
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					break;
				case SDL_WINDOWEVENT_EXPOSED:
					break;
				case SDL_WINDOWEVENT_MOVED:
					break;
				case SDL_WINDOWEVENT_RESIZED:
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					break;

				case SDL_WINDOWEVENT_MINIMIZED:
					wwin->_flags |= INFI_WINDOW_MINIMIZED;
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					wwin->_flags |= INFI_WINDOW_MAXIMIZED;
					break;
				case SDL_WINDOWEVENT_RESTORED:
					wwin->_flags &= INFI_WINDOW_RESTORED;
					break;
				case SDL_WINDOWEVENT_ENTER:
					wwin->_flags |= INFI_WINDOW_MOUSE_OVER;
					_input.mouse.inside.propagate(wwin, true);
					wwin -> input.mouse.inside.propagate(wwin, true);
					break;
				case SDL_WINDOWEVENT_LEAVE:
					wwin->_flags &= ~INFI_WINDOW_MOUSE_OVER;
					_input.mouse.inside.propagate(wwin, false);
					wwin -> input.mouse.inside.propagate(wwin, false);
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					wwin->_flags |= INFI_WINDOW_INTERNAL_FOCUS;
					_active = wwin;
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					wwin->_flags &= ~INFI_WINDOW_INTERNAL_FOCUS;
					if ( _active == wwin )
						_active = nullptr;
					break;
				case SDL_WINDOWEVENT_CLOSE:
					wwin->close();
					break;
			}
		}
	}

	void infi_root_module_t::__handle_key_down_ev( const void* evoid ) {
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		if ( (int)ev.key.repeat == 0 ) {
			//Error::define_scope __scope__( "handle_key_down_ev" );
			try {
				_input[ev.key.keysym.scancode](true);
				if ( _active != nullptr ) {
					_active -> input[ev.key.keysym.scancode](true);
				}
			} catch ( Error::message<Error::Fatality::Method> e ) {
				e.display(std::cerr);
			}
		}
	}
	void infi_root_module_t::__handle_key_up_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_key_up_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		try {
			_input[ev.key.keysym.scancode](false);
			if ( _active != nullptr ) {
				_active -> input[ev.key.keysym.scancode](false);
			}
		} catch ( Error::message<Error::Fatality::Method> e ) {
			e.display(std::cerr);
		}
	}

	void infi_root_module_t::__handle_mouse_move_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_mouse_move_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		infi_window_t* w = _winids[ev.motion.windowID];
		
		core::vec2i p( ev.motion.x, w->height() - ev.motion.y );
		core::vec2i d( ev.motion.xrel, -ev.motion.yrel );

		infi_input_events_t::mouse_data data{p,d};
		_input.mouse.position.propagate(data, true);
		if ( w != nullptr ) {
			w -> input.mouse.position.propagate(data, true);
		}
	}
	void infi_root_module_t::__handle_mouse_down_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_mouse_down_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		infi_window_t* w = _winids[ev.motion.windowID];
		_input.mouse[ev.button.button].propagate(true);
		if ( w != nullptr ) {
			w -> input.mouse[ev.button.button].propagate(true);
		}
	}
	void infi_root_module_t::__handle_mouse_up_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_mouse_up_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		infi_window_t* w = _winids[ev.motion.windowID];
		_input.mouse[ev.button.button].propagate(false);
		if ( w != nullptr ) {
			w -> input.mouse[ev.button.button].propagate(false);
		}
	}
	void infi_root_module_t::__handle_mouse_wheel_ev( const void* evoid ) {
		//Error::define_scope __scope__( "handle_mouse_wheel_ev" );
		const SDL_Event& ev = *(const SDL_Event*)evoid;
		infi_window_t* w = _winids[ev.motion.windowID];
		
		core::vec2i wh( ev.wheel.x, ev.wheel.y );

		_input.mouse.wheel.propagate(wh, true);
		if ( w != nullptr ) {
			w -> input.mouse.wheel.propagate(wh, true);
		}
	}


	void infi_root_module_t::__gen_window_control(infi_window_t* win) {
		win->_sdl = SDL_CreateWindow( win->_winname.c_str(),
									  win->x(), win->y(),
									  win->width(),
									  win->height(),
									  win->buildFlags() );
		if ( win->_sdl == nullptr ) {
			delete win;
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"Could not create window: %s",
				SDL_GetError()
			);
		}

		if ( win->_flags & SDL_WINDOW_RESIZABLE ) {
			if ( win->hmin() != INT_MAX || win->vmin() != INT_MAX )
				SDL_SetWindowMaximumSize( (SDL_Window*) win->_sdl, win->hmin(), win->vmin() );
			if ( win->hmax() != 0 || win->vmax() != 0 )
				SDL_SetWindowMinimumSize( (SDL_Window*) win->_sdl, win->hmax(), win->vmax() );
		}
		SDL_GetWindowPosition( (SDL_Window*) win->_sdl, (int32*)&(win->x()), (int32*)&(win->y()) );

		win->_id = SDL_GetWindowID( (SDL_Window*) win->_sdl );
		_winids[win->_id] = win;
		++ _window_count;
		
		_createContext(win);
	}
	void infi_root_module_t::__del_window_control(infi_window_t* win) {
		std::unordered_map<uint32,infi_window_t*>::iterator iter = _winids.find( win->_id );
		if ( iter == _winids.end() ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"Could not find window with id %d",
				win->_id
			);
		}

		_winids.erase( iter );
		-- _window_count;
		if ( _window_count == 0 ) {
			_winMngrTerminate();
			signalTerminate();
		}
		
		SDL_DestroyWindow( (SDL_Window*) win->_sdl );
		delete win;

		if ( _active == win )
			_active = nullptr;
	}

	void infi_root_module_t::run() {
		this -> __run();
	}

}