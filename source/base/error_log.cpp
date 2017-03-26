#include "base/error_log.hpp"

namespace Error {

	Time::Point __internalTimePoint__ = Time::Now();

	__internalErrorInput__& Log() {
		thread_local __internalErrorInput__ __log__;
		return __log__;
	}

	std::stack<std::string>& DEFINE_EXPORT __internalGetErrorStack__() {
		thread_local std::stack<std::string> __error__;
		return __error__;
	}

	define_scope::define_scope(const std::string& func) {
		//Error::Log().push(func);
		//__internalGetErrorStack__().push(func);
	}
	define_scope::~define_scope() {
		//Error::Log().pop();
		//__internalGetErrorStack__().pop();
	}
	
	const char* errorFatality(Fatality f) {
		switch(f) {
			case Fatality::Warning:
				return "Warning";
				break;
			case Fatality::Method:
				return "Method";
				break;
			case Fatality::Thread:
				return "Thread";
				break;
			case Fatality::Fatal:
				return "Fatal";
				break;
			default:
				return "Unknown";
		}
	}
	const char* errorType(Type t) {
		switch(t) {
			case Type::None:
				return "None";
				break;
			case Type::Message:
				return "Message";
				break;
			case Type::Warning:
				return "Warning";
				break;
			case Type::Ignored:
				return "Ignored";
				break;
			case Type::Unimplemented:
				return "Unimplemented";
				break;
			case Type::System:
				return "System";
				break;
			case Type::Library:
				return "Library";
				break;
			case Type::Graphics:
				return "Graphics";
				break;
			case Type::Failed:
				return "Failed";
				break;
			case Type::NullDeref:
				return "NullDeref";
				break;
			case Type::Overflow:
				return "Overflow";
				break;
			case Type::Underflow:
				return "Underflow";
				break;
			case Type::Index:
				return "Index";
				break;
			case Type::Value:
				return "Value";
				break;
			case Type::Type:
				return "Type";
				break;
			case Type::Init:
				return "Init";
				break;
			case Type::Binding:
				return "Binding";
				break;
			case Type::Locked:
				return "Locked";
				break;
			case Type::NotFound:
				return "Not Found";
				break;
			case Type::CannotReadFile:
				return "Cannot Read File";
				break;
			case Type::UnsupportedType:
				return "Unsupported Type";
				break;
			case Type::Unresolved:
				return "Unresolved";
				break;
			default:
				return "Unknown";
		}
	}
}

std::ostream& operator<<(std::ostream& ostr, Error::Fatality f) {
	ostr << Error::errorFatality(f);
	return ostr;
}
std::ostream& operator<<(std::ostream& ostr, Error::Type t) {
	ostr << Error::errorType(t);
	return ostr;
}