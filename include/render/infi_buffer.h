#ifndef __INFI_BUFFER_H__
#define __INFI_BUFFER_H__

#include "core/infi_indexable.h"
#include "render/infi_render_structs.h"
#include "render/infi_render.h"
#include "render/infi_storage_object.h"

namespace INFI {
namespace render {

const uint32 INFI_BUFFER_READ = GL_MAP_READ_BIT,
			 INFI_BUFFER_WRITE = GL_MAP_WRITE_BIT,
			 INFI_BUFFER_PERSISTENT = GL_MAP_PERSISTENT_BIT,
			 INFI_BUFFER_COHERENT = GL_MAP_COHERENT_BIT;

struct infi_buffer_t : infi_storage_t {
	uint32 flags;
	uint32 byteuse;
	uint32 bytesize;
	uint8* mapped;
	
	infi_buffer_t( INFI_array_write = INFI_W_STATIC );
	infi_buffer_t( const core::indexable_t<uint8>&,
				   INFI_array_write = INFI_W_STATIC );
	infi_buffer_t( const infi_buffer_t& );
	
	~infi_buffer_t();
	
	void setData( const core::indexable_t<uint8>& );
	void setData( uint32, const core::indexable_t<uint8>& );
	void getData( core::data_t<uint8>& ) const;
	
	void resizeData( uint32 );
	
	uint8 operator[] ( uint32 ) const;
	void* operator* () const;
	
	void const* read() const;
	void* write() const;
	
	uint32 dbg_handle() const;
	void dbg_print() const;
	
	protected:
		uint32 store_create_data();
		uint32 store_copy_data();
		void store_destroy_data();
		
	private:
		static void* map_buffer( const char*, uint32, uint32 );
		static void unmap_buffer( const char*, uint32 );
		static uint32 mapped_buffer;
		static uint8* mapped_data;
};

} }

#endif//__INFI_BUFFER_H__