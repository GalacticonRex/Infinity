#ifndef __INFI_INPUT_H__
#define __INFI_INPUT_H__

#include "core/infi_string.h"
#include "render/infi_texture.h"
#include "render/infi_vertices.h"

namespace INFI {
namespace io {

struct INFI_EXPORT directory;

INFI_FUNCTION( core::string_t, InfiLoadText, ( const core::string_t& ) );
INFI_FUNCTION( render::infi_texture_t*, InfiLoadTexture, ( const core::string_t& ) );
INFI_FUNCTION( render::infi_vertices_t*, InfiLoadModel, ( const core::string_t& ) );

INFI_FUNCTION( void, InfiLResetTextureAtlas, () );

} }

#endif//__INFI_INPUT_H__