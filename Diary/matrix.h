// matrix.h

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "key.h"
#include "text_clr.h"
#include <windows.h> // COORD	
#include <cstdlib>	 // srand() , GetTickCount()
#include <iostream>
using namespace std;

#define MATRIX_DEAD_LINE 35
#define MATRIX_SIZE		 150
#define MATRIX_SPEED	 10

class Matrix {
	char* mark;
	COORD Pos;
public:
	Matrix();
	void clear_pos(int _x=0,int _y=0); // clear position as a default
	char rand_pickup_char();		   // randomly pick up one char
	void rand_pickup_pos();			   // randomly pick up one position
	void draw_vert();				   // draw vertical
		
	int return_pos_y() const;
	virtual ~Matrix();	
};

#endif