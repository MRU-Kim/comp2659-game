/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       tstIsr.c
Professor     	Steve Kalmar

Purpose: tester for stage 10 mouse modality
*/
#include <stdio.h>
#include <osbind.h>

#include "CONST.H"
#include "CONST9.H"
#include "input.h"
#include "isr.h"
#include "clock.h"
#include "RASTER.H"
#include "render.h"
#include "objects.h"

int main()
{
    static UINT8 buffer2Arr[32000 + 256];

    UINT8 *defaultBuffer = get_video_base();

    UINT8 *buffer2 = buffer2Arr;
    UINT16 buffer2IntAdd = (UINT16)buffer2Arr;
    UINT16 displacement2 = 256 - buffer2IntAdd % 256;

    Vector originalVBL = installVector(VblVect, vblIsr);
    Vector originalIKBR = installVector(IKBDVect, IkbrIsr);
    int x, y, click;
    int i = 0;
    char getkeytest = 0;
    UINT32 countcounter = 0;

    buffer2 += displacement2;


    

    /*set_video_base(buffer2);
     */
    while (vbCounter < 700)
    {
        x = getMouseX();
        y = getMouseY();
        click = getMouseClick();

        plot16Bitmap(defaultBuffer, DinoStandSprite, x, y, 16);

        printf("%d %d\n", mousePress, click);

        if (x>100 && x <540 &&)
        {
            for ( i = 0; i < 50; i++)
            {
                plot16Bitmap(defaultBuffer, DinoStandSprite, 100, i, 16);
            }
            
        }
        
        waitVBlank();
        clear16Bitmap(defaultBuffer, DinoStandSpriteClear, x, y, 16);
    }
    vbCounter = 0;

    installVector(VblVect, originalVBL);
    installVector(IKBDVect, originalIKBR);
    set_video_base(defaultBuffer);

    return 0;
}
