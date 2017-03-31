#ifndef __INFI_VERTICES_HPP__
#define __INFI_VERTICES_HPP__

namespace Infinity {
namespace Render {

	struct infi_vertices_t {
	private:
		infi_renderer_t& _renderer;
		infi_vertex_format_t _format;
		infi_vertex_array_t _vertex_array;
		infi_buffer_object_t _geometry;
		infi_buffer_object_t _indices;

	public:
		struct Define {
		private:
			infi_vertices_t& _vertices;

		public:
			Define(infi_vertices_t&, const infi_vertex_format_t&);
			~Define();
			
		};

		infi_vertices_t(infi_renderer_t&);
	};

} }

#endif//__INFI_VERTICES_HPP__