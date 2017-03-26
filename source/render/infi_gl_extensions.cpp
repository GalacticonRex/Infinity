#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

#include "depend/infi_gl.hpp"
#include "render/gl/infi_gl_enum.hpp"
#include "render/gl/infi_gl_extensions.hpp"
#include "render/gl/infi_gl.hpp"

namespace Infinity {
namespace Render {

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

	#define CHECK_GL_EXT( ext, bit ) _glext |= (_glextensions[#ext]) ? bit : 0;

	infi_gl_info_t::infi_gl_info_t( infi_gl_t& GL ) :
		version( (const char*)GL.GetString( GL_VERSION ) ),
		glsl( version ),
		_glext( 0 ) {

		std::ofstream outputext( "opengl_ext.txt" );
		outputext << "--------------------------------------" << std::endl;

		_glvendor = (const char*)GL.GetString( GL_VENDOR );
		_glrenderer = (const char*)GL.GetString( GL_RENDERER );

		outputext << _glvendor << std::endl;
		outputext << _glrenderer << std::endl;

		outputext << "--------------------------------------" << std::endl;

		if ( version.major() < 3 ) {
			std::string allext = (const char*)GL.GetString( GL_EXTENSIONS );
			std::vector<std::string> exts;

			std::istringstream stream(allext);
			copy(	std::istream_iterator<std::string>(stream),
					std::istream_iterator<std::string>(),
					std::back_inserter(exts));

			for ( uint32 i=0;i<exts.size();i++ ) {
				std::string& working = exts[i];

				std::size_t a = working.find_first_of('_') + 1;
				working = working.substr(a, working.size() - a + 1);
				a = working.find_first_of('_') + 1;
				working = working.substr(a, working.size() - a + 1);

				outputext << working << std::endl;
				int32& ret = _glextensions[working];
				++ ret;
			}
		} else {
			int32 numext;
			GL.GetIntegerv( GL_NUM_EXTENSIONS, &numext );
			for ( int32 i=0;i<numext;i++ ) {
				std::string working = (const char*)GL.GetStringi( GL_EXTENSIONS, i );

				std::size_t a = working.find_first_of('_') + 1;
				working = working.substr(a, working.size() - a + 1);
				a = working.find_first_of('_') + 1;
				working = working.substr(a, working.size() - a + 1);

				outputext << working << std::endl;
				int32& ret = _glextensions[working];
				++ ret;
			}
		}
		outputext.close();

		GL.GetIntegerv( GL_MAX_VERTEX_ATTRIBS, (int32*) &_glmax_vertex_attribs );
		GL.GetIntegerv( GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, (int32*) &_glmax_texture_units );
		GL.GetIntegerv( GL_MAX_COLOR_ATTACHMENTS, (int32*) &_glmax_color_attachments );

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

	bool infi_gl_info_t::require( const char* ename ) const { return ( _glextensions.count(ename) != 0 ); }
	bool infi_gl_info_t::texture_npot() const 				{ return _glext & TEXTURE_NPOT; }
	bool infi_gl_info_t::texture_rg() const 				{ return _glext & TEXTURE_RG; }
	bool infi_gl_info_t::texture_storage() const 			{ return _glext & TEXTURE_STORAGE; }
	bool infi_gl_info_t::texture_clear() const 				{ return _glext & TEXTURE_CLEAR; }
	bool infi_gl_info_t::texture_float_store() const 		{ return _glext & TEXTURE_FLOAT; }
	bool infi_gl_info_t::texture_integer_render() const 	{ return _glext & TEXTURE_INTEGER; }
	bool infi_gl_info_t::texture_swizzle() const 			{ return _glext & TEXTURE_SWIZZLE; }
	bool infi_gl_info_t::texture_depth() const 				{ return _glext & TEXTURE_DEPTH; }
	bool infi_gl_info_t::texture_stencil() const 			{ return _glext & TEXTURE_STENCIL; }
	bool infi_gl_info_t::framebuffer_obj() const 			{ return _glext & FRAMEBUFFER_OBJ; }
	bool infi_gl_info_t::framebuffer_blit() const 			{ return _glext & FRAMEBUFFER_BLIT; }
	bool infi_gl_info_t::shader_vertex() const				{ return _glext & VERTEX_SHADER; }
	bool infi_gl_info_t::shader_fragment() const			{ return _glext & FRAGMENT_SHADER; }
	bool infi_gl_info_t::shader_geometry() const			{ return _glext & GEOMETRY_SHADER; }
	bool infi_gl_info_t::shader_tessellation() const		{ return _glext & TESS_SHADER; }
	bool infi_gl_info_t::shader_compute() const				{ return _glext & COMPUTE_SHADER; }
	bool infi_gl_info_t::shader_subroutine() const			{ return _glext & SHADER_SUB; }
	bool infi_gl_info_t::multisample() const 				{ return _glext & MULITSAMPLE; }
	bool infi_gl_info_t::pixel_buffers() const 				{ return _glext & PIXEL_BUFFERS; }
	bool infi_gl_info_t::buffer_copy() const 				{ return _glext & BUFFER_COPY; }
	bool infi_gl_info_t::transform_feedback() const 		{ return _glext & TRANSFORM_FEEDBACK1; }
	bool infi_gl_info_t::transform_feedback2() const 		{ return _glext & TRANSFORM_FEEDBACK2; }
	bool infi_gl_info_t::transform_feedback3() const 		{ return _glext & TRANSFORM_FEEDBACK3; }
	bool infi_gl_info_t::draw_instanced() const 			{ return _glext & DRAW_INSTANCED; }
	bool infi_gl_info_t::draw_elem_basev() const 			{ return _glext & DRAW_ELEM_BASEV; }
	bool infi_gl_info_t::timer_query() const 				{ return _glext & TIMER_QUERY; }
	bool infi_gl_info_t::vertex_buffers() const 			{ return _glext & VERTEX_BUFFERS; }
	bool infi_gl_info_t::vertex_arrays() const 				{ return _glext & VERTEX_ARRAYS; }
	bool infi_gl_info_t::program_binary() const 			{ return _glext & PROGRAM_BINARY; }
	bool infi_gl_info_t::debug_output() const 				{ return _glext & DEBUG_OUTPUT; }
	const std::string& infi_gl_info_t::vendor() const 		{ return _glvendor; }
	const std::string& infi_gl_info_t::renderer() const		{ return _glrenderer; }
	uint32 infi_gl_info_t::max_vertex_attribs() const 		{ return _glmax_vertex_attribs; }
	uint32 infi_gl_info_t::max_texture_units() const 		{ return _glmax_texture_units; }
	uint32 infi_gl_info_t::max_color_attachments() const 	{ return _glmax_color_attachments; }

	infigl_enum::infigl_enum( GLenum n ) : en( n ) { ; }
	std::ostream& operator<< ( std::ostream& ostr, infigl_enum en ) {
		InfiGLPrint( ostr, en.en );
		return ostr;
	}

} }
