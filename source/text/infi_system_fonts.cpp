#include "core/infi_array.h"
#include "core/infi_map.h"
#include "main/infi_error.h"
#include "text/infi_text.h"

namespace INFI {
namespace text {

struct infi_font_map {
	core::string_t regular;
	core::string_t bold;
	core::string_t italic;
	core::string_t bolditalic;
};

typedef core::map_t<core::string_t,infi_font_map> ccmap;
static ccmap fontnames;

static void add_font( const core::string_t& fname,
					  const core::string_t& dataname,
					  bool bold,
					  bool italic ) {
	ccmap::iterator iter = 
		fontnames.find( fname );
	if ( iter == fontnames.end() ) {
		infi_font_map build;
		if ( bold ) {
			if ( italic ) {
				build.bolditalic = dataname;
			} else {
				build.bold = dataname;
			}
		} else if ( italic ) {
			build.italic = dataname;
		} else {
			build.regular = dataname;
		}
		fontnames[fname] = build;
	} else {
		if ( bold ) {
			if ( italic ) {
				iter->second.bolditalic = dataname;
			} else {
				iter->second.bold = dataname;
			}
		} else if ( italic ) {
			iter->second.italic = dataname;
		} else {
			iter->second.regular = dataname;
		}
	}
}

#ifdef __WIN32__

#include <windows.h>
static core::string_t winpath( "C:\\Windows\\Fonts\\" );

void InfiLCollectFontNames() {
	InfiPushFunction( "InfiLCollectFontNames" );
	if ( fontnames.size() != 0 )
		InfiSendError( INFI_INIT_ERROR,
					   "font names already allocated" );
	
	HKEY result;
	RegOpenKeyEx( HKEY_LOCAL_MACHINE,
				  "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts",
				  0,
				  KEY_READ,
				  &result );
	DWORD subkeyCount;
	DWORD maxLenSubkey;
	DWORD valueCount;
	DWORD maxLenValue;
	DWORD maxLenData;
	RegQueryInfoKey( result,
					 NULL,
					 NULL,
					 NULL,
					 &subkeyCount,
					 &maxLenSubkey,
					 NULL,
					 &valueCount,
					 &maxLenValue,
					 &maxLenData,
					 NULL,
					 NULL );
	
	core::array_t<core::string_t> bufferlist;
	core::array_t<core::string_t> datalist;
	
	if ( valueCount ) {
		for ( uint32 i=0;i<valueCount;i++ ) {
			DWORD length = maxLenValue+1;
			DWORD datalen = maxLenData+1;
			
			char* buffer = new char[length];
			unsigned char* data = new unsigned char[datalen];
			
			buffer[0] = '\0';
			data[0] = '\0';
			
			RegEnumValue( result, i, buffer, &length, NULL, NULL, data, &datalen );
			
			bufferlist.add( core::string_t(buffer) );
			
			core::string_t windata;
				windata += winpath;
				windata += core::string_t((const char*)data);
			datalist.add( windata );
			
			delete[] buffer;
			delete[] data;
		}
	}
	
	RegCloseKey( result );
	
	for ( uint32 i=0;i<bufferlist.size();++i ) {
		core::array_t<core::string_t> words;
		bufferlist[i].split( ' ', words );
		
		if ( words[words.size()-1] == "(TrueType)" ) {
			
			core::string_t buffer;
			bool bold = false;
			bool italic = false;
			
			for ( uint32 i=0;i<words.size()-1 ;++i ) {
				if ( words[i] == "Bold" ) {
					bold = true;
				} else if ( words[i] == "Italic" ) {
					italic = true;
				} else if ( words[i] == "&" ) {
					add_font( buffer, datalist[i], bold, italic );
					bold = false;
					italic = false;
					buffer.clear();
				} else {
					if ( buffer.size() != 0 )
						buffer += ' ';
					buffer += words[i];
				}
			}
			if ( buffer.size() != 0 )
				add_font( buffer, datalist[i], bold, italic );
			
		}
	}
	
	InfiPopFunction();
}

#endif//__WIN32__

core::string_t InfiGetFontName( const core::string_t& fname, INFI_fontFlags flags ) {
	ccmap::iterator iter = fontnames.find( fname );
	if ( iter == fontnames.end() ) {
		return core::string_t();
	}
	
	core::string_t output;
	switch( flags ) {
		case 0:
			return iter->second.regular;
			break;
		case INFI_FONT_BOLD:
			return ( iter->second.bold.size() ) ? iter->second.bold : iter->second.regular;
			break;
		case INFI_FONT_ITALIC:
			return ( iter->second.italic.size() ) ? iter->second.italic : iter->second.regular;
			break;
		case INFI_FONT_BOLD_ITALIC:
			return ( iter->second.bolditalic.size() ) ? iter->second.bolditalic :
					 ( iter->second.bold.size() ) ? iter->second.bold : 
					 ( iter->second.italic.size() ) ? iter->second.italic : iter->second.regular;
			break;
		default:
			InfiSendError( INFI_TYPE_ERROR,
						   "invalid flag %d supplied", flags );
			return core::string_t();
	}
}

void InfiGetSystemFontNames( core::array_t<core::string_t>& out ) {
	out.clear();
	ccmap::iterator iter = fontnames.begin();
	for ( ;iter!=fontnames.end();++iter ) {
		out.add( iter->first );
	}
}

} }