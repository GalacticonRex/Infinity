#include "render/2D/infi_render_2d.hpp"

namespace Infinity {
namespace Render {

	const char* infi_render_2d_t::shader_Vertex_in_Position_out_Color_u_Color =
		"#version 150\n";
	const char* infi_render_2d_t::shader_Fragment_in_Position_out_Color_u_Color =
		"#version 150\n";

	bool infi_render_2d_t::generateVBORect2D::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_render_2d_t::generateVBORect2D::operator()(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_default_queue_t& state) const {

	}

	bool infi_render_2d_t::__draw_call__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_render_2d_t::__draw_call__::operator()(const infi_gl_t&, infi_gl_context_controller_t&, infi_default_queue_t&) const {

	}

	void infi_render_2d_t::__initialize(infi_renderer_t& r) {

	}

	infi_render_2d_t::infi_render_2d_t() :
		_renderer(nullptr) { ; }
	infi_render_2d_t::infi_render_2d_t(infi_renderer_t& r) :
		_renderer(&r) {
		__initialize(r);
	}

	void infi_render_2d_t::setRenderer(infi_renderer_t& r) {
		if ( _renderer == nullptr )
			__initialize(r);
		_renderer = &r;
	}

	void infi_render_2d_t::drawRect(const core::rectf& rect) {
		
	}
	void infi_render_2d_t::drawRect(float32, float32, float32, float32) {

	}

} }