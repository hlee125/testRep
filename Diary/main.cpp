// main.cpp

#include "start_wd.h"
#include "comm_wd.h"

int main() {
	// (0,0) 80*25
	unsigned int console_width = MAX_WIDTH;  
	unsigned int console_height = MAX_LENGTH; 
	unsigned int cur_pos_x=0;
	unsigned int cur_pos_y=0;

	start_wd exit_window;
	commd_wd start_window;
	int count=0;
	int failed=0;

	//starting window smaller effect
	for(;;) {
		start_window.set_pos(cur_pos_x++,cur_pos_y++); 
		start_window.draw_rect(console_width--,console_height--); 
		start_window.delete_rect_inside(); 
		count++;
		Sleep(10);

		if((start_window.return_cur_x()+1 >= console_width)||(start_window.return_cur_y()+1 >= console_height)) break;
		system("cls"); 
	}
	system("cls"); 	//(12,12) 69*14


	// setting for exit window (11,11) 57*2
	unsigned int temp_cur_x=start_window.return_cur_x()-1;
	unsigned int temp_cur_y=start_window.return_cur_y()-1;
	unsigned int temp_width=start_window.return_rect_width()-count;
	unsigned int temp_height=start_window.return_rect_height()-count;
	

	// input passwd
	start_window.goto_commd_wd_label("Passwd? ");
	start_window.goto_commd_wd_blank("[_______]");
	do {
		start_window.input_passwd();
		start_window.commd_wd_delete();

		if(start_window.check_passwd()) { 
			start_window.goto_commd_wd_label("Sucess! ");
			start_window.commd_wd_delete();
			break;
		} 
		else if (failed==CHANCE-1) {
			start_window.goto_commd_wd_label("Last!   ");
			start_window.commd_wd_delete();
		}
		else if (failed==CHANCE ) {
			start_window.goto_commd_wd_label("Exit!   ");
			start_window.commd_wd_delete();
			//starting window bigger effect
			for(;;) {
				exit_window.set_pos(temp_cur_x--,temp_cur_y--); 
				exit_window.draw_reverse(temp_width+=2,temp_height+=2);
				exit_window.delete_rect_inside(); 
				Sleep(10);

				if(exit_window.return_cur_x() == 2 || exit_window.return_cur_y() == 2 ) break; 
			}
		}
		else {
			start_window.goto_commd_wd_label("Failed! ");
			start_window.commd_wd_delete();
		}
	}while(failed++<CHANCE);

	system("cls"); 
	system("pause");
	return 0;
}


