#include "render/gl/infi_gl_shared.hpp"
#include "render/gl/infi_gl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {
namespace Render {

	bool infi_gl_shared_t::__create_texture__::compatible(const infi_gl_t& gl) const {
		return true;
	}
	void infi_gl_shared_t::__create_texture__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32*& state) const {
		gl.GenTextures(1, state);
	}
	bool infi_gl_shared_t::__destroy_texture__::compatible(const infi_gl_t& gl) const {
		return true;
	}
	void infi_gl_shared_t::__destroy_texture__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& state) const {
		uint32 a = ctx.shared.texture(state);
		gl.DeleteTextures(1, &a);
	}
	bool infi_gl_shared_t::__bind_texture__::compatible(const infi_gl_t& gl) const {
		return true;
	}
	void infi_gl_shared_t::__bind_texture__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& state) const {
		gl.BindTexture(ctx.shared.texture(state));
	}

	bool infi_gl_shared_t::__create_program__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__create_program__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32*& state) const {
		*state = gl.CreateProgram();
	}
	bool infi_gl_shared_t::__destroy_program__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__destroy_program__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& state) const {
		gl.DeleteProgram(ctx.shared.program(state));
	}
	bool infi_gl_shared_t::__bind_program__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__bind_program__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& state) const {
		gl.UseProgram(ctx.shared.program(state));
	}

	bool infi_gl_shared_t::__create_buffer__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__create_buffer__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __buffer_type__*& state) const {
		gl.GenBuffers(1, &(state -> handle));
	}
	bool infi_gl_shared_t::__destroy_buffer__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__destroy_buffer__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& state) const {
		uint32 a = ctx.shared.buffer(state);
		gl.DeleteBuffers(1, &a);
	}
	bool infi_gl_shared_t::__bind_buffer__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__bind_buffer__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __buffer_type__& state) const {
		gl.BindBuffer(state.type, ctx.shared.buffer(state.handle));
	}
	bool infi_gl_shared_t::__enable_vertex_attrib__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);	
	}
	void infi_gl_shared_t::__enable_vertex_attrib__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& attrib) const {
		gl.EnableVertexAttribArray(attrib);
	}
	bool infi_gl_shared_t::__disable_vertex_attrib__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__disable_vertex_attrib__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, uint32& attrib) const {
		gl.DisableVertexAttribArray(attrib);
	}
	bool infi_gl_shared_t::__push_vertex_format__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__push_vertex_format__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx) const {
		ctx.shared.__push_vertex_format(gl);
	}
	bool infi_gl_shared_t::__pop_vertex_format__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_shared_t::__pop_vertex_format__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx) const {
		ctx.shared.__pop_vertex_format(gl);
	}

	void infi_gl_shared_t::__push_vertex_format(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_vertex_lock);
		for ( int32 i=(int32)_vertex_attribs.size()-2; i>0 && _vertex_attribs[i] != -1; i-- ) {
			gl.DisableVertexAttribArray(_vertex_attribs[i]);
		}
		_vertex_attribs.push_back(-1);
	}
	void infi_gl_shared_t::__pop_vertex_format(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_vertex_lock);
		for ( int32 i=(int32)_vertex_attribs.size()-1; i>0 && _vertex_attribs[i] != -1; i-- ) {
			gl.DisableVertexAttribArray(_vertex_attribs[i]);
			_vertex_attribs.pop_back();
		}
		_vertex_attribs.pop_back();
		for ( int32 i=(int32)_vertex_attribs.size()-1; i>0 && _vertex_attribs[i] != -1; i-- ) {
			gl.EnableVertexAttribArray(_vertex_attribs[i]);
		}
	}

	infi_gl_shared_t::__buffer_stack__::__buffer_stack__() :
		current(0),
		stacks({{GL_ARRAY_BUFFER,std::stack<uint32>()},
				{GL_ATOMIC_COUNTER_BUFFER,std::stack<uint32>()},
				{GL_COPY_READ_BUFFER,std::stack<uint32>()},
				{GL_COPY_WRITE_BUFFER,std::stack<uint32>()},
				{GL_DISPATCH_INDIRECT_BUFFER,std::stack<uint32>()},
				{GL_DRAW_INDIRECT_BUFFER,std::stack<uint32>()},
				{GL_ELEMENT_ARRAY_BUFFER,std::stack<uint32>()},
				{GL_PIXEL_PACK_BUFFER,std::stack<uint32>()},
				{GL_PIXEL_UNPACK_BUFFER,std::stack<uint32>()},
				{GL_QUERY_BUFFER,std::stack<uint32>()},
				{GL_SHADER_STORAGE_BUFFER,std::stack<uint32>()},
				{GL_TEXTURE_BUFFER,std::stack<uint32>()},
				{GL_TRANSFORM_FEEDBACK_BUFFER,std::stack<uint32>()},
				{GL_UNIFORM_BUFFER,std::stack<uint32>()}}) {

	}

	infi_gl_shared_t::infi_gl_shared_t() { ; }

	void infi_gl_shared_t::allocate_texture_units(const infi_gl_t& gl) {
		int32 i;
		gl.GetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &i);
		_textures.stacks.resize(i);
	}

	uint32 infi_gl_shared_t::texture(uint32 tex) {
		std::lock_guard<std::mutex> lk(_textures.lock);
		return _textures.objects[tex];
	}
	uint32 infi_gl_shared_t::program(uint32 prg) {
		std::lock_guard<std::mutex> lk(_programs.lock);
		return _programs.objects[prg];
	}
	uint32 infi_gl_shared_t::buffer(uint32 buf) {
		std::lock_guard<std::mutex> lk(_buffers.lock);
		return _buffers.objects[buf].handle;
	}
	
	uint32 infi_gl_shared_t::createTexture(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_textures.lock);
		uint32 tex;

		if ( !_textures.available_stack.empty() ) {
			tex = _textures.available_stack.top();
			_textures.available_stack.pop();
		} else {
			tex = ++ _textures.current;
		}

		uint32& value = _textures.objects[tex];
		value = 0;

		uint32* value_ptr = &value;
		_textures.create.push(q.getStateQueue(), value_ptr);
		q.push(_textures.create);

		return tex;
	}
	void infi_gl_shared_t::destroyTexture(infi_gl_queue_t& q, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.destroyTexture");
		std::lock_guard<std::mutex> lk(_textures.lock);
		std::unordered_map<uint32,uint32>::iterator iter = _textures.objects.find(tex);

		if ( iter == _textures.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no texture %d exists", tex
			);

		_textures.destroy.push(q.getStateQueue(), tex);
		q.push(_textures.destroy);
	}
	void infi_gl_shared_t::pushTexture(infi_gl_queue_t& q, uint32 tex, uint32 active) {
		//Error::define_scope __scope__("infi_gl_shared.pushTexture");
		std::lock_guard<std::mutex> lk(_textures.lock);
		uint32 last = (_textures.stacks[active].empty()) ? 0 : _textures.stacks[active].top();
		if ( tex == last )
			return;

		std::unordered_map<uint32,uint32>::iterator iter = _textures.objects.find(tex);
		if ( iter == _textures.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no texture %d exists", tex
			);

		_textures.stacks[active].push(tex);
		_textures.bind.push(q.getStateQueue(), (*iter).second);
		q.push(_textures.bind);
	}
	uint32 infi_gl_shared_t::popTexture(infi_gl_queue_t& q, uint32 active) {
		std::lock_guard<std::mutex> lk(_textures.lock);
		uint32 value, last;
		
		if ( _textures.stacks[active].empty() ) {
			return 0;
		} else {
			value = _textures.stacks[active].top();
			_textures.stacks[active].pop();

			last = (_textures.stacks[active].empty())?0:_textures.stacks[active].top();

			if ( value != last ) {
				_textures.bind.push(q.getStateQueue(), _textures.objects[last]);
				q.push(_textures.bind);
			}

			return value;
		}
	}
	void infi_gl_shared_t::pushTexture(const infi_gl_t& gl, uint32 tex, uint32 active) {
		//Error::define_scope __scope__("infi_gl_shared.pushTexture");
		std::lock_guard<std::mutex> lk(_textures.lock);

		uint32 last = (_textures.stacks[active].empty()) ? 0 : _textures.stacks[active].top();
		if ( tex == last )
			return;

		std::unordered_map<uint32,uint32>::iterator iter = _textures.objects.find(tex);
		if ( iter == _textures.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no texture %d exists", tex
			);

		gl.BindTexture((*iter).second);
	}
	uint32 infi_gl_shared_t::popTexture(const infi_gl_t& gl, uint32 active) {
		std::lock_guard<std::mutex> lk(_textures.lock);
		uint32 value, last;
		
		if ( _textures.stacks[active].empty() ) {
			return 0;
		} else {
			value = _textures.stacks[active].top();
			_textures.stacks[active].pop();

			last = (_textures.stacks[active].empty())?0:_textures.stacks[active].top();

			if ( value != last )
				gl.BindTexture(_textures.objects[last]);

			return value;
		}
	}

	uint32 infi_gl_shared_t::createProgram(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_programs.lock);
		uint32 tex;

		if ( !_programs.available_stack.empty() ) {
			tex = _programs.available_stack.top();
			_programs.available_stack.pop();
		} else {
			tex = ++ _programs.current;
		}

		uint32& value = _programs.objects[tex];
		value = 0;

		_programs.create.push(q.getStateQueue(), &value);
		q.push(_programs.create);

		return tex;
	}
	void infi_gl_shared_t::destroyProgram(infi_gl_queue_t& q, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.destroyProgram");
		std::lock_guard<std::mutex> lk(_programs.lock);
		std::unordered_map<uint32,uint32>::iterator iter = _programs.objects.find(tex);

		if ( iter == _programs.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		_programs.destroy.push(q.getStateQueue(), (*iter).second);
		q.push(_programs.destroy);
	}
	void infi_gl_shared_t::pushProgram(infi_gl_queue_t& q, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.pushProgram");
		std::lock_guard<std::mutex> lk(_programs.lock);

		uint32 last = (_programs.stack.empty()) ? 0 : _programs.stack.top();
		if ( tex == last )
			return;

		std::unordered_map<uint32,uint32>::iterator iter = _programs.objects.find(tex);
		if ( iter == _programs.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		_programs.stack.push(tex);
		_programs.bind.push(q.getStateQueue(), tex);
		q.push(_programs.bind);
	}
	uint32 infi_gl_shared_t::popProgram(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_programs.lock);
		uint32 value, last;

		if (_programs.stack.empty()) {
			return 0;
		} else {
			value = _programs.stack.top();
			_programs.stack.pop();

			last = (_programs.stack.empty())?0:_programs.stack.top();

			if ( value != last ) {
				_programs.bind.push(q.getStateQueue(), _programs.objects[last]);
				q.push(_programs.bind);
			}

			return value;
		}
	}
	void infi_gl_shared_t::pushProgram(const infi_gl_t& gl, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.pushProgram");
		std::lock_guard<std::mutex> lk(_programs.lock);

		uint32 last = (_programs.stack.empty()) ? 0 : _programs.stack.top();
		if ( tex == last )
			return;

		std::unordered_map<uint32,uint32>::iterator iter = _programs.objects.find(tex);
		if ( iter == _programs.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		_programs.stack.push(tex);
		gl.UseProgram((*iter).second);
	}
	uint32 infi_gl_shared_t::popProgram(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_programs.lock);
		uint32 value, last;
		
		if ( _programs.stack.empty() ) {
			return 0;
		} else {
			value = _programs.stack.top();
			_programs.stack.pop();

			last = (_programs.stack.empty())?0:_programs.stack.top();

			if ( value != last )
				gl.UseProgram(_programs.objects[last]);

			return value;
		}
	}

	uint32 infi_gl_shared_t::createBuffer(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_buffers.lock);
		uint32 tex;

		if ( !_buffers.available_stack.empty() ) {
			tex = _buffers.available_stack.top();
			_buffers.available_stack.pop();
		} else {
			tex = ++ _buffers.current;
		}

		__buffer_type__& value = _buffers.objects[tex];
		value.handle = 0;
		value.type = GL_COPY_WRITE_BUFFER;

		_buffers.create.push(q.getStateQueue(), &value);
		q.push(_buffers.create);
		
		return tex;
	}
	uint32 infi_gl_shared_t::createBuffer(infi_gl_queue_t& q, BufferBindPoint type) {
		std::lock_guard<std::mutex> lk(_buffers.lock);
		uint32 tex;

		if ( !_buffers.available_stack.empty() ) {
			tex = _buffers.available_stack.top();
			_buffers.available_stack.pop();
		} else {
			tex = ++ _buffers.current;
		}

		__buffer_type__& value = _buffers.objects[tex];
		value.handle = 0;
		value.type = type;

		_buffers.create.push(q.getStateQueue(), &value);
		q.push(_buffers.create);

		return tex;
	}
	void infi_gl_shared_t::destroyBuffer(infi_gl_queue_t& q, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.destroyBuffer");
		std::lock_guard<std::mutex> lk(_buffers.lock);
		std::unordered_map<uint32,__buffer_type__>::iterator iter = _buffers.objects.find(tex);

		if ( iter == _buffers.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		_buffers.destroy.push(q.getStateQueue(), tex);
		q.push(_buffers.destroy);
	}
	void infi_gl_shared_t::pushBuffer(infi_gl_queue_t& q, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.pushBuffer");
		std::lock_guard<std::mutex> lk(_buffers.lock);

		std::unordered_map<uint32,__buffer_type__>::iterator iter = _buffers.objects.find(tex);
		if ( iter == _buffers.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		__buffer_type__& val = (*iter).second;

		uint32 last = (_buffers.stacks[val.type].empty()) ?
						0 : _buffers.stacks[val.type].top();
		if ( tex == last )
			return;

		_buffers.stacks[val.type].push(tex);
		_buffers.bind.push(q.getStateQueue(), {tex, val.type});
		q.push(_buffers.bind);
	}
	void infi_gl_shared_t::pushBuffer(infi_gl_queue_t& q, uint32 tex, BufferBindPoint type) {
		//Error::define_scope __scope__("infi_gl_shared.pushBuffer");
		std::lock_guard<std::mutex> lk(_buffers.lock);

		std::unordered_map<uint32,__buffer_type__>::iterator iter = _buffers.objects.find(tex);
		if ( iter == _buffers.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		uint32 last = (_buffers.stacks[type].empty()) ? 0 : _buffers.stacks[type].top();
		if ( tex == last )
			return;

		_buffers.stacks[type].push(tex);
		_buffers.bind.push(q.getStateQueue(), {tex, type});
		q.push(_buffers.bind);
	}
	uint32 infi_gl_shared_t::popBuffer(infi_gl_queue_t& q, BufferBindPoint type) {
		std::lock_guard<std::mutex> lk(_buffers.lock);
		uint32 value, last;

		if ( _buffers.stacks[type].empty() ) {
			return 0;
		} else {
			value = _buffers.stacks[type].top();
			_buffers.stacks[type].pop();

			last = (_buffers.stacks[type].empty())?0:_buffers.stacks[type].top();

			if ( value != last ) {
				__buffer_type__& buf = _buffers.objects[last];
				_buffers.bind.push(q.getStateQueue(), {buf.handle, type});
				q.push(_buffers.bind);
			}

			return value;
		}
	}
	void infi_gl_shared_t::pushBuffer(const infi_gl_t& gl, uint32 tex) {
		//Error::define_scope __scope__("infi_gl_shared.pushBuffer");
		std::lock_guard<std::mutex> lk(_buffers.lock);

		std::unordered_map<uint32,__buffer_type__>::iterator iter = _buffers.objects.find(tex);
		if ( iter == _buffers.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		__buffer_type__& val = (*iter).second;

		uint32 last = (_buffers.stacks[val.type].empty()) ?
						0 : _buffers.stacks[val.type].top();
		if ( tex == last )
			return;

		_buffers.stacks[val.type].push(tex);
		gl.BindBuffer(val.type, val.handle);
	}
	void infi_gl_shared_t::pushBuffer(const infi_gl_t& gl, uint32 tex, BufferBindPoint type) {
		//Error::define_scope __scope__("infi_gl_shared.pushBuffer");
		std::lock_guard<std::mutex> lk(_buffers.lock);

		std::unordered_map<uint32,__buffer_type__>::iterator iter = _buffers.objects.find(tex);
		if ( iter == _buffers.objects.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no program %d exists", tex
			);

		uint32 last = (_buffers.stacks[type].empty()) ? 0 : _buffers.stacks[type].top();
		if ( tex == last )
			return;

		_buffers.stacks[type].push(tex);
		gl.BindBuffer(type, (*iter).second.handle);
	}
	uint32 infi_gl_shared_t::popBuffer(const infi_gl_t& gl, BufferBindPoint type) {
		std::lock_guard<std::mutex> lk(_buffers.lock);
		uint32 value, last;
		
		if ( _buffers.stacks[type].empty() ) {
			return 0;
		} else {
			value = _buffers.stacks[type].top();
			_buffers.stacks[type].pop();

			last = (_buffers.stacks[type].empty())?0:_buffers.stacks[type].top();

			if ( value != last ) {
				__buffer_type__& buf = _buffers.objects[last];
				gl.BindBuffer(type, buf.handle);
			}

			return value;
		}
	}

	void infi_gl_shared_t::pushVertexFormat(infi_gl_queue_t& q) {
		q.push(_push_vertex_format);
	}
	void infi_gl_shared_t::enableVertexAttrib(infi_gl_queue_t& q, uint32 id) {
		std::lock_guard<std::mutex> lk(_vertex_lock);
		_vertex_attribs.push_back(id);
		_enable_vertex_attrib.push(q.getStateQueue(), id);
		q.push(_enable_vertex_attrib);
	}
	void infi_gl_shared_t::popVertexFormat(infi_gl_queue_t& q) {
		q.push(_pop_vertex_format);
	}

	void infi_gl_shared_t::pushVertexFormat(const infi_gl_t& gl) {
		__push_vertex_format(gl);
	}
	void infi_gl_shared_t::enableVertexAttrib(const infi_gl_t& gl, uint32 id) {
		std::lock_guard<std::mutex> lk(_vertex_lock);
		_vertex_attribs.push_back(id);
		gl.EnableVertexAttribArray(id);
	}
	void infi_gl_shared_t::popVertexFormat(const infi_gl_t& gl) {
		__pop_vertex_format(gl);
	}

} }