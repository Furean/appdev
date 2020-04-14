// we test functions of screen.coooooooo
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"

int main(void){
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
//	senddata(poststr, URL);
//	gotoXY(1,1); 
//	printf("Screen size, ROW=%d, COL=%d\n", cur.row, cur.col);
//	printf("HTTP post is sent to %s\n");
//	getchar();	// waiting for the user to press a key
//	getchar();
//	for(int i=0; i<cur.row; i++){
	for(int i=0; i<25; i++) {
		setcolors(RED, BLUE);
		clearscreen();
		//float step = (float)cur.col/cur.row;
		gotoXY(1+i, 1+i);
		printf("HELLO\n");
		setcolors(GREEN, BLUE);
		gotoXY(25-i, 1+i);
		printf("HELLO\n");
		usleep(500000);
	}
	for(int i=0; i<25; i++){
		setcolors(RED, BLUE);
		clearscreen();
		gotoXY(25-i, 40+i);
		printf("HELLO\n");
		setcolors(GREEN, BLUE);
		gotoXY(1+i, 40+i);
		printf("HELLO\n");
		usleep(500000);
	}
/*	for(int i=0; i<10; i++){
		setcolors(RED, BLUE);
		clearscreen();
		gotoXY(1+i, 20+i);
		printf("HELLO\n");
		usleep(500000);
	}
*/
//	printf("The following message will be in YELLOW color\n");
	gotoXY(14, 35);
	setfgcolor(BLUE);
	printf("e1901099\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);

	getchar();
	resetcolors();
	clearscreen();
	printf("This line is back to default color\n");
}
