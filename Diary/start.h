// start.h

#ifndef _START_H_
#define _START_H_

#include <Windows.h>
#include <iostream>
using namespace std;

#define MAX_LENGTH 25
#define MAX_WIDTH 80  // windows donsole 80*25
#define SPEED 20

class start {
	char mark;
	unsigned int cur_x; // current cursor position X
	unsigned int cur_y; // current cursor position Y
	unsigned int rect_width;
	unsigned int rect_height;
	unsigned int index; // number of calling
public:
	start();
	void setpos(unsigned int _x=0,unsigned int _y=0); 
	void draw_rect(unsigned int _width=0, unsigned int _height=0); 
	void delete_rect_inside(); 

	int return_cur_x() const;
	int return_cur_y() const;
	virtual ~start();
};

void gotoxy(unsigned int _x=0,unsigned int _y=0);

#endif