// commd_wd.h

#ifndef _COMMD_WD_H_
#define _COMMD_WD_H_

#include "start_wd.h"
#include <conio.h>

#define ESC		27 // to exit
#define CHANCE  5

#define PASSWORD	  "fuckyou"
#define PASSWORD_SIZE  7 //strlen(fuckyou)

class commd_wd : public start_wd {
	char* print_label; 
	char passwd_val[PASSWORD_SIZE];
	bool same;
public:
	commd_wd();
	void goto_commd_wd(const char* _print_label=""); // goto Last line at (0,25) print string
	void input_passwd();
	bool check_passwd();
	void commd_wd_delete();
	virtual ~commd_wd();
};



#endif