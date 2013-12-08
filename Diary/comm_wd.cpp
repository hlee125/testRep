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
	//set_color(DEFAULT_INPUT_FONT_COLOR,DEFAULT_INPUT_BG_COLOR); // setcolor
	set_color(DEFAULT_INPUT_FONT_COLOR,RED);

	int count=0;
	char temp_passwd[PASSWORD_SIZE];

	gotoxy(0+strlen(print_label)+1,25);	// +1 to input [X______]	

	do {
		temp_passwd[count]=getch();
		cout<<'*';
		
		//when get ESC exit program
		if(temp_passwd[count]==ESC) { 
			set_color(DEFAULT_FONT_COLOR,BLACK); 
			goto_commd_wd_label("Exit!   ");
			system("pause");
			exit(-1);
		}

		count++;
	} while(count<PASSWORD_SIZE);

	strcpy(passwd_val,temp_passwd);
	set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
}

void commd_wd::commd_wd_delete() {
	gotoxy(0+strlen(print_label)+1,25);				// [X______]
	for(int i=0;i<PASSWORD_SIZE;i++) putchar(' ');  // delete * as ' '
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