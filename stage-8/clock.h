/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
File name       clock.h
Professor     	Steve Kalmar
*/

#ifndef CLOCK_H
#define CLOCK_H

#define VBlankCountAdd 0x462

#include "const.h"

UINT32 get_Time();

void waitVBlank();

#endif