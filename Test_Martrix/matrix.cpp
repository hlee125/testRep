#include "matrix.h"

matrix::matrix() {
	char* _mark="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // strlen->62
	mark = new char[strlen(_mark)+1];
	strcpy(mark,_mark);
	
	Pos.X = 0;
	Pos.Y = 0;
	done = false;

	srand((unsigned)time(NULL));
	dis = rand()%9; // pick up randomly size of distance //fix it

	ptr = this;
}


void matrix::setPos(int _x,int _y) {
	_x<=0?Pos.X=0:Pos.X=_x-1;
	_y<=0?Pos.Y=0:Pos.Y=_y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar('X');
	cout<<endl;
}


char matrix::rand_pickup_char() {
	srand((unsigned)time(NULL));
	return mark[rand()%(strlen(mark)-1)];
}


void matrix::rand_pickup_pos() {
	unsigned int rand_x = 0;
	unsigned int rand_y = 0;
	
	srand((unsigned)time(NULL));
	rand_x = rand()%(MAX_WIDTH-1);

	srand((unsigned)time(NULL));
	rand_y = rand()%(MAX_LENGTH-1);

	Pos.X+=rand_x;
	Pos.Y+=rand_y; 

	// decide size of distance
	/*
	if ( dis + Pos.Y >= MAX_LENGTH ) { 
		if ( dis >= Pos.Y ) { 
			dis = MAX_LENGTH - Pos.Y ; 
		} else {
			dis = Pos.Y - MAX_LENGTH;
		}
	} */

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	putchar(rand_pickup_char());
}


matrix::~matrix() {
	delete[] mark;
}

void matrix::draw_vert() {
	Pos.Y+=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(rand_pickup_char());
	Sleep(200);
}

void matrix::draw_delete() {
	//delete first char
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(' '); 
	Sleep(50);	
	
	Pos.Y-=1; // reposition		
}

bool matrix::return_done() const {
	return done;
}

matrix* matrix::return_ptr(){
	return ptr;
}

int matrix::return_dis() const {
	return dis;
}

/*srand((unsigned)time(NULL));
	int random=rand()%50;
	Pos.X+=random;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(rand_pickup_char()); 	
	
	Pos.Y+=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(rand_pickup_char()); 
		
	Pos.Y-=1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
	putchar(' '); 
	
	for(int i=0;i<23;i++) {
		Pos.Y+=2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
		putchar(rand_pickup_char());
		Sleep(200);
		Pos.Y-=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
		putchar(' ');
		Sleep(100);
	
	}*/