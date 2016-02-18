#include "main/infi_gl.h"
#include "render/infi_blend_mode.h"
#include <set>

namespace INFI {
namespace render {
	
static std::set<infi_blend_t*> cache;
	
void InfiLEmptyBlendModeCache() {
	auto iter = cache.begin();
	for ( ;iter!=cache.end();++iter )
		delete *iter;
	cache.clear();
}

infi_blend_t* InfiCreateBlend() {
	infi_blend_t* ret = new infi_blend_t();
	
	ret->usage = 0;
	
	ret->srcalpha = GL_ONE;
	ret->srccolor = GL_ONE;
	ret->dstalpha = GL_ZERO;
	ret->dstcolor = GL_ZERO;
	ret->funcalpha = GL_ADD;
	ret->funccolor = GL_ADD;
	
	cache.insert( ret );
	
	return ret;
}

} }