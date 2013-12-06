// pass_wd.h

#ifndef _PASS_WD_H_
#define _PASS_WD_H_

#include "start_wd.h"
#include <conio.h>   // getch();

#define PASSWD "fuckyou"

class pass_wd : public start_wd {
	start_wd s;			// need to draw subwindow
	char* label;		// input string into sub window box 
	char* passwd_label; // input string into window box "PASSWORD" 
	char* blank;		// input string [_________] into window box 
	bool same;
public:
	pass_wd();
	void draw_window(unsigned int cur_x,unsigned int cur_y,unsigned int rect_width,unsigned int rect_height);
																// draw window at (28,6) size 24*5
	void write_label(const char* _label="");					// input label into sub window box  at (28,6)
	void write_label_passwd(const char* _passwd_label="");		// input label into sub at (20,13) and [_____] (32,13)
	void write_label_blank(const char* _blank="");				// input label into window box at (32,13)
	void set_font_color
		(COLOR_TYPE fgcolor = DEFAULT_FONT_COLOR,COLOR_TYPE bgcolor = BLACK); // setting font color

	void input_passwd();
	void message_print(const bool _same, int _failed);  // print message last line at (0,25)
	
	//void login_sucess();
	//void login_fail();

	virtual ~pass_wd();
};

#endif