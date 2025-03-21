#ifndef RASTER_H
#define RASTER_H

#include "CONST.H"

void clearScreen(UINT8 *base); 

void clear8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height);
void clear16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height);

void plot8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height);
void plot16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height);

void plotHorizontalLine (UINT8 *base, int y);
void clearHorizontalLine(UINT8* base, int x, int y);


void printChar(UINT8 *base, int x, int y, char ch);
void printString(UINT8 *base, int x, int y, char *string);
void printNum(UINT8 *base, int x, int y, UINT16 num);

#endif
