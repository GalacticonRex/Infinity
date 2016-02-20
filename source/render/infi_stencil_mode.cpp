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

infi_stencil_t::infi_stencil_t() {
	usage = 0;
	func = GL_ALWAYS;
	ref = 0;
	mask = 0;
	sfail = GL_KEEP;
	dpfail = GL_KEEP;
	dppass = GL_KEEP;
	wmask = 0;
	cache.insert( this );
}
infi_stencil_t::~infi_stencil_t() {
	cache.erase( this );
}

} }