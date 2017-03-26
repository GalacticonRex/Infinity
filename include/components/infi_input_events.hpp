#ifndef __INFI_INPUT_EVENTS_HPP__
#define __INFI_INPUT_EVENTS_HPP__

#include "threads/infi_trigger.hpp"
#include "engine/infi_engine_defs.hpp"
#include "components/infi_component_defs.hpp"
#include "components/infi_keyboard.hpp"

namespace Infinity {
	struct infi_input_events_t {
		struct DEFINE_EXPORT __keyboard_event__ : public infi_trigger_t {
		private:
			uint32 _code;
			infi_input_events_t& _source;

			void Triggered(infi_trigger_t*, bool, void*);

		public:
			__keyboard_event__(infi_input_events_t&, uint32);

			bool get() const;
			bool pressed(float64) const;
			bool released(float64) const;
		};

		struct DEFINE_EXPORT __mouse_event__ : public infi_trigger_t {
		private:
			uint32 _code;
			infi_input_events_t& _source;

			void Triggered(infi_trigger_t*, bool, void*);

		public:
			__mouse_event__(infi_input_events_t&, uint32);

			bool get() const;
			bool pressed(float64) const;
			bool released(float64) const;
		};

		struct DEFINE_EXPORT __mouse_position_change__ : public infi_trigger_t {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_position_change__(infi_input_events_t&);

			core::vec2i operator()() const;
			core::vec2i delta() const;

			void push(const core::vec2i&, const core::vec2i&);
		};

		struct DEFINE_EXPORT __mouse_inside_change__ : public infi_trigger_t {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_inside_change__(infi_input_events_t&);

			bool operator()() const;
			infi_window_t* currentWindow() const;

			void push(bool, infi_window_t*);
		};

		struct DEFINE_EXPORT __mouse_wheel_change__ : public infi_trigger_t {
		private:
			infi_input_events_t& _source;

		public:
			__mouse_wheel_change__(infi_input_events_t&);

			int32 operator()() const;
			int32 delta() const;

			int32 positionX() const;
			int32 deltaX() const;

			void push(const core::vec2i&);
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