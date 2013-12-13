// matrix.cpp

#include "matrix.h"

Matrix::Matrix() {
	char* _mark="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ /*-+~!@#$%^&*()'_=\[];',./{}|:<>?"; 
	mark = new char[strlen(_mark)+1];
	strcpy(mark,_mark);

	Pos.X = 0;
	Pos.Y = 0;
}


void Matrix::clear_pos(int _x,int _y) {
	_x<=0?Pos.X=0:Pos.X=_x-1;
	_y<=0?Pos.Y=0:Pos.Y=_y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}


char Matrix::rand_pickup_char() {
	srand((unsigned)GetTickCount());
	return mark[rand()%(strlen(mark)-1)];
}


void Matrix::rand_pickup_pos() {
	unsigned int rand_x;
	unsigned int rand_y;
	
	srand((unsigned)GetTickCount()); // do not use time(NULL) for random
	rand_x = rand()%(MAX_WIDTH-1);

	srand((unsigned)GetTickCount()); // return 1/1000 
	rand_y = rand()%(MAX_LENGTH-1);

	Pos.X+=rand_x;
	Pos.Y+=rand_y; 

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	putchar(rand_pickup_char());
}


void Matrix::draw_vert() {
	Pos.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(rand_pickup_char());
}


int Matrix::return_pos_y() const {
	return Pos.Y;
}

Matrix::~Matrix() {
	delete[] mark;
}




