// start_wd.h

#ifndef _START_WD_H_
#define _START_WD_H_

#include "text_clr.h"
#include <Windows.h>
#include <iostream>
using namespace std;

#define MAX_LENGTH 25
#define MAX_WIDTH 80  // windows donsole 80*25
#define SPEED 0.5

class start_wd {
	unsigned int cur_x;			// current cursor position X
	unsigned int cur_y;			// current cursor position Y
	unsigned int rect_width;	
	unsigned int rect_height;
	unsigned int index;			// needs to smaller size effect
public:
	start_wd();
	void set_pos (unsigned int _x=0,unsigned int _y=0); 
	void draw_rect (unsigned const int _width=0, unsigned const int _height=0); // draw rectangle width * height
	void delete_rect_inside(); 
	void clear_pos();

	int return_cur_x() const;
	int return_cur_y() const;
	int return_rect_width() const;
	int return_rect_height() const;
	virtual ~start_wd();
};

void gotoxy(unsigned int _x=0,unsigned int _y=0);

#endif