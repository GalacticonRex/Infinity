#ifndef __INFI_UNIT_TESTS_H__
#define __INFI_UNIT_TESTS_H__

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "main/infi_error.h"
#include "core/infi_datablock.h"
#include "core/infi_array.h"

void TestErrors() {
	std::cerr << "Testing Error Functionality" << std::endl;
	for ( int32 i=0;i<100;i++ ) {
		try {
			
			InfiSendError( INFI_SYSTEM_ERROR, 43 );
			
		} catch ( INFI_error_msg id ) {
			std::cerr << "There was an error!" << std::endl;
		}
		
		infi_error_t err;
		while ( InfiGetError( err ) ) {
			std::cerr << InfiErrorString( err.type ) << " : " << err.msg << std::endl;
			InfiFreeError( err );
		}
	}	
}
void TestDataBlock() {
	data_t<uint32> block1, block2;
	
	block1.resize( 6 );
	block1[0] = 10;
	block1[1] = 20;
	block1[2] = 30;
	block1[3] = 40;
	block1[4] = 50;
	block1[5] = 60;
	
	block2.resize( 3 );
	block2[0] = 100;
	block2[1] = 200;
	block2[2] = 300;
	
	block1.concat( block2 );
	block2.resize( 10 );
	block2.concat( block1 );
	
	std::cerr << block1 << std::endl;
	std::cerr << block2 << std::endl;
}
void TestArray() {
	array_t<uint32> block1, block2, block3;
	
	for ( int32 i=0;i<100;++i )
		block1.add(i);
	
	uint32& item = block2.add();
	item = 16;
	
	block2.concat( block1 );
	
	for ( int32 i=0;i<16;++i )
		block3.add(i);
	
	block3.insert( 5, 9999 );
	block3.insert( 0, 9999 );
	block3.remove( 1 );
	block3.remove( 2 );
	block3.remove( 13, 2 );
	
	block1.remove( 5, 10 );
	
	std::cerr << block1 << std::endl;
	std::cerr << block2 << std::endl;
	std::cerr << block3 << std::endl;
}

void TestStrings() {
	string_t sub1, sub2, sub3;
	sub1 = "Hello World!";
	sub2 = sub1.substr( 2,5 );
	sub3 = sub1.fromfront( 'r' );
	
	localstring_t str1, str2, str3, str4, str5;
	str1 = "Sally sells sea shells by the sea shore";
	str2 = str1.substr(6,15);
	str3 = str2;
	str4 = "BBBA";
	str5 = "BBBB";
	
	std::cerr << sub1 << std::endl;
	std::cerr << sub2 << std::endl;
	std::cerr << sub3 << std::endl;
	
	std::cerr << str1 << std::endl;
	std::cerr << str2 << std::endl;
	std::cerr << str3 << std::endl;
	
	std::cerr << str4;
	if ( str4 < str5 ) {
		std::cerr << " < ";
	} else {
		std::cerr << " >= ";
	}
	std::cerr << str5 << std::endl;
	
	core::string_t a( 'C', 5 );
	core::string_t b = "ABCDEFG";
	
	std::cerr << "01: " << '\'' << a << '\'' << std::endl;
	std::cerr << "02: " << '\'' << b << '\'' << std::endl;
	
	core::string_t c = b.substr( 1, 3 );
	
	std::cerr << "03: " << '\'' << c << '\'' << std::endl;
	
	core::string_t d = "Good work everyone";
	core::string_t e = "Phalanx";
	
	a.clear();
	
	std::cerr << "04: " << '\'' << c.from(0) << '\'' << std::endl;
	std::cerr << "05: " << '\'' << b.from(0) << '\'' << std::endl;
	std::cerr << "06: " << '\'' << c.source() << '\'' << std::endl;
	std::cerr << "07: " << '\'' << c.from(0) << '\'' << std::endl;
	
	std::cerr << e << std::endl;
	for ( uint32 i=0;i<10;++i ) {
		c += e;
		std::cerr << '\'' << c << '\'' << std::endl;
	}
}

void TestVectors() {
	vec2 obj;
	obj.x = 16;
	obj.y = 8;
	
	vec2 obj2 = obj.yx();
	
	std::cerr << Length(obj) << ", " << obj2 << ", " << obj.xxyy() << std::endl;
}

void TestQueue() {
	try {
		queue_t<uint32> q;
		
		q.push( 4 );
		q.push( 5 );
		q.push( 6 );
		
		std::cerr << "A: " << q << std::endl;
		
		q.pop();
		q.pop();
		
		std::cerr << "B: " << q << std::endl;
		
		q.push( 7 );
		q.push( 8 );
		q.push( 9 );
		q.push( 10 );
		q.push( 11 );
		
		std::cerr << "C: " << q << std::endl;
		
		q.push( 12 );
		
		std::cerr << "D: " << q << std::endl;
		
		q.push( 13 );
		
		std::cerr << "E: " << q << std::endl;
		
		q.push( 14 );
		
		std::cerr << "F: " << q << std::endl;
		
		q.push( 15 );
		q.push( 16 );
		q.push( 17 );
		
		std::cerr << "G: " << q << std::endl;
		
		q.push( 18 );
		q.push( 19 );
		q.push( 20 );
		
		std::cerr << "Z: " << q << std::endl;
		
		std::cerr << "1: " << q[0] << std::endl;
		std::cerr << "2: " << q[2] << std::endl;
		std::cerr << "3: " << q[4] << std::endl;
		std::cerr << "4: " << q[8] << std::endl;
		std::cerr << "5: " << q[16] << std::endl;
		std::cerr << "6: " << q[32] << std::endl;
		
	} catch( INFI_error_msg ) {
		infi_error_t err;
		InfiGetError( err );
		std::cerr << InfiErrorString( err.type ) << " || " << err.msg << std::endl;
	}
}

#endif//__INFI_UNIT_TESTS_H__