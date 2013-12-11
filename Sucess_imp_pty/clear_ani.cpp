// clear_ani.h

#include "clear_ani.h"

clear_ani::clear_ani() {
	mark=' ';
}

void clear_ani::clear_pos(unsigned const int _x,unsigned const int _y) {
	goto_xy(0,0);
}

void clear_ani::set_pos(unsigned const int _x,unsigned const int _y) {
	set_color(BLACK,DARK_CYAN);
	goto_xy(_x,_y);
	cout<<mark;
}

void clear_ani::del_pos(unsigned const int _x,unsigned const int _y) {
	goto_xy(_x,_y);
	cout<<' ';
}

void goto_xy(unsigned const int _x,unsigned const int _y) {
	COORD Pos;
	Pos.X=_x;
	Pos.Y=_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos); 
}

clear_ani::~clear_ani(){

}