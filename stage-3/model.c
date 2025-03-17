/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       model.C
Professor     	Steve Kalmar
*/

/*
The file defines the behavior of the game's objects which
consists of Dino, cactuses, terrain, current game's score
and the high score. Functions in this file change their states
based on game events like jumping, spawning obstacles, and
scrolling
*/

#include "model.h"
#include "../stage-2/CONST.H"

/*tester libs*/
#include <stdio.h>
/*random num gen*/
#include <time.h>

/*------dino behaviors------*/
/*function: dinoJump
    Makes Dino jump by setting its vertical velocity upwards
    inputs:
    player - pointer to player*/
void dinoJump(DinoPlayer *player)
{
    player->delta_y = JumpSpeed;
}

/* function dinoFall
    acclerates downwards
    inputs:
    player - dino object
*/
void dinoFall(DinoPlayer *player)
{
    if (player->y < DinoY)
    {
        ;
        player->delta_y++;
    }
}
void dinoLand(DinoPlayer *player)
{
    player->delta_y = 0;
}
/* Allows Dino to crouch mid-air */
void dinoAirCrouch(DinoPlayer *player)
{
    player->delta_y = airCrouchSpeed;
}
void updateY(DinoPlayer *player)
{
    player->y += player->delta_y;
}

/* Makes Dino crouch by decreasing its y-position */
void dinoCrouch(DinoPlayer *player)
{
    player->isCrouched = 1;
}
void dinoStand(DinoPlayer *player)
{
    player->isCrouched = 0;
}

void dinoDie(DinoPlayer *player)
{
    player->isAlive = 0;
}

/*------cactus behaviors------*/
/*fucntion: medCactusSpawn
    Spawns a cactus at a fixed starting position
    cactusMed - pointer to cactus to be spawned*/
void medCactusSpawn(CactusMed *cactusMed)
{
    cactusMed->x = ScreenWidth-1+CactMedWidth;
    cactusMed->y = CactMedY;
}
void medCactusScroll(CactusMed *cactusMed, ScrollSpeed scrollSpeed)
{
    if (cactusMed->x > -CactMedWidth)
    { /*if the cactus is on screen */
        cactusMed->x -= scrollSpeed.delta_x;
    }
}

/*------score behaviors------*/


/*funtion: scoreReset
resets score to 0
inputs: */
void scoreReset(Score *score)
{
    score->value = 0;
}

/*------high score behaviors------*/
/*function scoreUpdate
    Updates the high school if the current score is higher
    inputs:
    highScore: current highscore
    score: current score
    */
void scoreUpdate(HighScore *highScore, Score *score)
{
    if (score->value > highScore->value)
    {
        highScore->value = score->value;
    }
}

/*scroll behaviors*/

void scrollStart(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 5;
}

void scrollStop(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 0;
}

/*model behaviors*/
/* function: modelInitialize
    initializes model to start conditions
    inputs:
    model - model to be to be initialized

*/
void modelInitialize(Model *model)
{
    int i;
    model->player.x = DinoX; /*init player*/
    model->player.y = DinoY;
    model->player.delta_y = 0;
    model->player.isAlive = true;
    model->player.isCrouched = false;

    /*init cacti*/
    for (i = 0; i < 3; i++)
    {
        model->cactiMed[i].x = -16;
        model->cactiMed[i].y = CactMedY;
    }
    model->ground.y = GroundY;

    model->score.x = ScoreX;
    model->score.y = ScoreY;
    model->score.value = 0;

    model->highScore.x = HighScoreX;
    model->highScore.y = HighScoreY;
    model->highScore.value = 0;

    model->scrollSpeed.delta_x = 0;

    modelGetSeed(model);
    model->cacSpawnTimer = model->ranNum % 70 + 70; /*70 ticks in a second*/
    model->lastMilestone = 0;
    model->runTicksPassed = 0;
}

/*function: modelGetSeed
    uses systemclock to get a 16 bit num from systemclock*/
void modelGetSeed(Model *model)
{
    model->ranNum = time(NULL);
}

/*function modelIncrmentTick
    increments run ticks
    inputs:
    model - pointer to model*/
void modelIncrmentTick(Model *model)
{
    model->runTicksPassed++;
}
/*function modelIncrmentTick
    resets run ticks to 0
    inputs:
    model - pointer to model*/
void modelTicksPassedReset(Model *model)
{
    model->runTicksPassed = 0;
}

