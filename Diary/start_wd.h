// start_wd.h

#ifndef _START_WD_H_
#define _START_WD_H_

#include "text_color.h"
#include <Windows.h>
#include <iostream>
using namespace std;

#define MAX_LENGTH 25
#define MAX_WIDTH 80  // windows donsole 80*25
#define DEFAULT_MARK '*'
#define SPEED 0.1

class start_wd {
	char* mark;
	unsigned int cur_x;			// current cursor position X
	unsigned int cur_y;			// current cursor position Y
	unsigned int rect_width;	
	unsigned int rect_height;
	unsigned int index;			// needs to smaller size effect
public:
	start_wd();
	void setpos(unsigned int _x=0,unsigned int _y=0); 
	void draw_rect(unsigned int _width=0, unsigned int _height=0,const bool mark_select=false); 
								// if true, draw as '*'
	void delete_rect_inside(); 

	char return_char() const;	// pick up random one char
	int return_cur_x() const;
	int return_cur_y() const;
	virtual ~start_wd();
};

void gotoxy(unsigned int _x=0,unsigned int _y=0);

#endif