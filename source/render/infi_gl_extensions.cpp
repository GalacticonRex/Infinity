#include <fstream>
#include <set>

#include "render/infi_gl_extensions.h"
#include "render/infi_gl_wrapper.h"
#include "core/infi_string.h"

namespace INFI {
namespace render {
	
	static uint32 glext = 0;
	static const char* glvendor;
	static const char* glrenderer;
	
	// GL version numbers
	static uint32 glmajor = 0; 
	static uint32 glminor = 0;
	static uint32 glpatch = 0;
	
	// GLSL version numbers
	static uint32 glslmajor = 0;
	static uint32 glslminor = 0;
	static uint32 glslpatch = 0;
	
	static uint32 glmax_vertex_attribs;
	static uint32 glmax_texture_units;
	static uint32 glmax_color_attachments;
	
	static const uint32 TEXTURE_NPOT		= 0x00000001,
						TEXTURE_RG 			= 0x00000002,
						TEXTURE_STORAGE		= 0x00000004,
						TEXTURE_CLEAR		= 0x00000008,
						TEXTURE_FLOAT		= 0x00000010,
						TEXTURE_INTEGER		= 0x00000020,
						TEXTURE_SWIZZLE		= 0x00000040,
						TEXTURE_DEPTH		= 0x00000080,
						TEXTURE_STENCIL		= 0x00000100,
						MULITSAMPLE			= 0x00000200,
						FRAMEBUFFER_OBJ		= 0x00000400,
						FRAMEBUFFER_BLIT	= 0x00000800,
						PIXEL_BUFFERS		= 0x00001000,
						BUFFER_COPY			= 0x00002000,
						TRANSFORM_FEEDBACK1	= 0x00004000,
						TRANSFORM_FEEDBACK2	= 0x00008000,
						TRANSFORM_FEEDBACK3	= 0x00010000,
						DRAW_INSTANCED		= 0x00020000,
						DRAW_ELEM_BASEV		= 0x00040000,
						TIMER_QUERY			= 0x00080000,
						VERTEX_BUFFERS		= 0x00100000,
						VERTEX_ARRAYS		= 0x00200000,
						PROGRAM_BINARY		= 0x00400000,
						DEBUG_OUTPUT		= 0x00800000,
						VERTEX_SHADER		= 0x01000000,
						FRAGMENT_SHADER		= 0x02000000,
						GEOMETRY_SHADER		= 0x04000000,
						TESS_SHADER			= 0x08000000,
						COMPUTE_SHADER		= 0x10000000,
						SHADER_SUB			= 0x20000000;
						
	#define CHECK_GL_EXT( ext, bit ) glext |= (extensions.count( #ext )) ? bit : 0;
						
