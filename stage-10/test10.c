/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       tstIsr.c
Professor     	Steve Kalmar

Purpose: tester for stage 9 isr routines
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
    UINT8 *defaultBuffer = get_video_base();

    Vector originalVBL = installVector(VblVect, vblIsr);
    Vector originalIKBR = installVector(IKBDVect, IkbrIsr);
    int i = 0;
    char getkeytest = 0;
    UINT32 countcounter = 0;

    while (vbCounter < 700)
    {

        printf("%dx %dy \n",mouseXlocation, mouseYlocation);
        plot16Bitmap(defaultBuffer, DinoStandSprite ,mouseXlocation, mouseYlocation, 16);
    }
    vbCounter = 0;


    installVector(VblVect, originalVBL);
    installVector(IKBDVect, originalIKBR);
    return 0;
}
