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
typedef struct
{
    DinoPlayer lastDrawnPlayer;
    CactusMed lastDrawnCactiMed[MaxCactus];
    Ground lastDrawnGround;
    Score lastDrawnScore;
    HighScore lastDrawnHighScore;
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