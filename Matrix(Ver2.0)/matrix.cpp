﻿// matrix.cpp

#include "matrix.h"

namespace FuckU {

	matrix::matrix() {
		char* _mark="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ /*-+~!@#$%^&*()'_=\[];',./{}|:<>?"; 
		mark = new char[strlen(_mark)+1];
		strcpy(mark,_mark);

		Pos.X = 0;
		Pos.Y = 0;
		dis = 0;
		done = false;
	}

	char matrix::rand_pickup_char() {
		srand((unsigned)GetTickCount());
		return mark[rand()%(strlen(mark)-1)];
	}


	void matrix::rand_pickup_pos() {
		unsigned int rand_x;
		unsigned int rand_y;
	
		srand((unsigned)GetTickCount()); // do not use time(NULL) for random
		rand_x = rand()%(MAX_WIDTH-1);

		srand((unsigned)GetTickCount()); // return 1/1000 
		rand_y = rand()%(MAX_LENGTH-1);

		Pos.X+=rand_x;
		Pos.Y+=rand_y; 

		srand((unsigned)GetTickCount()); // setting distance
		dis = rand()%(MAX_LENGTH-1);

		//redirection of distance 
		if(dis + Pos.Y >= MAX_LENGTH) {
			dis -= dis + Pos.Y -  MAX_LENGTH;
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		putchar(rand_pickup_char());
	}


	void matrix::draw_vert() {
		Pos.Y+=1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
		putchar(rand_pickup_char());
		
		dis-=1;
		if(dis == 0 ) done=true;
	}


	matrix::~matrix() {
		delete[] mark;
	}

	int matrix::return_dis() const {
		return dis;
	}

	bool matrix::return_done() const {
		return done;
	}
}



