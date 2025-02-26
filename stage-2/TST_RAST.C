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
	Cnecin();
	clearScreen(base,0); /* set screen to all white */
	Cnecin();
	plot16Bitmap(base,Dino,320,200,DinoHeight);
	Cnecin();
	plotHorizontalLine(base, 200+DinoHeight);
	Cnecin();
	plot16Bitmap(base,CactusLarge,340,200,CactusLargeHeight);
	Cnecin();
	clear16Bitmap(base,Dino,320,200,DinoHeight);
	Cnecin();
	clearScreen(base,0); /* set screen to all white */
	Cnecin();
	return 0;
}
