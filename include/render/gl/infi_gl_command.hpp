#ifndef __INFI_GL_COMMAND_H__
#define __INFI_GL_COMMAND_H__

#include <mutex>
#include <condition_variable>
#include <atomic>
#include "base/error_log.hpp"
#include "threads/infi_generic_queue.hpp"
#include "render/gl/infi_gl_defs.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {
namespace Render {

struct infi_gl_command_t {
	virtual void operator()(const infi_gl_t&, infi_gl_context_controller_t&, infi_default_queue_t&) const = 0;
};

struct infi_gl_function_t : infi_gl_command_t {
	virtual bool compatible(const infi_gl_t&) const = 0;
};

struct infi_gl_selector_t : infi_gl_command_t {
private:
	infi_gl_function_t* _use;
protected:
	virtual infi_gl_function_t* select(const infi_gl_t& gl) { return NULL; }
public:
	infi_gl_selector_t(const infi_gl_t& gl) :
		_use(select(gl)) {
		if ( _use == NULL ) {
			//Error::define_scope __scope__("infi_gl_selector_t.ctor");
			Error::send<Error::Fatality::Fatal>(
				Error::Type::Graphics,
				"Could not find generate GL operation with this version"
			);
		}
	}
	void operator() (const infi_gl_t& gl, infi_gl_context_controller_t& ctrl, infi_default_queue_t& data) {
		(*_use)(gl, ctrl, data);
	}
};

template<typename T>
struct infi_gl_typed_function_t : infi_gl_function_t {
	void push(infi_default_queue_t& state, const T& data) const {
		infi_default_queue_t::push<T> p(state, data);
	}
	T& get(infi_default_queue_t& state) const {
		return infi_default_queue_t::get<T>(state);
	}
	void pop(infi_default_queue_t& state) const {
		infi_default_queue_t::pop<T> p(state);
	}
	
	virtual void run(const infi_gl_t&, infi_gl_context_controller_t&, T&) const = 0;
	void operator()(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_default_queue_t& q) const {
		run(gl, ctx, this -> get(q));
		this -> pop(q);
	}
};

template<>
struct infi_gl_typed_function_t<void> : infi_gl_function_t {
	virtual void run(const infi_gl_t&, infi_gl_context_controller_t&) const = 0;
	void operator()(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_default_queue_t& q) const {
		run(gl, ctx);
	}
};

} }

#endif//__INFI_GL_COMMAND_H__
