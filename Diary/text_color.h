// text_color.h

#ifndef _TEXT_COLOR_H
#define _TEXT_COLOR_H

#include <Windows.h>

#define DEFAULT_FONT_COLOR		   WHITE
#define RANDOM_COLOR_INCLUDE_BLACK rand()%16
#define RANDOM_COLOR_EXCLUDE_BLACK rand()%15+1

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