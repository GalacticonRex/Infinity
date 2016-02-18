#include "render/infi_object_dump.h"
#include "render/infi_gl_wrapper.h"

namespace INFI {
namespace render {
		
void infi_object_dump_t::add_vertex_array( uint32 va ) {
	vertexarrays.push( va );
}
void infi_object_dump_t::add_framebuffer( uint32 fb ) {
	framebuffers.push( fb );
}
void infi_object_dump_t::dump() {
	std::cerr << "DUMPING NOW" << std::endl;
	InfiGLSendMessage( "Dumping OBJ" );
	if ( vertexarrays.size() == 0 ) {
		for ( uint32 i=0;i<vertexarrays.size();++i )
			InfiGLDeleteVertexArrays( 1, &(vertexarrays[i]) );
		vertexarrays.clear();
	}
	if ( framebuffers.size() == 0 ) {
		for ( uint32 i=0;i<framebuffers.size();++i )
			InfiGLDeleteFramebuffers( 1, &(framebuffers[i]) );
		framebuffers.clear();
	}
	InfiGLSendMessage( "Dumping Done" );
}

} }