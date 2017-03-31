#include "render/objects/basic/infi_buffer_object.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {
namespace Render {

	void infi_buffer_object_t::__upload_data__::__realloc_buffer( const infi_gl_t& gl,
																  infi_gl_context_controller_t& ctx,
																  infi_buffer_object_t* obj,
																  uint32 new_size,
																  uint32 old_size,
																  uint32 carry_over ) {
		uint32 buffer = ctx.shared.buffer(obj -> _handle);

		uint32 id;
		gl.GenBuffers(1,&id);
		gl.BindBuffer(GL_COPY_WRITE_BUFFER, id);
		gl.BufferData(GL_COPY_WRITE_BUFFER, carry_over, NULL, GL_STREAM_COPY);

		if ( gl.extensions.require("copy_buffer") ) {
			gl.BindBuffer(GL_COPY_READ_BUFFER, buffer);
			gl.CopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, carry_over);
			gl.BufferData(GL_COPY_READ_BUFFER, new_size, NULL, obj -> _usage);
			gl.CopyBufferSubData(GL_COPY_WRITE_BUFFER, GL_COPY_READ_BUFFER, 0, 0, carry_over);
		} else {
			
		}

		gl.DeleteBuffers(1,&id);
	}

	bool infi_buffer_object_t::__upload_data__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_buffer_object_t::__upload_data__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __upload_item__& item) const {
		// buffer is not yet created
		if ( item.buffer -> _generated < 2 ) {
			gl.BufferData(
				item.bind_point,
				item.size,
				item.data,
				item.buffer -> _usage );
			item.buffer -> _generated ++ ;
		} else {
			gl.BufferSubData(
				item.bind_point,
				item.start,
				item.size,
				item.data );
		}
	}

	void infi_buffer_object_t::__upload(infi_renderer_t& r, uint32 offset, uint32 sz, uint8* data) {
		__upload_item__ u;
		u.buffer = this;
		u.bind_point = GL_COPY_WRITE_BUFFER;
		u.start = offset;
		u.size = sz;
		u.data = data;

		_size = std::max(offset + sz, _size);

		r.pushBuffer(_handle, GL_COPY_WRITE_BUFFER);

		_upload.push(r.state(), u);
		r(_upload);

		r.popBuffer(GL_COPY_WRITE_BUFFER);

		_generated ++ ;
	}

	infi_buffer_object_t::Bind::Bind(infi_renderer_t& r, infi_buffer_object_t& obj, BufferBindPoint b) :
		_buffer(obj),
		_renderer(r),
		_bind(b) {
		if ( _buffer._handle == 0 ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"cannot bind uninitialized texture!"
			);
		}
		_renderer.pushBuffer(obj._handle, b);
	}
	infi_buffer_object_t::Bind::~Bind() {
		_renderer.popBuffer(_bind);
	}

	infi_buffer_object_t::infi_buffer_object_t() :
		infi_resource_t(0),
		_generated(false),
		_usage(GL_STATIC_DRAW),
		_size(0),
		_mapping(NULL) { ; }

	infi_buffer_object_t::infi_buffer_object_t(infi_renderer_t& r, BufferBindPoint type) :
		infi_resource_t(r.createBuffer(type)),
		_generated(false),
		_usage(GL_STATIC_DRAW),
		_size(0),
		_mapping(NULL) { ; }

	void infi_buffer_object_t::create(infi_synchronized_renderer_t& renderer, BufferBindPoint b) {
		infi_synchronized_renderer_t::Acquire r(renderer);
		_handle = r -> createBuffer(b);
	}

	bool infi_buffer_object_t::ready() const {
		return (_generated == 2);
	}

	void infi_buffer_object_t::usage(Modification mod, Usage usg) {
		switch ( mod ) {
			case Modification::Stream:
				switch ( usg ) {
					case Usage::Draw:
						_usage = GL_STREAM_DRAW;
						break;
					case Usage::Read:
						_usage = GL_STREAM_READ;
						break;
					case Usage::Copy:
						_usage = GL_STREAM_COPY;
						break;
				} break;
			case Modification::Static:
				switch ( usg ) {
					case Usage::Draw:
						break;
						_usage = GL_STATIC_DRAW;
					case Usage::Read:
						break;
						_usage = GL_STATIC_READ;
					case Usage::Copy:
						_usage = GL_STATIC_COPY;
						break;
				} break;
			case Modification::Dynamic:
				switch ( usg ) {
					case Usage::Draw:
						_usage = GL_DYNAMIC_DRAW;
						break;
					case Usage::Read:
						_usage = GL_DYNAMIC_READ;
						break;
					case Usage::Copy:
						_usage = GL_DYNAMIC_COPY;
						break;
				} break;
		}
	}

	uint32 infi_buffer_object_t::handle() const {
		return _handle;
	}
	uint32 infi_buffer_object_t::byteSize() const {
		return _size;
	}

} }