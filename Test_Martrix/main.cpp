#include "matrix.h"
#include <iostream>
#include <conio.h>

int main() {
	matrix m[10];

	//m.rand_pickup_pos(); 
	//m.draw_vert();
	//m.draw_delete();

	m[0].rand_pickup_pos();
	m[0].draw_vert();
	m[0].draw_delete();

	m[1].rand_pickup_pos();
	m[1].draw_vert();
	m[1].draw_delete();

	m[2].rand_pickup_pos();
	m[2].draw_vert();
	m[2].draw_delete();
	
	return 0;
}