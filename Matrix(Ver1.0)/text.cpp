// text.cpp

#include "text.h"

void set_color(int color_num, int bgcolor) {		// only accept color_num 0 or 1	
	int color_arr[COLOR_SIZE] ={DARK_GREEN,GREEN};  // using only two color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color_arr[color_num]);
}

