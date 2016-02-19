#ifndef __INFI_VERTEX_ARRAY_H__
#define __INFI_VERTEX_ARRAY_H__

#include "main/infi_main.h"
#include "render/infi_multi_context.h"
#include "render/infi_formatted_buffer.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiLEmptyVertexCache, () );
	
	struct infi_vertex_binding_t {
		infi_field_t field;
		const infi_buffer_t* buffer;
		struct {
			uint32 disable : 1;
			uint32 stride : 31;
		} data;
	};
	
	typedef infi_multi_context_t<infi_window_t*,
								uint32,
								infi_vertex_binding_t,
								InfiRenderWindow,
								infi_dump_vertex_array>
			VertexSwitch;
	typedef VertexSwitch::local_handle VertexHandle;
	
	struct infi_vertices_t : VertexSwitch {
		uint32				 vcount;	// vertex count
		const infi_format_t* format;	// accepted vertex format
		const infi_buffer_t* indices;	// element array buffer (assume uint32)
		core::array_t<infi_formatted_buffer_t>
							 buffers;	// an array of all the added buffers
		core::bitfield_t	 required;	// determines if a vertex attribute needs to be filled
		core::bitfield_t	 inuse;		// determines if a vertex attribute is in use
		uint32				 active;	// how many attributes are active
		
		uint32 CreateNewHandle( infi_window_t* win );
		void SyncObject( const local_handle&, uint32, const infi_vertex_binding_t& );
		
		void get_vertex_count();
	};
	
	INFI_FUNCTION( infi_vertices_t*, InfiCreateVertices, () );
	INFI_FUNCTION( infi_vertices_t*, InfiCopyVertices, ( infi_vertices_t const* ) );
	INFI_FUNCTION( void, InfiDestroyVertices, ( infi_vertices_t* ) );
	
	INFI_FUNCTION( uint32, InfiBindVertices, ( infi_vertices_t*, const infi_formatted_buffer_t& ) );
	
	INFI_FUNCTION( void, InfiSetFormat, ( infi_vertices_t*, infi_format_t const* ) );
	INFI_FUNCTION( void, InfiSetIndices, ( infi_vertices_t*, infi_buffer_t const* ) );
	
	INFI_FUNCTION( void, InfiClearVertices, ( infi_vertices_t*, infi_format_t const* ) );
	
	INFI_FUNCTION( infi_vertices_t*, InfiCurrentVertices, () );
	INFI_FUNCTION( void, InfiPushVertices, ( infi_vertices_t* ) );
	INFI_FUNCTION( void, InfiPopVertices, () );
	
} }

#endif//__INFI_VERTEX_ARRAY_H__