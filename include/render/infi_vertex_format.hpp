#ifndef __INFI_VERTEX_FORMAT_HPP__
#define __INFI_VERTEX_FORMAT_HPP__

#include <vector>

#include "base/types.hpp"
#include "render/infi_render_defs.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/gl/infi_gl_context.hpp"

namespace Infinity {
namespace Render {

	struct infi_vertex_format_t {

	struct attribute {
		uint32 bind_point;
		ShaderAttribType type;
		uint32 count;
	};
	struct formatted_attrib {
		uint32 bind_point;
		AttribType type;
		uint32 count;
		uint32 size;
	};

	private:
		struct __bind_format__ : public infi_gl_typed_function_t<infi_vertex_format_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_vertex_format_t*&) const;
		};

		std::vector<formatted_attrib> _attributes;
		uint32 _size;
		__bind_format__ _bind;

	public:
		struct DEFINE_EXPORT Bind {
		private:
			infi_renderer_t& _renderer;
			infi_vertex_format_t& _vf;
		public:
			Bind(infi_renderer_t&, infi_vertex_format_t&);
			~Bind();
		};

		infi_vertex_format_t();
		infi_vertex_format_t(std::initializer_list<attribute>);
		infi_vertex_format_t(const std::vector<attribute>&);

		const formatted_attrib& operator[](uint32) const;
		uint32 attributeCount() const;
		uint32 byteSize() const;

		operator infi_vertex_array_bindings_t() const;
		void fillArrayBindings(infi_vertex_array_bindings_t&) const;
	};

} }

#endif//__INFI_VERTEX_FORMAT_HPP__/
