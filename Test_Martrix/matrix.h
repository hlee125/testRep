#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

#define ESC 27

class matrix {
	char* mark;
	COORD Pos;
public:
	matrix();
	void setPos(int _x,int _y);
	void setClear();
	char pickup_char();
	void pickup_col();
	void draw();
	~matrix();
};

#endif