#include <iostream>
#include <conio.h> // kbhit()

#include "text.h"
#include "matrix.h"
using namespace FuckU;

#define SIZE 150 // number of matrix

int main() {
	matrix m[SIZE];

	for(int i=0;i<SIZE;i++) {
		srand((unsigned)GetTickCount());
		set_color(rand()%COLOR_SIZE,0); // background color 0 is BLACK
		
		m[i].rand_pickup_pos();
		Sleep(SPEED);
	}

	do{
		for(int i=0;i<SIZE;) {
			srand((unsigned)GetTickCount());
			set_color(rand()%COLOR_SIZE,0);
			
			m[i++].draw_vert();
			Sleep(SPEED);	
			if(kbhit() && getch()==ESC) exit(-1);
		}
	}while(true);
	
	return 0;
}
