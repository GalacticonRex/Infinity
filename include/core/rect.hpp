#ifndef __CORE_RECTANGLE_H__
#define __CORE_RECTANGLE_H__

#include "core/vector.hpp"

namespace core {

template<typename __T>
union rect_t {

	// MEMBERS
	vec4_t<__T> data;
	struct { __T x, y, w, h; };
	struct { vec2_t<__T> pos, dim; };

	// CONSTRUCTORS
	rect_t() :
		x(0),y(0),w(0),h(0) { }
	rect_t( __T nw, __T nh ) :
		x(0),y(0),w(nw),h(nh) { }
	template<typename __K>
	rect_t( const vec2_t<__K>& wh ) :
		x(0),y(0),w(wh.x),h(wh.y) { }
	rect_t( __T nx, __T ny, __T nw, __T nh ) :
		x(nx),y(ny),w(nw),h(nh) { }
	template<typename __K>
	rect_t( const vec2_t<__K>& xy, vec2_t<__K> wh ) :
		x(xy.x),y(xy.y),w(wh.x),h(wh.y) { }
	template<typename __K>
	rect_t( const vec4_t<__K>& all ) :
		x(all.x),y(all.y),w(all.z),h(all.w) { }
	rect_t( const rect_t& copy ) :
		data( copy.data ) { ; }

	rect_t<__T>& operator= ( const vec2_t<__T>& a ) {
		x = a.x;
		y = a.y;
		return *this;
	}

	// GETTERS

	vec2_t<__T> start() const { return pos; }
	vec2_t<__T> dimensions() const { return dim; }
	vec2_t<__T> end() const { return dim+pos; }

	__T width() const { return w; }
	__T height() const { return h; }

	__T xMin() const { return x; }
	__T yMin() const { return y; }

	__T xMax() const { return x + w; }
	__T yMax() const { return y + h; }

	__T area() const { return w * h; }
	__T perimeter() const { return 2*w + 2*h; }

	// SETTERS
	rect_t<__T>& operator+= ( const vec2_t<__T>& a ) {
		x += a.x;
		y += a.y;
		return *this;
	}
	rect_t<__T>& operator-= ( const vec2_t<__T>& a ) {
		x -= a.x;
		y -= a.y;
		return *this;
	}

	rect_t<__T> operator| ( const rect_t<__T>& merge ) {
		vec2_t<__T> topleft( std::min( x, merge.x ), std::min( y,merge.y ) ),
					botright( std::max( x+w, merge.x+merge.w ),
							  std::max( y+h, merge.y+merge.h ) ),
					dim = botright - topleft;
		dim.x = std::max( 0.f, dim.x );
		dim.y = std::max( 0.f, dim.y );

		return rect_t<__T>( topleft.x, topleft.y, dim.x, dim.y );
	}
	rect_t<__T> operator& ( const rect_t<__T>& merge ) {
		vec2_t<__T> topleft( std::max( x, merge.x ), std::max( y,merge.y ) ),
					botright( std::min( x+w, merge.x+merge.w ),
							  std::min( y+h, merge.y+merge.h ) ),
					dim = botright - topleft;
		dim.x = std::max( 0.f, dim.x );
		dim.y = std::max( 0.f, dim.y );

		return rect_t<__T>( topleft.x, topleft.y, dim.x, dim.y );
	}
};

template<typename __T>
rect_t<__T> coordinates( const vec2_t<__T>& a, const vec2_t<__T>& b ) {
	__T minx = std::min( a.x, b.x );
	__T miny = std::min( a.y, b.y );
	__T maxx = std::max( a.x, b.x );
	__T maxy = std::max( a.y, b.y );
	return rect_t<__T>( minx, miny, maxx - minx, maxy - maxy );
}
template<typename __T>
rect_t<__T> coordinates( const __T& ax, const __T& ay, const __T& bx, const __T& by ) {
	__T minx = std::min( ax, bx );
	__T miny = std::min( ay, by );
	__T maxx = std::max( ax, bx );
	__T maxy = std::max( ay, by );
	return rect_t<__T>( minx, miny, maxx - minx, maxy - miny );
}

template<typename __T>
std::ostream& operator<< ( std::ostream& out, const rect_t<__T>& r ) {
	out << "[(" << r.x << ", " << r.y << "), (" << r.x+r.w << ", " << r.y+r.h << ")]";
	return out;
}

typedef rect_t<float32> rect;
typedef rect_t<float32> rectf;
typedef rect_t<int32> recti;
typedef rect_t<float64> rectd;
typedef rect_t<unsigned> rectui;

}

#endif//__CORE_RECTANGLE_H__
