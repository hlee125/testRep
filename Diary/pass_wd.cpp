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


void pass_wd::commd_wd_delete() {
	gotoxy(0+strlen(print_label)+1,LAST_LINE);		// [X______]
	for(int i=0;i<PASSWORD_SIZE;i++) putchar('_');  // delete * as ' '
	gotoxy(0+strlen(print_label)+1,LAST_LINE);		// reposition [X______]
}


void pass_wd::matrix_pos() {

	for(int i=0;i<MATRIX_SIZE;i++) {
		srand((unsigned)GetTickCount());
		set_color_matrix(MATRIX_COLOR,BLACK); // setting color for matrix

		m[i].rand_pickup_pos();
		Sleep(MATRIX_SPEED);
	}
}
	

void pass_wd::matrix_pos_clear(){

	for(int i=0;i<MATRIX_SIZE;i++) {
		m[i].clear_pos();		
	}
}


void pass_wd::matrix_draw() {
	bool esc_checker=false;

	do{
		for(int i=0;i<MATRIX_SIZE;i++) {
			srand((unsigned)GetTickCount());
			set_color_matrix(MATRIX_COLOR,BLACK);
			
			if(kbhit() && getch()==ESC) {
				esc_checker=true;	
				break; 
			}
			
			if((kbhit() && getch()!=ESC) || (m[i].return_pos_y() == MATRIX_DEAD_LINE) ){
				system("cls"); 
				matrix_pos_clear();
				matrix_pos();
			}

			m[i].draw_vert();
			Sleep(MATRIX_SPEED);
		}
	}while(esc_checker==false);

	set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
}


void pass_wd::sucess_ani() {
	set_color(DEFAULT_FONT_COLOR,DARK_CYAN); // setting color

	int move = 0;
	int del  = MAX_WIDTH;

	for(int i=0;i<MAX_WIDTH;i++,move++,del--) {
		int j=0;

		do{
			sucess[j].set_pos(move,j++); cout<<' '; 
			sucess[j].set_pos(del, j++); cout<<' '; 
			if(j==LAST_LINE-1) sucess[j].set_pos(move,j); cout<<' '; 
		}while(j<MAX_LENGTH-1);
		
		Sleep(MATRIX_SPEED);
	}
	set_color(DEFAULT_FONT_COLOR,BLACK);  // delete color
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
