#ifndef __INFI_OBJECT_DUMP_H__
#define __INFI_OBJECT_DUMP_H__

#include "core/infi_queue.h"
#include "main/infi_structs.h"

namespace INFI {
namespace render {

INFI_FUNCTION( void, infi_dump_vertex_array, ( infi_window_t*, uint32 ) ); 
INFI_FUNCTION( void, infi_dump_framebuffer, ( infi_window_t*, uint32 ) );
	
struct infi_object_dump_t {
	core::queue_t<uint32> vertexarrays;
	core::queue_t<uint32> framebuffers;
	
	void add_vertex_array( uint32 );
	void add_framebuffer( uint32 );
	void dump();
};

} }

#endif//__INFI_OBJECT_DUMP_H__