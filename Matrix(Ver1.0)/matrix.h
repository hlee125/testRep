#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <windows.h> // COORD	
#include <cstdlib>	 // srand() , GetTickCount()
#include <iostream>
using namespace std;

#define MAX_LENGTH 25
#define MAX_WIDTH 80 // window console size 80*25

#define SPEED 10

class matrix {
	char* mark;
	unsigned int dis;  // consider 0
	COORD Pos;
public:
	matrix();
	void setPos(int _x=0,int _y=0); // for test
	char rand_pickup_char();		// randomly pick up one char
	void rand_pickup_pos();			// randomly pick up one position
	void draw_vert();
	virtual ~matrix();	
};

#endif