// text_clr.h

#ifndef _TEXT_COLOR_H
#define _TEXT_COLOR_H

#include <Windows.h>

#define DEFAULT_BG_COLOR	     DARK_CYAN
#define DEFAULT_FONT_COLOR		 WHITE
#define DEFAULT_INPUT_FONT_COLOR DARK_WHITE
#define DEFAULT_INPUT_BG_COLOR	 RED

#define MATRIX_COLOR			 rand()%2

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
void set_color_matrix(int color, int bgcolor);

#endif