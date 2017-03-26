#include "components/infi_input_events.hpp"
#include "engine/infi_root_module.hpp"

namespace Infinity {
	infi_input_events_t::__keyboard_event__::__keyboard_event__(infi_input_events_t& i, uint32 c) :
		_code(c), _source(i) { ; }

	bool infi_input_events_t::__keyboard_event__::get() const {
		return _source.getKeyboard(_code);
	}
	bool infi_input_events_t::__keyboard_event__::pressed(float64 dt) const {
		return _source.pressedKeyboard(_code, dt);
	}
	bool infi_input_events_t::__keyboard_event__::released(float64 dt) const {
		return _source.releasedKeyboard(_code, dt);
	}

	void infi_input_events_t::__keyboard_event__::Triggered(infi_trigger_t* ev, bool value, void* data) {
		if( value )
			_source.pushKeyboard( _code );
		else
			_source.popKeyboard( _code );
	}

	infi_input_events_t::__mouse_event__::__mouse_event__(infi_input_events_t& i, uint32 c) :
		_code(c), _source(i) { ; }

	bool infi_input_events_t::__mouse_event__::get() const {
		return _source.getMouse(_code);
	}
	bool infi_input_events_t::__mouse_event__::pressed(float64 dt) const {
		return _source.pressedMouse(_code, dt);
	}
	bool infi_input_events_t::__mouse_event__::released(float64 dt) const {
		return _source.releasedMouse(_code, dt);
	}

	void infi_input_events_t::__mouse_event__::Triggered(infi_trigger_t* ev, bool value, void* data) {
		if( value )
			_source.pushMouse( _code );
		else
			_source.popMouse( _code );
	}

	infi_input_events_t::__mouse_position_change__::__mouse_position_change__(infi_input_events_t& i) :
		_source( i ) { ; }

	core::vec2i infi_input_events_t::__mouse_position_change__::operator()() const {
		return (_source._local_mouse==NULL)?core::vec2i():_source._local_mouse -> position();
	}
	core::vec2i infi_input_events_t::__mouse_position_change__::delta() const {
		return (_source._local_mouse==NULL)?core::vec2i():_source._local_mouse -> deltaPosition(Time::Now());
	}

	void infi_input_events_t::__mouse_position_change__::push(const core::vec2i& p, const core::vec2i& d) {
		if ( _source._local_mouse != NULL ) {
			_source._local_mouse -> push(p,d);
			infi_trigger_t::operator() (true);
		}
	}

	infi_input_events_t::__mouse_inside_change__::__mouse_inside_change__(infi_input_events_t& i) :
		_source( i ) { ; }

	bool infi_input_events_t::__mouse_inside_change__::operator()() const {
		return (_source._local_mouse==NULL)?false:_source._local_mouse -> inside();
	}
	infi_window_t* infi_input_events_t::__mouse_inside_change__::currentWindow() const {
		return (_source._local_mouse==NULL)?NULL:_source._local_mouse -> window();
	}

	void infi_input_events_t::__mouse_inside_change__::push(bool p, infi_window_t* w) {
		if ( _source._local_mouse != NULL ) {
			if ( p )
				_source._local_mouse -> push(w);
			else
				_source._local_mouse -> pop(w);
			infi_trigger_t::operator() (p);
		}
	}

	infi_input_events_t::__mouse_wheel_change__::__mouse_wheel_change__(infi_input_events_t& ev) :
		_source(ev) { ; }

	int32 infi_input_events_t::__mouse_wheel_change__::operator()() const {
		return (_source._local_mouse==NULL)?0:_source._local_mouse -> wheel().y;
	}
	int32 infi_input_events_t::__mouse_wheel_change__::delta() const {
		return (_source._local_mouse==NULL)?0:_source._local_mouse -> deltaWheel(Time::Now()).y;
	}

	int32 infi_input_events_t::__mouse_wheel_change__::positionX() const {
		return (_source._local_mouse==NULL)?0:_source._local_mouse -> wheel().x;
	}
	int32 infi_input_events_t::__mouse_wheel_change__::deltaX() const {
		return (_source._local_mouse==NULL)?0:_source._local_mouse -> deltaWheel(Time::Now()).x;
	}

	void infi_input_events_t::__mouse_wheel_change__::push(const core::vec2i& r) {
		if ( _source._local_mouse!=NULL )
			_source._local_mouse -> push(r);
	}

	infi_input_events_t::__mouse__::__mouse__(infi_input_events_t& ev) :
		_source(ev),
		left(ev._events_mouse[mousebutton::left]),
		right(ev._events_mouse[mousebutton::right]),
		middle(ev._events_mouse[mousebutton::middle]),
		position(ev),
		wheel(ev),
		inside(ev) { ; }

