#include "render/gl/infi_gl_queue.hpp"
#include "render/gl/infi_gl.hpp"

namespace Infinity {
namespace Render {

	infi_gl_queue_t::infi_gl_queue_t() :
		_running_length(0) { ; }
	infi_gl_queue_t::infi_gl_queue_t(const infi_gl_queue_t& cp) :
		_running_length(0) { ; }
	infi_gl_queue_t::infi_gl_queue_t(infi_gl_queue_t&& mv) :
		_running_length(0) { ; }

	bool infi_gl_queue_t::empty() const {
		return _command_length.empty();
	}

	infi_default_queue_t& infi_gl_queue_t::getStateQueue() {
		return _state;
	}

	void infi_gl_queue_t::push(infi_render_module_t::Function cmd) {
		std::lock_guard<std::mutex> lk(_lock);
		_commands.push(cmd);
		_running_length ++ ;
	}
	void infi_gl_queue_t::stop() {
		std::lock_guard<std::mutex> lk(_lock);
		if ( _running_length != 0 ) {
			_command_length.push(_running_length);
			_running_length = 0;
		}
	}
	void infi_gl_queue_t::draw(const infi_gl_t& GL, infi_gl_context_controller_t& ctrl) {
		//Error::define_scope __scope__("infi_gl_queue_t.draw");
		std::vector<infi_render_module_t::Function> _cmd_list;

		{
			std::lock_guard<std::mutex> lk(_lock);
			if ( !_command_length.empty() ) {
				uint32 count = _command_length.front();
				_command_length.pop();
				for ( uint32 i=0;i<count;i++ ) {
					_cmd_list.push_back(_commands.front());
					_commands.pop();
				}
			}
		}

		for ( uint32 i=0;i<_cmd_list.size();i++ )
			_cmd_list[i](GL, ctrl, _state);
	}

} }