#include "core/infi_map.h"
#include "core/infi_datablock.h"
#include "io/infi_load.h"
#include "main/infi_error.h"
#include "main/infi_time.h"
#include "main/infi_main.h"
#include "render/infi_texture.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_control.h"
#include <fstream>

#include "jpeg/jpeglib.h"

namespace INFI {
namespace io {

namespace {
	using namespace std;
	using namespace core;
	using namespace render;
}

infi_texture_t* openAsJpeg( const char* filename ) {
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	
	FILE * infile;
	JSAMPARRAY buffer;
	int32 row_stride;
	
	if ((infile = fopen(filename, "rb")) == NULL) {
		InfiSendError( INFI_FILE_NOT_FOUND, "no file named %s", filename );
		return NULL;
	}
	
	cinfo.err = jpeg_std_error(&jerr);
	
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, infile);
	
	(void) jpeg_read_header(&cinfo, TRUE);
	(void) jpeg_start_decompress(&cinfo);
	
	row_stride = ( cinfo.output_width * cinfo.output_components );
	uint32 irwst = row_stride;
	if ( row_stride % 4 )
		row_stride += 4 - row_stride % 4;
	
	buffer = (*cinfo.mem->alloc_sarray)
	((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);
	
	uint32 buflen = row_stride * cinfo.output_height;
	char* mainbuf = new char[buflen];
	
	uint32 scanlines = 1;
	uint32 index = 0;
	
	infi_texture_t* ntex = InfiCreateTexture( {cinfo.output_width,cinfo.output_height},
												INFI_UBYTE, INFI_FLOAT, INFI_RGB, true );
	
	while (cinfo.output_scanline < cinfo.output_height) {
		(void) jpeg_read_scanlines(&cinfo, buffer, scanlines);
		uint32 offset = row_stride * ( ntex->height() - index - 1 );
		memcpy( mainbuf + offset,
				buffer[0],
				irwst );
		index += scanlines;
	}
	
	InfiSetData( ntex, mainbuf );
	
	delete[] mainbuf;
	(void) jpeg_finish_decompress(&cinfo);
	
	jpeg_destroy_decompress(&cinfo);
	fclose(infile);
	
	return ntex;
}

typedef core::map_t<core::string_t,infi_texture_t*> TexAtlas;
typedef TexAtlas::iterator TexAtlasIter;
TexAtlas loadatlas;

infi_texture_t* InfiLoadTexture( const string_t& fname ) {
	InfiPushFunction( "InfiLoadTexture" );
	infi_texture_t* output = NULL;
	
	string_t str(fname);
	
	TexAtlasIter iter = loadatlas.find( str );
	if ( iter != loadatlas.end() ) {
		InfiPopFunction();
		return iter->second;
	}
	
	string_t ext = string_t( str.fromback( '.' ) );
	//std::cerr << ext << flush << endl;
	
	if ( ext == "jpg" || ext == "jpeg" || ext == "JPG" || ext == "JPEG" ) {
		
		output = openAsJpeg( str.source() );
		
	} else {
	
		ifstream istr( str.source() );
		if ( !istr.good() ) {
			InfiSendError( INFI_FILE_NOT_FOUND, "no image file named %s", str.source() );
		} istr.close();
		
		SDL_Surface* imgload = NULL;// = IMG_Load( str.source() );
		if ( imgload == NULL ) {
			InfiSendError( INFI_UNSUPPORTED_TYPE, "file %s cannot be opened", str.source() );
		}
		
		uint32 width = imgload->w,
			 height = imgload->h,
			 pitch = imgload->pitch;
		
		SDL_PixelFormat* pxfm = imgload->format;
		uint32 form = pxfm->format;
		uint32 type = SDL_PIXELTYPE(form);
		uint32 order = SDL_PIXELORDER(form);
		uint32 layout = SDL_PIXELLAYOUT(form);
		
		SDL_LockSurface( imgload );
		
		if ( type == SDL_PIXELTYPE_INDEX1 ) {
			//std::cerr << "index 1 bit" << endl;
		} else if ( type == SDL_PIXELTYPE_INDEX4 ) {
			//std::cerr << "index 4 bit" << endl;
		} else if ( type == SDL_PIXELTYPE_INDEX8 ) {
			if ( pxfm->palette == NULL ) {
				InfiSendError( INFI_LOAD_UNSUCCESSFUL, "%s (palette not found for indexed image)", str.source() );
			}
			if ( order == SDL_BITMAPORDER_4321 ) {
				//std::cerr << "order 4321" << endl;
			} else if ( order == SDL_BITMAPORDER_1234 ) {
				//std::cerr << "order 1234" << endl;
			} else {
				
				//std::cerr << "INDEX 8 IMAGE LOADING......." << endl;
				output = InfiCreateTexture( {width,height}, INFI_UBYTE, INFI_FLOAT, INFI_RGBA, true );
				
				SDL_Palette* pal = imgload->format->palette;
				uint8* indices = (uint8*) imgload->pixels;
				
				data_t<uint8> pixels( width*height*4 );
				
				for ( uint32 y=0;y<height;y++ )
					for ( uint32 x=0;x<width;x++ ) {
						SDL_Color tmp = pal->colors[indices[x+y*pitch]];
						pixels[4*(x+y*width)+0] = tmp.r;
						pixels[4*(x+y*width)+1] = tmp.g;
						pixels[4*(x+y*width)+2] = tmp.b;
						pixels[4*(x+y*width)+3] = tmp.a;
					}
				InfiSetData( output, pixels );
				
			}
		} else if ( type == SDL_PIXELTYPE_PACKED8 ) {
			//std::cerr << "packed 8 bit" << endl;
		} else if ( type == SDL_PIXELTYPE_PACKED16 ) {
			//std::cerr << "packed 16 bit" << endl;
		} else if ( type == SDL_PIXELTYPE_PACKED32 ) {
			
			if ( layout == SDL_PACKEDLAYOUT_NONE ) {
				InfiSendError( INFI_LOAD_UNSUCCESSFUL, "%s (array packing layout not found)", str.source() );
			} else if ( layout == SDL_PACKEDLAYOUT_8888 ) {
				
				//std::cerr << "PACKED 8888 IMAGE LOADING......." << endl;
				
				output = InfiCreateTexture( {width,height}, INFI_UBYTE, INFI_FLOAT, INFI_RGBA, true );
				InfiSetData( output, imgload->pixels );
				
			} else if ( layout == SDL_PACKEDLAYOUT_2101010 ) {
				//std::cerr << "2 10 10 10" << endl;
			} else if ( layout == SDL_PACKEDLAYOUT_1010102 ) {
				//std::cerr << "10 10 10 2" << endl;
			} else {
				//std::cerr << "who knows" << endl;
			}
			
		} else if ( type == SDL_PIXELTYPE_ARRAYU8 ) {
			
			if ( order == SDL_ARRAYORDER_NONE ) {
				InfiSendError( INFI_LOAD_UNSUCCESSFUL, "%s (no array order found)", str.source() );
			} else if ( order == SDL_ARRAYORDER_RGB ) {
				
				//std::cerr << "RGB8 IMAGE LOADING......." << endl;
				
				output = InfiCreateTexture( {width,height}, INFI_UBYTE, INFI_FLOAT, INFI_RGB, true );
				InfiSetData( output, imgload->pixels );
				
			} else if ( order == SDL_ARRAYORDER_RGBA ) {
				//std::cerr << "array RGBA" << endl;
			} else if ( order == SDL_ARRAYORDER_ARGB ) {
				//std::cerr << "array ARGB" << endl;
			} else if ( order == SDL_ARRAYORDER_BGR ) {
				//std::cerr << "array BGR" << endl;
			} else if ( order == SDL_ARRAYORDER_BGRA ) {
				//std::cerr << "array BGRA" << endl;
			} else if ( order == SDL_ARRAYORDER_ABGR ) {
				//std::cerr << "array ABGR" << endl;
			} else {
				//std::cerr << "who knows" << endl;
			}
			
		} else if ( type == SDL_PIXELTYPE_ARRAYU16 ) {
			//std::cerr << "array u16" << endl;
		} else if ( type == SDL_PIXELTYPE_ARRAYU32 ) {
			//std::cerr << "array u32" << endl;
		} else if ( type == SDL_PIXELTYPE_ARRAYF16 ) {
			//std::cerr << "array f16" << endl;
		} else if ( type == SDL_PIXELTYPE_ARRAYF32 ) {
			//std::cerr << "array f32" << endl;
		} else {
			InfiSendError( INFI_LOAD_UNSUCCESSFUL, "%s (image pixel structure unknown)", str.source() );
		}
		
		//object2D::InfiInvertTexture( output );
		
		InfiRepeatTexture( output );
		InfiBilinearTexel( output );
		
		// Free SDL Surface
		SDL_UnlockSurface( imgload );
		SDL_FreeSurface( imgload );
	}
	
	//std::cerr << "WORKING" << flush << endl;
	loadatlas.insert( std::pair<string_t,infi_texture_t*>( str, output ) );
	//std::cerr << "WORKING" << flush << endl;
	InfiPopFunction();
	
	return output;
}

void InfiLResetTextureAtlas() {
	loadatlas.clear();
}

} }
