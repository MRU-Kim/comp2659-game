/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       renderer.c
Professor     	Steve Kalmar
*/

/*
Contains rendering functions
*/

#include "render.h"
#include "../stage-2/raster.h"
#include "../stage-2/objects.h"
#include "../stage-2/CONST.H"
#include "../stage-3/model.h"
/*function: redraw
    runs redraw routines
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void redraw(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    redrawDino(model, tracker, base);
    redrawCacti(model, tracker, base);
    redrawScoreBox(model, tracker, base);
}

/*function: force draw
    clears screen and draws everything at once according to the model
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void forceDraw(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    clearScreen(base);
    drawDino(model, tracker, base);
    drawCacti(model, tracker, base);
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
    to be called after previous dino is anihilated
    input:
    base - pointer to frame buffer
    model - pointer to model
    tracker - pointer to the dino render tracker*/
void drawDino(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    const DinoPlayer *player = &model->player;
    DinoPlayer *trackerDino = &tracker->lastDrawnPlayer;
    if (player->isAlive)
    {
        if (player->isCrouched) /*crouch has precedence over all*/
        {
            plot16Bitmap(base, DinoCrouchSprite, player->x, player->y, DinoHeight);
            trackerDinoCopy(player, trackerDino);
        }
        else if (player->y == DinoY) /*if player is on ground*/
        {
            if (model->scrollSpeed.delta_x != 0) /*if dino is moving*/
            {
                if (player->walkCycle)
                {
                    plot16Bitmap(base, DinoMove2Sprite, player->x, player->y, DinoHeight);
                    trackerDinoCopy(player, trackerDino);
                }
                else
                {
                    plot16Bitmap(base, DinoMove1Sprite, player->x, player->y, DinoHeight);
                    trackerDinoCopy(player, trackerDino);
                }
            }
        }
        else
            plot16Bitmap(base, DinoStandSprite, player->x, player->y, DinoHeight);
        trackerDinoCopy(player, trackerDino);
    }
    else
    {
        plot16Bitmap(base, DinoDeadSprite, player->x, player->y, DinoHeight);
        trackerDinoCopy(player, trackerDino);
    }
}

/*function clearDino
    clears dino according to the the render tracker
    to be called if current render is different from model
    input:
    base - pointer to frame buffer
    player - pointer to model player
    trackerDino - pointer to the dino render tracker*/
void clearDino(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    DinoPlayer *trackerDino = &tracker->lastDrawnPlayer;
    if (trackerDino->isAlive)
    {
        if (trackerDino->isCrouched) /*crouch has precedence over all*/
        {
            clear16Bitmap(base, DinoCrouchSprite, trackerDino->x, trackerDino->y, DinoHeight);
        }
        else if (trackerDino->y == DinoY) /*if player is on ground*/
        {
            if (model->scrollSpeed.delta_x != 0) /*if dino is moving*/
            {
                if (trackerDino->walkCycle)
                {
                    clear16Bitmap(base, DinoMove2Sprite, trackerDino->x, trackerDino->y, DinoHeight);
                }
                else
                {
                    clear16Bitmap(base, DinoMove1Sprite, trackerDino->x, trackerDino->y, DinoHeight);
                }
            }
        }
        else
            clear16Bitmap(base, DinoStandSprite, trackerDino->x, trackerDino->y, DinoHeight);
    }
    else
    {
        clear16Bitmap(base, DinoDeadSprite, trackerDino->x, trackerDino->y, DinoHeight);
    }
}

/*function: trackerDinoCopy
    copies the current aspects of model dino into the tracker
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
}

/*  function: redrawCacti
    checks each cactus to see if it is on screen and has changed
    if so redraws it*/
void redrawCacti(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    const CactusMed *cactusMed = model->cactiMed;
    CactusMed *trackerCactusMed = tracker->lastDrawnCactiMed;
    int i;
    for (i = 0; i < 3; i++)
    {
        if (cactusMed[i].x != trackerCactusMed[i].x)
        {
            clear16Bitmap(base, CactusMedSprite, trackerCactusMed[i].x, trackerCactusMed[i].y, CactMedHeight);
            plot16Bitmap(base, CactusMedSprite, cactusMed[i].x, cactusMed[i].y, CactMedHeight);
            trackerCactusMed[i].x = cactusMed[i].x;
            trackerCactusMed[i].y = cactusMed[i].y;
        }
    }
}
void drawCacti(const Model *model, RenderTracker *tracker, UINT8 *base)
{
}
void clearCacti(const Model *model, RenderTracker *tracker, UINT8 *base)
{
}

void drawGround(const Model *model, RenderTracker *tracker, UINT8 *base)
{
}

void clearGround(const Model *model, RenderTracker *tracker, UINT8 *base)
{
}

void redrawScoreBox(const Model *model, RenderTracker *tracker, UINT8 *base)
{
    printString(base, model->score.x, model->score.y, "Score:");
    printNum(base, model->score.x + 50, model->score.y, model->score.value);
    printString(base, model->highScore.x, model->highScore.y, "HI:");
    printNum(base, model->highScore.x + 50, model->highScore.y, model->highScore.value);
}
