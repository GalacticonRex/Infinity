#ifndef __INFI_KEYCODE_INPUT_H__
#define __INFI_KEYCODE_INPUT_H__

#include <vector>
#include <atomic>

#include "base/structure.hpp"
#include "base/error_log.hpp"
#include "base/time.hpp"

#include "components/infi_component_defs.hpp"
#include "components/infi_input_types.hpp"

namespace Infinity {

	struct infi_key_buffer_t : does_not_copy {
	private:
		std::vector<bool> _isset;
		Time::Point* _pressed;
		Time::Point* _released;

		void set(uint32);
		void unset(uint32);

	public:
		infi_key_buffer_t( uint32 );
		~infi_key_buffer_t();

		void push( uint32, Time::Point );
		void pop( uint32, Time::Point );

		bool operator[] ( uint32 ) const;
		Time::Point pressed( uint32 ) const;
		Time::Point released( uint32 ) const;

		friend struct infi_keyboard_t;
	};

	struct infi_keyboard_t : does_not_copy,
							 infi_key_type_object_t {
	private:
		std::atomic<infi_key_buffer_t*> _front;
		std::atomic<infi_key_buffer_t*> _back;

		void __swap();

	public:
		infi_keyboard_t( uint32 );
		~infi_keyboard_t();

		bool operator[] ( uint32 ) const;
		bool pressed( uint32, float64 ) const;
		bool released( uint32, float64 ) const;

		void push( uint32 );
		void pop( uint32 );
	};

