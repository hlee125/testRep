// pass_wd.h

#ifndef _COMMD_WD_H_
#define _COMMD_WD_H_

#include "start_wd.h"
#include <conio.h>

#define CHANCE  5
#define PASSWORD	  "fuckyou"
#define MATRIX		  "matrix"
#define PASSWORD_SIZE  7 // strlen(fuckyou)

#define EXIT_WD_CUR_X 11
#define EXIT_WD_CUR_Y 11
#define EXIT_WD_WIDTH 57
#define EXIT_WD_HEIGHT 2

class pass_wd : public start_wd {
	start_wd exit_window; // to draw exit_window
	char* print_label; 
	char* print_blank;
	char passwd_val[PASSWORD_SIZE];
public:
	pass_wd();
	void goto_commd_wd_label(const char* _print_label=""); // goto Last line at (0,25) print string
	void goto_commd_wd_blank(const char* _print_blank="");
	void commd_wd_delete();

	void input_passwd();
	bool check_passwd();
	bool check_matrix();
	bool check_clear();
	virtual ~pass_wd();
};

#endif