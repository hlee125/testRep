#ifndef _TEST_H
#define _TEST_H

#include "key.h"
#include <windows.h>
#include <iostream>
using namespace std;

class Test{
	char mark;
	COORD Pos;
public:
	Test(char _mark='*');
	void setPos(int _x=0,int _y=0);
	void draw(int _width=0, int _length=0);
	void draw_rect(int _width=0, int _length=0);
	void edit(); //not yet

	char return_mark();
	virtual ~Test();
};
#endif
