#include "components/infi_keyboard.hpp"
#include "depend/infi_sdl.hpp"

namespace Infinity {

	infi_key_buffer_t::infi_key_buffer_t( uint32 sz ) :
		_isset( sz ),
		_pressed( new Time::Point[sz] ),
		_released( new Time::Point[sz] ) {
		for (uint32 i=0;i<sz;++i ) {
			_pressed[i] = Time::Point::max();
			_released[i] = Time::Point::max();
		}
	}
	infi_key_buffer_t::~infi_key_buffer_t() {
		delete[] _pressed;
		delete[] _released;
	}

	void infi_key_buffer_t::set(uint32 x) {
		if ( _isset.size() <= x ) {
			_isset.resize(x+1);
		}
		_isset[x] = true;
	}
	void infi_key_buffer_t::unset(uint32 x) {
		if ( _isset.size() <= x ) {
			_isset.resize(x+1);
		}
		_isset[x] = false;
	}

	void infi_key_buffer_t::push( uint32 index, Time::Point tm ) {
		set( index );
		_pressed[index] = tm;
	}
	void infi_key_buffer_t::pop( uint32 index, Time::Point tm ) {
		unset( index );
		_released[index] = tm;
	}

	bool infi_key_buffer_t::operator[] ( uint32 i ) const {
		if ( i >= _isset.size() ) {
			//Error::define_scope __scope__("infi_key_buffer_t.[]");
			Error::send<Error::Fatality::Method>(
				Error::Type::Index,
				"cannot get key %d out of %d",
				i, _isset.size() 
			);
		}
		return _isset[i];
	}
	Time::Point infi_key_buffer_t::pressed( uint32 i ) const {
		if ( i >= _isset.size() ) {
			//Error::define_scope __scope__("infi_key_buffer_t.pressed");
			Error::send<Error::Fatality::Method>(
				Error::Type::Index,
				"cannot get key %d out of %d",
				i, _isset.size() 
			);
		}
		return _pressed[i];
	}
	Time::Point infi_key_buffer_t::released( uint32 i ) const {
		if ( i >= _isset.size() ) {
			//Error::define_scope __scope__("infi_key_buffer_t.released");
			Error::send<Error::Fatality::Method>(
				Error::Type::Index,
				"cannot get key %d out of %d",
				i, _isset.size() 
			);
		}
		return _released[i];
	}

	infi_keyboard_t::infi_keyboard_t( uint32 sz ) :
		_front( new infi_key_buffer_t(sz) ),
		_back( new infi_key_buffer_t(sz) ) { ; }

	infi_keyboard_t::~infi_keyboard_t() {
		delete _front;
		delete _back;
	}

	void infi_keyboard_t::__swap() {
		infi_key_buffer_t* buf = _front;
		_front = _back.load();
		_back = buf;
	}

	void infi_keyboard_t::push( uint32 k ) {
		Time::Point t = Time::Now();
		(*_back).push( k, t );
		__swap();
		(*_back).push( k, t );
	}
	void infi_keyboard_t::pop( uint32 k ) {
		Time::Point t = Time::Now();
		(*_back).pop( k, t );
		__swap();
		(*_back).pop( k, t );
	}

	bool infi_keyboard_t::operator[] ( uint32 i ) const {
		return (*_front)._isset[i];
	}
	bool infi_keyboard_t::pressed( uint32 i, float64 dt ) const {
		Time::Frame t = Time::Now() - (*_front)._pressed[i];
		return ( t.count() <= dt );
	}
	bool infi_keyboard_t::released( uint32 i, float64 dt ) const {
		Time::Frame t = Time::Now() - (*_front)._released[i];
		return ( t.count() <= dt );
	}

	const uint32 keycode::size = 288;

