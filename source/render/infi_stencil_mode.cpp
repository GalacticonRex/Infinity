#include "main/infi_gl.h"
#include "render/infi_stencil_mode.h"
#include <set>

namespace INFI {
namespace render {
	
static std::set<infi_stencil_t*> cache;
	
void InfiLEmptyStencilModeCache() {
	auto iter = cache.begin();
	for ( ;iter!=cache.end();++iter )
		delete *iter;
	cache.clear();
}

infi_stencil_t* InfiCreateStencil() {
	infi_stencil_t* ret = new infi_stencil_t();
	ret->usage = 0;
	ret->func = GL_ALWAYS;
	ret->ref = 0;
	ret->mask = 0;
	ret->sfail = GL_KEEP;
	ret->dpfail = GL_KEEP;
	ret->dppass = GL_KEEP;
	ret->wmask = 0;
	
	cache.insert( ret );
	
	return ret;
}

} }