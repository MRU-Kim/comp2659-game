/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       renderer.c
Professor     	Steve Kalmar

Purpose:
Provides all rendering logic for drawing and updating game graphics
on screen based on the model state. This includes drawing and clearing
the Dino, obstacles, ground, and score. The file uses a render tracker
to minimize unnecessary redraws and ensure efficient frame updates.

Assumptions:
- All sprites are 16 pixels wide and use consistent dimensions for clearing and plotting.
- The raster, object, and CONST files from Stage 2 are correctly implemented and included.


*/

/*
Contains rendering functions
*/

#include "render.h"
#include "../stage-2/raster.h"
#include "../stage-2/objects.h"
#include "../stage-2/CONST.H"
#include "../stage-3/model.h"

/*function: initTracker
    redundant????
    force all */
void initTracker(RenderTracker *tracker)
{
    int i;
    for (i = 0; i < MaxCactus; i++)
    {
        tracker->lastDrawnCactiMed[i].x = -16;
    }
}

/*function: redraw
    runs redraw routines, if the game is restarted all objects are refreshed
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void redraw(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    redrawScoreBox(model, tracker, base);
    redrawCacti(model, tracker, base);
    redrawDino(model, tracker, base);
}

/*function: force draw
    clears buffer and draws everything at once according to the model
    should be used at start of game
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void forceDraw(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    clearScreen(base);
    trackerMedCactiCopy(model, tracker);
    drawDino(model, tracker, base);
    drawGround(model, tracker, base);
}

/*function: redraw Dino
    checks if Dino has changed since the last render, if so clears old bitmap,
    and draws according to new state
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void redrawDino(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    const DinoPlayer *player = &model->player;
    DinoPlayer *trackerDino = &tracker->lastDrawnPlayer;
    if (player->isAlive != trackerDino->isAlive ||
        player->isCrouched != trackerDino->isCrouched ||
        player->walkCycle != trackerDino->walkCycle ||
        player->y != trackerDino->walkCycle)
    {
        clearDino(model, tracker, base);
        drawDino(model, tracker, base);
    }
}

/*function drawDino
    draws dino according to the model
    if dead, draw dead, if alive and not on ground running draw
    to be called after previous dino render is anihilated
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void drawDino(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    const DinoPlayer *player = &model->player;
    DinoPlayer *trackerDino = &tracker->lastDrawnPlayer;
    if (!player->isAlive)
    {
        plot16Bitmap(base, DinoDeadSprite, player->x, player->y, DinoHeight);
    }
    else if (player->isCrouched) /*crouch has precedence over all*/
    {
        plot16Bitmap(base, DinoCrouchSprite, player->x, player->y, DinoHeight);
    }
    else if (player->y == DinoY && player->isMoving) /*if player is on ground*/
    {

        if (player->walkCycle)
        {
            plot16Bitmap(base, DinoMove2Sprite, player->x, player->y, DinoHeight);
        }
        else /*if dino is not moving but false walk flag*/
        {
            plot16Bitmap(base, DinoMove1Sprite, player->x, player->y, DinoHeight);
        }
    }
    else /*if dino is in air or on ground not moving*/
    {
        plot16Bitmap(base, DinoStandSprite, player->x, player->y, DinoHeight);
    }
    trackerDinoCopy(player, trackerDino);
}

/*function clearDino
    clears dino according to the the render tracker
    to be called if current render is different from model
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void clearDino(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    DinoPlayer *trackerDino = &tracker->lastDrawnPlayer;
    if (!trackerDino->isAlive)
    {
        clear16Bitmap(base, DinoDeadSpriteClear, trackerDino->x, trackerDino->y, DinoHeight);
    }
    else if (trackerDino->isCrouched) /*crouch has precedence over all*/
    {
        clear16Bitmap(base, DinoCrouchSpriteClear, trackerDino->x, trackerDino->y, DinoHeight);
    }
    else if (trackerDino->y == DinoY && trackerDino->isMoving) /*if trackerDino is on ground*/
    {

        if (trackerDino->walkCycle)
        {
            clear16Bitmap(base, DinoMove2SpriteClear, trackerDino->x, trackerDino->y, DinoHeight);
        }
        else /*if dino is not moving but false walk flag*/
        {
            clear16Bitmap(base, DinoMove1SpriteClear, trackerDino->x, trackerDino->y, DinoHeight);
        }
    }
    else /*if dino is in air or on ground not moving*/
    {
        clear16Bitmap(base, DinoStandSpriteClear, trackerDino->x, trackerDino->y, DinoHeight);
    }
}

/*function: trackerDinoCopy
    copies the current aspects of model dino and scrollspeed into the tracker
    should be called everytime the dino render is updated
    input:
    trackerDino, pointer dino render tracker
    dino, pointer to model dino*/
void trackerDinoCopy(const DinoPlayer *player, DinoPlayer *trackerDino)
{
    trackerDino->x = player->x;
    trackerDino->isAlive = player->isAlive;
    trackerDino->isCrouched = player->isCrouched;
    trackerDino->walkCycle = player->walkCycle;
    trackerDino->y = player->y;
    trackerDino->isMoving = player->isMoving;
}

/*  function: redrawCacti
    checks each cactus to see if it is on screen and has changed
    if so redraws it
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void redrawCacti(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    const CactusMed *cactusMed = model->cactiMed;
    CactusMed *trackerCactusMed = tracker->lastDrawnCactiMed;
    int i;
    for (i = 0; i < MaxCactus; i++)
    {
        if (cactusMed[i].x != trackerCactusMed[i].x)
        {
            clear16Bitmap(base, CactusMedSpriteClear, trackerCactusMed[i].x, trackerCactusMed[i].y, CactMedHeight);
            plot16Bitmap(base, CactusMedSprite, cactusMed[i].x, cactusMed[i].y, CactMedHeight);
            trackerCactusMed[i].x = cactusMed[i].x;
            trackerCactusMed[i].y = cactusMed[i].y;
        }
    }
}
/*function: trackerMedCactiCopy
    forcefully updates the render tracking for all medium cacti
    to be used after clearing screen
    input:
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void trackerMedCactiCopy(const Model *model, RenderTracker *tracker)
{
    int i;
    for (i = 0; i < MaxCactus; i++)
    {
        tracker->lastDrawnCactiMed[i].x = model->cactiMed[i].x;
        tracker->lastDrawnCactiMed[i].y = model->cactiMed[i].y;
    }
}

void drawGround(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    plotHorizontalLine(base, model->ground.y);
    tracker->lastDrawnGround.y = GroundY;
}

void clearGround(const Model *model, RenderTracker *tracker, UINT8 *base)
{
}

/*function: redrawScorebox
    if score has changed, redraw it
    if high score is not 0 and has changed redraw it
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void redrawScoreBox(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    if (tracker->lastDrawnHighScore.value != model->highScore.value)
    {
        printNum(base, ScoreX, ScoreY, model->score.value);
    }

    if (model->highScore.value != 0 && tracker->lastDrawnHighScore.value != model->highScore.value)
    {
        printString(base, HighScoreX - 20, HighScoreY, "HI");
        printNum(base, HighScoreX, HighScoreY, model->highScore.value);
    }
}
