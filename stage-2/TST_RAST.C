/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       TST_RAST.C
Professor     	Steve Kalmar
*/

#include <osbind.h>
#include "RASTER.H"
#include "objects.h"
#include "CONST.H"

char input;
int main()
{
	UINT8 *base = Physbase(); /* 8-bit */

	int i;

	Cnecin();
	clearScreen(base); /* set screen to all white */
	Cnecin();		   /*plot and clear mostly above screen*/
	plot16Bitmap(base, DinoDeadSprite, ScreenCentreX, ScreenCentreY, DinoHeight);

	Cnecin();
	clearScreen(base); /* set screen to all white */
	Cnecin();		   /*plot and clear mostly above screen*/
	plot16Bitmap(base, DinoStandSprite, 320, -15, DinoHeight);

	Cnecin();
	clear16Bitmap(base, DinoStandSprite, 320, -15, DinoHeight);
	Cnecin(); /*plot and clear mostly left of screen*/
	plot16Bitmap(base, DinoStandSprite, -15, DinoY, DinoHeight);

	Cnecin();
	clear16Bitmap(base, DinoStandSprite, -15, DinoY, DinoHeight);
	Cnecin(); /*plot and clear mostly right of screen*/
	plot16Bitmap(base, DinoStandSprite, 639 + 14, DinoY, DinoHeight);

	Cnecin();
	clear16Bitmap(base, DinoStandSprite, 639 + 14, DinoY, DinoHeight);
	Cnecin(); /*plot and clear mostly below of screen*/
	plot16Bitmap(base, DinoStandSprite, DinoX, 397, DinoHeight);

	Cnecin();
	clear16Bitmap(base, DinoStandSprite, DinoX, 397, DinoHeight);
	Cnecin();
	for (i = 383; i < ScreenHeight - 1; i++)
	{

		plot16Bitmap(base, DinoStandSprite, i, i, DinoHeight);
		Cnecin();
		clear16Bitmap(base, DinoStandSprite, i, i, DinoHeight);
	}

	plotHorizontalLine(base, 200 + DinoHeight);
	Cnecin();

	while (i < 600 - 16 && input != 'q')
	{
		plot16Bitmap(base, CactusMedSprite, (600 - 16) - i, 200, CactMedHeight);
		input = Cnecin();
		clear16Bitmap(base, CactusMedSprite, (600 - 16) - i, 200, CactMedHeight);

		i += 5;
	}

	plot16Bitmap(base, DinoCrouchSprite, 320, 200, DinoHeight);
	Cnecin();
	clear16Bitmap(base, DinoStandSprite, 320, 200, DinoHeight);
	clearScreen(base); /* set screen to all white */
	Cnecin();
	return 0;
}
