/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
Deadline        March 17, 2024
File name       clock.c
Professor     	Steve Kalmar
*/
#include "clock.h"
#include "osbind.h"
#include "../stage-2/const.h"

UINT32 get_Time()
{
    long *timer = (long *)0x462;
    long timeNow;
    long oldSsp = Super(0);
    timeNow = *timer;
    Super(oldSsp);
    return timeNow;
}

void waitVBlank()
{
    long *VBlankCounter = (long*)0x462;
    long countNow, countThen;
    long oldSsp = Super(0);
    countNow = *timer;
    countThen = countNow;

    while (countNow == countThen)
    {
        countNow = *timer;
    }
    Super(oldSsp);
}
