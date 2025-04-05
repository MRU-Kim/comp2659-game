/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 2
Deadline        February 28, 2024
File name       RASTER.H
Professor       Steve Kalmar

Purpose:
Declares graphics functions used to plot, clear, and render 8-bit and 16-bit bitmaps,
horizontal lines,and the score. These functions are implemented in RASTER.C and are
used to plot the sprites defined in objects.c to the screen.
*/
#ifndef RASTER_H
#define RASTER_H

#include "CONST.H"

void clearScreen(UINT8 *base); 

void clear8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height);
void clear16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height);

void plot8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height);
void plot16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height);

void plotHorizontalLine (UINT8 *base, int y);
void clearHorizontalLine(UINT8* base, int y);

void plotRectangle(UINT8 *base, int x, int y, int width, int height);
void clearRectangle(UINT8 *base, int x, int y, int width, int height);

void printChar(UINT8 *base, int x, int y, char ch);
void printString(UINT8 *base, int x, int y, char *string);
void printNum(UINT8 *base, int x, int y, UINT16 num);

UINT8 *get_video_base();

#endif
