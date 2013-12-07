#include "start_wd.h"
#include "pass_wd.h"
#include <conio.h>

int main() {
	// (0,0) 80*25
	unsigned int console_width = MAX_WIDTH;  
	unsigned int console_height = MAX_LENGTH; 
	unsigned int cur_pos_x=0;
	unsigned int cur_pos_y=0;
	
	start_wd window;

	// starting window smaller effect
	for(;;) {
		window.set_pos(cur_pos_x++,cur_pos_y++); 
		window.draw_rect(console_width--,console_height--); 
		window.delete_rect_inside(); 

		if((window.return_cur_x()+1 >= console_width)||(window.return_cur_y()+1 >= console_height)) break;
		system("cls");
	}
	// (12,12) 69*14

	// fix starting window (9,9) 72*17
	//window.clear_pos();
	//window.set_pos(10,10);
	//window.draw_rect(10,5);
	//window.delete_rect_inside();
	
	// draw subwindow (28,6) 24*5
	//window.draw_window(28,6,24,5); 
	//window.write_label("Log-in");
	//window.write_label_passwd("PASSWORD :");
	//window.write_label_blank("[________________]");
	
	//window.input_passwd();

	//window.setpos(0,25); // goto last line
	system("pause");
	return 0;
}

// need large effect
