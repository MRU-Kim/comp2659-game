/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       renderer.h
Professor     	Steve Kalmar
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "model.h"
#include "CONST.H"

void render(const DinoPlayer *player, UINT8 *base);
void dinoRender(const DinoPlayer *dino, UINT8 *base);
void obstacleRender(const CactusSmall *cactusSmall, UINT8 *base);
void groundRender(const Ground *ground, UINT8 *base);

#endif