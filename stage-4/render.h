/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       renderer.h
Professor     	Steve Kalmar
*/

#ifndef RENDER_H
#define RENDER_H

#include "../stage-3/model.h"
#include "../stage-2/const.h"

void redraw(const Model *model, UINT8 *base);
void forceRedraw(Model *model);

void redrawDino(const DinoPlayer *dino, UINT8 *base);
void redrawObticles(const CactusSmall *cactusSmall, UINT8 *base);
void redrawGround(const Ground *ground, UINT8 *base);
void reDrawScores(const Score* Score, UINT8 *base);

#endif