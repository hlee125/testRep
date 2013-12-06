// text_color.cpp

#include "text_color.h"

void set_color(int color, int bgcolor) {		// color range 0~15
	color &= 0xf;
    bgcolor &= 0xf;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

