#ifndef __INFINITY_H__
#define __INFINITY_H__

#include "core/convert.hpp"
#include "core/transform.hpp"

#include "components/infi_rate.hpp"
#include "components/infi_clock.hpp"
#include "components/function/infi_event_rate.hpp"

#include "engine/infi_lib_init.hpp"
#include "engine/infi_controller.hpp"

#include "render/objects/basic/infi_blend_func.hpp"
#include "render/objects/basic/infi_framebuffer.hpp"
#include "render/objects/basic/infi_program.hpp"
#include "render/objects/basic/infi_buffer_object.hpp"
#include "render/objects/basic/infi_texture.hpp"
#include "render/objects/basic/infi_vertex_format.hpp"
#include "render/objects/basic/infi_vertex_array.hpp"

#include "render/objects/intermediate/infi_vertices.hpp"

#include "render/infi_sync_renderer.hpp"

namespace Infinity {
	typedef infi_lib_init_t Library;
	typedef infi_controller_t Controller;
	typedef infi_window_t Window;
	typedef infi_renderable_t Renderable;
	typedef infi_extension_t Extension;
	
	template<typename _T>
	using Trigger = infi_event_trigger_t<_T>;

	typedef infi_threadable_t Thread;

	typedef infi_clock_t Clock;
	typedef infi_event_clock_t EventClock;

	template<typename _T,
			 typename _RateActive = core::constant<_T>,
			 typename _RateInactive = core::constant<_T>,
			 typename _Conv = _T>
	using EventRate = infi_event_rate_t<_T, _RateActive, _RateInactive, _Conv>;

	template<typename _T,
			 typename _Func,
			 typename _Rate = infi_event_clock_t,
			 typename _Conv = _T>
	using Rate = infi_rate_t<_T, _Func, _Rate, _Conv>;

	typedef Render::infi_renderer_t Renderer;
	typedef Render::infi_synchronized_renderer_t MultithreadedRenderer;
	typedef Render::infi_synchronized_renderer_t::Acquire AcquireRenderer;
	typedef Render::infi_gl_t OpenGL;

	namespace GL {
		typedef Render::infi_gl_context_controller_t ContextManager;
		typedef Render::infi_gl_queue_t Queue;

		template<typename _T>
		using Function = Render::infi_gl_typed_function_t<_T>;
	}

	typedef Render::infi_framebuffer_t Framebuffer;
	typedef Render::infi_program_t Program;
	typedef Render::infi_buffer_object_t Buffer;
	typedef Render::infi_texture_t Texture;
	typedef Render::infi_vertex_format_t VertexFormat;
	typedef Render::infi_blend_func_t Blender;
	typedef Render::infi_vertex_array_t VertexArray;

	typedef Render::infi_vertices_t Vertices;
}

#endif//__INFINITY_H__
