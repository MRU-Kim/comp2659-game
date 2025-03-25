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




UINT32 get_Time()
{
    long *timer = (long *)0x462; // Address of longword auto-incremented 70x per second
    long timeNow;
    long oldSsp = Super(0); // enter privileged mode
    timeNow = *timer;
    Super(oldSsp); // exit privileged mode as soon as possible
    return time;
}
