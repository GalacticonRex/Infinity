#ifndef __INFI_GL_CONTEXT_H__
#define __INFI_GL_CONTEXT_H__

#include <unordered_map>

#include "render/gl/infi_gl_defs.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_shared.hpp"
#include "threads/infi_typed_allocator.hpp"

namespace Infinity {
namespace Render {

	struct infi_framebuffer_bindings_t {
		struct __binding__ {
			uint32 handle;
			uint32 type;
			__binding__() :
				handle(0), type(0) { ; }
		};

		uint32 handle;
		uint32 hash_value;
		std::vector<__binding__> bindings;

		infi_framebuffer_bindings_t();

		uint32 generateHash() const;
		void set(uint32, uint32, uint32);

		void synchronizeTo(const infi_gl_t&, infi_gl_shared_t&, infi_framebuffer_bindings_t&);
	};
	struct infi_vertex_array_bindings_t {
		struct __binding__ {
			bool enabled;
			uint32 count;
			uint32 type;
			uint32 offset;
			__binding__() :
				enabled(false),
				count(0),
				type(0),
				offset(0) { ; }
		};

		uint32 handle;
		uint32 array_buffer_handle;
		uint32 index_buffer_handle;
		uint32 vertex_size;
		uint32 hash_value;
		std::vector<__binding__> bindings;

		infi_vertex_array_bindings_t();

		uint32 generateHash() const;
		
		void vertexSize(uint32);
		void set(uint32, uint32, uint32, uint32);
		void unset(uint32);

		void synchronizeTo(const infi_gl_t&, infi_gl_shared_t&, infi_vertex_array_bindings_t&);
	};
	struct infi_transform_feeback_bindings_t {
		uint32 handle;
		uint32 hash_value;
	};

	struct infi_blend_function_bindings_t {
	private:
		bool __sync_func(const infi_gl_t&, infi_blend_function_bindings_t&);

	public:
		bool alpha_only;

		uint32 source_alpha;
		uint32 destination_alpha;

		uint32 source_color;
		uint32 destination_color;

		infi_blend_function_bindings_t();

		void blendAlphaOnly();
		void blendSeparate();
		
		void functionAlpha(uint32, uint32);
		void functionColor(uint32, uint32);

		bool synchronizeTo(const infi_gl_t&, infi_blend_function_bindings_t&);
	};

	struct infi_blend_equation_bindings_t {
	private:
		bool __sync_mode(const infi_gl_t&, infi_blend_equation_bindings_t&);

	public:
		bool alpha_only;

		uint32 mode_alpha;
		uint32 mode_color;

		infi_blend_equation_bindings_t();

		void blendAlphaOnly();
		void blendSeparate();

		void equationAlpha(uint32);
		void equationColor(uint32);

		bool synchronizeTo(const infi_gl_t&, infi_blend_equation_bindings_t&);
	};

	struct infi_gl_context_t {
	private:
		typedef infi_framebuffer_bindings_t* fbo_ptr;
		typedef infi_vertex_array_bindings_t* vao_ptr;
		typedef infi_transform_feeback_bindings_t* tfo_ptr;

		infi_gl_context_access_t& _controller;

		std::unordered_map<uint32,fbo_ptr> _framebuffers;
		std::unordered_map<uint32,vao_ptr> _vertex_arrays;
		std::unordered_map<uint32,tfo_ptr> _transform_feedback;

		infi_blend_function_bindings_t _blend_function;
		infi_blend_equation_bindings_t _blend_equation;

	public:
		infi_gl_context_t( const infi_gl_t&, infi_gl_context_access_t& );

		infi_framebuffer_bindings_t& framebuffer(uint32);
		infi_vertex_array_bindings_t& vertexArray(uint32);
		infi_transform_feeback_bindings_t& transformFeedback(uint32);

		const infi_framebuffer_bindings_t& framebuffer(uint32) const;
		const infi_vertex_array_bindings_t& vertexArray(uint32) const;
		const infi_transform_feeback_bindings_t& transformFeedback(uint32) const;

		infi_blend_function_bindings_t& blendFunction();
		const infi_blend_function_bindings_t& blendFunction() const;

		infi_blend_equation_bindings_t& blendEquation();
		const infi_blend_equation_bindings_t& blendEquation() const;
	};

} }

#endif//__INFI_GL_CONTEXT_H__
