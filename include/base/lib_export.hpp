#ifndef __LIB_EXPORT_H__
#define __LIB_EXPORT_H__

// Build Type ( DLL vs EXE )
#ifndef EXPORT_AS_EXE
	#ifdef EXPORT_AS_DLL
		#define DEFINE_EXPORTED_FUNCTION(x,y,z) x __declspec(dllexport) y z
		#define DEFINE_EXPORTED_FUNCTION_(x,y) x __declspec(dllexport) y()
		#define DEFINE_EXPORT __declspec(dllexport)
	#else
		#define DEFINE_EXPORTED_FUNCTION(x,y,z) x __declspec(dllimport) y z
		#define DEFINE_EXPORTED_FUNCTION_(x,y) x __declspec(dllimport) y()
		#define DEFINE_EXPORT __declspec(dllimport)
	#endif
#else
	#define DEFINE_EXPORTED_FUNCTION(x,y,z) x y z
	#define DEFINE_EXPORTED_FUNCTION_(x,y) x y()
	#define DEFINE_EXPORT
#endif

#endif//__LIB_EXPORT_H__

