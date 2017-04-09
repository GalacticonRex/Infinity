#include "render/gl/infi_gl_context_access.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {
namespace Render {

	bool infi_gl_context_access_t::__sync_framebuffer__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_context_access_t::__sync_framebuffer__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_framebuffer_bindings_t*& data) const {
		if ( data == nullptr )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"Cannot synchronize null framebuffer!"
			);
		infi_framebuffer_bindings_t& fbo = *data;
		infi_framebuffer_bindings_t& bind = ctx.getCurrentContext() -> framebuffer(fbo.handle);
		bind.synchronizeTo(gl, ctx.shared, fbo);
	}
	bool infi_gl_context_access_t::__bind_framebuffer__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_context_access_t::__bind_framebuffer__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_framebuffer_bindings_t*& data) const {
		if ( data == nullptr ) {
			gl.BindFramebuffer(0);
		} else {
			infi_framebuffer_bindings_t& fbo = *data;
			infi_framebuffer_bindings_t& bind = ctx.getCurrentContext() -> framebuffer(fbo.handle);

			if ( bind.handle == 0 ) {
				gl.GenFramebuffers(1, &bind.handle);
				bind.hash_value = 0;
			}
			gl.BindFramebuffer(bind.handle);
			bind.synchronizeTo(gl, ctx.shared, fbo);
		}
	}

	bool infi_gl_context_access_t::__sync_vertex_array__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_context_access_t::__sync_vertex_array__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, vao_ptr& data) const {
		if ( data == nullptr )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"Cannot synchronize null framebuffer!"
			);
		infi_vertex_array_bindings_t& vao = *data;
		infi_vertex_array_bindings_t& bind = ctx.getCurrentContext() -> vertexArray(vao.handle);
		bind.synchronizeTo(gl, ctx.shared, vao);
	}
	bool infi_gl_context_access_t::__bind_vertex_array__::compatible(const infi_gl_t& gl) const {
		infi_gl_version_t version(2,0);
		return (gl.version > version);
	}
	void infi_gl_context_access_t::__bind_vertex_array__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, vao_ptr& data) const {
		if ( data == nullptr ) {
			gl.BindVertexArray(0);
		} else {
			infi_vertex_array_bindings_t& vao = *data;
			infi_vertex_array_bindings_t& bind = ctx.getCurrentContext() -> vertexArray(vao.handle);

			if ( bind.handle == 0 ) {
				gl.GenVertexArrays(1, &bind.handle);
				bind.hash_value = 0;
			}
			gl.BindVertexArray(bind.handle);
			bind.synchronizeTo(gl, ctx.shared, vao);
		}
	}

	bool infi_gl_context_access_t::__sync_blend_func__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_gl_context_access_t::__sync_blend_func__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_blend_function_bindings_t*& blend) const {
		if ( blend == nullptr )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"No blend function to bind!"
			);
		infi_blend_function_bindings_t& src = *blend;
		infi_blend_function_bindings_t& bind = ctx.getCurrentContext() -> blendFunction();
		bind.synchronizeTo(gl, src);
	}

	bool infi_gl_context_access_t::__sync_blend_eq__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_gl_context_access_t::__sync_blend_eq__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, infi_blend_equation_bindings_t*& blend) const {
		if ( blend == nullptr )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"No blend function to bind!"
			);
		infi_blend_equation_bindings_t& src = *blend;
		infi_blend_equation_bindings_t& bind = ctx.getCurrentContext() -> blendEquation();
		bind.synchronizeTo(gl, src);
	}

	infi_gl_context_access_t::vao_ptr	infi_gl_context_access_t::__vertex_array_stack__::operator[](uint32 vao) {
		std::unordered_map<uint32,vao_ptr>::iterator iter = bindings.find(vao);
		if ( iter == bindings.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no vertex array %d exists", vao
			);
		return (*iter).second;
	}

	infi_gl_context_access_t::infi_gl_context_access_t() :
		_context(nullptr) {
		_framebuffers.current = 0;
		_vertex_arrays.current = 0;
		_transform_feedback.current = 0;
	}

	void infi_gl_context_access_t::setContextController(infi_gl_context_controller_t& con) {
		_context = &con;
	}

	infi_gl_context_t& infi_gl_context_access_t::current() {
		if ( _context -> getCurrentContext() == nullptr ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no context currently bound"
			);
		}
		return *(_context -> getCurrentContext());
	}

	infi_framebuffer_bindings_t& infi_gl_context_access_t::allocFramebuffer() {
		return _framebuffers.alloc.alloc();
	}
	infi_vertex_array_bindings_t& infi_gl_context_access_t::allocVertexArray() {
		return _vertex_arrays.alloc.alloc();
	}
	infi_transform_feeback_bindings_t& infi_gl_context_access_t::allocTransformFeedback() {
		return _transform_feedback.alloc.alloc();
	}

	void infi_gl_context_access_t::deallocFramebuffer(infi_framebuffer_bindings_t& x) {
		_framebuffers.alloc.dealloc(x);
	}
	void infi_gl_context_access_t::deallocVertexArray(infi_vertex_array_bindings_t& x) {
		_vertex_arrays.alloc.dealloc(x);
	}
	void infi_gl_context_access_t::deallocTransformFeedback(infi_transform_feeback_bindings_t& x) {
		_transform_feedback.alloc.dealloc(x);
	}

	uint32 infi_gl_context_access_t::framebuffer(uint32 x) const {
		if ( _context -> getCurrentContext() == nullptr ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no context currently bound"
			);
		}
		return _context -> getCurrentContext() -> framebuffer(x).handle;
	}
	uint32 infi_gl_context_access_t::vertexArray(uint32 x) const {
		if ( _context -> getCurrentContext() == nullptr ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no context currently bound"
			);
		}
		return _context -> getCurrentContext() -> vertexArray(x).handle;
	}
	uint32 infi_gl_context_access_t::transformFeedback(uint32 x) const {
		if ( _context -> getCurrentContext() == nullptr ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no context currently bound"
			);
		}
		return _context -> getCurrentContext() -> transformFeedback(x).handle;
	}
	
	uint32 infi_gl_context_access_t::createFramebuffer() {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);
		uint32 f;

		if ( !_framebuffers.available_stack.empty() ) {
			f = _framebuffers.available_stack.top();
			_framebuffers.available_stack.pop();
		} else {
			f = ++ _framebuffers.current;
		}

		std::unordered_map<uint32,fbo_ptr>::iterator iter = _framebuffers.bindings.find(f);
		if ( iter != _framebuffers.bindings.end() )
			deallocFramebuffer(*(iter->second));
		
		infi_framebuffer_bindings_t& fbo = allocFramebuffer();
		fbo.handle = f;
		_framebuffers.bindings[f] = &fbo;

		return f;
	}
	void infi_gl_context_access_t::destroyFramebuffer(uint32 f) {
		
	}
	void infi_gl_context_access_t::attachToFramebuffer(uint32 f, uint32 tex, uint32 b, uint32 type) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);

		std::unordered_map<uint32,fbo_ptr>::iterator iter = _framebuffers.bindings.find(f);
		if ( iter == _framebuffers.bindings.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no framebuffer %d exists", f
			);

		fbo_ptr fbo = (*iter).second;
		fbo -> set(b, tex, type);
	}
	void infi_gl_context_access_t::pushFramebuffer(infi_gl_queue_t& q, uint32 f) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);

		uint32 last = (_framebuffers.element.empty()) ? 0 : _framebuffers.element.back();
		if ( f == last )
			return;

		std::unordered_map<uint32,fbo_ptr>::iterator iter = _framebuffers.bindings.find(f);
		if ( iter == _framebuffers.bindings.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no framebuffer %d exists", f
			);

		fbo_ptr fbo = (*iter).second;

		_framebuffers.element.push_back(f);
		_framebuffers.bind.push(q.getStateQueue(), fbo);
		q.push(_framebuffers.bind);
	}
	uint32 infi_gl_context_access_t::popFramebuffer(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);
		uint32 value, last;

		if (_framebuffers.element.empty()) {
			return 0;
		} else {
			value = _framebuffers.element.back();
			_framebuffers.element.pop_back();

			last = (_framebuffers.element.empty())?0:_framebuffers.element.back();

			if ( value != last ) {
				_framebuffers.bind.push(q.getStateQueue(), _framebuffers.bindings[last]);
				q.push(_framebuffers.bind);
			}

			return value;
		}
	}
	void infi_gl_context_access_t::pushFramebuffer(const infi_gl_t& gl, uint32 f) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);

		uint32 last = (_framebuffers.element.empty()) ? 0 : _framebuffers.element.back();
		if ( f == last )
			return;

		std::unordered_map<uint32,fbo_ptr>::iterator iter = _framebuffers.bindings.find(f);
		if ( iter == _framebuffers.bindings.end() )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"no framebuffer %d exists", f
			);	

		fbo_ptr fbo = (*iter).second;
		_framebuffers.bind.run(gl, *_context, fbo);
	}
	uint32 infi_gl_context_access_t::popFramebuffer(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);
		uint32 value, last;

		if (_framebuffers.element.empty()) {
			return 0;
		} else {
			value = _framebuffers.element.back();
			_framebuffers.element.pop_back();

			last = (_framebuffers.element.empty())?0:_framebuffers.element.back();

			if ( value != last )
				_framebuffers.bind.run(gl, *_context, _framebuffers.bindings[last]);

			return value;
		}
	}
	void infi_gl_context_access_t::synchronizeFramebuffer(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);
		if (!_framebuffers.element.empty()) {
			uint32 value = _framebuffers.element.back();
			_framebuffers.sync.push(q.getStateQueue(), _framebuffers.bindings[value]);
			q.push(_framebuffers.sync);
		}
	}
	void infi_gl_context_access_t::synchronizeFramebuffer(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_framebuffers.lock);
		if (!_framebuffers.element.empty()) {
			uint32 value = _framebuffers.element.back();
			_framebuffers.sync.run(gl, *_context, _framebuffers.bindings[value]);
		}
	}



















	uint32 infi_gl_context_access_t::createVertexArray() {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		uint32 v;

		if ( !_vertex_arrays.available_stack.empty() ) {
			v = _vertex_arrays.available_stack.top();
			_vertex_arrays.available_stack.pop();
		} else {
			v = ++ _vertex_arrays.current;
		}

		std::unordered_map<uint32,vao_ptr>::iterator iter = _vertex_arrays.bindings.find(v);
		if ( iter != _vertex_arrays.bindings.end() )
			deallocVertexArray(*(iter->second));

		infi_vertex_array_bindings_t& vao = allocVertexArray();
		vao.handle = v;
		_vertex_arrays.bindings[v] = &vao;

		return v;
	}
	void infi_gl_context_access_t::destroyVertexArray(uint32) {

	}

	void infi_gl_context_access_t::arrayBufferToVertexArray(uint32 vao, uint32 buf) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		vao_ptr vao_p = _vertex_arrays[vao];
		vao_p -> array_buffer_handle = buf;
	}
	void infi_gl_context_access_t::indexBufferToVertexArray(uint32 vao, uint32 buf) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		vao_ptr vao_p = _vertex_arrays[vao];
		vao_p -> index_buffer_handle = buf;
	}
	void infi_gl_context_access_t::vertexSizeToVertexArray(uint32 vao, uint32 size) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		vao_ptr vao_p = _vertex_arrays[vao];
		vao_p -> vertexSize( size );
	}
	void infi_gl_context_access_t::enableVertexArray(uint32 vao, uint32 index, uint32 count, uint32 type, uint32 offset) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		vao_ptr vao_p = _vertex_arrays[vao];
		vao_p -> set(index, count, type, offset);
	}
	void infi_gl_context_access_t::disableVertexArray(uint32 vao, uint32 index) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		vao_ptr vao_p = _vertex_arrays[vao];
		vao_p -> unset(index);
	}

	void infi_gl_context_access_t::pushVertexArray(infi_gl_queue_t& q, uint32 vao) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);

		uint32 last = (_vertex_arrays.element.empty()) ? 0 : _vertex_arrays.element.back();
		if ( vao == last )
			return;

		vao_ptr vao_p = _vertex_arrays[vao];

		_vertex_arrays.element.push_back(vao);
		_vertex_arrays.bind.push(q.getStateQueue(), vao_p);
		q.push(_vertex_arrays.bind);
	}
	uint32 infi_gl_context_access_t::popVertexArray(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		uint32 value, last;

		if (_vertex_arrays.element.empty()) {
			return 0;
		} else {
			value = _vertex_arrays.element.back();
			_vertex_arrays.element.pop_back();

			last = (_vertex_arrays.element.empty())?0:_vertex_arrays.element.back();

			if ( value != last ) {
				_vertex_arrays.bind.push(q.getStateQueue(), _vertex_arrays.bindings[last]);
				q.push(_vertex_arrays.bind);
			}

			return value;
		}
	}

	void infi_gl_context_access_t::pushVertexArray(const infi_gl_t&, uint32) {

	}
	uint32 infi_gl_context_access_t::popVertexArray(const infi_gl_t&) {
		return 0;
	}

	void infi_gl_context_access_t::synchronizeVertexArray(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_vertex_arrays.lock);
		if (!_vertex_arrays.element.empty()) {
			uint32 value = _vertex_arrays.element.back();
			_vertex_arrays.sync.push(q.getStateQueue(), _vertex_arrays.bindings[value]);
			q.push(_vertex_arrays.sync);
		}
	}
	void infi_gl_context_access_t::synchronizeVertexArray(const infi_gl_t&) {

	}






























	void infi_gl_context_access_t::pushBlendFunction(infi_gl_queue_t& q, const infi_blend_function_bindings_t& blend) {
		std::lock_guard<std::mutex> lk(_blend_function.lock);

		_blend_function.bindings.push(blend);
		infi_blend_function_bindings_t& top = _blend_function.bindings.top();
		_blend_function.sync.push(q.getStateQueue(), &top);
		q.push(_blend_function.sync);
	}
	void infi_gl_context_access_t::popBlendFunction(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_blend_function.lock);

		if (!_blend_function.bindings.empty()) {
			_blend_function.bindings.pop();
			_blend_function.sync.push(q.getStateQueue(),
				(_blend_function.bindings.empty())?
					&_blend_function.root :
					&_blend_function.bindings.top()
			);
			q.push(_blend_function.sync);
		}
	}

	void infi_gl_context_access_t::pushBlendFunction(const infi_gl_t& gl, const infi_blend_function_bindings_t& blend) {
		std::lock_guard<std::mutex> lk(_blend_function.lock);

		_blend_function.bindings.push(blend);
		infi_blend_function_bindings_t* top = &_blend_function.bindings.top();
		_blend_function.sync.run(gl, *_context, top);
	}
	void infi_gl_context_access_t::popBlendFunction(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_blend_function.lock);

		if (!_blend_function.bindings.empty()) {
			_blend_function.bindings.pop();
			infi_blend_function_bindings_t* top =
				(_blend_function.bindings.empty())?
					&_blend_function.root :
					&_blend_function.bindings.top();
			_blend_function.sync.run(gl, *_context, top);
		}
	}

	void infi_gl_context_access_t::pushBlendEquation(infi_gl_queue_t& q, const infi_blend_equation_bindings_t& blend) {
		std::lock_guard<std::mutex> lk(_blend_equation.lock);

		_blend_equation.bindings.push(blend);
		infi_blend_equation_bindings_t& top = _blend_equation.bindings.top();
		_blend_equation.sync.push(q.getStateQueue(), &top);
		q.push(_blend_equation.sync);
	}
	void infi_gl_context_access_t::popBlendEquation(infi_gl_queue_t& q) {
		std::lock_guard<std::mutex> lk(_blend_equation.lock);

		if (!_blend_equation.bindings.empty()) {
			_blend_equation.bindings.pop();
			_blend_equation.sync.push(q.getStateQueue(),
				(_blend_equation.bindings.empty())?
					&_blend_equation.root :
					&_blend_equation.bindings.top()
			);
			q.push(_blend_equation.sync);
		}
	}

	void infi_gl_context_access_t::pushBlendEquation(const infi_gl_t& gl, const infi_blend_equation_bindings_t& blend) {
		std::lock_guard<std::mutex> lk(_blend_equation.lock);

		_blend_equation.bindings.push(blend);
		infi_blend_equation_bindings_t* top = &_blend_equation.bindings.top();
		_blend_equation.sync.run(gl, *_context, top);
	}
	void infi_gl_context_access_t::popBlendEquation(const infi_gl_t& gl) {
		std::lock_guard<std::mutex> lk(_blend_equation.lock);

		if (!_blend_equation.bindings.empty()) {
			_blend_equation.bindings.pop();
			infi_blend_equation_bindings_t* top =
				(_blend_equation.bindings.empty())?
					&_blend_equation.root :
					&_blend_equation.bindings.top();
			_blend_equation.sync.run(gl, *_context, top);
		}
	}

} }