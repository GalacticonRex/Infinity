#include "core/infi_raw_data.h"
#include "core/infi_map.h"
#include "render/infi_format.h"
#include "io/infi_load.h"
#include <climits>
#include <string>
#include <fstream>

namespace INFI {
namespace io {
	
static uint32 bitfield_data[] = { 0x1, 0x2, 0x4 };
static InfiGetter<const render::infi_format_t*> funcs[] =
	{ render::Position3, render::Pos3Tex2, render::Position3Norm, render::Pos3Tex2Norm };
	
struct vertex_indices {
	int32 pos, uv, norm;
	int32& operator[] ( uint32 i ) {
		switch( i ) {
			case 1: return uv; break;
			case 2: return norm; break;
			default:
				return pos;
		}
	}
	bool operator< ( const vertex_indices& other ) const {
		return 	( pos == other.pos ) ?
					( uv == other.uv ) ?
						( norm == other.norm ) ?
							false :
						( norm < other.norm ) :
					( uv < other.uv ) :
				( pos < other.pos );
	}
};
	
static void split_face_vertex( const std::string& input, vertex_indices& output, uint32& available ) {
	uint32 location = 0;
	uint32 current = 0;
	char buffer[128];
	for ( uint32 i=0;i<input.size();++i ) {
		if ( input[i] == '/' ) {
			if ( location == 0 ) {
				output[current] = -1;
			} else {
				buffer[location] = '\0';
				location = 0;
				output[current] = atoi( buffer ) - 1;
				available |= bitfield_data[current];
			}
			++ current;
		} else
			buffer[location++] = input[i];
	}
	buffer[location] = '\0';
	output[current] = atoi( buffer ) - 1;
	available |= bitfield_data[current];
}

static render::infi_vertices_t* openAsWavefront( std::ifstream& input ) {
	InfiPushFunction( "openAsWavefront" );
	
	// represent Wavefront object
	
	uint32 available = 0;
	
	core::array_t<core::vec3> positions;
	core::array_t<core::vec2> uvcoords;
	core::array_t<core::vec3> normals;
	core::array_t<vertex_indices> vertices;
	core::array_t<uint32> faces;
	
	std::string buffer;
	bool searching_face = false;
	
	core::vec3i none( -1,-1,-1 );
	while( input >> buffer ) {
		if ( searching_face ) {
			if ( buffer[0] < '0' || buffer[0] > '9' ) {
				faces.add( (uint32) -1 );
				searching_face = false;
			} else {
				vertex_indices output;
				split_face_vertex( buffer, output, available );
				faces.add( vertices.size() );
				vertices.add( output );
			}
		}
		if ( !searching_face ) {
			if ( buffer == "v"  ) {
				core::vec3 value;
				input >> value.x;
				input >> value.y;
				input >> value.z;
				positions.add( value );
			} else if ( buffer == "vt" ) {
				core::vec2 value;
				input >> value.x;
				input >> value.y;
				uvcoords.add( value );
			} else if ( buffer == "vn" ) {
				core::vec3 value;
				input >> value.x;
				input >> value.y;
				input >> value.z;
				normals.add( value );
			} else if ( buffer == "f" ) {
				searching_face = true;
			} else {
				input.ignore( 1024, '\n' );
			}
		}
	}
	
	uint32 fields = ( available - 1 ) / 2;
	
	// convert Wavefront representation to a vertex object
	
	core::map_t<vertex_indices, uint32> compose; // ensure there are no duplicate entries
	
	uint32 current = 0;
	core::array_t<float> bufferdata; // floating point data for the vertex buffer
	core::array_t<uint32> indexdata; // indices for the index buffer
	
	core::array_t<uint32> ibuffer; // buffer used to divide face into triangles
	core::map_t<vertex_indices, uint32>::iterator iter;
	
	for ( uint32 i=0;i<faces.size();++i ) {
		ibuffer.clear();
		for ( ;i<faces.size()&&faces[i]!=(uint32)-1;++i ) {
			vertex_indices& vert = vertices[faces[i]];
			iter = compose.find( vert );
			if ( iter == compose.end() ) {
				if ( available & bitfield_data[0] ) {
					core::vec3& v = positions[vert.pos];
					bufferdata.add( v.x );
					bufferdata.add( v.y );
					bufferdata.add( v.z );
				}
				if ( available & bitfield_data[1] ) {
					core::vec2& v = uvcoords[vert.uv];
					bufferdata.add( v.x );
					bufferdata.add( v.y );
				}
				if ( available & bitfield_data[2] ) {
					core::vec3& v = normals[vert.norm];
					bufferdata.add( v.x );
					bufferdata.add( v.y );
					bufferdata.add( v.z );
				}
				compose.insert( std::make_pair( vert, current ) );
				ibuffer.add( current );
				++ current;
			} else
				ibuffer.add( iter->second );
		}
		// triangulate faces
		for ( uint32 j=2;j<ibuffer.size();++j ) {
			indexdata.add( ibuffer[0] );
			indexdata.add( ibuffer[j-1] );
			indexdata.add( ibuffer[j-0] );
		}
	}
	
	core::raw_data_t<uint8> rawb( bufferdata.size() * sizeof(float),
								  (uint8*) bufferdata.source() );
	core::raw_data_t<uint8> rawi( indexdata.size() * sizeof(uint32),
								  (uint8*) indexdata.source() );
	
	render::infi_buffer_t* bd = new render::infi_buffer_t( rawb );
	render::infi_buffer_t* id = new render::infi_buffer_t( rawi );
	
	render::infi_vertices_t* ret = render::InfiCreateVertices();
		render::InfiSetFormat( ret, funcs[fields]() );
		render::InfiSetIndices( ret, id );
		render::InfiBindVertices( ret,
			render::infi_formatted_buffer_t( bd, funcs[fields]() ) );
	
	InfiPopFunction();
	return ret;
}

render::infi_vertices_t* InfiLoadModel( const core::string_t& fname ) {
	InfiPushFunction( "InfiLoadModel" );
	
	core::string_t str( fname );
	std::ifstream input( str.source() );
	if ( !input.good() )
		InfiSendError( INFI_FILE_NOT_FOUND,
					   "no model file named %s",
					   str.source() );
	
	core::string_t ext = str.fromback( '.' );
	
	render::infi_vertices_t* output = NULL;
	if ( ext == "obj" ) {
		output = openAsWavefront(input);
	}
	
	return output;
}

} }