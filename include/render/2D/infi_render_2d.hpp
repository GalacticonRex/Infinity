#ifndef __INFI_RENDER_2D_HPP__
#define __INFI_RENDER_2D_HPP__

#include <mutex>
#include <condition_variable>
#include <vector>
#include "core/rect.hpp"
#include "render/infi_renderer.hpp"

namespace Infinity {
namespace Render {

	struct infi_render_2d_t {
	public:
		struct generateVBORect2D : public infi_gl_function_t {
			bool compatible(const infi_gl_t&) const;
			void operator()(const infi_gl_t&, infi_gl_context_controller_t&, infi_default_queue_t&) const;
		};

		infi_render_2d_t();
		infi_render_2d_t(infi_renderer_t&);

		void setRenderer(infi_renderer_t&);

		void drawRect(const core::rectf&);
		void drawRect(float32, float32, float32, float32);

	private:
		static const char* shader_Vertex_in_Position_out_Color_u_Color;
		static const char* shader_Fragment_in_Position_out_Color_u_Color;

		struct __draw_state__ {
			uint32 program;
			uint32 vbo;
		};

		struct __draw_call__ : public infi_gl_function_t {
			bool compatible(const infi_gl_t&) const;
			void operator()(const infi_gl_t&, infi_gl_context_controller_t&, infi_default_queue_t&) const;
		};

		void __initialize(infi_renderer_t&);

		infi_renderer_t* _renderer;

		generateVBORect2D _vbo_rect_2d;
		__draw_call__ _draw_call;
	};

} }

#endif//__INFI_RENDER_2D_HPP__