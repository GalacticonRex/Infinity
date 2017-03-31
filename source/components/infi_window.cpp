#include "base/time.hpp"
#include "components/infi_window.hpp"
#include "depend/infi_sdl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {

infi_window_spec_t::infi_window_spec_t() :
	dimensions( 640, 480 ),
	position( INFI_WINDOW_CENTERED ),
	hlimits( INT_MAX, 0 ),
	vlimits( INT_MAX, 0 ),
	anchor(),
	relposition( INFINITY, INFINITY ),
	frame_rate( 60 ),
	target_display( 0 ),
	fullscreen( false ),
	hidden( false ),
	borderless( false ),
	resizable( false ),
	builtin_ui( false ) { ; }

infi_window_t::__window_trigger::__window_trigger() :
	infi_event_trigger_t([this](bool sig){
		if ( sig ) _flagged = true;
	}),
	_flagged(false) { ; }

infi_window_t::infi_window_t( const infi_display_list_t& disp, infi_win_mngr_module_t::bindRenderable& rb, const std::string& n, const infi_window_spec_t& spec ) :
	_winname( n ),
	_id( 0 ),
	_position(),
	_anchor( spec.anchor ),
	_dimensions(),
	_limits( spec.hlimits.x, spec.hlimits.y,
			 spec.vlimits.x, spec.vlimits.y ),
	_counter( 0 ),
	_stream( 1.0 ),
	_framerate( 1.0/float64(spec.frame_rate) ),
	_lastframe( 0.0 ),
	_clearcolor( 0,0,0,1 ),
	_flags( INFI_WINDOW_CLEAR_ON_REFRESH ),
	_sdl( NULL ),
	_context(NULL),
	_keyboard(keycode::size),
	_mouse(mousebutton::size),
	_renderable(rb),
	close(_close),
	input(_input) {
	
	if ( spec.fullscreen ) {
		_dimensions.x = disp[spec.target_display].width;
		_dimensions.y = disp[spec.target_display].height;
	} else
		_dimensions = spec.dimensions;

	_dimensions = spec.dimensions;
	if ( !spec.hidden )
		_flags |= INFI_WINDOW_SHOWN;

	input.setKeyboard(*this);
	input.setMouse(*this);
}
infi_window_t::~infi_window_t() { ; }

void infi_window_t::__run_render( Render::infi_renderer_t& queue ) {
	//Error::define_scope __scope__(_winname.c_str());

	__update_locations();
	float64 now = _stream.globalToLocal(Time::Now());
	float64 elapsed = now - _lastframe;

	std::multiset<infi_renderable_t*>::iterator i(_renderables.begin());
	for (;i != _renderables.end();i++ )
		(*i)->Render( queue, elapsed );
	++ _counter;
	_lastframe = now;
}
void infi_window_t::__update_locations() {
	SDL_GetWindowPosition( (SDL_Window*)_sdl, (int32*) &(_position.x), (int32*) &(_position.y) );
	SDL_GetWindowSize( (SDL_Window*)_sdl, (int32*) &(_dimensions.x), (int32*) &(_dimensions.y) );
}

void infi_window_t::createContext(Render::infi_gl_context_controller_t& ctrl) {
	_context = ctrl.createContext(_sdl);
}
void infi_window_t::deleteContext(Render::infi_gl_context_controller_t& ctrl) {
	ctrl.destroyContext(_context);
}
void infi_window_t::makeCurrentContext(Render::infi_gl_context_controller_t& ctrl) {
	ctrl.setCurrentContext(_sdl, _context);
}
void infi_window_t::swapContext(Render::infi_gl_context_controller_t& ctrl) {
	ctrl.swapContext(_sdl);
}

infi_window_t& infi_window_t::renderWith( infi_renderable_t* r ) {
	r->_parent = this;
	_renderable(r);
	return *this;
}
infi_window_t& infi_window_t::renderWith( infi_renderable_t& r ) {
	r._parent = this;
	_renderable(&r);
	return *this;
}

infi_window_t& infi_window_t::remove( infi_renderable_t* r ) {
	std::multiset<infi_renderable_t*>::iterator iter = _renderables.find(r);
	if ( iter == _renderables.end() ) {
		//Error::define_scope __scope__("infi_window_t.-=");
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Could not find renderable in window"
		);
	}
	_renderables.erase( iter );
	r->_parent = NULL;
	return *this;
}
infi_window_t& infi_window_t::remove( infi_renderable_t& r ) {
	std::multiset<infi_renderable_t*>::iterator iter = _renderables.find(&r);
	if ( iter == _renderables.end() ) {
		//Error::define_scope __scope__("infi_window_t.-=");
		Error::send<Error::Fatality::Method>(
			Error::Type::NullDeref,
			"Could not find renderable in window"
		);
	}
	_renderables.erase( iter );
	r._parent = NULL;
	return *this;
}

core::mat4 infi_window_t::getProjection() const {
	return core::ortho4(core::vec2(), core::vec2(_dimensions));
}

infi_window_t::operator core::vec2() const {
	return _dimensions;
}

}
