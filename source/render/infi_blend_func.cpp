#include "render/objects/basic/infi_blend_func.hpp"
#include "render/infi_renderer.hpp"

namespace Infinity {
namespace Render {

	infi_blend_func_t::Bind::Bind(infi_renderer_t& r, infi_blend_func_t& f) :
		_renderer(r) {
		_renderer.pushBlendFunction(f);
		_renderer.pushBlendEquation(f);
	}
	infi_blend_func_t::Bind::~Bind() {
		_renderer.popBlendEquation();
		_renderer.popBlendFunction();
	}

	infi_blend_func_t::infi_blend_func_t() {
		alpha.src = GL_ONE;
		alpha.dst = GL_ZERO;

		color.src = GL_ONE;
		color.dst = GL_ZERO;

		alpha.mode = GL_FUNC_ADD;
		color.mode = GL_FUNC_ADD;
	}

	void infi_blend_func_t::function(uint32 s, uint32 d) {
		alpha.src = color.src = s;
		alpha.dst = color.dst = d;
	}
	void infi_blend_func_t::function(uint32 sc, uint32 dc, uint32 sa, uint32 da) {
		alpha.src = sa;
		color.src = sc;
		alpha.dst = da;
		color.dst = dc;
	}
	void infi_blend_func_t::equation(uint32 m) {
		alpha.mode = color.mode = m;
	}
	void infi_blend_func_t::equation(uint32 mc, uint32 ma) {
		alpha.mode = ma;
		color.mode = mc;
	}

	infi_blend_func_t::operator infi_blend_function_bindings_t() const {
		infi_blend_function_bindings_t b;
		bool alpha_only = (alpha.src == color.src && alpha.dst == color.dst);
		b.functionAlpha(alpha.src, alpha.dst);
		if ( !alpha_only ) {
			b.blendSeparate();
			b.functionColor(color.src, color.dst);
		}
		return b;
	}
	infi_blend_func_t::operator infi_blend_equation_bindings_t() const {
		infi_blend_equation_bindings_t b;
		bool alpha_only = (alpha.mode == color.mode);
		b.equationAlpha(alpha.mode);
		if ( !alpha_only ) {
			b.blendSeparate();
			b.equationColor(color.mode);
		}
		return b;
	}

} }