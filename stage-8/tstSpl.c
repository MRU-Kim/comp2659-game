/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       tstSpl.c
Professor     	Steve Kalmar

#include "RASTER.H"
#include "CONST8.H"
#include "splash.h"
#include <stdio.h>
#include <osbind.h>
#include"RASTER.H"

/*Purpose:
tester for splash screen functions stuff*/

int main()
{
    UINT8 *defaultBase = get_video_base();

    static UINT8 b2Arr[32000 + 256];
    int result = 0;

    UINT8 *b2 = b2Arr;
    UINT16 b2IntAdd = (UINT16)b2Arr;
    UINT16 displacement = 256 - b2IntAdd % 256;
    b2 += displacement;

    Cnecin();
    clearScreen(defaultBase);
    result = welcomeScreen(defaultBase);
    printf("%d reseult\n", result);
    Cnecin();
    return 0;
}