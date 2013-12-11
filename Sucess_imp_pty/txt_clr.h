// txt_clr.h

#ifndef _TXT_CLR_H
#define _TXT_CLR_H

#include <Windows.h>

typedef enum { // color range 0~15
	BLACK = 0,
    DARK_BLUE,
    DARK_GREEN,
    DARK_CYAN,
    DARK_RED,
    DARK_PINK, 
    DARK_YELLOW,
    DARK_WHITE,
    GRAY,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PINK,
    YELLOW,
	WHITE 
} COLOR_TYPE;

void set_color(int color, int bgcolor);

#endif