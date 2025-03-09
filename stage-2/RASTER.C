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

#include "RASTER.H"
#include "CONST.H"

/* function: clearScreen
    clears screen
   inputs:
   base    - pointer to starting address of framebuffer

*/
void clearScreen(UINT8 *base){
	register int i=0;
	register UINT32 *location = (UINT32 *)base;

	while(i++<BytesPerScreen/4){
		*(location++)= 0x0000;
	}
}

/* function: clear8Bitmap
   Clears a 8px bitmap. Used to clear pixles activated by the 
    plot8Bitmap() function.
    toggles each pixel as to only clear the prev plotted bitmap, given that the same (x,y) .

    inputs:
    base    - pointer to starting address of framebuffer
    bitmap - pointer to start of 8px wide bit map
    y - vertical cord to be cleared
    x - horizontal cord to be cleared
    height - height of bitmap
*/
*/
void clear8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height){
    int i;
    
    int offset = x&7; /*x%8* how far on horizontal plane the x is from being byte alligned*/
    UINT8 *plotLocation;
    int usedHeight = height;
    
    if (y < 0 && y > -height){
        bitmap += -y;
        usedHeight += y;
        y = 0;
    }   else if (y > 399-8){
        usedHeight -= y - 399-8;
    }

    /*plot location is a byte, y rows down, and x/8 bytes right*/
    plotLocation = (UINT16 *)base + (y * 80) + (x >> 3);

    /*check if x is in bounds*/
    if(x > -8 && x < 640){
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single bitwidth*/
        if (x < 0){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted abs(x) to the left 
                x is negative*/
                *(plotLocation+1) ^= *(bitmap++)<<-x;
                plotLocation += 80;
            } 
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639-8){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) ^= *(bitmap++)>> offset;
                plotLocation += 80;
            } 
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else{
            for(i=0;i<usedHeight;i++) {
                *plotLocation ^= *(bitmap)>>offset;
                if(offset != 0){
                    *(plotLocation+1) ^= *(bitmap)<< (8 - offset);
                }
                plotLocation += 80;
                bitmap++;
            }
        }
    }
}

/* function: clear16Bitmap
   Clears a 16px bitmap. Used to clear pixles activated by the 
    plot16Bitmap() function.
    toggles each pixel as to only clear the prev plotted bitmap, given that the same (x,y) .

   inputs:
   base    - pointer to starting address of framebuffer
   bitmap - pointer to start of 16px wide bit map
   y - vertical cord to be cleared
   x - horizontal cord to be cleared
   height - height of bitmap
*/
void clear16Bitmap(UINT8 *base, UINT16* bitmap, int x, int y, int height){    
    int i;

    int offset = x&15; /*x%16* how far on horizontal plane the x is from being word alligned*/
    UINT16 *location;
    int usedHeight = height;
    
    if (y < 0 && y > -height){
        bitmap += -y;
        usedHeight += y;
        y = 0;
    }
    else if (y > 399-16){
        usedHeight -= y - 399-16;
    }

    /*location is a word, y rows down, and x/16 words right*/
    location = (UINT16 *)base + (y * 40) + (x >> 4);

    /*check if x is in bounds*/
    if(x > -16 && x < 640){
        /*check if bitmap is off of left screen edge,
        if so offset and togglr single wordwidth*/
        if (x < 0){
            for(i=0;i<usedHeight;i++) {
                /*toggle the bitmap shifted abs(x) to the left 
                x is negative*/
                *(location+1) ^= *(bitmap++)<<-x;
                location += 40;
            } 
        }
        /*check if bitmap is off of right screen edge,
        if so, offset and toggle single wordwidth*/
        else if (x > 639-16){
            for(i=0;i<usedHeight;i++) {
                /*toggle the bitmap shifted  to the left */
                *(location) ^= *(bitmap++)>> offset;
                location += 40;
            } 
        }
        /*If x is not word alligned toggle over 2 words width, else use 1*/
        else{
            for(i=0;i<usedHeight;i++) {
                *location ^= *(bitmap)>>offset;
                if(offset != 0){
                    *(location+1) ^= *(bitmap)<< (16 - offset);
                }
                location += 40;
                bitmap++;
            }
        }
    }
}

