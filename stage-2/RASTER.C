/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       RASTER.C
Professor     	Steve Kalmar
*/

#include <stdio.h>
#include <osbind.h>

#include "raster.h"

#define BytesPerScreen 32000

/* function: clearScreen
   clears the screen with the color input.
   inputs:
   base   - pointed on the starting address of the bitmap
   color  - color to fill the screen with
*/
void clearScreen(char *base, char color){
	register int i=0;
	register char *location=base;

	while(i++<BytesPerScreen){
		*(location++)=color;
	}
}
