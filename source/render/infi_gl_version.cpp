#include <vector>
#include <sstream>
#include <iterator>

#include "base/error_log.hpp"
#include "render/gl/infi_gl_version.hpp"

namespace Infinity {
namespace Render {

const infi_gl_version_t infi_gl_version_t::maximum_version(4,5);
const infi_gl_version_t infi_gl_version_t::minimum_version(1,0);

infi_gl_version_t::infi_gl_version_t( uint32 mj, uint32 mn )
	: _major(mj), _minor(mn) { ; }

infi_gl_version_t::infi_gl_version_t( const std::string& parse ) {
	//Error::define_scope __scope__( "infi_gl_version_t.ctor" );
	std::vector<std::string> parsed;

	std::istringstream stream(parse);
	copy(	std::istream_iterator<std::string>(stream),
			std::istream_iterator<std::string>(),
			std::back_inserter(parsed));

	std::string data = parsed[0];
	std::string buffer;
	std::vector<int> integers;

	for ( uint32 i=0;i<data.size();i++ ) {
		if ( data[i] == '.' ) {
			integers.push_back(std::stoi(buffer));
			buffer = "";
		} else
			buffer += data[i];
	}

	if ( integers.size() < 2 )
		Error::send<Error::Fatality::Method>(
			Error::Type::Value,
			"Invalid GL version string '%s'", parse.c_str()
		);

	_major = integers[0];
	_minor = integers[1];
}

bool infi_gl_version_t::operator< (infi_gl_version_t& v) const {
	return ( _major < v._major || ( _major == v._major && _minor < v._minor ) );
}
bool infi_gl_version_t::operator<= (infi_gl_version_t& v) const {
	return ( _major < v._major || ( _major == v._major && _minor <= v._minor ) );
}
bool infi_gl_version_t::operator> (infi_gl_version_t& v) const {
	return ( _major > v._major || ( _major == v._major && _minor > v._minor ) );
}
bool infi_gl_version_t::operator>= (infi_gl_version_t& v) const {
	return ( _major > v._major || ( _major == v._major && _minor >= v._minor ) );
}

bool infi_gl_version_t::operator< (const std::string& v) const {
	//Error::define_scope __scope__( "infi_gl_version_t.lt" );
	infi_gl_version_t glv(v);
	return (*this < glv);
}
bool infi_gl_version_t::operator<= (const std::string& v) const {
	//Error::define_scope __scope__( "infi_gl_version_t.lt" );
	infi_gl_version_t glv(v);
	return (*this <= glv);
}
bool infi_gl_version_t::operator> (const std::string& v) const {
	//Error::define_scope __scope__( "infi_gl_version_t.gt" );
	infi_gl_version_t glv(v);
	return (*this > glv);
}
bool infi_gl_version_t::operator>= (const std::string& v) const {
	//Error::define_scope __scope__( "infi_gl_version_t.gt" );
	infi_gl_version_t glv(v);
	return (*this >= glv);
}

uint32 infi_gl_version_t::major() const { return _major; }
uint32 infi_gl_version_t::minor() const { return _minor; }

} }
