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
	clearScreen(base,0); /* set screen to all white */
	Cnecin();
	plot16Bitmap(base,Dino,320,200,DinoHeight);
	i = 0;
	
	Cnecin();


	clear16Bitmap(base,Dino,320,200,DinoHeight);


	while(i < 50){

		plot16Bitmap(base,Dino,320+i,200,DinoHeight);
		Cnecin();
		clear16Bitmap(base,Dino,320+i,200,DinoHeight);
		i++;

		
	}
	Cnecin();
	plotHorizontalLine(base, 200+DinoHeight);
	Cnecin();
	plot16Bitmap(base,CactusLarge,600-16,200,CactusLargeHeight);
	Cnecin();
	
	
	while( i<600-16){
		Cnecin();
		clear16Bitmap(base,CactusLarge,600-16-i,200,CactusLargeHeight);
		i++;
		plot16Bitmap(base,CactusLarge,600-16-i,200,CactusLargeHeight);
	}

	clear16Bitmap(base,Dino,320,200,DinoHeight);
	plot16Bitmap(base,DinoCrouch,320,200,DinoHeight);
	Cnecin();
	clear16Bitmap(base,Dino,320,200,DinoHeight);
	clearScreen(base,0); /* set screen to all white */
	Cnecin();
	return 0;
}