	infi_input_events_t::__mouse_event__& infi_input_events_t::__mouse__::operator[](uint32 x) {
		if ( x >= mousebutton::size) {
			//Error::define_scope __scope__("Input.getEvent");
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Index,
				"Cannot get event %d from event array of size %d",
				x, mousebutton::size
			);
		}
		return _source._events_mouse[x];
	}

	infi_input_events_t::infi_input_events_t() :
		_events_keyboard( (__keyboard_event__*) operator new[]( sizeof(__keyboard_event__) * keycode::size ) ),
		_local_keyboard( NULL ),
		_events_mouse( (__mouse_event__*) operator new[]( sizeof(__mouse_event__) * mousebutton::size ) ),
		_local_mouse( NULL ),

		escape		( _events_keyboard[keycode::escape] ),
		backspace	( _events_keyboard[keycode::backspace] ),
		enter		( _events_keyboard[keycode::ret] ),
		tab			( _events_keyboard[keycode::tab] ),
		space		( _events_keyboard[keycode::space] ),
		a			( _events_keyboard[keycode::a] ),
		b			( _events_keyboard[keycode::b] ),
		c			( _events_keyboard[keycode::c] ),
		d			( _events_keyboard[keycode::d] ),
		e			( _events_keyboard[keycode::e] ),
		f			( _events_keyboard[keycode::f] ),
		g			( _events_keyboard[keycode::j] ),
		h			( _events_keyboard[keycode::h] ),
		i			( _events_keyboard[keycode::i] ),
		j			( _events_keyboard[keycode::j] ),
		k			( _events_keyboard[keycode::k] ),
		l			( _events_keyboard[keycode::l] ),
		m			( _events_keyboard[keycode::m] ),
		n			( _events_keyboard[keycode::n] ),
		o			( _events_keyboard[keycode::o] ),
		p			( _events_keyboard[keycode::p] ),
		q			( _events_keyboard[keycode::q] ),
		r			( _events_keyboard[keycode::r] ),
		s			( _events_keyboard[keycode::s] ),
		t			( _events_keyboard[keycode::t] ),
		u			( _events_keyboard[keycode::u] ),
		v			( _events_keyboard[keycode::v] ),
		w			( _events_keyboard[keycode::w] ),
		x			( _events_keyboard[keycode::x] ),
		y			( _events_keyboard[keycode::y] ),
		z			( _events_keyboard[keycode::z] ),
		zero		( _events_keyboard[keycode::zero] ),
		one			( _events_keyboard[keycode::one] ),
		two			( _events_keyboard[keycode::two] ),
		three		( _events_keyboard[keycode::three] ),
		four		( _events_keyboard[keycode::four] ),
		five		( _events_keyboard[keycode::five] ),
		six			( _events_keyboard[keycode::six] ),
		seven		( _events_keyboard[keycode::seven] ),
		eight		( _events_keyboard[keycode::eight] ),
		nine		( _events_keyboard[keycode::nine] ),

		mouse 		( *this ) {

		for( uint32 i=0;i<keycode::size;++i )
			new (_events_keyboard+i) __keyboard_event__(*this,i);
		for ( uint32 i=0;i<mousebutton::size;++i )
			new (_events_mouse+i) __mouse_event__(*this,i);

	}

	infi_input_events_t::~infi_input_events_t() {
		uint32 size;
		size = sizeof(*_events_keyboard) / sizeof(__keyboard_event__);
		for( uint32 i=0;i<size;++i )
			_events_keyboard[i].~__keyboard_event__();

		size = sizeof(*_events_mouse) / sizeof(__mouse_event__);
		for( uint32 i=0;i<size;++i )
			_events_mouse[i].~__mouse_event__();

		operator delete[]( _events_keyboard );
		operator delete[]( _events_mouse );
	}

	void infi_input_events_t::setKeyboard(infi_root_module_t& mod) {
		_local_keyboard = &(mod.getKeys());
	}
	void infi_input_events_t::setKeyboard(infi_window_t& win) {
		_local_keyboard = &(win.getKeys());
	}

	void infi_input_events_t::pushKeyboard(uint32 x) {
		if ( _local_keyboard != NULL )
			_local_keyboard->push(x);
	}
	void infi_input_events_t::popKeyboard(uint32 x) {
		if ( _local_keyboard != NULL )
			_local_keyboard->pop(x);
	}

	bool infi_input_events_t::getKeyboard(uint32 x) const {
		return ( _local_keyboard == NULL ) ? false : (*_local_keyboard)[x];
	}
	bool infi_input_events_t::pressedKeyboard(uint32 x, float64 dt) const {
		return ( _local_keyboard == NULL ) ? false : _local_keyboard->pressed(x, dt);
	}
	bool infi_input_events_t::releasedKeyboard(uint32 x, float64 dt) const {
		return ( _local_keyboard == NULL ) ? false : _local_keyboard->released(x, dt);
	}

	void infi_input_events_t::setMouse(infi_root_module_t& mod) {
		_local_mouse = &(mod.getMouse());
	}
	void infi_input_events_t::setMouse(infi_window_t& win) {
		_local_mouse = &(win.getMouse());
	}

	void infi_input_events_t::pushMouse(uint32 x) {
		if ( _local_mouse != NULL )
			_local_mouse->push(x);
	}
	void infi_input_events_t::popMouse(uint32 x) {
		if ( _local_mouse != NULL )
			_local_mouse->pop(x);
	}

	bool infi_input_events_t::getMouse(uint32 x) const {
		return ( _local_mouse == NULL ) ? false : (*_local_mouse)[x];
	}
	bool infi_input_events_t::pressedMouse(uint32 x, float64 dt) const {
		return ( _local_mouse == NULL ) ? false : _local_mouse->pressed(x, dt);
	}
	bool infi_input_events_t::releasedMouse(uint32 x, float64 dt) const {
		return ( _local_mouse == NULL ) ? false : _local_mouse->released(x, dt);
	}

	infi_input_events_t::__keyboard_event__& infi_input_events_t::operator[](uint32 x) {
		if ( x >= keycode::size) {
			//Error::define_scope __scope__("Input.getEvent");
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Index,
				"Cannot get event %d from event array of size %d",
				x, sizeof(*_events_keyboard) / sizeof(__keyboard_event__)
			);
		}
		return _events_keyboard[x];
	}
}