	const uint32 keycode::unknown = SDL_SCANCODE_UNKNOWN;
	const uint32 keycode::a = SDL_SCANCODE_A;
	const uint32 keycode::b = SDL_SCANCODE_B;
	const uint32 keycode::c = SDL_SCANCODE_C;
	const uint32 keycode::d = SDL_SCANCODE_D;
	const uint32 keycode::e = SDL_SCANCODE_E;
	const uint32 keycode::f = SDL_SCANCODE_F;
	const uint32 keycode::g = SDL_SCANCODE_G;
	const uint32 keycode::h = SDL_SCANCODE_H;
	const uint32 keycode::i = SDL_SCANCODE_I;
	const uint32 keycode::j = SDL_SCANCODE_J;
	const uint32 keycode::k = SDL_SCANCODE_K;
	const uint32 keycode::l = SDL_SCANCODE_L;
	const uint32 keycode::m = SDL_SCANCODE_M;
	const uint32 keycode::n = SDL_SCANCODE_N;
	const uint32 keycode::o = SDL_SCANCODE_O;
	const uint32 keycode::p = SDL_SCANCODE_P;
	const uint32 keycode::q = SDL_SCANCODE_Q;
	const uint32 keycode::r = SDL_SCANCODE_R;
	const uint32 keycode::s = SDL_SCANCODE_S;
	const uint32 keycode::t = SDL_SCANCODE_T;
	const uint32 keycode::u = SDL_SCANCODE_U;
	const uint32 keycode::v = SDL_SCANCODE_V;
	const uint32 keycode::w = SDL_SCANCODE_W;
	const uint32 keycode::x = SDL_SCANCODE_X;
	const uint32 keycode::y = SDL_SCANCODE_Y;
	const uint32 keycode::z = SDL_SCANCODE_Z;
	const uint32 keycode::one = SDL_SCANCODE_1;
	const uint32 keycode::two = SDL_SCANCODE_2;
	const uint32 keycode::three = SDL_SCANCODE_3;
	const uint32 keycode::four = SDL_SCANCODE_4;
	const uint32 keycode::five = SDL_SCANCODE_5;
	const uint32 keycode::six = SDL_SCANCODE_6;
	const uint32 keycode::seven = SDL_SCANCODE_7;
	const uint32 keycode::eight = SDL_SCANCODE_8;
	const uint32 keycode::nine = SDL_SCANCODE_9;
	const uint32 keycode::zero = SDL_SCANCODE_0;
	const uint32 keycode::ret = SDL_SCANCODE_RETURN;
	const uint32 keycode::escape = SDL_SCANCODE_ESCAPE;
	const uint32 keycode::backspace = SDL_SCANCODE_BACKSPACE;
	const uint32 keycode::tab = SDL_SCANCODE_TAB;
	const uint32 keycode::space = SDL_SCANCODE_SPACE;
	const uint32 keycode::minus = SDL_SCANCODE_MINUS;
	const uint32 keycode::equals = SDL_SCANCODE_EQUALS;
	const uint32 keycode::leftbracket = SDL_SCANCODE_LEFTBRACKET;
	const uint32 keycode::rightbracket = SDL_SCANCODE_RIGHTBRACKET;
	const uint32 keycode::backslash = SDL_SCANCODE_BACKSLASH;
	const uint32 keycode::nonushash = SDL_SCANCODE_NONUSHASH;
	const uint32 keycode::semicolon = SDL_SCANCODE_SEMICOLON;
	const uint32 keycode::apostrophe = SDL_SCANCODE_APOSTROPHE;
	const uint32 keycode::grave = SDL_SCANCODE_GRAVE;
	const uint32 keycode::comma = SDL_SCANCODE_COMMA;
	const uint32 keycode::period = SDL_SCANCODE_PERIOD;
	const uint32 keycode::slash = SDL_SCANCODE_SLASH;
	const uint32 keycode::capslock = SDL_SCANCODE_CAPSLOCK;
	const uint32 keycode::f1 = SDL_SCANCODE_F1;
	const uint32 keycode::f2 = SDL_SCANCODE_F2;
	const uint32 keycode::f3 = SDL_SCANCODE_F3;
	const uint32 keycode::f4 = SDL_SCANCODE_F4;
	const uint32 keycode::f5 = SDL_SCANCODE_F5;
	const uint32 keycode::f6 = SDL_SCANCODE_F6;
	const uint32 keycode::f7 = SDL_SCANCODE_F7;
	const uint32 keycode::f8 = SDL_SCANCODE_F8;
	const uint32 keycode::f9 = SDL_SCANCODE_F9;
	const uint32 keycode::f10 = SDL_SCANCODE_F10;
	const uint32 keycode::f11 = SDL_SCANCODE_F11;
	const uint32 keycode::f12 = SDL_SCANCODE_F12;
	const uint32 keycode::printscreen = SDL_SCANCODE_PRINTSCREEN;
	const uint32 keycode::scrolllock = SDL_SCANCODE_SCROLLLOCK;
	const uint32 keycode::pause = SDL_SCANCODE_PAUSE;
	const uint32 keycode::insert = SDL_SCANCODE_INSERT;
	const uint32 keycode::home = SDL_SCANCODE_HOME;
	const uint32 keycode::pageup = SDL_SCANCODE_PAGEUP;
	const uint32 keycode::del = SDL_SCANCODE_DELETE;
	const uint32 keycode::end = SDL_SCANCODE_END;
	const uint32 keycode::pagedown = SDL_SCANCODE_PAGEDOWN;
	const uint32 keycode::right = SDL_SCANCODE_RIGHT;
	const uint32 keycode::left = SDL_SCANCODE_LEFT;
	const uint32 keycode::down = SDL_SCANCODE_DOWN;
	const uint32 keycode::up = SDL_SCANCODE_UP;
	const uint32 keycode::numlockclear = SDL_SCANCODE_NUMLOCKCLEAR;
	const uint32 keycode::kp_divide = SDL_SCANCODE_KP_DIVIDE;
	const uint32 keycode::kp_multiply = SDL_SCANCODE_KP_MULTIPLY;
	const uint32 keycode::kp_minus = SDL_SCANCODE_KP_MINUS;
	const uint32 keycode::kp_plus = SDL_SCANCODE_KP_PLUS;
	const uint32 keycode::kp_enter = SDL_SCANCODE_KP_ENTER;
	const uint32 keycode::kp_1 = SDL_SCANCODE_KP_1;
	const uint32 keycode::kp_2 = SDL_SCANCODE_KP_2;
	const uint32 keycode::kp_3 = SDL_SCANCODE_KP_3;
	const uint32 keycode::kp_4 = SDL_SCANCODE_KP_4;
	const uint32 keycode::kp_5 = SDL_SCANCODE_KP_5;
	const uint32 keycode::kp_6 = SDL_SCANCODE_KP_6;
	const uint32 keycode::kp_7 = SDL_SCANCODE_KP_7;
	const uint32 keycode::kp_8 = SDL_SCANCODE_KP_8;
	const uint32 keycode::kp_9 = SDL_SCANCODE_KP_9;
	const uint32 keycode::kp_0 = SDL_SCANCODE_KP_0;
	const uint32 keycode::kp_period = SDL_SCANCODE_KP_PERIOD;
	const uint32 keycode::nonusbackslash = SDL_SCANCODE_NONUSBACKSLASH;
	const uint32 keycode::application = SDL_SCANCODE_APPLICATION;
	const uint32 keycode::power = SDL_SCANCODE_POWER;
	const uint32 keycode::kp_equals = SDL_SCANCODE_KP_EQUALS;
	const uint32 keycode::f13 = SDL_SCANCODE_F13;
	const uint32 keycode::f14 = SDL_SCANCODE_F14;
	const uint32 keycode::f15 = SDL_SCANCODE_F15;
	const uint32 keycode::f16 = SDL_SCANCODE_F16;
	const uint32 keycode::f17 = SDL_SCANCODE_F17;
	const uint32 keycode::f18 = SDL_SCANCODE_F18;
	const uint32 keycode::f19 = SDL_SCANCODE_F19;
	const uint32 keycode::f20 = SDL_SCANCODE_F20;
	const uint32 keycode::f21 = SDL_SCANCODE_F21;
	const uint32 keycode::f22 = SDL_SCANCODE_F22;
	const uint32 keycode::f23 = SDL_SCANCODE_F23;
	const uint32 keycode::f24 = SDL_SCANCODE_F24;
	const uint32 keycode::execute = SDL_SCANCODE_EXECUTE;
	const uint32 keycode::help = SDL_SCANCODE_HELP;
	const uint32 keycode::menu = SDL_SCANCODE_MENU;
	const uint32 keycode::select = SDL_SCANCODE_SELECT;
	const uint32 keycode::stop = SDL_SCANCODE_STOP;
	const uint32 keycode::again = SDL_SCANCODE_AGAIN;
	const uint32 keycode::undo = SDL_SCANCODE_UNDO;
	const uint32 keycode::cut = SDL_SCANCODE_CUT;
	const uint32 keycode::copy = SDL_SCANCODE_COPY;
	const uint32 keycode::paste = SDL_SCANCODE_PASTE;
	const uint32 keycode::find = SDL_SCANCODE_FIND;
	const uint32 keycode::mute = SDL_SCANCODE_MUTE;
	const uint32 keycode::volumeup = SDL_SCANCODE_VOLUMEUP;
	const uint32 keycode::volumedown = SDL_SCANCODE_VOLUMEDOWN;
	const uint32 keycode::kp_comma = SDL_SCANCODE_KP_COMMA;
	const uint32 keycode::kp_equalsas400 = SDL_SCANCODE_KP_EQUALSAS400;
	const uint32 keycode::international1 = SDL_SCANCODE_INTERNATIONAL1;
	const uint32 keycode::international2 = SDL_SCANCODE_INTERNATIONAL2;
	const uint32 keycode::international3 = SDL_SCANCODE_INTERNATIONAL3;
	const uint32 keycode::international4 = SDL_SCANCODE_INTERNATIONAL4;
	const uint32 keycode::international5 = SDL_SCANCODE_INTERNATIONAL5;
	const uint32 keycode::international6 = SDL_SCANCODE_INTERNATIONAL6;
	const uint32 keycode::international7 = SDL_SCANCODE_INTERNATIONAL7;
	const uint32 keycode::international8 = SDL_SCANCODE_INTERNATIONAL8;
	const uint32 keycode::international9 = SDL_SCANCODE_INTERNATIONAL9;
	const uint32 keycode::lang1 = SDL_SCANCODE_LANG1;
	const uint32 keycode::lang2 = SDL_SCANCODE_LANG2;
	const uint32 keycode::lang3 = SDL_SCANCODE_LANG3;
	const uint32 keycode::lang4 = SDL_SCANCODE_LANG4;
	const uint32 keycode::lang5 = SDL_SCANCODE_LANG5;
	const uint32 keycode::lang6 = SDL_SCANCODE_LANG6;
	const uint32 keycode::lang7 = SDL_SCANCODE_LANG7;
	const uint32 keycode::lang8 = SDL_SCANCODE_LANG8;
	const uint32 keycode::lang9 = SDL_SCANCODE_LANG9;
	const uint32 keycode::alterase = SDL_SCANCODE_ALTERASE;
	const uint32 keycode::sysreq = SDL_SCANCODE_SYSREQ;
	const uint32 keycode::cancel = SDL_SCANCODE_CANCEL;
	const uint32 keycode::clear = SDL_SCANCODE_CLEAR;
	const uint32 keycode::prior = SDL_SCANCODE_PRIOR;
	const uint32 keycode::ret2 = SDL_SCANCODE_RETURN2;
	const uint32 keycode::separator = SDL_SCANCODE_SEPARATOR;
	const uint32 keycode::out = SDL_SCANCODE_OUT;
	const uint32 keycode::oper = SDL_SCANCODE_OPER;
	const uint32 keycode::clearagain = SDL_SCANCODE_CLEARAGAIN;
	const uint32 keycode::crsel = SDL_SCANCODE_CRSEL;
	const uint32 keycode::exsel = SDL_SCANCODE_EXSEL;
	const uint32 keycode::kp_00 = SDL_SCANCODE_KP_00;
	const uint32 keycode::kp_000 = SDL_SCANCODE_KP_000;
	const uint32 keycode::thousandsseparator = SDL_SCANCODE_THOUSANDSSEPARATOR;
	const uint32 keycode::decimalseparator = SDL_SCANCODE_DECIMALSEPARATOR;
	const uint32 keycode::currencyunit = SDL_SCANCODE_CURRENCYUNIT;
	const uint32 keycode::currencysubunit = SDL_SCANCODE_CURRENCYSUBUNIT;
	const uint32 keycode::kp_leftparen = SDL_SCANCODE_KP_LEFTPAREN;
	const uint32 keycode::kp_rightparen = SDL_SCANCODE_KP_RIGHTPAREN;
	const uint32 keycode::kp_leftbrace = SDL_SCANCODE_KP_LEFTBRACE;
	const uint32 keycode::kp_rightbrace = SDL_SCANCODE_KP_RIGHTBRACE;
	const uint32 keycode::kp_tab = SDL_SCANCODE_KP_TAB;
	const uint32 keycode::kp_backspace = SDL_SCANCODE_KP_BACKSPACE;
	const uint32 keycode::kp_a = SDL_SCANCODE_KP_A;
	const uint32 keycode::kp_b = SDL_SCANCODE_KP_B;
	const uint32 keycode::kp_c = SDL_SCANCODE_KP_C;
	const uint32 keycode::kp_d = SDL_SCANCODE_KP_D;
	const uint32 keycode::kp_e = SDL_SCANCODE_KP_E;
	const uint32 keycode::kp_f = SDL_SCANCODE_KP_F;
	const uint32 keycode::kp_xor = SDL_SCANCODE_KP_XOR;
	const uint32 keycode::kp_power = SDL_SCANCODE_KP_POWER;
	const uint32 keycode::kp_percent = SDL_SCANCODE_KP_PERCENT;
	const uint32 keycode::kp_less = SDL_SCANCODE_KP_LESS;
	const uint32 keycode::kp_greater = SDL_SCANCODE_KP_GREATER;
	const uint32 keycode::kp_ampersand = SDL_SCANCODE_KP_AMPERSAND;
	const uint32 keycode::kp_dblampersand = SDL_SCANCODE_KP_DBLAMPERSAND;
	const uint32 keycode::kp_verticalbar = SDL_SCANCODE_KP_VERTICALBAR;
	const uint32 keycode::kp_dblverticalbar = SDL_SCANCODE_KP_DBLVERTICALBAR;
	const uint32 keycode::kp_colon = SDL_SCANCODE_KP_COLON;
	const uint32 keycode::kp_hash = SDL_SCANCODE_KP_HASH;
	const uint32 keycode::kp_space = SDL_SCANCODE_KP_SPACE;
	const uint32 keycode::kp_at = SDL_SCANCODE_KP_AT;
	const uint32 keycode::kp_exclam = SDL_SCANCODE_KP_EXCLAM;
	const uint32 keycode::kp_memstore = SDL_SCANCODE_KP_MEMSTORE;
	const uint32 keycode::kp_memrecall = SDL_SCANCODE_KP_MEMRECALL;
	const uint32 keycode::kp_memclear = SDL_SCANCODE_KP_MEMCLEAR;
	const uint32 keycode::kp_memadd = SDL_SCANCODE_KP_MEMADD;
	const uint32 keycode::kp_memsubtract = SDL_SCANCODE_KP_MEMSUBTRACT;
	const uint32 keycode::kp_memmultiply = SDL_SCANCODE_KP_MEMMULTIPLY;
	const uint32 keycode::kp_memdivide = SDL_SCANCODE_KP_MEMDIVIDE;
	const uint32 keycode::kp_plusminus = SDL_SCANCODE_KP_PLUSMINUS;
	const uint32 keycode::kp_clear = SDL_SCANCODE_KP_CLEAR;
	const uint32 keycode::kp_clearentry = SDL_SCANCODE_KP_CLEARENTRY;
	const uint32 keycode::kp_binary = SDL_SCANCODE_KP_BINARY;
	const uint32 keycode::kp_octal = SDL_SCANCODE_KP_OCTAL;
	const uint32 keycode::kp_decimal = SDL_SCANCODE_KP_DECIMAL;
	const uint32 keycode::kp_hexadecimal = SDL_SCANCODE_KP_HEXADECIMAL;
	const uint32 keycode::lctrl = SDL_SCANCODE_LCTRL;
	const uint32 keycode::lshift = SDL_SCANCODE_LSHIFT;
	const uint32 keycode::lalt = SDL_SCANCODE_LALT;
	const uint32 keycode::lgui = SDL_SCANCODE_LGUI;
	const uint32 keycode::rctrl = SDL_SCANCODE_RCTRL;
	const uint32 keycode::rshift = SDL_SCANCODE_RSHIFT;
	const uint32 keycode::ralt = SDL_SCANCODE_RALT;
	const uint32 keycode::rgui = SDL_SCANCODE_RGUI;
	const uint32 keycode::mode = SDL_SCANCODE_MODE;
	const uint32 keycode::audionext = SDL_SCANCODE_AUDIONEXT;
	const uint32 keycode::audioprev = SDL_SCANCODE_AUDIOPREV;
	const uint32 keycode::audiostop = SDL_SCANCODE_AUDIOSTOP;
	const uint32 keycode::audioplay = SDL_SCANCODE_AUDIOPLAY;
	const uint32 keycode::audiomute = SDL_SCANCODE_AUDIOMUTE;
	const uint32 keycode::mediaselect = SDL_SCANCODE_MEDIASELECT;
	const uint32 keycode::www = SDL_SCANCODE_WWW;
	const uint32 keycode::mail = SDL_SCANCODE_MAIL;
	const uint32 keycode::calculator = SDL_SCANCODE_CALCULATOR;
	const uint32 keycode::computer = SDL_SCANCODE_COMPUTER;
	const uint32 keycode::ac_search = SDL_SCANCODE_AC_SEARCH;
	const uint32 keycode::ac_home = SDL_SCANCODE_AC_HOME;
	const uint32 keycode::ac_back = SDL_SCANCODE_AC_BACK;
	const uint32 keycode::ac_forward = SDL_SCANCODE_AC_FORWARD;
	const uint32 keycode::ac_stop = SDL_SCANCODE_AC_STOP;
	const uint32 keycode::ac_refresh = SDL_SCANCODE_AC_REFRESH;
	const uint32 keycode::ac_bookmarks = SDL_SCANCODE_AC_BOOKMARKS;
	const uint32 keycode::brightnessdown = SDL_SCANCODE_BRIGHTNESSDOWN;
	const uint32 keycode::brightnessup = SDL_SCANCODE_BRIGHTNESSUP;
	const uint32 keycode::displayswitch = SDL_SCANCODE_DISPLAYSWITCH;
	const uint32 keycode::kbdillumtoggle = SDL_SCANCODE_KBDILLUMTOGGLE;
	const uint32 keycode::kbdillumdown= SDL_SCANCODE_KBDILLUMDOWN;
	const uint32 keycode::kbdillumup = SDL_SCANCODE_KBDILLUMUP;
	const uint32 keycode::eject = SDL_SCANCODE_EJECT;
	const uint32 keycode::sleep = SDL_SCANCODE_SLEEP;
	const uint32 keycode::app1 = SDL_SCANCODE_APP1;
	const uint32 keycode::app2 = SDL_SCANCODE_APP2;

