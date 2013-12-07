// comm_wd.cpp

#include "comm_wd.h"

commd_wd::commd_wd() {
	same = false;
}

void commd_wd::goto_commd_wd(const char* _print_label) {
	print_label = new char[strlen(_print_label)+1];
	strcpy(print_label,_print_label);
	
	char temp_passwd[PASSWORD_SIZE];
	int count = 0;
	gotoxy(0,25); 

	cout<<print_label; // print "Passwd?"		
	
	cout<<'[';
	for(int i=0;i<PASSWORD_SIZE;i++) cout<<'_';
	cout<<']';
}

void commd_wd::input_passwd(){	   
	set_color(DEFAULT_INPUT_FONT_COLOR,DEFAULT_INPUT_BG_COLOR); // setcolor

	char temp_passwd[PASSWORD_SIZE];
	int count=0;
	
	gotoxy(0+strlen(print_label)+1,25);				
	do {
		temp_passwd[count++]=getch();
		cout<<'*';
	} while(count<PASSWORD_SIZE);
	strcpy(passwd_val,temp_passwd);
	set_color(DEFAULT_FONT_COLOR,BLACK); // delete color
}

void commd_wd::commd_wd_delete() {
	gotoxy(0+strlen(print_label)+1,25);				// position next to '['
	for(int i=0;i<PASSWORD_SIZE;i++) putchar(' ');  // delete * as ' '
	gotoxy(0+strlen(print_label)+1,25);				// reposition next to '['
	for(int i=0;i<PASSWORD_SIZE;i++) putchar('_');
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
	delete[] print_label;
}