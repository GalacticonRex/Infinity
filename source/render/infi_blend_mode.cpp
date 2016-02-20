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

infi_blend_t::infi_blend_t() {
	usage = 0;
	srcalpha = GL_ONE;
	srccolor = GL_ONE;
	dstalpha = GL_ZERO;
	dstcolor = GL_ZERO;
	funcalpha = GL_ADD;
	funccolor = GL_ADD;
	
	cache.insert( this );
}
infi_blend_t::~infi_blend_t() {
	cache.erase( this );
}

} }