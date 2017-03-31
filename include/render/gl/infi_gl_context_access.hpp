#ifndef __INFI_GL_CONTEXT_ACCESS_HPP__
#define __INFI_GL_CONTEXT_ACCESS_HPP__

#include <vector>
#include <unordered_map>

#include "threads/infi_typed_allocator.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/gl/infi_gl_context.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_context_access_t {
	private:
		typedef infi_framebuffer_bindings_t* fbo_ptr;
		typedef infi_vertex_array_bindings_t* vao_ptr;
		typedef infi_transform_feeback_bindings_t* tfo_ptr;

		struct __sync_framebuffer__ : public infi_gl_typed_function_t<fbo_ptr> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, fbo_ptr&) const;
		};
		struct __bind_framebuffer__ : public infi_gl_typed_function_t<fbo_ptr> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, fbo_ptr&) const;
		};

		struct __sync_vertex_array__ : public infi_gl_typed_function_t<vao_ptr> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, vao_ptr&) const;
		};
		struct __bind_vertex_array__ : public infi_gl_typed_function_t<vao_ptr> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, vao_ptr&) const;
		};

		struct __sync_blend_func__ : public infi_gl_typed_function_t<infi_blend_function_bindings_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_blend_function_bindings_t*&) const;
		};

		struct __sync_blend_eq__ : public infi_gl_typed_function_t<infi_blend_equation_bindings_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_blend_equation_bindings_t*&) const;
		};

		struct __framebuffer_stack__ {
			
			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::vector<uint32> element; 

			std::unordered_map<uint32, fbo_ptr> bindings;
			infi_typed_allocator_t<infi_framebuffer_bindings_t, 1024> alloc;

			__bind_framebuffer__ bind;
			__sync_framebuffer__ sync;

		} _framebuffers;

		struct __vertex_array_stack__ {
			
			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::vector<uint32> element; 

			std::unordered_map<uint32, vao_ptr> bindings;
			infi_typed_allocator_t<infi_vertex_array_bindings_t, 1024> alloc;

			__bind_vertex_array__ bind;
			__sync_vertex_array__ sync;

			vao_ptr	operator[](uint32);

		} _vertex_arrays;

		struct __transform_feedback_stack__ {
			
			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::vector<uint32> element; 

			std::unordered_map<uint32, tfo_ptr> bindings;
			infi_typed_allocator_t<infi_transform_feeback_bindings_t, 1024> alloc;

		} _transform_feedback;

		struct __blend_function_stack__ {
			
			std::mutex lock;
			infi_blend_function_bindings_t root;
			std::stack<infi_blend_function_bindings_t> bindings;

			__sync_blend_func__ sync;

		} _blend_function;

		struct __blend_equation_stack__ {
			
			std::mutex lock;
			infi_blend_equation_bindings_t root;
			std::stack<infi_blend_equation_bindings_t> bindings;

			__sync_blend_eq__ sync;

		} _blend_equation;

		infi_gl_context_controller_t* _context;

	public:

		infi_gl_context_access_t();

		void setContextController(infi_gl_context_controller_t&);
		infi_gl_context_t& current();

		infi_framebuffer_bindings_t& allocFramebuffer();
		infi_vertex_array_bindings_t& allocVertexArray();
		infi_transform_feeback_bindings_t& allocTransformFeedback();

		void deallocFramebuffer(infi_framebuffer_bindings_t&);
		void deallocVertexArray(infi_vertex_array_bindings_t&);
		void deallocTransformFeedback(infi_transform_feeback_bindings_t&);

		uint32 framebuffer(uint32) const;
		uint32 vertexArray(uint32) const;
		uint32 transformFeedback(uint32) const;
		
		// Framebuffers
		uint32 createFramebuffer();
		void destroyFramebuffer(uint32);
		void attachToFramebuffer(uint32 fbo, uint32 tex, uint32 bindpt=0, uint32 type=0);
		
		void pushFramebuffer(infi_gl_queue_t&, uint32);
		uint32 popFramebuffer(infi_gl_queue_t&);

		void pushFramebuffer(const infi_gl_t&, uint32);
		uint32 popFramebuffer(const infi_gl_t&);
 	
		void synchronizeFramebuffer(infi_gl_queue_t&);
		void synchronizeFramebuffer(const infi_gl_t&);

		// Vertex Arrays
		uint32 createVertexArray();
		void destroyVertexArray(uint32);

		void arrayBufferToVertexArray(uint32 vao, uint32 buf);
		void indexBufferToVertexArray(uint32 vao, uint32 buf);
		void vertexSizeToVertexArray(uint32 vao, uint32 size);
		void enableVertexArray(uint32 vao, uint32 index, uint32 count, uint32 type, uint32 offset);
		void disableVertexArray(uint32 vao, uint32 index);
		
		void pushVertexArray(infi_gl_queue_t&, uint32);
		uint32 popVertexArray(infi_gl_queue_t&);

		void pushVertexArray(const infi_gl_t&, uint32);
		uint32 popVertexArray(const infi_gl_t&);

		void synchronizeVertexArray(infi_gl_queue_t&);
		void synchronizeVertexArray(const infi_gl_t&);

		// Blend Functions/Equations
		void pushBlendFunction(infi_gl_queue_t&, const infi_blend_function_bindings_t&);
		void popBlendFunction(infi_gl_queue_t&);

		void pushBlendFunction(const infi_gl_t&, const infi_blend_function_bindings_t&);
		void popBlendFunction(const infi_gl_t&);
		
		void pushBlendEquation(infi_gl_queue_t&, const infi_blend_equation_bindings_t&);
		void popBlendEquation(infi_gl_queue_t&);

		void pushBlendEquation(const infi_gl_t&, const infi_blend_equation_bindings_t&);
		void popBlendEquation(const infi_gl_t&);

		// Stencil Functions
		
	};

} }

#endif//__INFI_GL_CONTEXT_ACCESS_HPP__