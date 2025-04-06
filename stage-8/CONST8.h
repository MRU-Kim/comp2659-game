/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       soundconst.h
Professor     	Steve Kalmar

Purpose:
    Holds constants for stage-8 implementation.
*/

#ifndef CONST8_H
#define CONST8_H

/*ox heights*/
#define P1BoxY      100
#define P1TextY     P1BoxY+(BoxHeight/2+4)
#define P2BoxY      200
#define P2TextY     P2BoxY+(BoxHeight/2+4)
#define ExitBoxY     300
#define ExitTextY     ExitBoxY+(BoxHeight/2+4)
#define MiddleScreen 319
#define BoxHeight   50

#define BigLettY     30
#define BigLettHeight 16
#define BigDX       MiddleScreen-40
#define BigIX       MiddleScreen-20
#define BigNX       MiddleScreen
#define BigOX       MiddleScreen+20

#endif