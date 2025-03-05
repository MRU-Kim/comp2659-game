/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       TST_RAST.C
Professor     	Steve Kalmar
*/

#include <osbind.h>
#include <osbind.h>
#include "RASTER.H"
#include "objects.h"
#include "CONST.H"

int main()
{
	UINT8 *base = Physbase();  /* 8-bit */

	int i;
	Cnecin();
	clearScreen(base); /* set screen to all white */
	Cnecin();
	plot16Bitmap(base,Dino,320,384,DinoHeight);
	Cnecin();
	clear16Bitmap(base,Dino,320,200,DinoHeight);


	for(i = -16; i < 640; i++){

		plot16Bitmap(base,Dino,i,i,DinoHeight);
		Cnecin();
		clearScreen(base); /* set screen to all white */
	}

	plotHorizontalLine(base, 200+DinoHeight);
	Cnecin();
	
	
	while( i<600-16){
		Cnecin();
		clearScreen(base); /* set screen to all white */
		i++;
		plot16Bitmap(base,CactusLarge,(600-16)-i,200,CactusLargeHeight);
	}

	plot16Bitmap(base,DinoCrouch,320,200,DinoHeight);
	Cnecin();
	clear16Bitmap(base,Dino,320,200,DinoHeight);
	clearScreen(base); /* set screen to all white */
	Cnecin();
	return 0;
}
