#include "components/infi_mouse.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	const uint32 mousebutton::size = 16;
	const uint32 mousebutton::left = 1;
	const uint32 mousebutton::middle = 2;
	const uint32 mousebutton::right = 3;

	infi_mouse_buffer_t::infi_mouse_buffer_t( uint32 sz ) :
		infi_key_buffer_t( sz ),
		_inside_window( NULL ),
		_pos_time( Time::Now() ),
		_wheel_time ( Time::Now() ),
		_enter_time( Time::Now() ),
		_leave_time( Time::Now() ) { ; }


	void infi_mouse_buffer_t::push_enter( infi_window_t* w, Time::Point t ) {
		_inside_window = w;
		_enter_time = t;
	}
	void infi_mouse_buffer_t::push_leave( infi_window_t* w, Time::Point t ) {
		_inside_window = NULL;
		_leave_time = t;
	}
	void infi_mouse_buffer_t::push_move( core::vec2i pos, core::vec2i rel, Time::Point t ) {
		_position = pos;
		_deltap = rel;
		_pos_time = t;
	}
	void infi_mouse_buffer_t::push_wheel( core::vec2i w, Time::Point t ) {
		_wheel += w;
		_deltaw = w;
		_wheel_time = t;
	}

	infi_window_t* infi_mouse_buffer_t::window() const {
		return _inside_window;
	}
	bool infi_mouse_buffer_t::inside() const {
		return (_inside_window!=NULL);
	}

	const core::vec2i& infi_mouse_buffer_t::position() const {
		return _position;
	}
	const core::vec2i& infi_mouse_buffer_t::deltaPosition() const {
		return _deltap;
	}
	const core::vec2i& infi_mouse_buffer_t::wheel() const {
		return _wheel;
	}
	const core::vec2i& infi_mouse_buffer_t::deltaWheel() const {
		return _deltaw;
	}

	Time::Point infi_mouse_buffer_t::positionTime() const {
		return _pos_time;
	}
	Time::Point infi_mouse_buffer_t::enterTime() const {
		return _enter_time;
	}
	Time::Point infi_mouse_buffer_t::leaveTime() const {
		return _leave_time;
	}
	Time::Point infi_mouse_buffer_t::wheelTime() const {
		return _wheel_time;
	}

	infi_mouse_t::infi_mouse_t( uint32 sz ) :
		_front( new infi_mouse_buffer_t(sz) ),
		_back( new infi_mouse_buffer_t(sz) ) { ; }

	infi_mouse_t::~infi_mouse_t() {
		delete _front;
		delete _back;
	}

	void infi_mouse_t::__swap() {
		infi_mouse_buffer_t* m = _front;
		_front = _back.load();
		_back = m;
	}

	void infi_mouse_t::push( infi_window_t* w ) {
		Time::Point n = Time::Now();
		(*_back).push_enter( w, n );
		__swap();
		(*_back).push_enter( w, n );
	}
	void infi_mouse_t::pop( infi_window_t* w ) {
		Time::Point n = Time::Now();
		(*_back).push_leave( w, n );
		__swap();
		(*_back).push_leave( w, n );
	}

	void infi_mouse_t::push( core::vec2i pos, core::vec2i rel ) {
		Time::Point n = Time::Now();
		(*_back).push_move( pos, rel, n );
		__swap();
		(*_back).push_move( pos, rel, n );
	}
	void infi_mouse_t::push( core::vec2i rel ) {
		Time::Point n = Time::Now();
		(*_back).push_wheel( rel, n );
		__swap();
		(*_back).push_wheel( rel, n );
	}

	void infi_mouse_t::push( uint32 b ) {
		Time::Point n = Time::Now();
		(*_back).push( b, n );
		__swap();
		(*_back).push( b, n );
	}
	void infi_mouse_t::pop( uint32 b ) {
		Time::Point n = Time::Now();
		(*_back).pop( b, n );
		__swap();
		(*_back).pop( b, n );
	}

	bool infi_mouse_t::operator[] ( uint32 i ) const {
		return (*_front)[i];
	}
	bool infi_mouse_t::pressed( uint32 i, float64 dt ) const {
		Time::Frame t = Time::Now() - (*_front).pressed(i);
		return ( t.count() <= dt );
	}
	bool infi_mouse_t::released( uint32 i, float64 dt ) const {
		Time::Frame t = Time::Now() - (*_front).released(i);
		return ( t.count() <= dt );
	}

	core::vec2i infi_mouse_t::position() const {
		return (*_front).position();
	}
	core::vec2i infi_mouse_t::deltaPosition( Time::Point ) const {
		return (*_front).deltaPosition();
	}

	core::vec2i infi_mouse_t::wheel() const {
		return (*_front).wheel();
	}
	core::vec2i infi_mouse_t::deltaWheel( Time::Point ) const {
		return (*_front).deltaWheel();
	}

	infi_window_t* infi_mouse_t::window() const {
		return (*_front).window();
	}
	bool infi_mouse_t::inside() const {
		return (*_front).inside();
	}
}
