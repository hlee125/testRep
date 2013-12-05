#include <iostream>
#include <conio.h> // kbhit()
#include "text.h"
#include "matrix.h"
using namespace FuckU;

#define SIZE 150	 // number of matrix
#define DEAD_LINE 50 // if approach the line then re-positioning

int main() {
	matrix m[SIZE];

	for(int i=0;i<SIZE;i++) {
		srand((unsigned)GetTickCount());
		set_color(rand()%COLOR_SIZE,0); // background color 0 is BLACK

		m[i].rand_pickup_pos();
		Sleep(SPEED);
	}

	do{
		for(int i=0;i<SIZE;i++) {
			srand((unsigned)GetTickCount());
			set_color(rand()%COLOR_SIZE,0);	
			
			if((kbhit() && getch()!=ESC) || (m[i].return_pos_y() == DEAD_LINE) ){
				system("cls"); 

				for(int i=0;i<SIZE;i++) {
					srand((unsigned)GetTickCount());
					set_color(rand()%COLOR_SIZE,0); // background color 0 is BLACK
					
					m[i].clear_pos();				// set position (0,0) all elements 
					m[i].rand_pickup_pos();			// re positioning
					Sleep(SPEED);
				}
			}

			m[i].draw_vert();
			Sleep(SPEED);
			if(kbhit() && getch()==ESC) exit(-1); // good example to exit
		}
	}while(true);
	
	return 0;
}
