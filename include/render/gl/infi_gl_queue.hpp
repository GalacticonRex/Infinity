#ifndef __INFI_GL_QUEUE_HPP__
#define __INFI_GL_QUEUE_HPP__

#include <mutex>
#include <queue>

#include "threads/infi_generic_queue.hpp"
#include "components/infi_component_defs.hpp"
#include "render/module/infi_render_module.hpp"
#include "render/gl/infi_gl_defs.hpp"
#include "render/gl/infi_gl_command.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_queue_t {
	private:
		std::mutex _lock;
		std::queue<infi_render_module_t::Function> _commands;
		std::queue<uint32> _command_length;
		uint32 _running_length;
		infi_default_queue_t _state;
		
	public:
		infi_gl_queue_t();
		infi_gl_queue_t(const infi_gl_queue_t&);
		infi_gl_queue_t(infi_gl_queue_t&&);

		bool empty() const;

		infi_default_queue_t& getStateQueue();

		void push(infi_render_module_t::Function);
		void stop();
		void draw(const infi_gl_t&, infi_gl_context_controller_t&);
	};

} }

#endif//__INFI_GL_QUEUE_HPP__