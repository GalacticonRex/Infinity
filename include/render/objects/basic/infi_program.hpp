#ifndef __INFI_PROGRAM_HPP__
#define __INFI_PROGRAM_HPP__

#include <utility>

#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/infi_render_async.hpp"
#include "render/objects/basic/infi_vertex_format.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_render_resource.hpp"

namespace Infinity {
namespace Render {

	struct infi_program_t : public infi_resource_t {
	private:
		struct __link_program__ : public infi_gl_typed_function_t<infi_program_t*> {
		private:
			void __check_shader(const infi_gl_t&, const char*, uint32) const;
			void __check_program(const infi_gl_t&, uint32) const;
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_program_t*&) const;
		};

		template<typename T>
		struct __data_item__ {
			infi_program_t* source;
			std::string name;
			T data;
		};
		template<typename T>
		struct __data_array__ {
			infi_program_t* source;
			std::string name;
			uint32 count;
			T* data;
		};

		struct __assign_uniform_int1__ : public infi_gl_typed_function_t< __data_item__<int32> > {
			typedef __data_item__<int32> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_int1v__ : public infi_gl_typed_function_t< __data_array__<int32> > {
			typedef __data_array__<int32> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};

		struct __assign_uniform_float1__ : public infi_gl_typed_function_t< __data_item__<float32> > {
			typedef __data_item__<float32> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_float1v__ : public infi_gl_typed_function_t< __data_array__<float32> > {
			typedef __data_array__<float32> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};

		struct __assign_uniform_float2__ : public infi_gl_typed_function_t< __data_item__<core::vec2> > {
			typedef __data_item__<core::vec2> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_float3__ : public infi_gl_typed_function_t< __data_item__<core::vec3> > {
			typedef __data_item__<core::vec3> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_float4__ : public infi_gl_typed_function_t< __data_item__<core::vec4> > {
			typedef __data_item__<core::vec4> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};

		struct __assign_uniform_float2x2__ : public infi_gl_typed_function_t< __data_item__<core::mat2> > {
			typedef __data_item__<core::mat2> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_float3x3__ : public infi_gl_typed_function_t< __data_item__<core::mat3> > {
			typedef __data_item__<core::mat3> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};
		struct __assign_uniform_float4x4__ : public infi_gl_typed_function_t< __data_item__<core::mat4> > {
			typedef __data_item__<core::mat4> data_item;
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, data_item&) const;
		};

		struct __draw_item__ {
			DrawMode mode;
			infi_buffer_object_t* buffer;
			infi_vertex_format_t* format;
		};
		struct __draw_arrays__ : public infi_gl_typed_function_t<__draw_item__> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __draw_item__&) const;
		};

		uint32 __get_uniform(const std::string&);
		uint32 __get_attribute(const std::string&);

		uint8 _linked;

		std::vector<ShaderAttribType> _uniform_types;
		std::vector<ShaderAttribType> _attrib_types;

		std::unordered_map<std::string, uint32> _uniforms;
		std::unordered_map<std::string, uint32> _attributes;

		__link_program__ _linker;

		__assign_uniform_int1__ _assign_int1;
		__assign_uniform_int1v__ _assign_int1v;

		__assign_uniform_float1__ _assign_float1;
		__assign_uniform_float1v__ _assign_float1v;

		__assign_uniform_float2__ _assign_float2;
		__assign_uniform_float3__ _assign_float3;
		__assign_uniform_float4__ _assign_float4;

		__assign_uniform_float2x2__ _assign_float2x2;
		__assign_uniform_float3x3__ _assign_float3x3;
		__assign_uniform_float4x4__ _assign_float4x4;

		__draw_arrays__ _draw_arrays;

	public:

		struct Bind;

		struct DEFINE_EXPORT assign_uniform {
		private:
			const std::string& _name;
			Bind& _program;

		public:
			assign_uniform(Bind&, const std::string&);

			void operator=(float32);
			void operator=(core::vec2);
			void operator=(core::vec3);
			void operator=(core::vec4);
		};

		struct DEFINE_EXPORT Bind {
		private:
			infi_program_t& _program;
			infi_renderer_t& _renderer;
			
		public:
			infi_vertex_format_t& format;

			Bind(infi_renderer_t&, infi_program_t&);
			~Bind();

			void uniformi(const std::string&, int32);
			void uniformiv(const std::string&, uint32, int32*);

			void uniform(const std::string&, float32);
			void uniformv(const std::string&, uint32, float32*);

			void uniform(const std::string&, const core::vec2&);
			void uniform(const std::string&, const core::vec3&);
			void uniform(const std::string&, const core::vec4&);

			void uniform(const std::string&, const core::mat2&);
			void uniform(const std::string&, const core::mat3&);
			void uniform(const std::string&, const core::mat4&);
			
			assign_uniform operator[](const std::string&);
			
			void draw(infi_buffer_object_t&);
			void draw(infi_buffer_object_t&, infi_buffer_object_t&);
		};

		infi_vertex_format_t format;

		const char* vertex;
		const char* fragment;

		infi_program_t();
		infi_program_t(infi_renderer_t&);

		void create(infi_renderer_t&);
		bool ready() const;

		infi_render_async_t link(infi_renderer_t&);
	};


} }

#endif//__INFI_PROGRAM_HPP__