#include "components/infi_renderable.hpp"
#include "components/infi_window.hpp"

namespace Infinity {

	const uint32 ACTIVE_MASK = 0x1;
	const uint32 VISIBLE_MASK = 0x2;
	const uint32 RED_BLACK_MASK = 0x80000000;

	infi_renderable_t::infi_renderable_t( const std::string& str )
		: _name( str ), _parent(NULL), _zpos(0), _flags( ACTIVE_MASK | VISIBLE_MASK ) { }
	infi_renderable_t::~infi_renderable_t() {

	}
	
	const std::string& infi_renderable_t::getName() const {
		return _name;
	}

	infi_window_t& infi_renderable_t::parent() {
		return *_parent;
	}
	const infi_window_t& infi_renderable_t::parent() const {
		return *_parent;
	}
	void infi_renderable_t::parent( infi_window_t& win ) {
		if ( _parent != NULL )
			(*_parent).unRenderWith(this);
		_parent = &win;
	}

	uint32 infi_renderable_t::depth() const {
		return _zpos;
	}
	void infi_renderable_t::depth( uint32 nd) {
		_zpos = nd;
		if ( _parent != NULL ) {
			(*_parent).unRenderWith(this);
			(*_parent).renderWith(this);
		}
	}

	bool infi_renderable_t::isActive() const { return ( _flags & ACTIVE_MASK ) != 0; }
	bool infi_renderable_t::isVisible() const { return ( _flags & VISIBLE_MASK ) != 0; }

	void infi_renderable_t::active( bool a ) {
		( a ) ? _flags |= ACTIVE_MASK :
				_flags &= ~ACTIVE_MASK;
	}
	void infi_renderable_t::visible( bool v ) {
		( v ) ? _flags |= VISIBLE_MASK :
				_flags &= ~VISIBLE_MASK;
	}
}
