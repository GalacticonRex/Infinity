#include <thread>
#include "engine/infi_controller.hpp"
#include "depend/infi_sdl.hpp"
	
namespace Infinity {

	infi_controller_t::__module_error_handler__::__module_error_handler__() :
		_root(NULL) { ; }
			
	void infi_controller_t::__module_error_handler__::setRootModule(infi_root_module_t* rt) {
		_root = rt;
	}

	bool infi_controller_t::__module_error_handler__::handle(infi_named_object_t& m, Error::message<Error::Fatality::Fatal>& e) {
		std::cerr << "---------------------------------------------" << std::endl;
		std::cerr << "Fatal Error in " << m.name() << std::endl;

		e.display(std::cerr);
		
		std::cerr << "---------------------------------------------" << std::endl;

		if ( _root != NULL ) _root -> signalError();

		return false;
	}
	bool infi_controller_t::__module_error_handler__::handle(infi_named_object_t& m, Error::message<Error::Fatality::Thread>& e) {
		std::cerr << "---------------------------------------------" << std::endl;
		std::cerr << "Thread Error in " << m.name() << std::endl;

		e.display(std::cerr);
		
		std::cerr << "---------------------------------------------" << std::endl;
		
		if ( _root != NULL ) _root -> signalError();

		return false;
	}
	bool infi_controller_t::__module_error_handler__::handle(infi_named_object_t& m, Error::message<Error::Fatality::Method>& e) {
		std::cerr << "---------------------------------------------" << std::endl;
		std::cerr << "Method Error in " << m.name() << std::endl;

		e.display(std::cerr);
		
		std::cerr << "---------------------------------------------" << std::endl;
		return true;
	}
	bool infi_controller_t::__module_error_handler__::handle(infi_named_object_t& m, Error::message<Error::Fatality::Warning>& e) {
		std::cerr << "---------------------------------------------" << std::endl;
		std::cerr << "Warning in " << m.name() << std::endl;

		e.display(std::cerr);
		
		std::cerr << "---------------------------------------------" << std::endl;
		return true;
	}

	infi_controller_t::infi_controller_t(infi_lib_init_t& lib) :
		_displays(lib),
		_winmngr("Window Manager", _error_handler),
		_update("Update Manager", _error_handler),
		_render("Render", _error_handler),
		_winmngr_recv(_winmngr),
		_updatemngr_recv(_update),
		_render_recv(_render),
		_root(*this, _render_recv.createContext, _winmngr_recv.terminate),
		renderer(_root.renderer()),
		extendWith(_updatemngr_recv.extension),
		displays(_displays),
		input(_root.input()),
		clock(1.0) {

		_update_thr = std::thread(	infi_update_mngr_module_t::run, 
									std::ref(*this),
									std::ref(_update),
									std::ref(_error_handler),
									4u,
									std::ref(_updatemngr_recv.extension),
									std::ref(_updatemngr_recv.threadComplete));

		std::mutex temp;
		std::unique_lock<std::mutex> lk(temp);
		std::condition_variable cond;
		_render_thr = std::thread(	Render::infi_render_module_t::run,
									std::ref(cond),
									"GL.txt",
									std::ref(_root),
									std::ref(_displays),
									std::ref(_render),
									std::ref(_winmngr_recv.refresh),
									std::ref(_render_recv.shared),
									std::ref(_render_recv.perContext));
		cond.wait(lk);
	}

	infi_controller_t::~infi_controller_t() {
		_updatemngr_recv.terminate();
		_update_thr.join();

		_render_recv.terminate();
		_render_thr.join();
	}

	infi_window_t& infi_controller_t::createWindow( const std::string& name, const core::vec2ui& dim, uint32 fps ) {
		infi_window_spec_t spec;
		spec.dimensions = dim;
		spec.frame_rate = fps;
		return this->createWindow( name, spec );
	}
	infi_window_t& infi_controller_t::createWindow( const std::string& name, const infi_window_spec_t& spec ) {
		infi_window_t* win = new infi_window_t( _displays, _winmngr_recv.bindRenderable, name, spec );

		win->_build_flags = SDL_WINDOW_OPENGL;
		if ( spec.resizable )
			win->_build_flags |= SDL_WINDOW_RESIZABLE;
		if ( spec.hidden )
			win->_build_flags |= SDL_WINDOW_HIDDEN;
		if ( spec.borderless )
			win->_build_flags |= SDL_WINDOW_BORDERLESS;

		if ( spec.fullscreen )
			win->_build_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		if ( spec.position.x >= 0 )
			win->x() = spec.position.x;
		else if ( spec.position.x == INFI_WINDOW_CENTERED )
			win->x() = SDL_WINDOWPOS_CENTERED;
		else	
			win->x() = SDL_WINDOWPOS_UNDEFINED;

		if ( spec.position.y >= 0 )
			win->y() = spec.position.y;
		else if ( spec.position.y == INFI_WINDOW_CENTERED )
			win->y() = SDL_WINDOWPOS_CENTERED;
		else
			win->y() = SDL_WINDOWPOS_UNDEFINED;

		_root.createWindow(win);

		return *win;
	}

	Render::infi_renderer_t infi_controller_t::createRenderer() {
		return Render::infi_renderer_t(_render_recv.shared, _render_recv.perContext, _render_recv.draw);
	}

	infi_controller_t& infi_controller_t::doWith( infi_extension_t* ext ) {
		return this -> doWith(*ext);
	}
	infi_controller_t& infi_controller_t::doWith( infi_extension_t* ext, float64 sec ) {
		return this -> doWith(*ext, sec);
	}
	infi_controller_t& infi_controller_t::doWith( infi_extension_t* ext, infi_event_clock_t& ts, float64 sec ) {
		return this -> doWith(*ext, ts, sec);
	}

	infi_controller_t& infi_controller_t::doWith( infi_extension_t& ext ) {
		infi_extension_t* ext_ptr = &ext;
		infi_update_mngr_module_t::Function func = [=](infi_controller_t& ctrl){
			ext_ptr -> run(ctrl);
		};
		_updatemngr_recv.extension(func);
		return *this;
	}
	infi_controller_t& infi_controller_t::doWith( infi_extension_t& ext, float64 sec ) {
		infi_extension_t* ext_ptr = &ext;
		infi_update_mngr_module_t::Function func = [=](infi_controller_t& ctrl){ext_ptr -> run(ctrl);};
		_updatemngr_recv.extension(clock, sec, func);
		return *this;
	}
	infi_controller_t& infi_controller_t::doWith( infi_extension_t& ext, infi_event_clock_t& ts, float64 sec ) {
		infi_extension_t* ext_ptr = &ext;
		infi_update_mngr_module_t::Function func = [=](infi_controller_t& ctrl){ext_ptr -> run(ctrl);};
		_updatemngr_recv.extension(ts, sec, func);
		return *this;
	}

	void infi_controller_t::abort() {
		_root.signalError();
	}

	void infi_controller_t::run() {
		//Error::define_scope __scope__("infi_controller_t.run");
		_root.renderer().flush();

		std::thread winthr;
		infi_win_mngr_interpreter_t winint( *this,
											_winmngr_recv.refresh,
											_winmngr_recv.destroyWindow,
											_render_recv.destroyContext );
		_winmngr.interpreter(winint);

		clock.restart();

		winthr = std::thread(infi_win_mngr_module_t::module::run, &_winmngr);

		try {
			_root.run();
		} catch ( Error::message<Error::Fatality::Thread> e ) {
			_winmngr_recv.terminate();
		}

		winthr.join();
	}
}