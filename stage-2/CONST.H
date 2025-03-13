/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       CONST.H
Professor     	Steve Kalmar
*/

#ifndef CONST_H
#define CONST_H

/* types */
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
#define true 1
#define false 0

/* screen */
#define ScreenWidth 640
#define ScreenHeight 400
#define BytesPerScreen 32000

/* object */
#define DinoHeight 16
#define CactusMedHeight 16
#define GroundLevel 200
#define MaxJump GroundLevel-DinoHeight-30



#endif
