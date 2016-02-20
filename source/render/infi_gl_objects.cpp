#include "core/infi_map.h"
#include "main/infi_main.h"
#include "render/infi_gl_objects.h"
#include <set>

namespace INFI {
namespace render {
	
	typedef std::set<uint32> ObjSet;
	typedef core::map_t<SDL_GLContext,ObjSet*> ObjMap;
	ObjMap vertexarrays, framebuffers;
	
	static ObjSet* get_vertex_array() {
		SDL_GLContext ctx = InfiCurrentContext();
		ObjMap::iterator f = vertexarrays.find( ctx );
		if ( f == vertexarrays.end() ) {
			ObjSet* narr = new ObjSet;
			vertexarrays.insert( f, std::make_pair( ctx, narr ) );
			return narr;
		} else {
			return f->second;
		}
	}
	static ObjSet* get_framebuffer() {
		SDL_GLContext ctx = InfiCurrentContext();
		ObjMap::iterator f = framebuffers.find( ctx );
		if ( f == framebuffers.end() ) {
			ObjSet* narr = new ObjSet;
			framebuffers.insert( f, std::make_pair( ctx, narr ) );
			return narr;
		} else {
			return f->second;
		}
	}
	
	void InfiGLDestroyContextObjects( SDL_GLContext ctx ) {
		ObjMap::iterator vai = vertexarrays.find( ctx );
		if ( vai != vertexarrays.end() ) {
			ObjSet* va = vai->second;
			
			uint32* bufferva = new uint32[va->size()];
			
			ObjSet::iterator vaiter = va->begin();
			for ( uint32 i=0;vaiter!=va->end();++vaiter,++i )
				bufferva[i] = *vaiter;
			
			InfiGLDeleteVertexArrays( va->size(), bufferva );
			delete[] bufferva;
			delete va;
		}
		
		ObjMap::iterator fbi = framebuffers.find( ctx );
		if ( fbi != framebuffers.end() ) {
			ObjSet* fb = fbi->second;
			
			uint32* bufferfb = new uint32[fb->size()];
			
			ObjSet::iterator fbiter = fb->begin();
			for ( uint32 i=0;fbiter!=fb->end();++fbiter,++i )
				bufferfb[i] = *fbiter;
			
			InfiGLDeleteFramebuffers( fb->size(), bufferfb );
			delete[] bufferfb;
			delete fb;
		}
	}
	
	uint32 InfiGLCreateFramebuffer() {
		ObjSet* arr = get_framebuffer();
		uint32 hnd;
		InfiGLGenFramebuffers( 1, &hnd );
		arr->insert( hnd );
		return hnd;
	}
	uint32 InfiGLCreateVertexArray() {
		ObjSet* arr = get_vertex_array();
		uint32 hnd;
		InfiGLGenVertexArrays( 1, &hnd );
		arr->insert( hnd );
		return hnd;
	}
	
	void InfiGLDestroyFramebuffer( uint32 obj ) {
		ObjSet* arr = get_framebuffer();
		ObjSet::iterator iter = arr->find( obj );
		
		InfiGLDeleteVertexArrays( 1, &(*iter) );
		if ( iter != arr->end() )
			arr->erase( iter );
	}
	void InfiGLDestroyVertexArray( uint32 obj ) {
		ObjSet* arr = get_framebuffer();
		ObjSet::iterator iter = arr->find( obj );
		InfiGLDeleteFramebuffers( 1, &(*iter) );
		if ( iter != arr->end() )
			arr->erase( iter );
	}
	
} }