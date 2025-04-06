/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       clock.h
Professor     	Steve Kalmar
*/

#ifndef CLOCK_H
#define CLOCK_H
#include "const.h"

extern volatile UINT32 vbCounter;

UINT32 get_Time();

void waitVBlank();

#endif