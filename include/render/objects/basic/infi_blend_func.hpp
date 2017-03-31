#ifndef __INFI_BLEND_FUNCTION_HPP__
#define __INFI_BLEND_FUNCTION_HPP__

#include "render/gl/infi_gl_context.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {
namespace Render {

	struct infi_blend_func_t {
	public:
		struct DEFINE_EXPORT Bind {
		private:
			infi_renderer_t& _renderer;
		public:
			Bind(infi_renderer_t&, infi_blend_func_t&);
			~Bind();
		};

		struct {
			uint32 src;
			uint32 dst;
			uint32 mode;
		} alpha, color;

		infi_blend_func_t();

		void function(uint32, uint32);
		void function(uint32, uint32, uint32, uint32);
		void equation(uint32);
		void equation(uint32, uint32);

		operator infi_blend_function_bindings_t() const;
		operator infi_blend_equation_bindings_t() const;
	};

} }

#endif//__INFI_BLEND_FUNCTION_HPP__