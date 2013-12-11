// main.cpp

#include "clear_ani.h"
#include <conio.h>

#define MAX_LENGTH 25
#define MAX_WIDTH  80


int main() {
	unsigned int speed=20;
	unsigned int move=1;
	unsigned int del=move-1;

	unsigned int end=MAX_WIDTH ;
	unsigned int end_del=end-1;

	clear_ani ani[MAX_LENGTH];
/*	
	for(int i=0;i<MAX_WIDTH;i++,move++,del++) {
		ani[0].set_pos(move,0);
		ani[0].del_pos(del,0);
		Sleep(speed);
	
		ani[1].set_pos(move,1);
		ani[1].del_pos(del,1);
		Sleep(speed);
		
		if(kbhit() && getch()==27) break;
	}*/

	for(int i=0;i<MAX_WIDTH;i++,move++,del++,end--,end_del--) {
		ani[0].set_pos(move,0);
		ani[0].del_pos(del,0);
		ani[1].set_pos(end,1);
		ani[1].del_pos(end_del,1);

		ani[2].set_pos(move,2);
		ani[2].del_pos(del,2);	
		ani[3].set_pos(end,3);
		ani[3].del_pos(end_del,3);

		ani[4].set_pos(move,4);
		ani[4].del_pos(del,4);	
		ani[5].set_pos(end,5);
		ani[5].del_pos(end_del,5);

		ani[6].set_pos(move,6);
		ani[6].del_pos(del,6);	
		ani[7].set_pos(end,7);
		ani[7].del_pos(end_del,7);

		ani[8].set_pos(move,8);
		ani[8].del_pos(del,8);
		ani[9].set_pos(end,9);
		ani[9].del_pos(end_del,9);

		ani[10].set_pos(move,10);
		ani[10].del_pos(del,10);	
		ani[11].set_pos(end,11);
		ani[11].del_pos(end_del,11);

		ani[12].set_pos(move,12);
		ani[12].del_pos(del,12);	
		ani[13].set_pos(end,13);
		ani[13].del_pos(end_del,13);

		ani[14].set_pos(move,14);
		ani[14].del_pos(del,14);	
		ani[15].set_pos(end,15);
		ani[15].del_pos(end_del,15);

		ani[16].set_pos(move,16);
		ani[16].del_pos(del,16);	
		ani[17].set_pos(end,17);
		ani[17].del_pos(end_del,17);

		ani[18].set_pos(move,18);
		ani[18].del_pos(del,18);	
		ani[19].set_pos(end,19);
		ani[19].del_pos(end_del,19);

		ani[20].set_pos(move,20);
		ani[20].del_pos(del,20);	
		ani[21].set_pos(end,21);
		ani[21].del_pos(end_del,21);

		ani[22].set_pos(move,22);
		ani[22].del_pos(del,22);	
		ani[23].set_pos(end,23);
		ani[23].del_pos(end_del,23);

		ani[24].set_pos(move,24);
		ani[24].del_pos(del,24);	
	
		Sleep(speed);
		
		if(kbhit() && getch()==27) break;
	}
	ani[0].set_pos(0,24);
	cout<<'x';
	system("pause");
	return 0;
}