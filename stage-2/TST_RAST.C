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
	UINT8 *base8 = Physbase();  /* 8-bit */
	UINT16 *base16 = Physbase();
	UINT32 *base32 = Physbase();
	Cnecin();
	clearScreen(base8,0); /* set screen to all white */
	Cnecin();
	plot16Bitmap(base16,Dino,320,200,DinoHeight);
	Cnecin();
	plot32HorizontalLine(base32, 200+DinoHeight);
	Cnecin();
	clear16Bitmap(base16,Dino,320,200,DinoHeight);
	Cnecin();
	clearScreen(base8,0); /* set screen to all white */
	Cnecin();
	return 0;
}
