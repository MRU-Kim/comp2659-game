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

void redraw(Model *model, UINT8 *base);
void forceDraw(Model *model, UINT8 *base);

void redrawDino(Model *model, UINT8 *base);
void redrawScoreBox(Model *model, UINT8 *base);
void redrawObticles(Model *model, UINT8 *base);
void redrawGround(Model *model, UINT8 *base);

#endif