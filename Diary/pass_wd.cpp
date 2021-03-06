// pass_wd.cpp

#include "pass_wd.h"

Pass_wd::Pass_wd() {
	print_label = new char; 
	print_blank = new char; 
}


void Pass_wd::goto_pass_wd_label(const char* _print_label) {
	print_label = new char[strlen(_print_label)+1];
	strcpy(print_label,_print_label);
	gotoxy(0,LAST_LINE); 

	set_color_wd();		 // color setting
	cout<<print_label;   // print "Passwd?"		
	delete_color();		 // delete color
}


void Pass_wd::goto_pass_wd_blank(const char* _print_blank) {
	print_blank = new char[strlen(_print_blank)+1];
	strcpy(print_blank,_print_blank);
	gotoxy(0+strlen(print_label),LAST_LINE); 

	set_color_wd();				// setcolor '[' as WHITE 
	putchar(print_blank[0]);	// print '['
	delete_color();				// delete color

	for(int i=0;i<PASSWORD_SIZE;i++) putchar(print_blank[i+1]); // print "________"
	
	set_color_wd();								 // setcolor ']' as WHITE 
	putchar(print_blank[PASSWORD_SIZE+1]);		 // print ']'
	delete_color();								 // delete color
}


void Pass_wd::pass_wd_delete() {
	gotoxy(0+strlen(print_label)+1,LAST_LINE);					 // [X______]
	for(int i=0;i<PASSWORD_SIZE;i++) putchar(print_blank[i+1]);  // delete * to '_'
	gotoxy(0+strlen(print_label)+1,LAST_LINE);					 // reposition [X______]
}


void Pass_wd::set_color_wd(unsigned const int font_color,unsigned const int bg_color) {
	set_color(font_color,bg_color);
}


void Pass_wd::matrix_pos() {
	
	for(int i=0;i<MATRIX_SIZE;i++) {
		srand((unsigned)GetTickCount());
		set_color_matrix(MATRIX_COLOR,BLACK);  // setting color for matrix "test_clr.cpp"

		m[i].rand_pickup_pos();
		Sleep(MATRIX_SPEED);
	}

	delete_color(); // delete color
}
	

void Pass_wd::matrix_pos_clear(){

	for(int i=0;i<MATRIX_SIZE;i++) {
		m[i].clear_pos();		
	}
}


void Pass_wd::matrix_draw() {
	bool esc_checker=false;

	do{
		for(int i=0;i<MATRIX_SIZE;i++) {
			srand((unsigned)GetTickCount());
			set_color_matrix(MATRIX_COLOR,BLACK); // setting color for matrix "test_clr.cpp"
			
			if(_kbhit() && _getch()==ESC) {
				esc_checker=true;	
				break; 
			}
			
			if((_kbhit() && _getch()!=ESC) || (m[i].return_pos_y() == MATRIX_DEAD_LINE)){
				system("cls"); 
				matrix_pos_clear();
				matrix_pos();
			}

			m[i].draw_vert();
			Sleep(MATRIX_SPEED);
		}
	}while(esc_checker==false);

	delete_color(); // delete color
}


void Pass_wd::sucess_ani() {
	int move = 0;
	int del  = MAX_WIDTH - 1;	// -1 to delete last empty blank

	Start_wd::set_color_wd();	// setting color as "ANI_FONT_COLOR","ANI_BG_COLOR"

	for(int i=0;i<MAX_WIDTH;i++,move++,del--) {
		int j=0;

		do{
			if(j==LAST_LINE) {   // 24
				sucess[j].set_pos(move,j);
				cout<<' '; 
				break;
			}

			sucess[j].set_pos(move,j); cout<<' '; j++;
			sucess[j].set_pos(del, j); cout<<' '; j++;
		}while(j<MAX_LENGTH);  // 25
		Sleep(DEFAULT_SPEED);
	}
	delete_color(); // delete color
}


void Pass_wd::input_passwd(){	   
	char temp_passwd[PASSWORD_SIZE];
	int count=0;
	gotoxy(0+strlen(print_label)+1,LAST_LINE);	// +1 to input [X______]	

	set_color_wd(PASSWD_INTPUT_FONT_COLOR,PASSWD_INPUT_BG_COLOR); // setcolor

	do {
		temp_passwd[count]=_getch();

		// when gets ESC, print nothing 
		if(temp_passwd[count]!=ESC) cout<<'*';
		
		// when gets ESC, as the first char then exit program
		if(temp_passwd[0]==ESC) { 
			goto_pass_wd_label("Exit!   ");

			unsigned int temp_cur_x=EXIT_WD_CUR_X ;
			unsigned int temp_cur_y=EXIT_WD_CUR_Y;
			unsigned int temp_width=EXIT_WD_WIDTH;
			unsigned int temp_height=EXIT_WD_HEIGHT;
			//(11,11) 57*2

			//staring bigger effect 
			for(;;temp_width+=2,temp_height+=2) {
				exit_window.set_pos(temp_cur_x--,temp_cur_y--);
				exit_window.draw_reverse(temp_width,temp_height);
				exit_window.delete_rect_inside(); 

				Sleep(DEFAULT_SPEED);
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
	delete_color(); // delete color
}


bool Pass_wd::check_passwd() {
	int count=0;

	for(int i=0;i<PASSWORD_SIZE;i++) {
		if(passwd_val[i]==PASSWORD[i]) count++;
	}

	if(count == strlen(PASSWORD)) return true;
	else return false;
}


bool Pass_wd::check_matrix() {
	int count=0;
	int check_white_space=0;

	for(int i=0;i<PASSWORD_SIZE;i++) {
		if(passwd_val[i]==MATRIX[i]) count++;
	}

	//check last char as ENTER or SPACE
	if(passwd_val[count]==ENTER || passwd_val[count]==SPACE) check_white_space++;

	if(count+check_white_space == strlen(PASSWORD)) return true;
	else return false;
}


bool Pass_wd::check_clear() {
	if(passwd_val[0]==char(NULL)) return true;
	else return false;
}


Pass_wd::~Pass_wd() {
	if(print_blank!=(char*)NULL) {
		delete[] print_blank;
	}
	if(print_label!=(char*)NULL) {
		delete[] print_label;
	}
}
