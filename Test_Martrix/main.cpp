#include "matrix.h"
#include <iostream>
#include <conio.h>

#define SIZE 2

int main() {
	matrix m[SIZE];
	
	for(int i=0;i<SIZE;i++) {
		m[i].rand_pickup_pos();
	}
	
	for(int i=0;i<10;i++) {
		m[i].draw_vert();
	}

	for(int i=0;i<10;i++) {
		m[i].draw_delete();
	}

	return 0;
}
// probelm is distance take gabage value
