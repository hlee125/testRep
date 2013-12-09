// comm_wd.cpp

#include "comm_wd.h"

commd_wd::commd_wd() {
	print_label = new char; 
	print_blank = new char; 
	same = false;

}

void commd_wd::goto_commd_wd_label(const char* _print_label) {
	print_label = new char[strlen(_print_label)+1];
	strcpy(print_label,_print_label);

	gotoxy(0,25); 
	cout<<print_label; // print "Passwd?"		
}


void commd_wd::goto_commd_wd_blank(const char* _print_blank) {
	print_blank = new char[strlen(_print_blank)+1];
	strcpy(print_blank,_print_blank);

	gotoxy(0+strlen(print_label),25); 
	cout<<print_blank;
}


void commd_wd::input_passwd(){	   
	set_color(DEFAULT_INPUT_FONT_COLOR,DEFAULT_INPUT_BG_COLOR); // setcolor

	char temp_passwd[PASSWORD_SIZE];
	int count=0;

	gotoxy(0+strlen(print_label)+1,25);	// +1 to input [X______]	
		
	do {
		temp_passwd[count]=getch();
		cout<<'*';
		
		//when get ESC exit program
		if(temp_passwd[count]==ESC) { 	
			set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
			goto_commd_wd_label("Exit!   ");

			unsigned int temp_cur_x=EXIT_WD_CUR_X ;
			unsigned int temp_cur_y=EXIT_WD_CUR_Y;
			unsigned int temp_width=EXIT_WD_WIDTH;
			unsigned int temp_height=EXIT_WD_HEIGHT;
			//(11,11) 57*2

			for(;;) {
				exit_window.set_pos(temp_cur_x--,temp_cur_y--);
				exit_window.draw_reverse(temp_width+=2,temp_height+=2);
				exit_window.delete_rect_inside(); 
				Sleep(10);

				if(exit_window.return_cur_x() == 2 || exit_window.return_cur_y() == 2 ) break; 
			}
			exit(-1);
		}
		count++;
	} while(count<PASSWORD_SIZE);
	
	strcpy(passwd_val,temp_passwd);
	set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
}

void commd_wd::commd_wd_delete() {
	gotoxy(0+strlen(print_label)+1,25);				// [X______]
	for(int i=0;i<PASSWORD_SIZE;i++) putchar('_');  // delete * as ' '
	gotoxy(0+strlen(print_label)+1,25);				// reposition [X______]
}

bool commd_wd::check_passwd() {
	int count=0;

	for(int i=0;i<PASSWORD_SIZE;i++) {
		if(passwd_val[i]==PASSWORD[i]) count++;
	}

	if(count == strlen(PASSWORD)) return true;
	else return false;
}


commd_wd::~commd_wd() {
	delete[] print_blank;
	delete[] print_label;
}