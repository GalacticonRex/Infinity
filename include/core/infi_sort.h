#ifndef __INFI_SORT_H__
#define __INFI_SORT_H__

namespace INFI {
namespace core {
	
template<typename T> using SortFunction = bool (*)(const T&, const T&);
template<typename T> using SortFunctionData = bool (*)(const T&, const T&,void*);
	
} }

#endif