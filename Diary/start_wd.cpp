// start_wd.cpp

#include "start_wd.h"

start_wd::start_wd() {
	rect_width = 0;
	rect_height = 0;
	
	index = 0;
	cur_x = 0;
	cur_y = 0;
}


void start_wd::set_pos(unsigned int _x,unsigned int _y) {
	cur_x=_x;
	cur_y=_y;
	gotoxy(cur_x,cur_y);
}


void start_wd::draw_rect(unsigned const int _width,unsigned int _height) { 
	int count=0;
	rect_width=_width;
	rect_height=_height;
	
	do {
		for(int i=0;i<rect_width-index;i++) { 
			set_color(DEFAULT_FONT_COLOR,DEFAULT_BG_COLOR); // draw bgcolor
			putchar(' ');	
			Sleep(SPEED);
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line 
		Sleep(SPEED);
	}while(count<rect_height-index);
	index++;
}


void start_wd::delete_rect_inside() {
	int count=0;
	cur_x++;
	cur_y++; 
	gotoxy(cur_x,cur_y); // goto inside (x+1,y+1)

	do {
		for(int i=0;i<rect_width-index-1;i++) {
			set_color(DEFAULT_FONT_COLOR,BLACK); // delete bgcolor as BLACK
			putchar(' ');
			Sleep(SPEED);
		}
		count++;
		gotoxy(cur_x,cur_y+count); 
		Sleep(SPEED);
	}while(count<rect_height-index-1); 
}


void start_wd::clear_pos() {
	cur_x=0;
	cur_y=0;
}


int start_wd::return_cur_x() const {
	return cur_x;
}


int start_wd::return_cur_y() const {
	return cur_y;
}


int start_wd::return_rect_width() const {
	return rect_width;
}


int start_wd::return_rect_height() const {
	return rect_height;
}


start_wd::~start_wd() {

}


void gotoxy(unsigned int _x,unsigned int _y) {
	COORD Pos;
	Pos.X=_x;
	Pos.Y=_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

