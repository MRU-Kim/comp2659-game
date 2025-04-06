/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       renderer.h
Professor     	Steve Kalmar

Purpose:
Declares all rendering functions and the RenderTracker struct used 
to manage and update the visual display of game entities (Dino, cacti,
ground, score). These functions are responsible for drawing and clearing 
objects on screen based on changes to the game model.

*/

#ifndef RENDER_H
#define RENDER_H

#include "CONST.H"
#include "model.h"
typedef struct
{
    DinoPlayer lastDrawnPlayer;
    CactusMed lastDrawnCactiMed[MaxCactus];
    Ground lastDrawnGround;
    Score lastDrawnScore;
    HighScore lastDrawnHighScore;
    ScrollSpeed lastScrollSpeed;
} RenderTracker;

void initTracker(RenderTracker *tracker);

void redraw(const Model *model, RenderTracker *tracker, UINT8 *base);
void forceDraw(const Model *model, RenderTracker *tracker, UINT8 *base);

void redrawDino(const Model *model, RenderTracker *tracker, UINT8 *base);
void drawDino(const Model *model, RenderTracker *tracker, UINT8 *base);
void clearDino(const Model *model, RenderTracker *tracker, UINT8 *base);
void trackerDinoCopy(const DinoPlayer *player, DinoPlayer *trackerDino);

void redrawCacti(const Model *model, RenderTracker *tracker, UINT8 *base);
void trackerMedCactiCopy(const Model *model, RenderTracker *tracker);



void drawGround(const Model *model, RenderTracker *tracker, UINT8 *base);
void clearGround(const Model *model, RenderTracker *tracker, UINT8 *base);



void redrawScoreBox(const Model *model, RenderTracker *tracker, UINT8 *base);


#endif