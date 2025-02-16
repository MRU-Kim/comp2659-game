#ifndef RASTER_H
#define RASTER_H

#include "CONST.H"

void clearScreen(char *base, char color); 
void clear8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height);
void clear16Bitmap(UINT16 *base, UINT16* bitmap, int x, int y, int height);
void clear32Bitmap(UINT32 *base, UINT32* bitmap, int x, int y, int height);
void plot8Bitmap(UINT8 *base, UINT8* bitmap, int x, int y, int height);
void plot16Bitmap(UINT16 *base, UINT16* bitmap, int x, int y, int height);
void plot32Bitmap(UINT32 *base, UINT32* bitmap, int x, int y, int height);

#endif
