#include "matrix.h"

matrix::matrix() {
	char _mark[100]="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	mark = new char[strlen(_mark)+1];
	strcpy(mark,_mark);
	Pos.X=0;
	Pos.Y=0;
}

void matrix::setPos(int _x,int _y) {
	_x<=0?Pos.X=0:Pos.X=_x-1;
	_y<=0?Pos.Y=0:Pos.Y=_y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

char matrix::pickup_char() {
	srand((unsigned)time(NULL));
	return mark[rand()%62];
}

void matrix::pickup_col() {
	srand((unsigned)time(NULL));
	int random=rand()%50;
	Pos.X+=random;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(pickup_char()); //printf("%d",Pos.Y);	
	
	Pos.Y+=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(pickup_char()); //printf("%d",Pos.Y);
		
	Pos.Y-=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(' '); //printf("%d",Pos.Y);
	
	for(int i=0;i<23;i++) {
		Pos.Y+=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
		putchar(pickup_char());// printf("%d",Pos.Y);
		Sleep(200);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
		putchar(' ');
		Sleep(100);
	
	}
}

void matrix::setClear() {
	Pos.X=0;
	Pos.Y=0;
}

matrix::~matrix() {
	delete[] mark;
}