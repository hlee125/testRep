#include "start.h"
#include "passwd.h"
#include <conio.h>

int main() {
	unsigned int console_width=80;
	unsigned int console_height=25;
	unsigned int cur_pos_x=0;
	unsigned int cur_pos_y=0;
	
	passwd s;
	for(int i=0;i<8;i++) {
		s.setpos(cur_pos_x++,cur_pos_y++);
		s.draw_rect(console_width--,console_height--); 
		s.delete_rect_inside();
		
		system("cls");
		Sleep(SPEED);	
	}
	
	s.setpos(cur_pos_x,cur_pos_y);
	s.draw_rect(console_width,console_height);
	s.delete_rect_inside();
	
	s.draw_window(28,6,24,5); // position(28,6) windown size 24*5
	s.write_label("Log-in");
	s.write_label_passwd("PASSWORD :");

	//putchar('x');
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;

	system("pause");
	return 0;
}

