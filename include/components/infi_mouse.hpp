#ifndef __INFI_MOUSE_INPUT_H__
#define __INFI_MOUSE_INPUT_H__

#include "components/infi_keyboard.hpp"
#include "components/infi_component_defs.hpp"

#define INFI_MOUSE_BUTTON_CAP 16

namespace Infinity {

	struct infi_mouse_buffer_t : infi_key_buffer_t {
	private:

		core::vec2i _position;
		core::vec2i _deltap;
		core::vec2i _wheel;
		core::vec2i _deltaw;

		infi_window_t* _inside_window;

		Time::Point _pos_time;
		Time::Point _wheel_time;
		Time::Point _enter_time;
		Time::Point _leave_time;

	public:

		infi_mouse_buffer_t( uint32 );

		void push_enter( infi_window_t*, Time::Point );
		void push_leave( infi_window_t*, Time::Point );

		void push_move( core::vec2i, core::vec2i, Time::Point );
		void push_wheel( core::vec2i, Time::Point );

		infi_window_t* window() const;
		bool inside() const;

		const core::vec2i& position() const;
		const core::vec2i& deltaPosition() const;
		const core::vec2i& wheel() const;
		const core::vec2i& deltaWheel() const;

		Time::Point positionTime() const;
		Time::Point enterTime() const;
		Time::Point leaveTime() const;
		Time::Point wheelTime() const;

		friend struct infi_mouse_t;
	};

	struct infi_mouse_t : does_not_copy,
						  infi_key_type_object_t,
						  infi_mouse_type_object_t {
	private:

		std::atomic<infi_mouse_buffer_t*> _front;
		std::atomic<infi_mouse_buffer_t*> _back;

		void __swap();

	public:
		infi_mouse_t( uint32 );
		~infi_mouse_t();

		bool operator[] ( uint32 ) const;
		bool pressed( uint32, float64 ) const;
		bool released( uint32, float64 ) const;

		core::vec2i position() const;
		core::vec2i deltaPosition( Time::Point ) const;

		core::vec2i wheel() const;
		core::vec2i deltaWheel( Time::Point ) const;

		infi_window_t* window() const;
		bool inside() const;
		
		void push( infi_window_t* );
		void pop( infi_window_t* );

		void push( core::vec2i pos, core::vec2i rel );
		void push( core::vec2i rel );

		void push( uint32 );
		void pop( uint32 );
	};

	struct mousebutton {
		static const uint32 size;
		static const uint32 left;
		static const uint32 middle;
		static const uint32 right;
	};

}

#endif//__INFI_MOUSE_INPUT_H__
