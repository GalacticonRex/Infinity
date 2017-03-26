#ifndef __ERROR_LOG_HPP__
#define __ERROR_LOG_HPP__

#include <thread>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdarg>

#include "base/lib_export.hpp"
#include "base/types.hpp"
#include "base/time.hpp"

#define __WriteError__(a) Error::Log() << a << " (" << __FILE__ << ":" << __LINE__ << ")" << std::endl

namespace Error {
	extern Time::Point DEFINE_EXPORT __internalTimePoint__;

	std::stack<std::string>& DEFINE_EXPORT __internalGetErrorStack__();

	struct DEFINE_EXPORT __internalErrorInput__ {
	private:
		std::ofstream _output;
		uint32 _indent;
	public:
		__internalErrorInput__() : _indent(0) {
			std::stringstream ss;
			ss << "ThreadError" << std::this_thread::get_id() << ".log";
			_output.open(ss.str());
			_output.rdbuf()->pubsetbuf(0, 0);
		}
		~__internalErrorInput__() {
			_output.flush();
			_output << "Closing!" << std::endl;
			_output.close();
		}
		operator std::ostream& () {
			return _output;
		}
		void push(const std::string& scope) {
			_output << std::string(_indent*4, ' ') << scope << " {" << std::endl;
			++ _indent;
		}
		void pop() {
			-- _indent;
			_output << std::string(_indent*4, ' ') << '}' << std::endl;
		}
		template<typename T>
		std::ostream& operator<< (T& elem) {
			_output << std::string(_indent*4, ' ')
					<< std::fixed
					<< std::setprecision( 6 )
					<< std::setw(12)
					<< (Time::Now() - __internalTimePoint__).count() / 1000000000
					<< " : " << elem;
			return _output;
		}
	};

	__internalErrorInput__& DEFINE_EXPORT Log();

	enum class Fatality {
		Warning,
		Method,
		Thread,
		Fatal
	};
	enum class Type {
		None,
		Message,
		Warning,
		Ignored,
		Unimplemented,
		System,
		Library,
		Graphics,
		Failed,
		NullDeref,
		Overflow,
		Underflow,
		Index,
		Value,
		Type,
		Init,
		Binding,
		Locked,
		NotFound,
		CannotReadFile,
		UnsupportedType,
		Unresolved
	};

	const char* DEFINE_EXPORT errorFatality(Fatality f);
	const char* DEFINE_EXPORT errorType(Type t);

	class DEFINE_EXPORT define_scope {
	public:
		define_scope(const std::string&);
		~define_scope();
	};

	template<Fatality T>
	class message {
	private:
		Type _type;
		std::string _data;
	public:
		message(Type t, const std::string& d) :
			_type(t), _data(d) { ; }

		Type type() {
			return _type;
		}
		void display(std::ostream& ostr) {
			ostr << errorFatality(T) << std::endl;
			ostr << errorType(_type) << std::endl;
			ostr << _data;
		}
	};

	template<Fatality T>
	static void send(Type t, const char* format, ...) {
		int8 buffer[256];
		
		va_list args;
		va_start( args, format );
		vsprintf( buffer, format, args );
		va_end( args );

		std::stringstream final;
		final << buffer << std::endl;
		std::stack<std::string> copy = Error::__internalGetErrorStack__();
				
		for (uint32 i=0;i<copy.size();i++) {
			final << "... " << copy.top() << std::endl;
			copy.pop();
		}
		
		throw message<T>(t,final.str());
	}
};

std::ostream& DEFINE_EXPORT operator<<(std::ostream&, Error::Fatality);
std::ostream& DEFINE_EXPORT operator<<(std::ostream&, Error::Type);

#endif//__ERROR_LOG_HPP__