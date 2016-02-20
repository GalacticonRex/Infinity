#include "render/infi_vertices.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_objects.h"
#include <set>

namespace INFI {
namespace render {
	
static std::set<infi_vertices_t*> cache;

void InfiLEmptyVertexCache() {
	auto iter = cache.begin();
	for ( ;iter!=cache.end();++iter )
		InfiDestroyVertices( *iter );
	cache.clear();
}
	
uint32 infi_vertices_t::CreateNewHandle( infi_window_t* win ) {
	InfiPushFunction( "infi_vertices_t.create_handle" );
	uint32 hnd = InfiGLCreateVertexArray();
	InfiPopFunction();
	return hnd;
}
void infi_vertices_t::SyncObject( const local_handle& temp,
								  uint32 index,
								  const infi_vertex_binding_t& buf ) {
	InfiPushFunction( "infi_vertices_t.sync" );
	InfiGLPushVertexArray( temp.handle );
	
	if ( buf.data.disable ) {
		InfiGLDisableVertexAttribArray( index );
	} else {
		InfiGLEnableVertexAttribArray( index );
		InfiGLBindBuffer( GL_ARRAY_BUFFER, buf.buffer->getHandle() );
		buf.field.enable( index, buf.data.stride );
	}
	
	InfiGLPopVertexArray();
	InfiPopFunction();
}
void infi_vertices_t::get_vertex_count() {
	vcount = 0;
	for ( uint32 i=0;i<buffers.size();++i ) {
		uint32 sz = buffers[i].buffer()->bytesize / buffers[i].format()->stride();
		vcount = (vcount==0) ? sz : std::min( sz, vcount );
	}
	if ( indices != NULL ) {
		uint32 sz = indices->bytesize / infi_sizeof(INFI_UINT);
		vcount = (vcount==0) ? sz : std::min( sz, vcount );
	}
}

infi_vertices_t* InfiCreateVertices() {
	infi_vertices_t* vb = new infi_vertices_t;
	
	vb->vcount = 0;
	vb->format = NULL;
	vb->indices = NULL;
	
	cache.insert( vb );
	return vb;
	
}
void InfiDestroyVertices( infi_vertices_t* vb ) {
	cache.erase( vb );
	delete vb;
}
infi_vertices_t* InfiCopyVertices( infi_vertices_t const* vb ) {
	InfiPushFunction( "InfiCopyVertices" );
	infi_vertices_t* ret = new infi_vertices_t( *vb );
	
	ret->vcount = vb->vcount;
	ret->format = vb->format;
	ret->indices = vb->indices;
	ret->inuse = vb->inuse;
	
	InfiPopFunction();
	return ret;
}

uint32 InfiBindVertices( infi_vertices_t* verts,
						 const infi_formatted_buffer_t& buffer ) {
	InfiPushFunction( "InfiBindVertices" );
	
	if ( verts->format == NULL )
		InfiSendError( INFI_BINDING_ERROR,
					   "cannot bind buffer to unformatted vertex object" );
	
	const infi_buffer_t* b = buffer.buffer();   
	const infi_format_t* f = buffer.format(); 
	uint32 stride = f->stride();
	
	for ( uint32 i=0;i<f->size();++i ) {
		uint32 index = buffer.index(i);
		if ( verts->inuse[index] )
			InfiSendError( INFI_BINDING_ERROR,
						   "vertex attribute %d is already in use", index );
		if ( !(f->fields[i] == verts->format->fields[index] ) )
			InfiSendError( INFI_BINDING_ERROR,
						   "cannot map attribute %d in incoming buffer to %d in vertex object",
						   i, index );
		infi_vertex_binding_t vb;
		vb.buffer = b;
		vb.field = f->fields[i];
		vb.data.disable = false;
		vb.data.stride = stride;
		verts->add( index, vb );
		verts->inuse.set( index );
		++ verts->active;
	}
	
	verts->buffers.add( buffer );
	verts->get_vertex_count();
	
	InfiPopFunction();
	
	return verts->buffers.size() - 1;
}

void InfiSetFormat( infi_vertices_t* verts, infi_format_t const* form ) {
	InfiPushFunction( "InfiBindVertices" );
	if ( verts->format != NULL ) {
		for ( uint32 i=0;i<verts->format->size();++i ) {
			if ( verts->exists(i) && !(verts->get(i).field == form->fields[i]) )
				InfiSendError( INFI_BINDING_ERROR,
						  	   "cannot remap attribute %d in vertex object", i );
		}
	}
	verts->format = form;
	InfiPopFunction();
}
void InfiSetIndices( infi_vertices_t* verts, infi_buffer_t const* buffer ) {
	verts->indices = buffer;
	verts->get_vertex_count();
}
void InfiClearVertices( infi_vertices_t* verts, infi_format_t const* buffer ) {
	for ( uint32 i=0;i<verts->inuse.size();++i ) {
		if ( verts->inuse[i] ) {
			infi_vertex_binding_t vb;
			vb.data.disable = false;
			verts->add( i, vb );
		}
	}
	verts->inuse.clear();
	verts->buffers.clear();
	verts->active = 0;
	verts->indices = NULL;
	verts->format = NULL;
	verts->vcount = 0;
}

static core::stack_t<infi_vertices_t*> vertstack;

infi_vertices_t* InfiCurrentVertices() {
	return ( vertstack.empty() ) ? NULL : *vertstack;
}
void InfiPushVertices( infi_vertices_t* verts ) {
	InfiPushFunction( "InfiPushVertices" );
	vertstack.push( verts );
	InfiPopFunction();
}
void InfiPopVertices() {
	InfiPushFunction( "InfiPopVertices" );
	vertstack.pop();
	InfiPopFunction(); 
}

} }