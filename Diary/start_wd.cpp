// start_wd.cpp

#include "start_wd.h"

Start_wd::Start_wd() {
	rect_width  = 0;
	rect_height = 0;

	index = 0;
	cur_x = 0;
	cur_y = 0;
}


void Start_wd::set_pos(unsigned int _x,unsigned int _y) {
	cur_x=_x;
	cur_y=_y;

	gotoxy(cur_x,cur_y);
}

void Start_wd::draw_rect(unsigned const int _width,unsigned int _height) { 
	rect_width  = _width;
	rect_height = _height;
	int count   = 0;
	
	set_color(ANI_FONT_COLOR,ANI_BG_COLOR); // draw bgcolor

	do {
		for(int i=0;i<rect_width-index;i++) { 
			putchar(' ');	
			Sleep(ANI_SPEED);
		}
		count++;
		gotoxy(cur_x,cur_y+count);	// goto next line 
		Sleep(ANI_SPEED);
	}while(count<rect_height-index);
	index++;

	delete_color(); // delete color
}


void Start_wd::draw_reverse(unsigned const int _width,unsigned int _height) { 
	rect_width  = _width;
	rect_height = _height;
	int count   = 0;

	set_color(ANI_FONT_COLOR,ANI_BG_COLOR);  // draw bgcolor

	do {
		for(int i=0;i<rect_width+1;i++) { 
			putchar(' ');	
			Sleep(ANI_SPEED);
		}
		count++;
		gotoxy(cur_x,cur_y+count);  // goto next line 
		Sleep(ANI_SPEED);
	}while(count<rect_height+1);

	delete_color(); // delete color
}


void Start_wd::delete_rect_inside() {
	int count=0;
	gotoxy(cur_x+=1,cur_y+=1); // goto inside (x+1,y+1)

	set_color(ANI_FONT_COLOR,BLACK); // delete bgcolor as BLACK
	
	do {
		for(int i=0;i<rect_width-index-1;i++) {
			
			putchar(' ');
			Sleep(ANI_SPEED);
		}
		count++;
		gotoxy(cur_x,cur_y+count); // goto next line 
		Sleep(ANI_SPEED);
	}while(count<rect_height-index-1); 
	
	delete_color(); // delete color
}


void Start_wd::delete_color() {
	set_color(DEFAULT_FONT_COLOR,DEFAULT_BG_COLOR);
}


void Start_wd::clear_pos() {
	cur_x=0;
	cur_y=0;
}


int Start_wd::return_cur_x() const {
	return cur_x;
}


int Start_wd::return_cur_y() const {
	return cur_y;
}


int Start_wd::return_rect_width() const {
	return rect_width;
}


int Start_wd::return_rect_height() const {
	return rect_height;
}


Start_wd::~Start_wd() {

}


void gotoxy(unsigned int _x,unsigned int _y) {
	COORD Pos;
	Pos.X=_x;
	Pos.Y=_y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos); 
}

