#include "Test.h"

Test::Test(char _mark) { //default '*'
	mark=_mark;
	Pos.X=0;
	Pos.Y=0;
}

void Test::setPos(int _x, int _y) {
	_x<=0?Pos.X=0:Pos.X=_x-1;
	_y<=0?Pos.Y=0:Pos.Y=_y-1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	cout<<'X'<<endl;
}

/*
void Test::draw() {
	
	int val=50; //how many print mark
	COORD Pos = { x-1, y-1 };
	// draw horizontal
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	for(int i=0;i<val;i++) {
		printf("%c",return_mark());
	}

	Pos.Y+=1; // set position new line
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	// draw vertical
	for(int i=0;i<val;i++) {
		if(i==0) printf("%c",return_mark());
		else if(i==val-1) printf("%c",return_mark());
		else printf("%c",' ');
	}

	Pos.Y+=1; // set position new line
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	// draw vertical
	for(int i=0;i<val;i++) {
		if(i==0) printf("%c",return_mark());
		else if(i==val-1) printf("%c",return_mark());
		else printf("%c",' ');
	}

	Pos.Y+=1; // set position new line
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	// draw horizontal
	for(int i=0;i<val;i++) {
		printf("%c",return_mark());
	}

}
*/

void Test::draw(int _width, int _length) { 
	int temp_row=Pos.Y;
	do {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
			for(int i=0;i<_width;i++) {
				printf("%c",return_mark());
			}
			Pos.Y+=1; 
	}while(Pos.Y<temp_row+_length-1); 
}

char Test::return_mark() {
	return mark;
}

Test::~Test(){
}


