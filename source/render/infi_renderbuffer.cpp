#include "render/infi_gl_wrapper.h"
#include "render/infi_renderbuffer.h"
#include <set>

namespace INFI {
namespace render {
	
	static std::set<infi_renderbuffer_t*> cache;
	
	void InfiLEmptyRenderbufferCache() {
		auto iter = cache.begin();
		for ( ;iter!=cache.end();++iter )
			InfiDestroyRenderbuffer( *iter );
		cache.clear();
	}
	
	infi_renderbuffer_t* InfiCreateRenderbuffer() {
		infi_renderbuffer_t* tmp = new infi_renderbuffer_t;
		
		InfiGLGenRenderbuffers( 1, &(tmp->handle) );
		
		tmp->pxformat = 0;
		tmp->samples = 1;
		
		cache.insert( tmp );
		
		return tmp;
	}
	infi_renderbuffer_t* InfiCreateRenderbuffer( uint32 width, uint32 height, GLenum format ) {
		infi_renderbuffer_t* tmp = new infi_renderbuffer_t;
		
		InfiGLGenRenderbuffers( 1, &(tmp->handle) );
		InfiGLBindRenderbuffer( tmp->handle );
		
		tmp->dimensions.x = width;
		tmp->dimensions.y = width;
		tmp->pxformat = format;
		tmp->samples = 1;
		
		InfiGLRenderbufferStorage( format, width, height );
		
		cache.insert( tmp );
		
		return tmp;
	}
	void InfiDestroyRenderbuffer( infi_renderbuffer_t* tmp ) {
		InfiGLDeleteRenderbuffers( 1, &(tmp->handle) );
		cache.erase( tmp );
		delete tmp;
	}
	
	void InfiFormat( infi_renderbuffer_t* tmp, uint32 width, uint32 height, GLenum format ) {
		InfiGLBindRenderbuffer( tmp->handle );
		
		tmp->dimensions.x = width;
		tmp->dimensions.y = width;
		tmp->pxformat = format;
		
		InfiGLRenderbufferStorage( format, width, height );
	}
	void InfiFormat( infi_renderbuffer_t* tmp, core::vec2ui dim, GLenum format ) {
		InfiGLBindRenderbuffer( tmp->handle );
		
		tmp->dimensions = dim;
		tmp->pxformat = format;
		
		InfiGLRenderbufferStorage( format, dim.x, dim.y );
	}
	
} }