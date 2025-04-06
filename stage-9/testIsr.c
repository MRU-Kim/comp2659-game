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

int main()
{
    int oldticks = -1;
    Vector original = installVector(VblVect, vblIsr);
    UINT32 countcounter = 0;

    while (vbCounter < 70)
    {
        countcounter++;
    }
    waitVBlank();
    countcounter = get_Time();
    printf("%lu\n", countcounter);
    installVector(VblVect, original);
    return 0;
}
