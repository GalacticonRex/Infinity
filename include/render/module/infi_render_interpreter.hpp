#ifndef __INFI_RENDER_INTERPRETER_HPP__
#define __INFI_RENDER_INTERPRETER_HPP__

#include "modules/infi_module_defs.hpp"
#include "modules/infi_interpreter.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {
namespace Render {

	struct infi_render_interpreter_t : public infi_render_module_t::interpreter {
	private:
		struct __draw__ : public infi_process_message_t<infi_gl_queue_t*> {
		private:
			infi_render_interpreter_t& _src;
		public:
			__draw__(infi_render_interpreter_t&);
			void interpret(infi_gl_queue_t*&);
		};
		struct __create_context__ : public infi_process_message_t<infi_window_t*> {
		private:
			infi_render_interpreter_t& _src;
		public:
			__create_context__(infi_render_interpreter_t&);
			void interpret(infi_window_t*&);
		};
		struct __destroy_context__ : public infi_process_message_t<infi_window_t*> {
		private:
			infi_render_interpreter_t& _src;
		public:
			__destroy_context__(infi_render_interpreter_t&);
			void interpret(infi_window_t*&);
		};

		infi_root_module_t& _root;
		Render::infi_gl_t& _gl;
		Render::infi_gl_context_controller_t& _gl_ctx;
		infi_win_mngr_module_t::refresh& _refresh;

		__draw__ _draw;
		__create_context__ _create_context;
		__destroy_context__ _destroy_context;

	public:
		infi_render_interpreter_t(infi_root_module_t&,
								  Render::infi_gl_t&,
								  Render::infi_gl_context_controller_t&,
								  infi_win_mngr_module_t::refresh&);
		~infi_render_interpreter_t();

		void interpret(const infi_event_queue_t::message&);
	};

} }

#endif//__INFI_RENDER_INTERPRETER_HPP__
