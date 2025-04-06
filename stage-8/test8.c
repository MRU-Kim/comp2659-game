/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       test8.c
Professor     	Steve Kalmar

purpose:
test driver of new characteristics of stage 8 implementation
ie: get_video_base, set_video_base
rectangles.
*/
#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "RASTER.H"


int main()
{
    UINT32 oldSsp;
    UINT8 *fb;
    static UINT8 buffer2Arr[32000 + 256];
    UINT8 *buffer2 = buffer2Arr;
    UINT16 buffer2IntAdd = (UINT16)buffer2Arr;

    /*find displacement of buffer2 from being 256 byte alligned
    then add displacement */
    UINT16 displacement = 256 - buffer2IntAdd % 256;
    buffer2 += displacement;


    fb = get_video_base();
    printf("%p default address\n", fb);
    set_video_base(buffer2);
    printf("%p default address\n", fb);

    plotRectangle(buffer2, 100, 50);

    plotRectangle(buffer2, 200, 50);

    plotRectangle(buffer2, 300, 50);
    /*modify via ass*/
    Cnecin();
    set_video_base(fb);
    fb = get_video_base();
    printf("%p address\n", fb);




    return 0;
}
