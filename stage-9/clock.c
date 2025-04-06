/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       clock.c
Professor     	Steve Kalmar

Purpose:
Hold functions that involve time based purposes ans stores
global varaiable vbCounter
*/

#include "clock.h"
#include "osbind.h"
#include "const.h"
#include "CONST9.H"

volatile UINT32 vbCounter = 0;

/*function get_Time
returns unsigned long from the verticle blank counter
Output:
TimeNow - current value of VBlank counder */
UINT32 get_Time()
{
    return vbCounter;
}
/*function waitVblank
stalls program until Vblank counter changes*/
void waitVBlank()
{
    UINT32 then;
    then = vbCounter;


    while (vbCounter == then)
    {
    }
}
