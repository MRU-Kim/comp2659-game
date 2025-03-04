/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 28, 2024
File name       RASTER.C
Professor     	Steve Kalmar
*/

#include <stdio.h>
#include <osbind.h>

#include "raster.h"
#include "CONST.H"

/* function: clearScreen
   clears the screen with the 8 bit pattern input.
   inputs:
   base   - pointed on the starting address of the bitmap
   pattern  - pattern to fill the screen with

*/
void clearScreen(UINT8 *base, char pattern){
	register int i=0;
	register UINT8 *location = base;

	while(i++<BytesPerScreen){
		*(location++)=pattern;
	}
}

/* function: clear8Bit
   clears an 8-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void clear8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height){
    int i;
    UINT8* clearArea = base+(y * 80) + (x >> 3); /* remove base +? */

    for(i=0;i<height;i++){
       /* *clearArea |= *(bitmap++); /* remove? */
        *clearArea = 0x00;
        clearArea += 80;
    }
}

/* function: clear16Bitmap
   clears a 16-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void clear16Bitmap(UINT8 *base, UINT16* bitmap, int x, int y, int height){
    int i;
    UINT16* clearArea = (UINT16 *)base + (y * 40) + (x >> 4);

    for(i=0;i<height;i++){
        *clearArea ^= *(bitmap++);
        clearArea += 40;
    }
}

/* function: clear32Bitmap
   clears a 32-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void clear32Bitmap(UINT8 *base, UINT32* bitmap, int x, int y, int height){
    int i;
    UINT32* clearArea = (UINT32 *)base + (y * 20) + (x >> 5); 

    for(i=0;i<height;i++){
        *clearArea |= *(bitmap++); 
        *clearArea = 0x00;
        clearArea += 20;
    }
}

/* function: plot8Bitmap
   plots an 8-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void plot8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height) {
    int i;

    UINT8 *plotLocation = base + (y * 80) + (x >> 3);
    for(i=0;i<height;i++) {
        *plotLocation |= *(bitmap++);
        plotLocation += 80;
    }
}

/* function: plot16Bitmap
   plots a 16-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void plot16Bitmap(UINT8 *base, UINT16* bitmap, int x, int y, int height) {
    int i;

    UINT16 *plotLocation = (UINT16 *)base + (y * 40) + (x >> 4);
    for(i=0;i<height;i++) {
        *plotLocation |= *(bitmap++);
        plotLocation += 40;
    }
}

/* function: plot32Bitmap
   plots a 32-bit bitmap
   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   column - starting column in the bitmap
   row    - starting row in the bitmap
   height - number of rows affected
*/
void plot32Bitmap(UINT8 *base, UINT32* bitmap, int x, int y, int height) {
    int i;

    UINT32 *plotLocation = (UINT32 *)base + (y * 20) + (x >> 5);
    for(i=0;i<height;i++) {
        *plotLocation |= *(bitmap++);
        plotLocation += 20;
    }
}

/* function: plot32Bitmap
   plots a horizontal line
   inputs:
   base   - pointed on the starting address of the bitmap
   row    - row to plot line in
*/
void plotHorizontalLine (UINT8 *base, int y) {
    int i;
    UINT32 *plotLocation = (UINT32 *)base + (y * 20);
    for(i=0;i<20;i++) {
        *plotLocation |= -1;
        plotLocation++;
    }



}
