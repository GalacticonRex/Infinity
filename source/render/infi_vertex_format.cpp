#include "render/objects/basic/infi_vertex_format.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"
#include "render/gl/infi_gl_version.hpp"
#include "render/infi_renderer.hpp"

namespace Infinity {
namespace Render {

	bool infi_vertex_format_t::__bind_format__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_vertex_format_t::__bind_format__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_vertex_format_t*& ptr) const {
		infi_vertex_format_t& format = *ptr;

		std::size_t offset = 0;
		ctx.shared.pushVertexFormat(gl);
		for ( uint32 i=0;i<format._attributes.size();i++ ) {
			const formatted_attrib& a = format._attributes[i];
			ctx.shared.enableVertexAttrib(gl, a.bind_point);
			gl.VertexAttribPointer( a.bind_point, a.count, a.type, false, format._size, (void*)offset );
    		offset += a.size;
		}
	}

	infi_vertex_format_t::Bind::Bind(infi_renderer_t& r, infi_vertex_format_t& vf) :
		_renderer(r), _vf(vf) {
		_vf._bind.push(_renderer.state(), &_vf);
		_renderer(_vf._bind);
	}
	infi_vertex_format_t::Bind::~Bind() {
		_renderer.popVertexFormat();
	}

	infi_vertex_format_t::infi_vertex_format_t() : _size(0) { ; }
	infi_vertex_format_t::infi_vertex_format_t(std::initializer_list<attribute> il) :
		_size(0) {
		std::vector<attribute> attr(il);
		_attributes.resize(attr.size());

		for ( uint32 i=0;i<attr.size();i++ ) {
			const attribute& a = attr[i];
			formatted_attrib& b = _attributes[i];

			b.bind_point = a.bind_point;
			
			b.size = a.count * infi_gl_t::sizeOf( a.type );
			_size += b.size;

			infi_gl_t::getComponents( a.type, b.type, b.count );
			b.count *= a.count;
		}
	}
	infi_vertex_format_t::infi_vertex_format_t(const std::vector<attribute>& attr) :
		_size(0) {
		_attributes.resize(attr.size());

		for ( uint32 i=0;i<attr.size();i++ ) {
			const attribute& a = attr[i];
			formatted_attrib& b = _attributes[i];

			b.bind_point = a.bind_point;
			
			b.size = a.count * infi_gl_t::sizeOf( a.type );
			_size += b.size;

			infi_gl_t::getComponents( a.type, b.type, b.count );
		}
	}

	const infi_vertex_format_t::formatted_attrib& infi_vertex_format_t::operator[](uint32 x) const {
		if ( _attributes.size() <= x ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::Index,
				"Index %d out of range (size %d)",
				x, _attributes.size()
			);
		}
		return _attributes[x];
	}
	uint32 infi_vertex_format_t::attributeCount() const {
		return _attributes.size();
	}
	uint32 infi_vertex_format_t::byteSize() const {
		return _size;
	}

	infi_vertex_format_t::operator infi_vertex_array_bindings_t() const {
		infi_vertex_array_bindings_t output;
		fillArrayBindings(output);
		return output;
	}
	void infi_vertex_format_t::fillArrayBindings(infi_vertex_array_bindings_t& output) const {
		std::size_t offset = 0;
		for (uint32 i=0;i<_attributes.size();i++ ) {
			output.set( _attributes[i].bind_point,
						_attributes[i].count,
						_attributes[i].type,
						(uint32)offset );
			offset += _attributes[i].size;
		}
		output.vertexSize(_size);
	}

	template<>
	bool infi_vertex_format_t::__matches_base<>(uint32 i) const {
		return (i==_attributes.size());
	}
	template<>
	void infi_vertex_format_t::__fill_data_base<>() { ; }

	template<>
	bool infi_vertex_format_t::__matches<float32>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 1);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec2>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 2);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec3>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 3);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec4>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 4);
	}

	template<>
	bool infi_vertex_format_t::__matches<int32>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_INT && 
				_attributes[i].count == 1);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec2i>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_INT && 
				_attributes[i].count == 2);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec3i>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_INT && 
				_attributes[i].count == 3);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec4i>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_INT && 
				_attributes[i].count == 4);
	}

	template<>
	bool infi_vertex_format_t::__matches<uint32>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_UNSIGNED_INT && 
				_attributes[i].count == 1);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec2ui>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_UNSIGNED_INT && 
				_attributes[i].count == 2);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec3ui>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_UNSIGNED_INT && 
				_attributes[i].count == 3);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::vec4ui>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_UNSIGNED_INT && 
				_attributes[i].count == 4);
	}

	template<>
	bool infi_vertex_format_t::__matches<core::mat2>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 4);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::mat3>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 9);
	}
	template<>
	bool infi_vertex_format_t::__matches<core::mat4>(uint32 i) const {
		return (_attributes[i].type == infi_gl_t::TYPE_FLOAT && 
				_attributes[i].count == 16);
	}

} }