// text_clr.h

#ifndef _TEXT_COLOR_H
#define _TEXT_COLOR_H

#include <Windows.h>

#define DEFAULT_FONT_COLOR	  DARK_WHITE
#define DEFAULT_BG_COLOR	  BLACK

#define ANI_FONT_COLOR		  WHITE
#define ANI_BG_COLOR	      DARK_CYAN

#define PASSWD_INTPUT_FONT_COLOR	  DARK_WHITE
#define PASSWD_INPUT_BG_COLOR	      RED

#define PASSWD_LABEL_FONT_COLOR WHITE
#define PASSWD_LABEL_BG_COLOR   BLACK

#define MATRIX_COLOR	      rand()%2

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