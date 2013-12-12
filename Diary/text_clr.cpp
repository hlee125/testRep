// text_clr.cpp

#include "text_clr.h"

void set_color(int color, int bgcolor) {  // color range 0~15
	color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void set_color_matrix(int color, int bgcolor) {	// only accept 0 or 1	
	int color_arr[2]={DARK_GREEN,GREEN}; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color_arr[color]);
}

