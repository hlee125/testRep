// pass_wd.cpp

#include "pass_wd.h"

pass_wd::pass_wd() {
	print_label = new char; 
	print_blank = new char; 
}

void pass_wd::goto_commd_wd_label(const char* _print_label) {
	print_label = new char[strlen(_print_label)+1];
	strcpy(print_label,_print_label);

	gotoxy(0,LAST_LINE); 
	cout<<print_label; // print "Passwd?"		
}


void pass_wd::goto_commd_wd_blank(const char* _print_blank) {
	print_blank = new char[strlen(_print_blank)+1];
	strcpy(print_blank,_print_blank);

	gotoxy(0+strlen(print_label),LAST_LINE); 
	cout<<print_blank;
}


void pass_wd::input_passwd(){	   
	set_color(DEFAULT_INPUT_FONT_COLOR,DEFAULT_INPUT_BG_COLOR); // setcolor

	char temp_passwd[PASSWORD_SIZE];
	int count=0;

	gotoxy(0+strlen(print_label)+1,LAST_LINE);	// +1 to input [X______]	

	do {
		temp_passwd[count]=getch();

		// when gets ESC, print nothing 
		if(temp_passwd[count]!=ESC) cout<<'*';
		
		// when gets ESC, at first char then exit program
		if(temp_passwd[0]==ESC) { 
			set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
			goto_commd_wd_label("Exit!   ");

			unsigned int temp_cur_x=EXIT_WD_CUR_X ;
			unsigned int temp_cur_y=EXIT_WD_CUR_Y;
			unsigned int temp_width=EXIT_WD_WIDTH;
			unsigned int temp_height=EXIT_WD_HEIGHT;
			//(11,11) 57*2

			//staring beigger effect 
			for(;;) {
				exit_window.set_pos(temp_cur_x--,temp_cur_y--);
				exit_window.draw_reverse(temp_width+=2,temp_height+=2);
				exit_window.delete_rect_inside(); 
				Sleep(10);

				if(exit_window.return_cur_x() == 2 || exit_window.return_cur_y() == 2 ) break; 
			}
			//exit program
			system("cls"); 
			system("pause");
			exit(-1);
		}

		// when gets ESC, delete buffer 
		if(temp_passwd[count]==ESC) {
			for(int i=0;i<PASSWORD_SIZE;i++) {
				temp_passwd[i]=(char)NULL;
			}
			break;
		}
		count++;
	} while(count<PASSWORD_SIZE);
	
	strcpy(passwd_val,temp_passwd);
	set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
}

void pass_wd::commd_wd_delete() {
	gotoxy(0+strlen(print_label)+1,LAST_LINE);				// [X______]
	for(int i=0;i<PASSWORD_SIZE;i++) putchar('_');  // delete * as ' '
	gotoxy(0+strlen(print_label)+1,LAST_LINE);				// reposition [X______]
}

bool pass_wd::check_passwd() {
	int count=0;

	for(int i=0;i<PASSWORD_SIZE;i++) {
		if(passwd_val[i]==PASSWORD[i]) count++;
	}

	if(count == strlen(PASSWORD)) return true;
	else return false;
}


bool pass_wd::check_matrix() {
	int count=0;
	int check_white_space=0;

	for(int i=0;i<PASSWORD_SIZE;i++) {
		if(passwd_val[i]==MATRIX[i]) count++;
	}

	//check last char as ENTER or SPACE
	if(passwd_val[count]==ENTER || passwd_val[count]==SPACE ) check_white_space++;

	if(count+check_white_space == strlen(PASSWORD)) return true;
	else return false;
}

bool pass_wd::check_clear() {

	if(passwd_val[0]==char(NULL)) return true;
	else return false;
}

pass_wd::~pass_wd() {
	delete[] print_blank;
	delete[] print_label;
}