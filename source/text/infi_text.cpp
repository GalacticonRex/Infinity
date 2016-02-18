#include "text/infi_text.h"
#include "text/infi_font.h"
#include "render/infi_canvas.h"
#include <fstream>

namespace INFI {
namespace text {

namespace {
	using namespace std;
	using namespace core;
	using namespace render;
}

/*static void debugdisplay( ostream& out, char value ) {
	if ( value >= 127 )
		out << '#';
	else if ( value > 96 )
		out << '=';
	else if ( value > 64 )
		out << '-';
	else if ( value > 32 )
		out << '.';
	else
		out << ' ';
}*/

static render::infi_canvas_t* __fbo;
static FT_Library __lib;

void InfiLInitText() {
	std::cerr << "Create Font Canvas" << std::flush << endl;
	__fbo = InfiCreateEmptyCanvas();
	std::cerr << "Collect Font Names" << std::flush << endl;
	//InfiLCollectFontNames();
	std::cerr << "Create Font Repository" << std::flush << endl;
	FT_Init_FreeType( &__lib );
	std::cerr << "Text Init Done" << std::flush << endl;
}

void InfiLQuitText() {
	std::cerr << "Destroy Text FBO" << std::flush << endl;
	InfiDestroyCanvas( __fbo );
	__fbo = NULL;
	std::cerr << "Free Font Names" << std::flush << endl;
	//InfiLFreeFontNames();
	std::cerr << "Done with the FreeType Library" << std::flush << endl;
	FT_Done_FreeType( __lib );
	std::cerr << "Finished Deallocation of Fonts" << std::flush << endl;
}

struct sized_font_handle {
	const char*	fname;
	uint32 size;
	uint32 outline;
};
struct cmp_handle {
	bool operator() ( const sized_font_handle& a, const sized_font_handle& b ) {
		int32 i = strcmp( a.fname, b.fname );
		return ( i < 0 ) || ( i == 0 && ( a.size < b.size || ( a.size == b.size && a.outline < b.outline ) ) );
	}
};
typedef std::map<sized_font_handle,infi_tt_font_t*,cmp_handle> ftmap;
static ftmap fontnames;

static FT_Face load_library( const char* fname, uint32 sz ) {
	ifstream istr( fname );
	if ( !istr.good() ) {
		istr.close();
		return NULL;
	} istr.close();
	
	FT_Face output;
	FT_New_Face( __lib, fname, 0, &output );
	FT_Set_Char_Size( output, sz<<6, sz<<6, 96, 96 );
	
	return output;
}
/* KILL */
const char* InfiGetFontName ( const char* a, INFI_fontFlags b ) {
	return NULL;
}
/* KILL */
static FT_Face load_sys_library( const char* fname, INFI_fontFlags flags, uint32 sz ) {
	std::cerr << "    WHOA!!!!!" << flush << endl;
	const char* sysname = InfiGetFontName( fname, flags );
	
	if ( sysname == NULL )
		return NULL;
	
	std::cerr << "    WHOA!!!!!" << flush << endl;
	
	ifstream istr( sysname );
	if ( !istr.good() ) {
		istr.close();
		return NULL;
	} istr.close();
	
	std::cerr << "    WHOA!!!!!" << flush << endl;
	
	FT_Face output;
	FT_New_Face( __lib, sysname, 0, &output );
	FT_Set_Char_Size( output, sz<<6, sz<<6, 96, 96 );
	
	std::cerr << "    WHOA!!!!!" << flush << endl;
	
	return output;
}
void raster_callback( const int32 y,
					  const int32 c,
					  const FT_Span * const spans,
					  void * const user ) {
	spanlp sptr = (spanlp) user;
	for ( int32 i=0;i<c;i++ )
		sptr->add( vec4i( spans[i].x, y, spans[i].len, spans[i].coverage ) );
}

infi_tt_font_t* InfiCreateFont( const string_t& nname, uint32 size, INFI_fontFlags flag, uint32 out ) {
	string_t name(nname);
	
	std::cerr << "WHOA!!!!!" << flush << endl;
	
	sized_font_handle hnd;
	hnd.fname = name.source();
	hnd.size = size;
	hnd.outline = out;
	
	std::cerr << "WHOA!!!!!" << flush << endl;
	
	ftmap::iterator iter = fontnames.find( hnd );
	
	std::cerr << "WHOA!!!!!" << flush << endl;
	
	if ( iter == fontnames.end() ) {
		
		std::cerr << "WHOA!!!!!" << flush << endl;
		
		FT_Face face;
		face = load_library( name.source(), size );
		if ( face == NULL ) {
			face = load_sys_library( name.source(), flag, size );
			if ( face == NULL ) {
				std::cerr << "FAILED" << endl;
				InfiSendError( INFI_FILE_NOT_FOUND, "InfiCreateFont", "could not create font from %s", name.source() );
				return NULL;
			}
		}
		
		std::cerr << "WHOA!!!!!" << flush << endl;
		
		infi_tt_font_t* nf = new infi_tt_font_t;
		InfiLInitFonts( nf );
		
		nf->source = face;
		nf->size = size;
		nf->outline = out;
		
		uint32 sz = size * 16;
		nf->buffer = InfiCreateTexture( { sz, sz }, INFI_BYTE, INFI_FLOAT, INFI_111R, true );
		InfiClearTexture( nf->buffer, {1,1,1,0} );
		InfiBilinearTexel( nf->buffer );
		InfiClampTexture( nf->buffer );
		
		memset(&(nf->params), 0, sizeof(nf->params));
		nf->params.flags = FT_RASTER_FLAG_AA | FT_RASTER_FLAG_DIRECT;
		nf->params.gray_spans = raster_callback;
		
		fontnames[hnd] = nf;
		
		std::cerr << "WHOA!!!!!" << flush << endl;
		
		return nf;
	} else
		return iter->second;
}

static inline void render_spans( FT_Raster_Params param, FT_Library& lib, FT_Outline * const out, spanl& s ) {
	param.user = &s;
	FT_Outline_Render( lib, out, &param);
}

static inline void gen_texture( uint32 w, uint32 h, vec4i r, spanl& sp, data_t<int8>& output ) {
	uint32 len = (w+1)*(h+1);
	output.resize( len );
	for ( uint32 i=0;i<len;++i )
		output[i] = 0;
	for ( uint32 i=0;i<sp.size();i++ )
		for ( int32 j=0;j<sp[i].z;j++ ) {
			int32 n = ( sp[i].y - r.y ) * w + sp[i].x - r.x + j;
			output[n] = std::min( 127, char(sp[i].w/2) + output[n] );
		}
}
infi_character_t* infi_tt_font_t::fetch( char k ) {
	
	CharMap::iterator iter = data.find( k );
	
	if ( iter == data.end() ) {
		
		infi_character_t* cc = self_get_new_char();
		
		FT_UInt id = FT_Get_Char_Index( source, k );
		FT_Load_Glyph( source, id, FT_LOAD_NO_BITMAP );
		
		spanl baselist;
		
		FT_Glyph glyph;
		FT_Get_Glyph( source->glyph, &glyph );
		
		if ( source->glyph->format == FT_GLYPH_FORMAT_OUTLINE ) {
			if ( outline != 0 ) {
				FT_Stroker stroker;
				FT_Stroker_New( __lib, &stroker );
				FT_Stroker_Set( stroker,
								(int32)(outline << 6),
								FT_STROKER_LINECAP_ROUND,
								FT_STROKER_LINEJOIN_ROUND, 0 );
				
				FT_Glyph_StrokeBorder(&glyph, stroker, 0, 1);
				
				render_spans( params,
							  __lib, 
							  &reinterpret_cast<FT_OutlineGlyph>(glyph)->outline, 
							  baselist );
				
				FT_Stroker_Done( stroker );
			} else
				render_spans( params, __lib, &(source->glyph->outline), baselist );
		} else
			InfiSendError( INFI_LIBRARY_ERROR, "TTFont.Fetch", "font does not have outline feature" );
		
		cc->advance.x = glyph->advance.x >> 16;
		
		data_t<int8> fontdata;
		vec2i ccdim;
		
		if ( baselist.size() != 0 ) {
			vec4i brect; // vec4 serves as rectangle (xmin,ymin,xmax,ymax)
			brect.x = brect.z = baselist[0].x;
			brect.y = brect.w = baselist[0].y;
			
			// Find limits of the bounding box
			for ( uint32 i=0;i<baselist.size();i++ ) {
				brect.x = std::min( brect.x, baselist[i].x );
				brect.y = std::min( brect.y, baselist[i].y );
				brect.z = std::max( brect.z, baselist[i].x + baselist[i].z );
				brect.w = std::max( brect.w, baselist[i].y );
			}
			
			cc->before.x = brect.x;
			cc->before.y = brect.y;
			cc->after.x =  brect.z;
			cc->after.y =  brect.w;
			
			mindim.x = std::min( cc->before.x - 1, mindim.x );
			mindim.y = std::min( cc->before.y - 1, mindim.y );
			
			maxdim.x = std::max( cc->after.x + 1, maxdim.x );
			maxdim.y = std::max( cc->after.y + 1, maxdim.y );
			
			int32 w = cc->after.x - cc->before.x + 1,
				h = cc->after.y - cc->before.y + 1;
			
			ccdim.x = w;
			ccdim.y = h;
			
			gen_texture( w,h, brect, baselist, fontdata );
			
			/*// <---- DISPLAY TEXT -------------------------------------------->
			for ( int32 y=0;y<h;y++ ) {
				( y == cc->after.y ) ? std::cerr << ">> " : std::cerr << ".. ";
				for ( int32 x=0;x<w;x++ ) 
					debugdisplay( std::cerr, (uint8)fontdata[y*w+x] );
				( y == cc->after.y ) ? std::cerr << " <<" : std::cerr << " ..";
				std::cerr << endl;
			} std::cerr << endl << endl;
			// <-------------------------------------------------------------->*/
			
		}
		
		FT_Done_Glyph( glyph );
		
		if ( anchor.x + ccdim.x > buffer->width() ) {
			anchor.x = 0;
			anchor.y += (maxdim.y-mindim.y+2);
		}
		
		rectui pxrect( anchor, vec2ui(ccdim) );
		InfiSetData( buffer, pxrect, (void*)fontdata.source() );
		
		cc->sample.x = (float32)anchor.x / (float32)(size * 16);
		cc->sample.y = (float32)anchor.y / (float32)(size * 16);
		
		cc->sample.w = (float32)ccdim.x / (float32)(size * 16);
		cc->sample.h = (float32)ccdim.y / (float32)(size * 16);
		
		anchor.x += ccdim.x + 1;
		
		data.insert( std::pair<char,infi_character_t*>( k, cc ) );
		
		return cc;
		
	} else
		return iter->second;
}

} }
