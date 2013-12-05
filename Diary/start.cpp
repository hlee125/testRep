// start.cpp

#include "start.h"

start::start() {
	mark = '*'; 
	cur_x = 0;
	cur_y = 0;

	rect_width = 0;
	rect_height = 0;
	index = 0;
}

void start::setpos(unsigned int _x,unsigned int _y) {
	cur_x=_x;
	cur_y=_y;
	gotoxy(cur_x,cur_y);
}

void start::draw_rect(unsigned int _width,unsigned int _height) {
	int count=0;
	rect_width=_width;
	rect_height=_height;
	
	do {
		for(int i=0;i<rect_width-index;i++) {
			putchar(mark);
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line
	}while(count<rect_height-index);
	index++;
}


void start::delete_rect_inside() {
	int count=0;
	cur_x++;
	cur_y++;
	gotoxy(cur_x,cur_y);

	do {
		for(int i=0;i<rect_width-index-1;i++) {
			putchar(' ');
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line
	}while(count<rect_height-index-1);
}

start::~start() {

}


int  start::return_cur_x() const {
	return cur_x;
}

int start::return_cur_y() const {
	return cur_y;
}

void gotoxy(unsigned int _x,unsigned int _y) {
	COORD Pos;
	Pos.X=_x;
	Pos.Y=_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}
