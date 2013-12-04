#include "matrix.h"
#include <iostream>
#include <conio.h>

#define SIZE 50

int main() {
	matrix m[SIZE];

	for(int i=0;i<SIZE;i++) {
		m[i].rand_pickup_pos();
		Sleep(SPEED/10);
	}

	do{
		for(int i=0;i<SIZE;) {
			m[i++].draw_vert();
			Sleep(SPEED/10);
		}
		Sleep(SPEED);
	}while(!kbhit());


	
	/*
	for(int i=0;i<10;i++) {
		m.draw_delete();
	}
	*/
	
	return 0;
}

// need refresh each char
// need draw() delete
// need color