	const uint32 keymod::none = KMOD_NONE;
	const uint32 keymod::lshift = KMOD_LSHIFT;
	const uint32 keymod::rshift = KMOD_RSHIFT;
	const uint32 keymod::lctrl = KMOD_LCTRL;
	const uint32 keymod::rctrl = KMOD_RCTRL;
	const uint32 keymod::lalt = KMOD_LALT;
	const uint32 keymod::ralt = KMOD_RALT;
	const uint32 keymod::lgui = KMOD_LGUI;
	const uint32 keymod::rgui = KMOD_RGUI;
	const uint32 keymod::num = KMOD_NUM;
	const uint32 keymod::caps = KMOD_CAPS;
	const uint32 keymod::mode = KMOD_MODE;
	const uint32 keymod::reserved = KMOD_RESERVED;

	const uint32 keyalt::lshift = 		0x0001;
	const uint32 keyalt::rshift = 		0x0002;
	const uint32 keyalt::shift = 		0x0003;
	const uint32 keyalt::lctrl = 		0x0004;
	const uint32 keyalt::rctrl = 		0x0008;
	const uint32 keyalt::lalt = 		0x0010;
	const uint32 keyalt::ralt = 		0x0020;
	const uint32 keyalt::lgui = 		0x0040;
	const uint32 keyalt::rgui = 		0x0080;
	const uint32 keyalt::numlock = 		0x0100;
	const uint32 keyalt::capslock = 	0x0200;
	const uint32 keyalt::key_mask = 	0x03FF;
	const uint32 keyalt::knext_exists = 0x4000;

}