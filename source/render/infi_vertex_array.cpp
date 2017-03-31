#include "render/objects/basic/infi_vertex_array.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_sync_renderer.hpp"
#include "render/objects/basic/infi_buffer_object.hpp"

namespace Infinity {
namespace Render {

	infi_vertex_array_t::Modify::Modify(infi_renderer_t& r, infi_vertex_array_t& v) :
		_vertices(v), _renderer(r), _buffer_size(0), _vertex_size(0) { 
		if ( _vertices.ready() )
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"Cannot initialize vertices, object already initialized"
			);
	}

	void infi_vertex_array_t::Modify::__calculate_vertex_count() {
		if ( _buffer_size % _vertex_size ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::Type,
				"Buffer of %d bytes is not compatible with a format of %d bytes",
				_buffer_size, _vertex_size
			);
		}
		_vertices._vertex_count = _buffer_size / _vertex_size;
	}

	void infi_vertex_array_t::Modify::vertices(const infi_buffer_object_t& buffer) {
		_vertices._vertices = buffer.handle();
		_renderer.arrayBufferToVertexArray(_vertices._handle, buffer.handle());
		_buffer_size = buffer.byteSize();

		if ( _vertex_size != 0 )
			__calculate_vertex_count();
	}
	void infi_vertex_array_t::Modify::indices(const infi_buffer_object_t& buffer) {
		_vertices._indices = buffer.handle();
		_renderer.indexBufferToVertexArray(_vertices._handle, buffer.handle());

		if ( _vertex_size != 0 )
			__calculate_vertex_count();
	}

	void infi_vertex_array_t::Modify::attributes(const infi_vertex_format_t& v) {
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
		_vertex_size = _vertices.format.byteSize();
		_renderer.vertexSizeToVertexArray(_vertices._handle, _vertex_size);

		if ( _buffer_size != 0 )
			__calculate_vertex_count();
	}
	void infi_vertex_array_t::Modify::attributes(const std::vector<infi_vertex_format_t::attribute>& a) {
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
		_vertex_size = _vertices.format.byteSize();
		_renderer.vertexSizeToVertexArray(_vertices._handle, _vertex_size);

		if ( _buffer_size != 0 )
			__calculate_vertex_count();
	}

	infi_vertex_array_t::Bind::Bind(infi_renderer_t& r, infi_vertex_array_t& v) :
		_vertices(v), _renderer(r) {
		_renderer.pushVertexArray(_vertices._handle);
	}
	infi_vertex_array_t::Bind::~Bind() {
		_renderer.popVertexArray();
	}

	infi_vertex_array_t::infi_vertex_array_t() :
		infi_resource_t(0),
		_vertices(0),
		_indices(0),
		_vertex_count(0) { ; }

	infi_vertex_array_t::infi_vertex_array_t(infi_renderer_t& r) :
		infi_resource_t(r.createVertexArray()),
		_vertices(0),
		_indices(0),
		_vertex_count(0) { ; }

	void infi_vertex_array_t::create(infi_synchronized_renderer_t& r) {
		if ( _handle != 0 )
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"Vertex Object already initialized"
			);

		infi_synchronized_renderer_t::Acquire rend(r);
		_handle = rend -> createVertexArray();
	}

	bool infi_vertex_array_t::ready() const {
		return (_vertex_count != 0);
	}

	uint32 infi_vertex_array_t::vertexCount() const {
		return _vertex_count;
	}

} }