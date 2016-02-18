#include "render/infi_storage_object.h"

namespace INFI {
namespace render {
	
	infi_storage_t::infi_storage_t() :
		handle(0),
		refcount( new uint32(1) ) { ; }
	infi_storage_t::infi_storage_t(const infi_storage_t& copy) :
		handle( copy.handle ),
		refcount( copy.refcount ) { increment(); }
	
	uint32 infi_storage_t::getHandle() const {
		return handle;
	}
	void infi_storage_t::increment() const {
		++ (*refcount);
	}
	void infi_storage_t::decrement() {
		if ( --(*refcount) == 0 ) {
			store_destroy_data();
			delete refcount;
		}
	}
	void infi_storage_t::assign( infi_storage_t& store ) const {
		store.refcount = refcount;
		store.handle = handle;
	}
	bool infi_storage_t::fork_data() {
		if ( handle != 0 && *refcount == 1 )
			return false;
		std::cerr << "fork data" << std::endl;
		decrement();
		handle = store_create_data();
		refcount = new uint32(1);
		return true;
	}
	
	
} }