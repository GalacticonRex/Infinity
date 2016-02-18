#ifndef __INFI_HASH_FUNC_H__
#define __INFI_HASH_FUNC_H__

#include "main/infi_types.h"

namespace INFI {
namespace core {
	
	typedef uint32 (*INFI_hash_func)( uint32, uint32* );
	
} }

#endif//__INFI_HASH_FUNC_H__