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

int main()
{
    Vector originalVBL = installVector(VblVect, vblIsr);
    Vector originalIKBR = installVector(IKBDVect, IkbrIsr);
    int i = 0;
    char getkeytest = 0;
    UINT32 countcounter = 0;

    while (vbCounter < 70)
    {
        countcounter++;
    }
    vbCounter = 0;
    waitVBlank();
    countcounter = get_Time();
    printf("%lu\n", countcounter);

    while (vbCounter < 70)
    {
        for (i = 0; i < 8; i++)
        {
            printf("%du ", keyValues[i]);
        }

        printf("\n", );
    }
    vbCounter = 0;

    while (vbCounter < 700)
    {
        getkeytest = getKey();
        printf("%c \n", getkeytest);
    }
    vbCounter = 0;

    installVector(VblVect, originalVBL);
    installVector(IKBDVect, originalIKBR);
    return 0;
}
