#ifndef __INFI_INPUT_EVENTS_HPP__
#define __INFI_INPUT_EVENTS_HPP__

#include "threads/infi_event_trigger.hpp"
#include "engine/infi_engine_defs.hpp"
#include "components/infi_component_defs.hpp"
#include "components/infi_keyboard.hpp"

namespace Infinity {
	struct infi_input_events_t {
		struct mouse_data {
			core::vec2i position;
			core::vec2i delta;
		};

		struct DEFINE_EXPORT __keyboard_event__ : public infi_event_trigger_t<void> {
		private:
			uint32 _code;
			infi_input_events_t& _source;

		public:
			__keyboard_event__(infi_input_events_t&, uint32);

			bool get() const;
			bool pressed(float64) const;
			bool released(float64) const;
		};

		struct DEFINE_EXPORT __mouse_event__ : public infi_event_trigger_t<void> {
		private:
			uint32 _code;
			infi_input_events_t& _source;

		public:
			__mouse_event__(infi_input_events_t&, uint32);

			bool get() const;
			bool pressed(float64) const;
			bool released(float64) const;
		};

		struct DEFINE_EXPORT __mouse_position_change__ : public infi_event_trigger_t<mouse_data> {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_position_change__(infi_input_events_t&);

			core::vec2i operator()() const;
			core::vec2i delta() const;
		};

		struct DEFINE_EXPORT __mouse_inside_change__ : public infi_event_trigger_t<infi_window_t*> {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_inside_change__(infi_input_events_t&);

			bool operator()() const;
			infi_window_t* currentWindow() const;
		};

		struct DEFINE_EXPORT __mouse_wheel_change__ : public infi_event_trigger_t<core::vec2i> {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_wheel_change__(infi_input_events_t&);

			int32 operator()() const;
			int32 delta() const;

			int32 positionX() const;
			int32 deltaX() const;
		};
		
	private:

		__keyboard_event__* _events_keyboard;
		infi_keyboard_t* _local_keyboard;

		__mouse_event__* _events_mouse;
		infi_mouse_t* _local_mouse;

	public:

		__keyboard_event__& operator[](uint32);

		__keyboard_event__
			&escape,
			&backspace,
			&enter,
			&tab,
			&space,
			&a,
			&b,
			&c,
			&d,
			&e,
			&f,
			&g,
			&h,
			&i,
			&j,
			&k,
			&l,
			&m,
			&n,
			&o,
			&p,
			&q,
			&r,
			&s,
			&t,
			&u,
			&v,
			&w,
			&x,
			&y,
			&z,
			&zero,
			&one,
			&two,
			&three,
			&four,
			&five,
			&six,
			&seven,
			&eight,
			&nine;

		struct __mouse__ {
		private:
			infi_input_events_t& _source;
		public:
			__mouse__(infi_input_events_t&);

			__mouse_event__& operator[](uint32);

			__mouse_event__
				&left,
				&right,
				&middle;

			__mouse_position_change__ position;
			__mouse_wheel_change__ wheel;
			__mouse_inside_change__ inside;
		} mouse;
		
		infi_input_events_t();
		~infi_input_events_t();

		void setKeyboard(infi_root_module_t&);
		void setKeyboard(infi_window_t&);

		void setMouse(infi_root_module_t&);
		void setMouse(infi_window_t&);

		void pushKeyboard(uint32);
		void popKeyboard(uint32);

		bool getKeyboard(uint32) const;
		bool pressedKeyboard(uint32, float64) const;
		bool releasedKeyboard(uint32, float64) const;

		void pushMouse(uint32);
		void popMouse(uint32);

		bool getMouse(uint32) const;
		bool pressedMouse(uint32, float64) const;
		bool releasedMouse(uint32, float64) const;

	};
}

#endif//__INFI_INPUT_EVENTS_HPP__