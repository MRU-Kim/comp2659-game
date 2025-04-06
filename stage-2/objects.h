/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
File name       objects.h
Professor     	Steve Kalmar

Purpose:
Declares external references to sprite values used for rendering 
game objects such as the Dino and obstacles. These definitions are
provided in objects.c.
*/

#ifndef OBJECTS_H
#define OBJECTS_H

#include "CONST.H"

extern UINT16 DinoStandSprite[];
extern UINT16 DinoStandSpriteClear[];

extern UINT16 DinoDeadSprite[];
extern UINT16 DinoDeadSpriteClear[];

extern UINT16 DinoMove1Sprite[];
extern UINT16 DinoMove1SpriteClear[];

extern UINT16 DinoMove2Sprite[];
extern UINT16 DinoMove2SpriteClear[];

extern UINT16 DinoCrouchSprite[];
extern UINT16 DinoCrouchSpriteClear[];

extern UINT16 CactusMedSprite[];
extern UINT16 CactusMedSpriteClear[];


#endif