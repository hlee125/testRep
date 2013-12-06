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

bool pass_wd::return_same() const {
	return same;
}

pass_wd::~pass_wd() {
	//delete[] passwd_val;
	delete[] label;
	delete[] passwd_label;
	delete[] blank;
}