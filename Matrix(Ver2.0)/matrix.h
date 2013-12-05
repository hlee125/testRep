// matrix.h

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <windows.h> // COORD	
#include <cstdlib>	 // srand() , GetTickCount()
#include <iostream>
using namespace std;

#define ESC 27		// to exit program
#define SPEED 100
#define MAX_LENGTH 25
#define MAX_WIDTH 80 // window console size 80*25

namespace FuckU {
	class matrix {
		char* mark;
		unsigned int dis;  // consider garbage
		COORD Pos;
		bool done;
	public:
		matrix();
		char rand_pickup_char();		// randomly pick up one char
		void rand_pickup_pos();			// randomly pick up one position
		void draw_vert();				// draw vertical
		virtual ~matrix();	

		int return_dis() const;
		bool return_done() const;
	};
}

#endif