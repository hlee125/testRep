// pass_wd.cpp

#include "pass_wd.h"

pass_wd::pass_wd() {
	same=false;
	// need initializing all attirbutes?
}


void pass_wd::draw_window (unsigned int cur_x,unsigned int cur_y,unsigned int rect_width,unsigned int rect_height){
	s.setpos(cur_x,cur_y);
	s.draw_rect(rect_width,rect_height,true);
	s.delete_rect_inside();
}


void pass_wd::write_label(const char* _label) {
	set_font_color();
	label = new char[strlen(_label)+1];
	strcpy(label,_label);

	int temp_cur_x=s.return_cur_x();
	int temp_cur_y=s.return_cur_y();

	s.setpos(temp_cur_x+=8,temp_cur_y+=1); //"Log-in" at (37,8) in subwindow
	cout<<label<<endl;
}


void pass_wd::write_label_passwd(const char* _passwd_label) {
	set_font_color();
	passwd_label = new char[strlen(_passwd_label)+1];
	strcpy(passwd_label,_passwd_label);

	s.setpos(20,13); // "PASSWORD" at (20,13)
	cout<<passwd_label<<endl;
}


void pass_wd::write_label_blank(const char* _blank) {
	set_font_color();
	blank = new char[strlen(_blank)+1];
	strcpy(blank,_blank);

	s.setpos(32,13); // [__________] at (32,13)
	cout<<blank<<endl;
}

void pass_wd::set_font_color(COLOR_TYPE fgcolor,COLOR_TYPE bgcolor) {
	set_color(fgcolor,bgcolor);
}

void pass_wd::input_passwd() {
	int flag = 0;
	int failed = 0;
	char* temp_passwd; // need to delete grabage

	for(;;){
		temp_passwd = new char[20];
		
		s.setpos(33,13);	// position [x__________]
		for(int i=0;i<16;i++) putchar('_'); // delete as '_'
		
		s.setpos(33,13);
		cin.getline(temp_passwd,strlen(temp_passwd),'\n');

		for(int i=0;i<strlen(temp_passwd);i++) {
			if(temp_passwd[i]==PASSWD[i]) {
				flag++;
			}
		}
	
		if(flag == strlen(temp_passwd)) {
			same=true;
			message_print(true,failed);
		} else { 
			failed++;
			message_print(false,failed);
		}
		flag = 0 ;// refresh
		if(kbhit() && getch()==ESC) exit(-1);
		delete[] temp_passwd;
	}
}
// need to block til faled and exception 3 times

void pass_wd::message_print(const bool _same,int _failed) {
	setpos(0,25);	  // go last line
	for(int i=0;i<MAX_WIDTH;i++) putchar(' '); // delete previous sentence

	setpos(0,25);	 // reposition
	set_color(YELLOW,RED);

	if(_same==true) {
		cout<<"Sucess Mother fucker ";
	} else if (_failed == CHANCE - 1 ) {
		cout<<"You have only one chance";
	} else if (_failed == CHANCE ) {
		cout<<"You fucked Mother fucker";
		exit(-1);
	} else {
		cout<<_failed<<" Failed Mother fucker ";
	}

	set_font_color(); // go back default font color
}




pass_wd::~pass_wd() {
	delete[] label;
	delete[] passwd_label;
	delete[] blank;
}