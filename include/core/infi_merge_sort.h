#ifndef __INFI_MERGE_SORT_H__
#define __INFI_MERGE_SORT_H__

#include "core/infi_sort.h"
#include "core/infi_array.h"

namespace INFI {
namespace core {

template<typename T>
static void __mergeelement( T* writeto, T* readfrom, uint32& i, uint32 half, uint32 divis, SortFunction<T> sfunc ) {
	uint32 remA = i + half,
		 remB = i + divis;
	uint32 posA = i,
		 posB = i + half;
	while ( posA != remA || posB != remB ) {
		if ( posA == remA ) {
			writeto[i] = readfrom[posB];
			posB ++ ;
		} else if ( posB == remB ) {
			writeto[i] = readfrom[posA];
			posA ++ ;
		} else if ( sfunc( readfrom[posA], readfrom[posB] ) ) {
			writeto[i] = readfrom[posA];
			posA ++ ;
		} else {
			writeto[i] = readfrom[posB];
			posB ++ ;
		}
		i ++ ;
	}
}
template<typename T>
static void mergesort( T* data, T* buffer, uint32 length, SortFunction<T> sfunc ) {
	uint32 divis = 2;
	T* readfrom = data;
	T* writeto = buffer;
	
	uint32 ct = 2;
	while ( 1 ) {
		uint32 i = 0;
		uint32 d2 = divis * 2;
		
		while ( i + d2 <= length )
			__mergeelement( writeto, readfrom, i, divis / 2, divis, sfunc );
		__mergeelement( writeto, readfrom, i, divis / 2, length - i, sfunc );
		
		if ( divis > length )
			break;
		divis = d2;
		
		T* tmp = readfrom;
		readfrom = writeto;
		writeto = tmp;
		ct ++ ;
	}
	
	if ( writeto != data )
		memcpy( data, buffer, length * sizeof( T ) );
}
template<typename T>
static void __mergeelementdata( T* writeto, T* readfrom, uint32& i, uint32 half, uint32 divis, SortFunctionData<T> sfunc, void* data ) {
	uint32 remA = i + half,
		 remB = i + divis;
	uint32 posA = i,
		 posB = i + half;
	while ( posA != remA || posB != remB ) {
		if ( posA == remA ) {
			writeto[i] = readfrom[posB];
			posB ++ ;
		} else if ( posB == remB ) {
			writeto[i] = readfrom[posA];
			posA ++ ;
		} else if ( sfunc( readfrom[posA], readfrom[posB], data ) ) {
			writeto[i] = readfrom[posA];
			posA ++ ;
		} else {
			writeto[i] = readfrom[posB];
			posB ++ ;
		}
		i ++ ;
	}
}
template<typename T>
static void mergesortdata( T* data, T* buffer, uint32 length, SortFunctionData<T> sfunc, void* vdata ) {
	uint32 divis = 2;
	T* readfrom = data;
	T* writeto = buffer;
	
	uint32 ct = 2;
	while ( 1 ) {
		uint32 i = 0;
		uint32 d2 = divis * 2;
		
		while ( i + d2 <= length )
			__mergeelementdata( writeto, readfrom, i, divis / 2, divis, sfunc, vdata );
		__mergeelementdata( writeto, readfrom, i, divis / 2, length - i, sfunc, vdata );
		
		if ( divis > length )
			break;
		divis = d2;
		
		T* tmp = readfrom;
		readfrom = writeto;
		writeto = tmp;
		ct ++ ;
	}
	
	if ( writeto != data )
		memcpy( data, buffer, length * sizeof( T ) );
}

template<typename T>
void MergeSort( T* first, uint32 length, SortFunction<T> sfunc ) {
	data_t<T> block( length );
	mergesort( first, block.get_data(), length, sfunc );
}

template<typename T>
void MergeSort( T* first, uint32 length, SortFunctionData<T> sfunc, void* data ) {
	data_t<T> block( length );
	mergesortdata( first, block.get_data(), length, sfunc, data );
}

} }

#endif//__INFI_SORT_H__