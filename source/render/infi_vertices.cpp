#include "render/infi_vertices.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_sync_renderer.hpp"
#include "render/infi_buffer_object.hpp"

namespace Infinity {
namespace Render {

	infi_vertices_t::Bind::Bind(infi_renderer_t& r, infi_vertices_t& v) :
		_vertices(v), _renderer(r) {
		_renderer.pushVertexArray(_vertices._handle);
	}
	infi_vertices_t::Bind::~Bind() {
		_renderer.popVertexArray();
	}

	infi_vertices_t::infi_vertices_t() :
		_handle(0),
		_vertices(0),
		_indices(0),
		_vertex_count(0) { ; }

	infi_vertices_t::infi_vertices_t(infi_renderer_t& r) :
		_handle(r.createVertexArray()),
		_vertices(0),
		_indices(0),
		_vertex_count(0) { ; }

	void infi_vertices_t::create(infi_synchronized_renderer_t& r) {
		if ( _handle != 0 )
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"Vertex Object already initialized"
			);

		infi_synchronized_renderer_t::Acquire rend(r);
		_handle = rend -> createVertexArray();
	}

	infi_vertices_t::Modify::Modify(infi_renderer_t& r, infi_vertices_t& v) :
		_vertices(v), _renderer(r) { ; }

	void infi_vertices_t::Modify::vertices(const infi_buffer_object_t& buffer) {
		_vertices._vertices = buffer.handle();
		_renderer.arrayBufferToVertexArray(_vertices._handle, buffer.handle());
	}
	void infi_vertices_t::Modify::indices(const infi_buffer_object_t& buffer) {
		_vertices._indices = buffer.handle();
		_renderer.indexBufferToVertexArray(_vertices._handle, buffer.handle());
	}

	void infi_vertices_t::Modify::attributes(const infi_vertex_format_t& v) {
		_vertices.format = v;
		std::size_t offset = 0;
		for (uint32 i=0;i<_vertices.format.attributeCount();i++) {
			const infi_vertex_format_t::formatted_attrib& a = _vertices.format[i];
			_renderer.enableVertexArray(_vertices._handle,
										a.bind_point,
										a.count,
										a.type,
										offset);
			offset += a.size;
		}
	}
	void infi_vertices_t::Modify::attributes(const std::vector<infi_vertex_format_t::attribute>& a) {
		_vertices.format = infi_vertex_format_t(a);
		std::size_t offset = 0;
		for (uint32 i=0;i<_vertices.format.attributeCount();i++) {
			const infi_vertex_format_t::formatted_attrib& a = _vertices.format[i];
			_renderer.enableVertexArray(_vertices._handle,
										a.bind_point,
										a.count,
										a.type,
										offset);
			offset += a.size;
		}
	}

	uint32 infi_vertices_t::vertexCount() const {
		return _vertex_count;
	}

} }