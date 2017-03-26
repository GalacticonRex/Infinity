#ifndef __INFI_VERTICES_HPP__
#define __INFI_VERTICES_HPP__

#include "render/infi_vertex_format.hpp"

namespace Infinity {
namespace Render {

	struct infi_vertices_t {
	private:
		uint32 _handle;
		uint32 _vertices;
		uint32 _indices;
		uint32 _vertex_count;

	public:
		struct DEFINE_EXPORT Modify {
		private:
			infi_vertices_t& _vertices;
			infi_renderer_t& _renderer;

		public:
			Modify(infi_renderer_t&, infi_vertices_t&);

			void vertices(const infi_buffer_object_t&);
			void indices(const infi_buffer_object_t&);

			void attributes(const infi_vertex_format_t&);
			void attributes(const std::vector<infi_vertex_format_t::attribute>&);
		};
		
		struct DEFINE_EXPORT Bind {
		private:
			infi_vertices_t& _vertices;
			infi_renderer_t& _renderer;

		public:
			Bind(infi_renderer_t&, infi_vertices_t&);
			~Bind();

			void draw(infi_program_t&);
		};

		infi_vertex_format_t format;

		infi_vertices_t();
		infi_vertices_t(infi_renderer_t&);

		void create(infi_synchronized_renderer_t&);

		uint32 vertexCount() const;
	};

} }

#endif//__INFI_VERTICES_HPP__