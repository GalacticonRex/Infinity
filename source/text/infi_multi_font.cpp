#include "text/infi_font.h"
#include "render/infi_render.h"

namespace INFI {
namespace text {
	
	namespace {
		using namespace std;
		using namespace core;
		using namespace render;
	}
	
	void infi_font_container_t::rasterize( const vec2i& pos, const string_t& str, infi_font_functions_t* adv ) {
		if ( draw.size() == 0 )
			return;
		infi_font_functions_t* advf = (adv == NULL)?draw[advance].data:adv;
		
		InfiPushColor();
		vec3 c = draw[0].color;
		InfiSetColor( vec4(c.r,c.g,c.b,1.f) );
		draw[0].data->rasterize( pos + draw[0].offset - mindim + draw[0].data->mindim, str, advf );
		
		InfiGLPushBlendMode( BlendMix() );
		for ( uint32 i=1;i<draw.size();i++ ) {
			vec3 c = draw[i].color;
			InfiSetColor( vec4(c.r,c.g,c.b,1.f) );
			draw[i].data->rasterize( pos + draw[i].offset - mindim + draw[i].data->mindim, str, advf );
		}
		InfiGLPopBlendMode();
		InfiPopColor();
	}
	infi_character_t* infi_font_container_t::fetch( char k ) {
		
		CharMap::iterator iter = data.find( k );
	
		if ( iter == data.end() ) {
			infi_character_t* ch = self_get_new_char();
			ch->before = vec2i(((uint32)-1)/2,((uint32)-1)/2);
			ch->after = vec2i();
			
			for ( uint32 i=0;i<draw.size();i++ ) {
				infi_character_t* sch = draw[i].data->fetch( k );
				
				if ( sch->before.x < ch->before.x ) ch->before.x = sch->before.x;
				if ( sch->before.y < ch->before.y ) ch->before.y = sch->before.y;
				if ( sch->after.x > ch->after.x ) ch->after.x = sch->after.x;
				if ( sch->after.y > ch->after.y ) ch->after.y = sch->after.y;
				
				if ( sch->before.x - 1 < mindim.x ) mindim.x = sch->before.x - 1;
				if ( sch->before.y - 1 < mindim.y ) mindim.y = sch->before.y - 1;
				if ( sch->after.x + 1 > maxdim.x ) maxdim.x = sch->after.x + 1;
				if ( sch->after.y + 1 > maxdim.y ) maxdim.y = sch->after.y + 1;
				
				if ( i == advance ) ch->advance = sch->advance;
			}
			
			return ch;
		} else
			return iter->second;
	}
	
	infi_font_container_t* InfiCreateMultiFont() {
		infi_font_container_t* ft = new infi_font_container_t;
		ft->advance = 0;
		return ft;
	}
	void InfiAddToMultiFont( infi_font_container_t* cont, const string_t& ft, uint32 sz, INFI_fontFlags flg, uint32 out, vec3 col, vec2i offset ) {
		infi_font_container_t::__node& n = cont->draw.add();
		n.data = InfiCreateFont( ft, sz, flg, out );
		n.offset = offset;
		n.color = col;
	}
	void InfiAddToMultiFont( infi_font_container_t* cont, infi_font_t* f, vec3 col, vec2i offset ) {
		infi_font_container_t::__node& n = cont->draw.add();
		n.data = f;
		n.offset = offset;
		n.color = col;
	}
	void InfiSetMultiFontColor( infi_font_container_t* cont, vec3 col, uint32 i ) {
		if ( i >= cont->draw.size() ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "cannot set color at index %d out of %d", 
						   i, cont->draw.size() );
			return;
		}
		cont->draw[i].color = col;
	}
	void InfiSetAdvanceMultiFont( infi_font_container_t* cont, uint32 adv ) {
		if ( adv >= cont->draw.size() )
			InfiSendError( INFI_INDEX_ERROR,
						   "cannot set color at index %d out of %d", 
						   adv, cont->draw.size() );
		cont->advance = adv;
	}
	
} }