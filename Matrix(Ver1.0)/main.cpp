#include <iostream>
#include <conio.h> // kbhit()
#include "matrix.h"
#include "text.h"

#define SIZE 100

int main() {
	matrix m[SIZE];

	for(int i=0;i<SIZE;i++) {
		srand((unsigned)GetTickCount());
		set_color(rand()%COLOR_SIZE,0);
		
		m[i].rand_pickup_pos();
		Sleep(SPEED);
	}

	do{
		for(int i=0;i<SIZE;) {
			srand((unsigned)GetTickCount());
			set_color(rand()%COLOR_SIZE,0);
			
			m[i++].draw_vert();
			Sleep(SPEED);
		}
	}while(!kbhit());
	
	return 0;
}
