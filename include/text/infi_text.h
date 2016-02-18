#ifndef __INFI_TEXT_H__
#define __INFI_TEXT_H__

#include "core/infi_string.h"
#include "core/infi_vector.h"
#include "render/infi_program.h"

namespace INFI {
namespace text {
	
	typedef uint32 INFI_fontFlags;
	const uint32 INFI_FONT_REGULAR = 0x00,
			   INFI_FONT_BOLD = 0x01,
			   INFI_FONT_ITALIC = 0x02,
			   INFI_FONT_BOLD_ITALIC = 0x03;
	
	INFI_FUNCTION( void, InfiLCollectFontNames, () );
	INFI_FUNCTION( void, InfiLFreeFontNames, () );
	INFI_FUNCTION( const char*, InfiGetFontName, ( const char*, INFI_fontFlags = 0 ) );
	
	INFI_FUNCTION( void, InfiLInitText, () );
	INFI_FUNCTION( void, InfiLQuitText, () );
	
	struct INFI_EXPORT infi_character_t;
	struct INFI_EXPORT infi_font_metrics_t;
	struct INFI_EXPORT infi_font_t;
	struct INFI_EXPORT infi_bmp_load_table_t;
	struct INFI_EXPORT infi_bmp_font_t;
	struct INFI_EXPORT infi_tt_font_t;
	struct INFI_EXPORT infi_label_t;
	
} }

#endif//__INFI_TEXT_H__