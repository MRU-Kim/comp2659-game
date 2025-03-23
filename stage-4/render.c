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

void redraw(Model *model, UINT8 *base)
{
    /*check what objects have changed render state. to clear previous state, previous state must be stored  */

    redrawDino(model,base);
    redrawObticles(model,base);
    redrawScoreBox(model,base);
}
void forceDraw(Model *model, UINT8 *base)
{
    return;
}

void redrawDino(Model *model, UINT8 *base)
{
    const DinoPlayer *player = &model->player;
    DinoPlayer *lastDrawPlayer = &model->lastDrawnPlayer;
    if (player->isAlive != lastDrawPlayer->isAlive ||
        player->isCrouched != lastDrawPlayer->isCrouched ||
        player->x != lastDrawPlayer->x ||
        player->y != lastDrawPlayer->y)
    {
        if (lastDrawPlayer->isAlive)
        {
        }
        
    }
}
/* */
void redrawObticles(Model *model, UINT8 *base)
{
    return;
}

void redrawScoreBox(Model *model, UINT8 *base)
{
    printString(base, model->score.x, model->score.y, "Score:");
    printNum(base, model->score.x + 50, model->score.y, model->score.value);
    printString(base, model->highScore.x, model->highScore.y, "HI:");
    printNum(base, model->highScore.x + 50, model->highScore.y, model->highScore.value);
}

void redrawGround(Model *model, UINT8 *base)
{
    /* */
}