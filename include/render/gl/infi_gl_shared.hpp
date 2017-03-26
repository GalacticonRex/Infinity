#ifndef __INFI_GL_EXTERNAL_HPP__
#define __INFI_GL_EXTERNAL_HPP__

#include <mutex>
#include <stack>
#include <unordered_map>

#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/gl/infi_gl_queue.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_shared_t {
	private:
		struct __buffer_type__ {
			uint32 handle;
			BufferBindPoint type;
		};

		struct __create_texture__ : public infi_gl_typed_function_t<uint32*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32*&) const;
		};
		struct __destroy_texture__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};
		struct __bind_texture__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};

		struct __create_program__ : public infi_gl_typed_function_t<uint32*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32*&) const;
		};
		struct __destroy_program__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};
		struct __bind_program__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};

		struct __create_buffer__ : public infi_gl_typed_function_t<__buffer_type__*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __buffer_type__*&) const;
		};
		struct __destroy_buffer__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};
		struct __bind_buffer__ : public infi_gl_typed_function_t<__buffer_type__> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __buffer_type__&) const;
		};

		struct __enable_vertex_attrib__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};
		struct __disable_vertex_attrib__ : public infi_gl_typed_function_t<uint32> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, uint32&) const;
		};

		struct __push_vertex_format__ : public infi_gl_typed_function_t<void> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&) const;
		};
		struct __pop_vertex_format__ : public infi_gl_typed_function_t<void> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&) const;
		};

		struct __texture_stack__ {
			typedef std::stack<uint32> element_stack;

			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::unordered_map<uint32, uint32> objects;
			std::vector<element_stack> stacks;

			__create_texture__ create;
			__destroy_texture__ destroy;
			__bind_texture__ bind;

			__texture_stack__() :
				current(0) { ; }
		} _textures;

		struct __program_stack__ {
			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::unordered_map<uint32, uint32> objects;
			std::stack<uint32> stack;

			__create_program__ create;
			__destroy_program__ destroy;
			__bind_program__ bind;

			__program_stack__() :
				current(0) { ; }
		} _programs;
		
		struct __buffer_stack__ {
			typedef std::stack<uint32> element_stack;
			
			std::mutex lock;
			uint32 current;
			std::stack<uint32> available_stack;
			std::unordered_map<uint32, __buffer_type__> objects;
			std::unordered_map<BufferBindPoint, element_stack> stacks;

			__create_buffer__ create;
			__destroy_buffer__ destroy;
			__bind_buffer__ bind;

			__buffer_stack__();
		} _buffers;

		std::mutex _vertex_lock;
		std::vector<int32> _vertex_attribs;

		void __push_vertex_format(const infi_gl_t&);
		void __pop_vertex_format(const infi_gl_t&);

		__push_vertex_format__ _push_vertex_format;
		__pop_vertex_format__ _pop_vertex_format;
		__enable_vertex_attrib__ _enable_vertex_attrib;
		__disable_vertex_attrib__ _disable_vertex_attrib;

	public:
		infi_gl_shared_t();

		void allocate_texture_units(const infi_gl_t&);

		uint32 texture(uint32);
		uint32 program(uint32);
		uint32 buffer(uint32);

		uint32 createTexture(infi_gl_queue_t&);
		void destroyTexture(infi_gl_queue_t&, uint32);
		
		void pushTexture(infi_gl_queue_t&, uint32, uint32=0);
		uint32 popTexture(infi_gl_queue_t&, uint32=0);

		void pushTexture(const infi_gl_t&, uint32, uint32=0);
		uint32 popTexture(const infi_gl_t&, uint32=0);

		uint32 createProgram(infi_gl_queue_t&);
		void destroyProgram(infi_gl_queue_t&, uint32);

		void pushProgram(infi_gl_queue_t&, uint32);
		uint32 popProgram(infi_gl_queue_t&);

		void pushProgram(const infi_gl_t&, uint32);
		uint32 popProgram(const infi_gl_t&);

		uint32 createBuffer(infi_gl_queue_t&);
		uint32 createBuffer(infi_gl_queue_t&, BufferBindPoint);
		void destroyBuffer(infi_gl_queue_t&, uint32);

		void pushBuffer(infi_gl_queue_t&, uint32);
		void pushBuffer(infi_gl_queue_t&, uint32, BufferBindPoint);
		uint32 popBuffer(infi_gl_queue_t&, BufferBindPoint);

		void pushBuffer(const infi_gl_t&, uint32);
		void pushBuffer(const infi_gl_t&, uint32, BufferBindPoint);
		uint32 popBuffer(const infi_gl_t&, BufferBindPoint);

		void pushVertexFormat(infi_gl_queue_t&);
		void enableVertexAttrib(infi_gl_queue_t&, uint32);
		void popVertexFormat(infi_gl_queue_t&);

		void pushVertexFormat(const infi_gl_t&);
		void enableVertexAttrib(const infi_gl_t&, uint32);
		void popVertexFormat(const infi_gl_t&);
	};

} }

#endif//__INFI_GL_EXTERNAL_HPP__