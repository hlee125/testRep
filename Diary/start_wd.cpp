// start_wd.cpp

#include "start_wd.h"

start_wd::start_wd() {
	char* _mark="*/-+~!@#$%^&*()'_=\[];',./{}|:<>?0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	mark = new char[strlen(_mark)+1];
	strcpy(mark,_mark);

	rect_width = 0;
	rect_height = 0;
	cur_x = 0;
	cur_y = 0;
	index = 0;
}


void start_wd::setpos(unsigned int _x,unsigned int _y) {
	cur_x=_x;
	cur_y=_y;

	gotoxy(cur_x,cur_y);
}


void start_wd::draw_rect(unsigned int _width,unsigned int _height,const bool mark_select) {
	int count=0;
	rect_width=_width;
	rect_height=_height;
	
	do {
		for(int i=0;i<rect_width-index;i++) {
			set_color(RANDOM_COLOR_EXCLUDE_BLACK,0); // don't use color black
			if(mark_select)  {
				putchar(DEFAULT_MARK);
			} else {
				putchar(return_char());
			}
			Sleep(SPEED);		   // each char print putchar() and setcolor(), depends on number of SPEED
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line
	}while(count<rect_height-index);
	index++;
}


void start_wd::delete_rect_inside() {
	int count=0;
	cur_x++; // goto into inside Coord X
	cur_y++; // goto into inside Coord Y
	gotoxy(cur_x,cur_y);

	do {
		for(int i=0;i<rect_width-index-1;i++) {
			putchar(' ');
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line
	}while(count<rect_height-index-1);
}


char start_wd::return_char() const {
	srand((unsigned)GetTickCount());
	return mark[rand()%(strlen(mark)-1)];
}


int start_wd::return_cur_x() const {
	return cur_x;
}


int start_wd::return_cur_y() const {
	return cur_y;
}


start_wd::~start_wd() {
	delete[] mark;
}

void gotoxy(unsigned int _x,unsigned int _y) {
	COORD Pos;
	Pos.X=_x;
	Pos.Y=_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}