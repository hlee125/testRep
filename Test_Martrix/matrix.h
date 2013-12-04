#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <windows.h> // COORD
#include <time.h>	//  time()
#include <cstdlib>	//  srand()
#include <iostream>
using namespace std;
	
#define ESC 27		// to exit proram
#define MAX_LENGTH 25
#define MAX_WIDTH 80 // window console size 80*25

class matrix {
	char* mark;
	bool done;		   // check draw_vert() or not 
	unsigned int dis;  // how long the size -> shouldn't be 0
	COORD Pos;
public:
	matrix();
	void setPos(int _x,int _y); // for test
	char rand_pickup_char();	// randomly pick up one char
	void rand_pickup_pos();		// randomly pick up one position
	void draw_vert();
	void draw_delete();
	~matrix();
};

#endif