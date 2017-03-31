#ifndef __INFI_VERTEX_ARRAY_HPP__
#define __INFI_VERTEX_ARRAY_HPP__

#include "render/objects/basic/infi_vertex_format.hpp"
#include "render/infi_render_resource.hpp"

namespace Infinity {
namespace Render {

	struct infi_vertex_array_t : public infi_resource_t {
	private:
		uint32 _vertices;
		uint32 _indices;
		uint32 _vertex_count;

	public:
		struct DEFINE_EXPORT Modify {
		private:
			infi_vertex_array_t& _vertices;
			infi_renderer_t& _renderer;
			uint32 _buffer_size;
			uint32 _vertex_size;

			void __calculate_vertex_count();

		public:
			Modify(infi_renderer_t&, infi_vertex_array_t&);

			void vertices(const infi_buffer_object_t&);
			void indices(const infi_buffer_object_t&);

			void attributes(const infi_vertex_format_t&);
			void attributes(const std::vector<infi_vertex_format_t::attribute>&);
		};
		
		struct DEFINE_EXPORT Bind {
		private:
			infi_vertex_array_t& _vertices;
			infi_renderer_t& _renderer;

		public:
			Bind(infi_renderer_t&, infi_vertex_array_t&);
			~Bind();

			void draw(infi_program_t&);
		};

		infi_vertex_format_t format;

		infi_vertex_array_t();
		infi_vertex_array_t(infi_renderer_t&);

		void create(infi_synchronized_renderer_t&);
		bool ready() const;

		uint32 vertexCount() const;
	};

} }

#endif//__INFI_VERTEX_ARRAY_HPP__