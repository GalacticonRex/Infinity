#ifndef __INFI_GL_VERSION_H__
#define __INFI_GL_VERSION_H__

#include <string>
#include "render/gl/infi_gl_defs.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_version_t {
	private:

		uint32 _major;
		uint32 _minor;

	public:

		static const infi_gl_version_t maximum_version;
		static const infi_gl_version_t minimum_version;

		infi_gl_version_t( uint32, uint32 );
		infi_gl_version_t( const std::string& );

		bool operator< (infi_gl_version_t&) const;
		bool operator> (infi_gl_version_t&) const;
		bool operator<= (infi_gl_version_t&) const;
		bool operator>= (infi_gl_version_t&) const;

		bool operator< (const std::string&) const;
		bool operator> (const std::string&) const;
		bool operator<= (const std::string&) const;
		bool operator>= (const std::string&) const;

		uint32 major() const;
		uint32 minor() const;

	};

} }

#endif//__INFI_GL_VERSION_H__
