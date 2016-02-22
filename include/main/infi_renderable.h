#ifndef __INFI_RENDERABLE_H__
#define __INFI_RENDERABLE_H__

#include "main/infi_types.h"
#include "main/infi_extension.h"
#include "core/infi_vector.h"
#include "core/infi_rb_tree.h"

namespace INFI {
	
	struct infi_renderable_t : core::rb_tree_node_t,
							   virtual infi_extension_t {
		
		infi_renderable_t* parent;
		uint32 zpos;
		uint32 flags;
		
		infi_renderable_t( uint32 );
		virtual ~infi_renderable_t() { }
		
		// draw the internal target
		virtual void Render( const core::vec2ui& frame, float64 dt ) = 0;
		
		bool is_active() const;
		bool is_visible() const;
		
		void active( bool = true );
		void visible( bool = true );
		
		uint32 get_reference() const { return zpos; }
		bool compare( const rb_tree_node_t* );
		void color( bool );
		bool black() const;
		bool red() const;
	};
	
}

#endif//__INFI_RENDERABLE_H__