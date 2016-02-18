#include "render/infi_gl_enabled.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_extensions.h"

namespace INFI {
namespace render {
	
	#define CHECK_GL_ENABLED( name1, name2 ) \
			if ( InfiGLIsEnabled( GL_ ## name2 ) ) \
				name1->data |= INFI_ ## name2;

	void InfiGLSyncEnabled( infi_gl_enabled_t* out ) {
		out->data = 0;
		
		CHECK_GL_ENABLED( out, BLEND );
		CHECK_GL_ENABLED( out, COLOR_LOGIC_OP );
		CHECK_GL_ENABLED( out, CULL_FACE );
		CHECK_GL_ENABLED( out, DEPTH_CLAMP );
		if ( GL.debug_output() ) {
			CHECK_GL_ENABLED( out, DEBUG_OUTPUT );
			CHECK_GL_ENABLED( out, DEBUG_OUTPUT_SYNCHRONOUS );
		}
		CHECK_GL_ENABLED( out, DEPTH_TEST );
		CHECK_GL_ENABLED( out, DITHER );
		CHECK_GL_ENABLED( out, FRAMEBUFFER_SRGB );
		CHECK_GL_ENABLED( out, LINE_SMOOTH );
		CHECK_GL_ENABLED( out, POLYGON_SMOOTH );
		CHECK_GL_ENABLED( out, POLYGON_OFFSET_FILL );
		CHECK_GL_ENABLED( out, POLYGON_OFFSET_LINE );
		CHECK_GL_ENABLED( out, POLYGON_OFFSET_POINT );
		CHECK_GL_ENABLED( out, PROGRAM_POINT_SIZE );
		CHECK_GL_ENABLED( out, PRIMITIVE_RESTART );
		if ( GL.multisample() ) {
			CHECK_GL_ENABLED( out, MULTISAMPLE );
			CHECK_GL_ENABLED( out, SAMPLE_ALPHA_TO_COVERAGE );
			CHECK_GL_ENABLED( out, SAMPLE_ALPHA_TO_ONE );
			CHECK_GL_ENABLED( out, SAMPLE_COVERAGE );
			CHECK_GL_ENABLED( out, SAMPLE_MASK );
		}
		CHECK_GL_ENABLED( out, SCISSOR_TEST );
		CHECK_GL_ENABLED( out, STENCIL_TEST );
		CHECK_GL_ENABLED( out, TEXTURE_CUBE_MAP_SEAMLESS );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE0 );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE1 );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE2 );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE3 );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE4 );
		CHECK_GL_ENABLED( out, CLIP_DISTANCE5 );
	}

} }