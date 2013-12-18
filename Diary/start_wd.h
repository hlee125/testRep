// start_wd.h

#ifndef _START_WD_H_
#define _START_WD_H_

#include "key.h"
#include "text_clr.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class Start_wd {
	unsigned int cur_x;			// current cursor position X
	unsigned int cur_y;			// current cursor position Y
	unsigned int rect_width;	
	unsigned int rect_height;
	unsigned int index;			// needs to only smaller size effect
public:
	Start_wd();
	void set_pos(unsigned int _x=0,unsigned int _y=0); 
	void clear_pos();
	void draw_rect(unsigned const int _width=0, unsigned const int _height=0);    // draw rectangle width * height
	void draw_reverse(unsigned const int _width=0, unsigned const int _height=0);
	void delete_rect_inside(); 

	virtual void set_color_wd(unsigned const int font_color=ANI_FONT_COLOR,unsigned const int bg_color=ANI_BG_COLOR); 
	void delete_color();	// delete color


	int return_cur_x() const;
	int return_cur_y() const;
	int return_rect_width() const;
	int return_rect_height() const;
	virtual ~Start_wd();
};

void gotoxy(unsigned int _x=0,unsigned int _y=0);

#endif