#ifndef __INFI_MAP_H__
#define __INFI_MAP_H__

#include <map>

namespace INFI {
namespace core {
	
	template<typename T1,typename T2>
	using map_t = std::map<T1,T2>;
	
} }

#endif//__INFI_MAP_H__