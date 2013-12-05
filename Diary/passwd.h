// passwd.h

#ifndef _PASSWD_H_
#define _PSSWD_H_

#include "start.h"
#include <conio.h> // getch();
#define PASSWD "fuckyou"

class passwd:public start {
	start s;
	char* label;		// input string into window box to 
	char* passwd_label; // input string "PASSWORD" 
	//char* passwd_val;	
	bool same;
public:
	passwd();
	void draw_window(unsigned int cur_x,unsigned int cur_y,unsigned int rect_width,unsigned int rect_height);
	void write_label(char* _label=""); // input label into window box (28,6)
	void write_label_passwd(char* _passwd_label=""); //input label into (20,13) and [_____] (32,13)
	
	void input_passwd();
	
	void login_sucess();
	void login_fail();
	
	bool return_same();
	virtual ~passwd();
};

#endif