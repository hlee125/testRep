// clear_ani.h

#ifndef CLEAR_ANI_H
#define CLEAR_ANI_H

#include "txt_clr.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class clear_ani {
	char mark;
public:
	clear_ani();
	void clear_pos(unsigned const int _x=0,unsigned const int _y=0);
	void set_pos(unsigned const int _x=0,unsigned const int _y=0);
	void del_pos(unsigned const int _x=0,unsigned const int _y=0);
	virtual ~clear_ani();
};

void goto_xy(unsigned const int _x=0,unsigned const int _y=0);

#endif