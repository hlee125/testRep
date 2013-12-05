// passwd.cpp

#include "passwd.h"

passwd::passwd() {

	same=false;
}
// need initializing all attirbutes?

void passwd::draw_window (unsigned int cur_x,unsigned int cur_y,unsigned int rect_width,unsigned int rect_height){
	s.setpos(cur_x,cur_y);
	s.draw_rect(rect_width,rect_height);
	s.delete_rect_inside();
}

void passwd::write_label(char* _label) {
	label = new char[strlen(_label)+1];
	strcpy(label,_label);

	int temp_cur_x=s.return_cur_x();
	int temp_cur_y=s.return_cur_y();

	s.setpos(temp_cur_x+=8,temp_cur_y+=1); //(37,8)
	cout<<label<<endl;
}

void passwd::write_label_passwd(char* _passwd_label) {
	passwd_label = new char[strlen(_passwd_label)+1];
	strcpy(passwd_label,_passwd_label);


	s.setpos(20,13); // PASSWORD (20,13)
	cout<<passwd_label<<endl;

	s.setpos(32,13); // [__________] (32,13)
	cout<<"[________________]"<<endl;
}

void passwd::input_passwd() {
	s.setpos(33,13);
	
	int key;
	key=getch();

}

passwd::~passwd() {
	//delete[] passwd_val;
	delete[] label;
	delete[] passwd_label;
}