	struct keycode {
		static const uint32 size;
		static const uint32 unknown;
		static const uint32 a;
		static const uint32 b;
		static const uint32 c;
		static const uint32 d;
		static const uint32 e;
		static const uint32 f;
		static const uint32 g;
		static const uint32 h;
		static const uint32 i;
		static const uint32 j;
		static const uint32 k;
		static const uint32 l;
		static const uint32 m;
		static const uint32 n;
		static const uint32 o;
		static const uint32 p;
		static const uint32 q;
		static const uint32 r;
		static const uint32 s;
		static const uint32 t;
		static const uint32 u;
		static const uint32 v;
		static const uint32 w;
		static const uint32 x;
		static const uint32 y;
		static const uint32 z;
		static const uint32 one;
		static const uint32 two;
		static const uint32 three;
		static const uint32 four;
		static const uint32 five;
		static const uint32 six;
		static const uint32 seven;
		static const uint32 eight;
		static const uint32 nine;
		static const uint32 zero;
		static const uint32 ret;
		static const uint32 escape;
		static const uint32 backspace;
		static const uint32 tab;
		static const uint32 space;
		static const uint32 minus;
		static const uint32 equals;
		static const uint32 leftbracket;
		static const uint32 rightbracket;
		static const uint32 backslash;
		static const uint32 nonushash;
		static const uint32 semicolon;
		static const uint32 apostrophe;
		static const uint32 grave;
		static const uint32 comma;
		static const uint32 period;
		static const uint32 slash;
		static const uint32 capslock;
		static const uint32 f1;
		static const uint32 f2;
		static const uint32 f3;
		static const uint32 f4;
		static const uint32 f5;
		static const uint32 f6;
		static const uint32 f7;
		static const uint32 f8;
		static const uint32 f9;
		static const uint32 f10;
		static const uint32 f11;
		static const uint32 f12;
		static const uint32 printscreen;
		static const uint32 scrolllock;
		static const uint32 pause;
		static const uint32 insert;
		static const uint32 home;
		static const uint32 pageup;
		static const uint32 del;
		static const uint32 end;
		static const uint32 pagedown;
		static const uint32 right;
		static const uint32 left;
		static const uint32 down;
		static const uint32 up;
		static const uint32 numlockclear;
		static const uint32 kp_divide;
		static const uint32 kp_multiply;
		static const uint32 kp_minus;
		static const uint32 kp_plus;
		static const uint32 kp_enter;
		static const uint32 kp_1;
		static const uint32 kp_2;
		static const uint32 kp_3;
		static const uint32 kp_4;
		static const uint32 kp_5;
		static const uint32 kp_6;
		static const uint32 kp_7;
		static const uint32 kp_8;
		static const uint32 kp_9;
		static const uint32 kp_0;
		static const uint32 kp_period;
		static const uint32 nonusbackslash;
		static const uint32 application;
		static const uint32 power;
		static const uint32 kp_equals;
		static const uint32 f13;
		static const uint32 f14;
		static const uint32 f15;
		static const uint32 f16;
		static const uint32 f17;
		static const uint32 f18;
		static const uint32 f19;
		static const uint32 f20;
		static const uint32 f21;
		static const uint32 f22;
		static const uint32 f23;
		static const uint32 f24;
		static const uint32 execute;
		static const uint32 help;
		static const uint32 menu;
		static const uint32 select;
		static const uint32 stop;
		static const uint32 again;
		static const uint32 undo;
		static const uint32 cut;
		static const uint32 copy;
		static const uint32 paste;
		static const uint32 find;
		static const uint32 mute;
		static const uint32 volumeup;
		static const uint32 volumedown;
		static const uint32 kp_comma;
		static const uint32 kp_equalsas400;
		static const uint32 international1;
		static const uint32 international2;
		static const uint32 international3;
		static const uint32 international4;
		static const uint32 international5;
		static const uint32 international6;
		static const uint32 international7;
		static const uint32 international8;
		static const uint32 international9;
		static const uint32 lang1;
		static const uint32 lang2;
		static const uint32 lang3;
		static const uint32 lang4;
		static const uint32 lang5;
		static const uint32 lang6;
		static const uint32 lang7;
		static const uint32 lang8;
		static const uint32 lang9;
		static const uint32 alterase;
		static const uint32 sysreq;
		static const uint32 cancel;
		static const uint32 clear;
		static const uint32 prior;
		static const uint32 ret2;
		static const uint32 separator;
		static const uint32 out;
		static const uint32 oper;
		static const uint32 clearagain;
		static const uint32 crsel;
		static const uint32 exsel;
		static const uint32 kp_00;
		static const uint32 kp_000;
		static const uint32 thousandsseparator;
		static const uint32 decimalseparator;
		static const uint32 currencyunit;
		static const uint32 currencysubunit;
		static const uint32 kp_leftparen;
		static const uint32 kp_rightparen;
		static const uint32 kp_leftbrace;
		static const uint32 kp_rightbrace;
		static const uint32 kp_tab;
		static const uint32 kp_backspace;
		static const uint32 kp_a;
		static const uint32 kp_b;
		static const uint32 kp_c;
		static const uint32 kp_d;
		static const uint32 kp_e;
		static const uint32 kp_f;
		static const uint32 kp_xor;
		static const uint32 kp_power;
		static const uint32 kp_percent;
		static const uint32 kp_less;
		static const uint32 kp_greater;
		static const uint32 kp_ampersand;
		static const uint32 kp_dblampersand;
		static const uint32 kp_verticalbar;
		static const uint32 kp_dblverticalbar;
		static const uint32 kp_colon;
		static const uint32 kp_hash;
		static const uint32 kp_space;
		static const uint32 kp_at;
		static const uint32 kp_exclam;
		static const uint32 kp_memstore;
		static const uint32 kp_memrecall;
		static const uint32 kp_memclear;
		static const uint32 kp_memadd;
		static const uint32 kp_memsubtract;
		static const uint32 kp_memmultiply;
		static const uint32 kp_memdivide;
		static const uint32 kp_plusminus;
		static const uint32 kp_clear;
		static const uint32 kp_clearentry;
		static const uint32 kp_binary;
		static const uint32 kp_octal;
		static const uint32 kp_decimal;
		static const uint32 kp_hexadecimal;
		static const uint32 lctrl;
		static const uint32 lshift;
		static const uint32 lalt;
		static const uint32 lgui;
		static const uint32 rctrl;
		static const uint32 rshift;
		static const uint32 ralt;
		static const uint32 rgui;
		static const uint32 mode;
		static const uint32 audionext;
		static const uint32 audioprev;
		static const uint32 audiostop;
		static const uint32 audioplay;
		static const uint32 audiomute;
		static const uint32 mediaselect;
		static const uint32 www;
		static const uint32 mail;
		static const uint32 calculator;
		static const uint32 computer;
		static const uint32 ac_search;
		static const uint32 ac_home;
		static const uint32 ac_back;
		static const uint32 ac_forward;
		static const uint32 ac_stop;
		static const uint32 ac_refresh;
		static const uint32 ac_bookmarks;
		static const uint32 brightnessdown;
		static const uint32 brightnessup;
		static const uint32 displayswitch;
		static const uint32 kbdillumtoggle;
		static const uint32 kbdillumdown;
		static const uint32 kbdillumup;
		static const uint32 eject;
		static const uint32 sleep;
		static const uint32 app1;
		static const uint32 app2;
	};

	struct keymod {
		static const uint32 none;
		static const uint32 lshift;
		static const uint32 rshift;
		static const uint32 lctrl;
		static const uint32 rctrl;
		static const uint32 lalt;
		static const uint32 ralt;
		static const uint32 lgui;
		static const uint32 rgui;
		static const uint32 num;
		static const uint32 caps;
		static const uint32 mode;
		static const uint32 reserved;
	};

	struct keyalt {
		static const uint32 lshift;
		static const uint32 rshift;
		static const uint32 shift;
		static const uint32 lctrl;
		static const uint32 rctrl;
		static const uint32 lalt;
		static const uint32 ralt;
		static const uint32 lgui;
		static const uint32 rgui;
		static const uint32 numlock;
		static const uint32 capslock;
		static const uint32 key_mask;
		static const uint32 knext_exists;
	};

}

#endif//__INFI_KEYCODE_INPUT_H__