	void InfiGLUpdateInfo() {
		std::ofstream outputext( "opengl_ext.txt" );
		outputext << "--------------------------------------" << std::endl;
		
		glvendor = (const char*) InfiGLGetString( GL_VENDOR );
		glrenderer = (const char*) InfiGLGetString( GL_RENDERER );
		
		outputext << glvendor << std::endl; 
		outputext << glrenderer << std::endl;
		
		core::string_t buffer;
		core::array_t<core::string_t> output;
		
		const GLubyte* ver = InfiGLGetString( GL_VERSION );
		outputext << ver << std::endl; 
		
		buffer = (const char*) ver;
		buffer.split( '.', output );
		
		glmajor = (output.size()>0) ? int32( output[0] ) : 0;
		glminor = (output.size()>1) ? int32( output[1] ) : 0;
		glpatch = (output.size()>2) ? int32( output[2] ) : 0;
		
		const GLubyte* sha = InfiGLGetString( GL_SHADING_LANGUAGE_VERSION );
		outputext << sha << std::endl; 
		
		buffer = (const char*) sha;
		buffer.split( '.', output );
		
		glslmajor = (output.size()>0) ? int32( output[0] ) : 0;
		glslminor = (output.size()>1) ? int32( output[1] ) : 0;
		glslpatch = (output.size()>2) ? int32( output[2] ) : 0;
		
		outputext << "--------------------------------------" << std::endl;
		
		int32 numext;
		InfiGLGetIntegerv( GL_NUM_EXTENSIONS, &numext );
		std::set<core::string_t> extensions;
		for ( int32 i=0;i<numext;i++ ) {
			const GLubyte* str = InfiGLGetStringi( GL_EXTENSIONS, i );
			core::string_t working = (const char*) str;
			working = working.tofront( '_' ).tofront( '_' );
			outputext << working << std::endl;
			
			extensions.insert( working );
		}
		outputext.close();
		
		InfiGLGetIntegerv( GL_MAX_VERTEX_ATTRIBS, (GLint*) &glmax_vertex_attribs );
		InfiGLGetIntegerv( GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, (GLint*) &glmax_texture_units );
		InfiGLGetIntegerv( GL_MAX_COLOR_ATTACHMENTS, (GLint*) &glmax_color_attachments );
		
		CHECK_GL_EXT( texture_non_power_of_two, TEXTURE_NPOT );
		CHECK_GL_EXT( texture_rg, TEXTURE_RG );
		CHECK_GL_EXT( texture_storage, TEXTURE_STORAGE );
		CHECK_GL_EXT( texture_clear, TEXTURE_CLEAR );
		CHECK_GL_EXT( texture_float, TEXTURE_FLOAT );
		CHECK_GL_EXT( texture_integer, TEXTURE_INTEGER );
		CHECK_GL_EXT( texture_swizzle, TEXTURE_SWIZZLE );
		CHECK_GL_EXT( depth_texture, TEXTURE_DEPTH );
		CHECK_GL_EXT( stencil_texturing, TEXTURE_STENCIL );
		CHECK_GL_EXT( multisample, MULITSAMPLE );
		CHECK_GL_EXT( framebuffer_object, FRAMEBUFFER_OBJ );
		CHECK_GL_EXT( framebuffer_blit, FRAMEBUFFER_BLIT );
		CHECK_GL_EXT( vertex_shader, VERTEX_SHADER );
		CHECK_GL_EXT( fragment_shader, FRAGMENT_SHADER );
		CHECK_GL_EXT( geometry_shader4, GEOMETRY_SHADER );
		CHECK_GL_EXT( tessellation_shader, TESS_SHADER );
		CHECK_GL_EXT( computer_shader, COMPUTE_SHADER );
		CHECK_GL_EXT( shader_subroutine, SHADER_SUB );
		CHECK_GL_EXT( pixel_buffer_object, PIXEL_BUFFERS );
		CHECK_GL_EXT( copy_buffer, BUFFER_COPY );
		CHECK_GL_EXT( transform_feedback, TRANSFORM_FEEDBACK1 );
		CHECK_GL_EXT( transform_feedback2, TRANSFORM_FEEDBACK2 );
		CHECK_GL_EXT( transform_feedback3, TRANSFORM_FEEDBACK3 );
		CHECK_GL_EXT( draw_instanced, DRAW_INSTANCED );
		CHECK_GL_EXT( draw_elements_base_vertex, DRAW_ELEM_BASEV );
		CHECK_GL_EXT( timer_query, TIMER_QUERY );
		CHECK_GL_EXT( vertex_buffer_object, VERTEX_BUFFERS );
		CHECK_GL_EXT( vertex_array_object, VERTEX_ARRAYS );
		CHECK_GL_EXT( get_program_binary, PROGRAM_BINARY );
		CHECK_GL_EXT( debug_output, DEBUG_OUTPUT );
	}
	
	const infi_gl_info_t& InfiGLGetInfo() {
		static infi_gl_info_t self;
		return self;
	}
	
