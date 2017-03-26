#ifndef __INFI_OPENGL_EXTENSIONS_H__
#define __INFI_OPENGL_EXTENSIONS_H__

#include <unordered_map>

#include "base/structure.hpp"
#include "render/gl/infi_gl_defs.hpp"
#include "render/gl/infi_gl_version.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_info_t : does_not_copy {

		infi_gl_info_t( infi_gl_t& );

		const infi_gl_version_t version;
		const infi_gl_version_t glsl;

		bool require( const char* ) const;

		bool texture_npot() const;
		bool texture_rg() const;
		bool texture_storage() const;
		bool texture_clear() const;
		bool texture_float_store() const;
		bool texture_integer_render() const;
		bool texture_swizzle() const;
		bool texture_depth() const;
		bool texture_stencil() const;

		bool framebuffer_obj() const;
		bool framebuffer_blit() const;

		bool shader_vertex() const;
		bool shader_fragment() const;
		bool shader_geometry() const;
		bool shader_tessellation() const;
		bool shader_compute() const;
		bool shader_subroutine() const;

		bool multisample() const;
		bool pixel_buffers() const;
		bool buffer_copy() const;
		bool transform_feedback() const;
		bool transform_feedback2() const;
		bool transform_feedback3() const;
		bool draw_instanced() const;
		bool draw_elem_basev() const;
		bool timer_query() const;
		bool vertex_buffers() const;
		bool vertex_arrays() const;
		bool program_binary() const;
		bool debug_output() const;

		const std::string& vendor() const;
		const std::string& renderer() const;

		uint32 max_vertex_attribs() const;
		uint32 max_texture_units() const;
		uint32 max_color_attachments() const;

	private:

		uint32 _glext;

		std::string _glvendor;
		std::string _glrenderer;

		std::unordered_map<std::string, int> _glextensions;

		uint32 _glmax_vertex_attribs;
		uint32 _glmax_texture_units;
		uint32 _glmax_color_attachments;

	};

} }

#endif//__INFI_OPENGL_EXTENSIONS_H__
