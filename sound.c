#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displayWAVhdr(WAVheader h){
	printf("Chunk ID: ");
	for(int i=0; i<4; i++) printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk Size: %d\n", h.chunkSize);
	printf("Num of Channels: %d\n", h.numChannels);
	printf("Sample Rate: %d\n", h.sampleRate);
	printf("Block Align: %d\n", h.blockAlign);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	// ... to be continued
}

void wavdata(WAVheader h, FILE *fp){
	// In this function we will read sound samples from the opened file.
	// The samples are calculated into decibel value using Root Mean Square
	// (RMS) formula. We will display a 5-sec recorded sound into bar chart.
	// Our sound file uses sample rate 16000, for 5 seconds, there are
	// 5*16000 = 80000 samples, we want to display them into 160 bars
	// on our screen.
	short samples[500];		// to read 500 samples from wav file
	int peaks = 0, flag = 0, high = 0;	// 1st value is to count, the 2nd is to show th you are in a peak

	for(int i=0; i<160; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0;	//  accumulate the sum
		for(int j=0; j<500; j++){
			sum = sum + samples[j]*samples[j];
		}
		double re = sqrt(sum/500);
		if(re > high) {
			high = re;
		}
		else
		{
		high = 0;
		}
#ifdef SDEBUG
		printf("db[%d] = %f\n", i+1, 20*log10(re));
#else
		// displaybar for re value
		if(20*log10(re)>60) {
			setfgcolor(RED);
			if(flag == 0){
				flag = 1;
				peaks++;		// I got a peak
			}
		}
		else {
			setfgcolor(WHITE);
			flag = 0;
		}
		drawbar(i+1, (int)20*log10(re)/3);
#endif
	}
	// display sample rate, duration, number of peaks
	gotoXY(1,1); printf("Sample Rate: %d\n", h.sampleRate);
	gotoXY(1,25); printf("Duration: %f s\n", (float)h.subchunk2Size/h.byteRate);
	char poststr[100];
	gotoXY(1,75); printf("Peaks: %d\n", peaks);
	gotoXY(2, 1); sprintf(poststr, "data=%d&high=%d", peaks, high);
	senddata(poststr, URL);
}

//end of file
