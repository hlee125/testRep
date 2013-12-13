// pass_wd.h

#ifndef _PASS_WD_H_
#define _PASS_WD_H_

#include "matrix.h"
#include "start_wd.h"
#include <conio.h>

#define CHANCE		   5
#define PASSWORD_SIZE  7 // strlen(fuckyou)

#define PASSWORD	  "fuckyou"
#define MATRIX		  "matrix"

#define EXIT_WD_CUR_X 11
#define EXIT_WD_CUR_Y 11
#define EXIT_WD_WIDTH 57
#define EXIT_WD_HEIGHT 2  //(11,11) 57*2

class Pass_wd : public Start_wd {
	Start_wd sucess[MAX_LENGTH]; // to draw sucess ani
	Matrix m[MATRIX_SIZE];	     // to matrix animation
	Start_wd exit_window;		 // to draw exit_window ani
	
	char* print_label; 
	char* print_blank;
	char passwd_val[PASSWORD_SIZE];
public:
	Pass_wd();
	void goto_pass_wd_label(const char* _print_label=""); // goto Last line at (0,25) print string
	void goto_pass_wd_blank(const char* _print_blank="");
	void pass_wd_delete();

	// matrix effect
	void matrix_pos();
	void matrix_pos_clear();
	void matrix_draw();

	// sucess effect
	void sucess_ani();

	void input_passwd();
	bool check_passwd();
	bool check_matrix();
	bool check_clear();
	virtual ~Pass_wd();
};

#endif