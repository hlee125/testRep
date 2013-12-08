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

	//starting window smaller effect
	for(;;) {
		windows.set_pos(cur_pos_x++,cur_pos_y++); 
		windows.draw_rect(console_width--,console_height--); 
		windows.delete_rect_inside(); 

		if((windows.return_cur_x()+1 >= console_width)||(windows.return_cur_y()+1 >= console_height)) break;
		system("cls");
	}
	system("cls"); 
	
	// input passwd
	windows.goto_commd_wd_label("Passwd? ");
	windows.goto_commd_wd_blank("[_______]");
	do {
		windows.input_passwd();
		windows.commd_wd_delete();
		
		if(windows.check_passwd()) { 
			windows.goto_commd_wd_label("Sucess! ");
			windows.commd_wd_delete();
			break;
		} 
		else if (i==CHANCE-1) {
			windows.goto_commd_wd_label("Last!   ");
			windows.commd_wd_delete();
		}
		else if (i==CHANCE) {
			windows.goto_commd_wd_label("Exit!   ");
			windows.commd_wd_delete();
		}
		else {
			windows.goto_commd_wd_label("Failed! ");
			windows.commd_wd_delete();
		}
	}while(i++<CHANCE);

	system("pause");
	return 0;
}


