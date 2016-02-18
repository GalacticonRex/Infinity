#ifndef __INFI_EXPORT_OPS_H__
#define __INFI_EXPORT_OPS_H__

// Build Type ( DLL vs EXE )
#ifndef INFI_BUILD_AS_EXE
	#ifdef INFI_BUILD_AS_DLL
		#define INFI_FUNCTION(x,y,z) x __declspec(dllexport) y z
		#define INFI_FUNCTION_(x,y) x __declspec(dllexport) y()
		#define INFI_EXPORT __declspec(dllexport)
	#else
		#define INFI_FUNCTION(x,y,z) x __declspec(dllimport) y z
		#define INFI_FUNCTION_(x,y) x __declspec(dllimport) y()
		#define INFI_EXPORT __declspec(dllimport)
	#endif
#else
	#define INFI_FUNCTION(x,y,z) x y z
	#define INFI_FUNCTION_(x,y) x y()
	#define INFI_EXPORT
#endif

#endif//__INFI_EXPORT_OPS_H__

