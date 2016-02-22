#include "main/infi_renderable.h"

namespace INFI {

	const uint32 ACTIVE_MASK = 0x1;
	const uint32 VISIBLE_MASK = 0x2;
	const uint32 RED_BLACK_MASK = 0x80000000;
	
	infi_renderable_t::infi_renderable_t( uint32 z )
		: parent( NULL ), zpos( z ), flags( ACTIVE_MASK | VISIBLE_MASK ) { }
	
	bool infi_renderable_t::is_active() const { return ( flags & ACTIVE_MASK ) != 0; }
	bool infi_renderable_t::is_visible() const { return ( flags & VISIBLE_MASK ) != 0; }
	
	void infi_renderable_t::active( bool a ) {
		( a ) ? flags |= ACTIVE_MASK :
				flags &= ~ACTIVE_MASK;
	}
	void infi_renderable_t::visible( bool v ) {
		( v ) ? flags |= VISIBLE_MASK :
				flags &= ~VISIBLE_MASK;
	}
	
	bool infi_renderable_t::compare( const rb_tree_node_t* rb ) {
		const infi_renderable_t* re = dynamic_cast<const infi_renderable_t*>( rb );
		return ( zpos < re->zpos );
	}
	void infi_renderable_t::color( bool c ) {
		( c ) ? flags |= RED_BLACK_MASK :
				flags &= ~RED_BLACK_MASK;
	}
	bool infi_renderable_t::black() const {
		return flags & RED_BLACK_MASK;
	}
	bool infi_renderable_t::red() const {
		return !(flags & RED_BLACK_MASK);
	}
	
}