#include "start_wd.h"
#include "pass_wd.h"
#include <conio.h>

int main() {
	unsigned int console_width=80;
	unsigned int console_height=25;
	unsigned int cur_pos_x=0;
	unsigned int cur_pos_y=0;
	
	pass_wd window;

	// starting window effect
	for(int i=0;i<8;i++) {
		window.setpos(cur_pos_x++,cur_pos_y++);
		window.draw_rect(console_width--,console_height--); 
		window.delete_rect_inside();
		
		system("cls");
	}
	
	// fix starting window (9,9) 72*17
	window.setpos(cur_pos_x,cur_pos_y);
	window.draw_rect(console_width,console_height,true);
	window.delete_rect_inside();
	
	// draw subwindow (28,6) 24*5
	window.draw_window(28,6,24,5); 
	window.write_label("Log-in");
	window.write_label_passwd("PASSWORD :");
	window.write_label_blank("[________________]");

	window.setpos(0,25); // goto last line

	system("pause");
	return 0;
}

