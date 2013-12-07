// main.cpp

#include "start_wd.h"
#include "comm_wd.h"

int main() {
	// (0,0) 80*25
	unsigned int console_width = MAX_WIDTH;  
	unsigned int console_height = MAX_LENGTH; 
	unsigned int cur_pos_x=0;
	unsigned int cur_pos_y=0;
	
	commd_wd windows;
	int i=0;

	// starting window smaller effect
	for(;;) {
		windows.set_pos(cur_pos_x++,cur_pos_y++); 
		windows.draw_rect(console_width--,console_height--); 
		windows.delete_rect_inside(); 

		if((windows.return_cur_x()+1 >= console_width)||(windows.return_cur_y()+1 >= console_height)) break;
		system("cls");
	}
	system("cls");

	windows.goto_commd_wd("Passwd? ");
	do {
		windows.input_passwd();
		windows.commd_wd_delete();
		
		if(windows.check_passwd()) {
			windows.goto_commd_wd("Sucess! ");
			windows.commd_wd_delete();
			break;
		} 
		else if (i==CHANCE-1) {
			windows.goto_commd_wd("Last!! ");
			windows.commd_wd_delete();

		}
		else {
			windows.goto_commd_wd("Failed! ");
			windows.commd_wd_delete();
		}
		
	}while(i++<CHANCE);
	
	
	/*
	if(window.check_passwd()) {
		window.comm_wd_delete();
		window.goto_comm_wd("Sucess");
	} else {
		window.comm_wd_delete();
		window.goto_comm_wd("failed");
	}*/


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