/* function: clear32Bitmap
   Clears a 32px bitmap. Used to clear pixles activated by the 
    plot32Bitmap() function.
    toggles each pixel as to only clear the prev plotted bitmap, given that the same (x,y) .

   inputs:
   base    - pointer to starting address of framebuffer
   bitmap - pointer to start of 32px wide bit map
   y - vertical cord to be cleared
   x - horizontal cord to be cleared
   height - height of bitmap
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
   Plots an 8px wide bitmap onto the screen. The function renders 
   an 8px wide bitmap at a specified (x,y) coordinate position
   on the screen. It uses an OR operation.

   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   y - vertical cord to be cleared
   x - horizontal cord to be cleared
   height - number of rows affected
*/
void plot8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height) {
    int i;
    
    int offset = x&7; /*x%8* how far on horizontal plane the x is from being byte alligned*/
    UINT8 *plotLocation;
    int usedHeight = height;
    
    if (y < 0 && y > -height){
        bitmap += -y;
        usedHeight += y;
        y = 0;
    }   else if (y > 399-8){
        usedHeight -= y - 399-8;
    }

    /*plot location is a byte, y rows down, and x/8 bytes right*/
    plotLocation = (UINT16 *)base + (y * 80) + (x >> 3);

    /*check if x is in bounds*/
    if(x > -8 && x < 640){
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single bitwidth*/
        if (x < 0){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted abs(x) to the left 
                x is negative*/
                *(plotLocation+1) |= *(bitmap++)<<-x;
                plotLocation += 80;
            } 
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639-8){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) |= *(bitmap++)>> offset;
                plotLocation += 80;
            } 
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else{
            for(i=0;i<usedHeight;i++) {
                *plotLocation |= *(bitmap)>>offset;
                if(offset != 0){
                    *(plotLocation+1) |= *(bitmap)<< (8 - offset);
                }
                plotLocation += 80;
                bitmap++;
            }
        }
    }
}

/* function: plot16Bitmap
   Plots a 16px wide bitmap onto the screen. The function renders 
   a 16px wide bitmap at a specified (x,y) coordinate position
   on the screen. It uses an OR operation.

   inputs:
   base   - pointed on the starting address of the bitmap
   bitmap -
   y - vertical cord to be cleared
   x - horizontal cord to be cleared
   height - number of rows affected
*/
void plot16Bitmap(UINT8 *base, UINT16* bitmap, int x, int y, int height) {
    int i;
    
    int offset = x&15; /*x%16* how far on horizontal plane the x is from being word alligned*/
    UINT16 *plotLocation;
    int usedHeight = height;
    
    if (y < 0 && y > -height){
        bitmap += -y;
        usedHeight += y;
        y = 0;
    }   else if (y > 399-16){
        usedHeight -= y - 399-16;
    }

    /*plot location is a word, y rows down, and x/16 words right*/
    plotLocation = (UINT16 *)base + (y * 40) + (x >> 4);

    /*check if x is in bounds*/
    if(x > -16 && x < 640){
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single wordwidth*/
        if (x < 0){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted abs(x) to the left 
                x is negative*/
                *(plotLocation+1) |= *(bitmap++)<<-x;
                plotLocation += 40;
            } 
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639-16){
            for(i=0;i<usedHeight;i++) {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) |= *(bitmap++)>> offset;
                plotLocation += 40;
            } 
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else{
            for(i=0;i<usedHeight;i++) {
                *plotLocation |= *(bitmap)>>offset;
                if(offset != 0){
                    *(plotLocation+1) |= *(bitmap)<< (16 - offset);
                }
                plotLocation += 40;
                bitmap++;
            }
        }
    }
}

/* function: plot32Bitmap
   Plots a 32px wide bitmap onto the screen. The function renders 
   a 32px wide bitmap at a specified (x,y) coordinate position
   on the screen. It uses an OR operation.

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

/* function: plotHorizontalLine
   Plots a horizontal line accross the screen. The function
   sets all pixels in a single horizontal row to 1, effectively 
   drawing a solid horizontal line. It modifies 20 full bytes
   at a specified y-coordinate.

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
