/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       clock.c
Professor     	Steve Kalmar

Purpose:
Hold functions that involve time based purposes
*/

#include "clock.h"
#include "osbind.h"
#include "const.h"

/*function get_Time
returns unsigned long from the verticle blank counter
Output:
TimeNow - current value of VBlank counder */
UINT32 get_Time()
{
    long volatile *timer = (long *)VBlankCountAdd;
    long timeNow;
    long oldSsp = Super(0);
    timeNow = *timer;
    Super(oldSsp);
    return timeNow;
}
/*function waitVblank
stalls program until Vblank counter changes*/
void waitVBlank()
{
    long volatile *VBlankCounter = (long*)VBlankCountAdd;
    long countNow, countThen;
    long oldSsp = Super(0);
    countNow = *VBlankCounter;
    countThen = countNow;

    while (countNow == countThen)
    {
        countNow = *VBlankCounter;
    }
    Super(oldSsp);
}
