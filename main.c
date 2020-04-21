// we test functions of screen.coo
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displayWAVhdr(h);
	clearscreen();
	wavdata(h, fp);		// to calculate dB values and display them as a barcharto
	fclose(fp);
	getchar();
}

//oooo

