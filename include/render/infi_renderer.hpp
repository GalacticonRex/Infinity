#ifndef __INFI_RENDERER_HPP__
#define __INFI_RENDERER_HPP__

#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_queue.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/gl/infi_gl_shared.hpp"
#include "render/gl/infi_gl_context.hpp"
#include "render/infi_render_defs.hpp"
#include "modules/infi_module_defs.hpp"	
#include "modules/infi_dispatcher.hpp"
#include "render/module/infi_render_module.hpp"

namespace Infinity {
namespace Render {

	struct infi_renderer_t {
	private:
		struct __draw_call__ {
			DrawMode mode;
			uint32 initial;
			uint32 count;
		};

	public:
		struct MakeCurrentContext : public infi_gl_typed_function_t<infi_window_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_window_t*&) const;
		};
		struct SwapContext : public infi_gl_typed_function_t<infi_window_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_window_t*&) const;
		};
		struct ClearScreen : public infi_gl_typed_function_t<core::rgba_t> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, core::rgba_t&) const;
		};

		struct DrawArrays : public infi_gl_typed_function_t<__draw_call__> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __draw_call__&) const;
		};

		infi_renderer_t(infi_gl_shared_t&, infi_gl_context_access_t&, infi_render_module_t::draw&);

		void setContext(infi_window_t*);
		void swapContext(infi_window_t*);
		void clearScreen(const core::rgba_t&);

		void drawArrays(DrawMode, uint32, uint32=0);

		uint32 createTexture();
		void destroyTexture(uint32);
		void pushTexture(uint32, uint32=0);
		uint32 popTexture(uint32=0);

		uint32 createProgram();
		void destroyProgram(uint32);
		void pushProgram(uint32);
		uint32 popProgram();

		uint32 createBuffer(BufferBindPoint);
		void destroyBuffer(uint32);
		void pushBuffer(uint32);
		void pushBuffer(uint32, BufferBindPoint);
		uint32 popBuffer(BufferBindPoint);

		void pushVertexFormat();
		void enableVertexAttrib(uint32);
		void popVertexFormat();

		uint32 createFramebuffer();
		void destroyFramebuffer(uint32);
		void pushFramebuffer(uint32);
		uint32 popFramebuffer();
		void attachToFramebuffer(uint32, uint32, uint32=0, uint32=0);

		uint32 createVertexArray();
		void destroyVertexArray(uint32);
		void pushVertexArray(uint32);
		uint32 popVertexArray();
		
		void arrayBufferToVertexArray(uint32 vao, uint32 buf);
		void indexBufferToVertexArray(uint32 vao, uint32 buf);
		void enableVertexArray(uint32 vao, uint32 index, uint32 count, uint32 type, uint32 offset);
		void disableVertexArray(uint32 vao, uint32 index);

		void pushBlendFunction(const infi_blend_function_bindings_t&);
		void popBlendFunction();

		void pushBlendEquation(const infi_blend_equation_bindings_t&);
		void popBlendEquation();

		infi_default_queue_t& state();
		
		void command(infi_render_module_t::Function);
		
		template<typename T>
		void command(infi_gl_typed_function_t<T>& f, const T& st) {
			f.push(this -> state(), st);
			this -> command(f);
		}

		void operator() (infi_render_module_t::Function);

		void flush();

	private:
		infi_gl_queue_t _queue;

		infi_gl_shared_t& _shared;
		infi_gl_context_access_t& _contexts;
		infi_render_module_t::draw& _draw;

		MakeCurrentContext _make_current_context;
		SwapContext _swap_context;
		ClearScreen _clear_screen;

		DrawArrays _draw_arrays;
	};

} }

#endif//__INFI_RENDERER_HPP__