	uint32 infi_gl_info_t::__version__::major() const 			{ return glmajor; }
	uint32 infi_gl_info_t::__version__::minor() const 			{ return glminor; }
	uint32 infi_gl_info_t::__version__::patch() const 			{ return glpatch; }
	uint32 infi_gl_info_t::__glsl__::major() const 				{ return glslmajor; }
	uint32 infi_gl_info_t::__glsl__::minor() const 				{ return glslmajor; }
	uint32 infi_gl_info_t::__glsl__::patch() const 				{ return glslmajor; }
	bool infi_gl_info_t::__texture__::npot() const 				{ return glext & TEXTURE_NPOT; }
	bool infi_gl_info_t::__texture__::rg() const 				{ return glext & TEXTURE_RG; }
	bool infi_gl_info_t::__texture__::storage() const 			{ return glext & TEXTURE_STORAGE; }
	bool infi_gl_info_t::__texture__::clear() const 			{ return glext & TEXTURE_CLEAR; }
	bool infi_gl_info_t::__texture__::float_store() const 		{ return glext & TEXTURE_FLOAT; }
	bool infi_gl_info_t::__texture__::integer_render() const 	{ return glext & TEXTURE_INTEGER; }
	bool infi_gl_info_t::__texture__::swizzle() const 			{ return glext & TEXTURE_SWIZZLE; }
	bool infi_gl_info_t::__texture__::depth() const 			{ return glext & TEXTURE_DEPTH; }
	bool infi_gl_info_t::__texture__::stencil() const 			{ return glext & TEXTURE_STENCIL; }
	bool infi_gl_info_t::__framebuffer__::obj() const 			{ return glext & FRAMEBUFFER_OBJ; }
	bool infi_gl_info_t::__framebuffer__::blit() const 			{ return glext & FRAMEBUFFER_BLIT; }
	bool infi_gl_info_t::__shader__::vertex() const				{ return glext & VERTEX_SHADER; }
	bool infi_gl_info_t::__shader__::fragment() const			{ return glext & FRAGMENT_SHADER; }
	bool infi_gl_info_t::__shader__::geometry() const			{ return glext & GEOMETRY_SHADER; }
	bool infi_gl_info_t::__shader__::tessellation() const		{ return glext & TESS_SHADER; }
	bool infi_gl_info_t::__shader__::compute() const			{ return glext & COMPUTE_SHADER; }
	bool infi_gl_info_t::__shader__::subroutine() const			{ return glext & SHADER_SUB; }
	bool infi_gl_info_t::multisample() const 					{ return glext & MULITSAMPLE; }
	bool infi_gl_info_t::pixel_buffers() const 					{ return glext & PIXEL_BUFFERS; }
	bool infi_gl_info_t::buffer_copy() const 					{ return glext & BUFFER_COPY; }
	bool infi_gl_info_t::transform_feedback() const 			{ return glext & TRANSFORM_FEEDBACK1; }
	bool infi_gl_info_t::transform_feedback2() const 			{ return glext & TRANSFORM_FEEDBACK2; }
	bool infi_gl_info_t::transform_feedback3() const 			{ return glext & TRANSFORM_FEEDBACK3; }
	bool infi_gl_info_t::draw_instanced() const 				{ return glext & DRAW_INSTANCED; }
	bool infi_gl_info_t::draw_elem_basev() const 				{ return glext & DRAW_ELEM_BASEV; }
	bool infi_gl_info_t::timer_query() const 					{ return glext & TIMER_QUERY; }
	bool infi_gl_info_t::vertex_buffers() const 				{ return glext & VERTEX_BUFFERS; }
	bool infi_gl_info_t::vertex_arrays() const 					{ return glext & VERTEX_ARRAYS; }
	bool infi_gl_info_t::program_binary() const 				{ return glext & PROGRAM_BINARY; }
	bool infi_gl_info_t::debug_output() const 					{ return glext & DEBUG_OUTPUT; }
	const char* infi_gl_info_t::vendor() const 					{ return glvendor; }
	const char* infi_gl_info_t::renderer() const 				{ return glrenderer; }
	uint32 infi_gl_info_t::__max__::vertex_attribs() const 		{ return glmax_vertex_attribs; }
	uint32 infi_gl_info_t::__max__::texture_units() const 		{ return glmax_texture_units; }
	uint32 infi_gl_info_t::__max__::color_attachments() const 	{ return glmax_color_attachments; }
	
	infigl_enum::infigl_enum( GLenum n ) : en( n ) { ; }
	std::ostream& operator<< ( std::ostream& ostr, infigl_enum en ) {
		InfiGLPrint( ostr, en.en );
		return ostr;
	}
	
} }