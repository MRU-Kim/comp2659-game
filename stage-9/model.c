/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       model.C
Professor     	Steve Kalmar

Purpose:
The file defines the behavior of the game's objects which
consists of Dino, cactuses, terrain, current game's score
and the high score. Functions in this file change their states
based on game events like jumping, spawning obstacles, and
scrolling.
*/

#include "model.h"
#include "CONST.H"


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
    acclerates player downwards if they are in air
    inputs:
    player - dino object
*/
void dinoFall(DinoPlayer *player)
{
    if (player->y < DinoY)
    {
        player->delta_y++;
    }
}
/*  function: dinoLand
    resets dino velocity
    inputs:
    player - pointer to player*/
void dinoLand(DinoPlayer *player)
{
    player->delta_y = 0;
}
/*  function: dinoAirCrouch
    sets dinos velocity to AirCrouchSpeed
    inputs:
    player - pointer to player*/
void dinoAirCrouch(DinoPlayer *player)
{
    player->delta_y = AirCrouchSpeed;
}

/* function: updateDinoY
    changes Dino's y by it's velocity on an update
    inputs:
    player - pointer to player*/
void updateDinoY(DinoPlayer *player)
{
    player->y += player->delta_y;
}

/*  function: dinoCrouch
    Makes Dino crouch, used purely for sprite draw purposes
    inputs:
    player - pointer to player*/
void dinoCrouch(DinoPlayer *player)
{
    player->isCrouched = true;
}

/*  function: dinoStand
    Makes Dino stand, used purely for sprite draw purposes
    inputs:
    player - pointer to player*/
void dinoStand(DinoPlayer *player)
{
    player->isCrouched = false;
}

/*  function: dinoDie
    Makes Dino die and clears moving flag
    inputs:
    player - pointer to player*/
void dinoDie(DinoPlayer *player)
{
    player->isAlive = false;
    player->isMoving = false;
}

/*function: dinoMove
    sets dino move flag
    inputs:
    player - pointer to player*/
void dinoMove(DinoPlayer *player){
    player->isMoving = true;
}

/*  function: dinoRunCycleAdvance
    Toggles run sprite flag for animation
    inputs:
    player - pointer to player*/
void dinoRunCycleAdvance(DinoPlayer *player)
{
    player->walkCycle = !player->walkCycle;
}

/*------cactus behaviors------*/
/*fucntion: medCactusSpawn
    Spawns a cactus at a fixed starting position
    cactusMed - pointer to cactus to be spawned*/
void medCactusSpawn(CactusMed *cactusMed)
{
    cactusMed->x = ScreenWidth + CactMedWidth;
    cactusMed->y = CactMedY;
}
void medCactusScroll(CactusMed *cactusMed, ScrollSpeed scrollSpeed)
{
    if (cactusMed->x > leftLimit)
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

/*function: scrollStart
    starts scrolling of horizontally moving objects
    inputs:
    scrollSpeed - pointer to model scroll speed*/
void scrollStart(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = StartScrollSpeed;
}
/*function: scrollStop
    stops scrolling of horizontally moving objects
    inputs:
    scrollSpeed - pointer to model scroll speed*/
void scrollStop(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 0;
}

/*model behaviors*/

/* function: modelInitialize
    gets random seed
    sets highscore to zero
    initializes model to start conditions
    inputs:
    model - model to be to be initialized
*/
void modelInitialize(Model *model)
{
    modelGetSeed(model);
    model->highScore.value = 0;

    modelResetNonePersists(model);
}

/* function: modelResetNonePersists
    reset everything into new run except high score and rand num
*/
void modelResetNonePersists(Model *model)
{
    int i;
    model->player.x = DinoX; /*set player*/
    model->player.y = DinoY;
    model->player.delta_y = 0;
    model->player.isAlive = true;
    model->player.isCrouched = false;
    model->player.runAnimationTimer = DinoRunTimerLength;
    model->player.isMoving = false;

    /*set cacti*/
    for (i = 0; i < MaxCactus; i++)
    {
        model->cactiMed[i].x = leftLimit;
        model->cactiMed[i].y = CactMedY;
    }
    model->ground.y = GroundY;
    /*set score*/
    model->score.value = 0;

    /*set model logic*/

    model->scrollSpeed.delta_x = 0;
    model->hasInput = false;

    model->gravTimer = GravityTime;
    modelResetCacSpawnTimer(model);
    model->nextMilestone = MileStoneScore;
    model->runTicksPassed = 0;
}

/*function: modelGetSeed
    puts a semi random number in model ranNum*/
void modelGetSeed(Model *model)
{
    model->ranNum = (UINT16)model;
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

/*function: modelResetCacSpawnTimer
    after spawning a cactus this is called to reset to
    MinCacSpawnTime + 0 to MaxCacSpawnTimeAdd ticks
    inputs:
    model - pointer to model*/
void modelResetCacSpawnTimer(Model *model)
{
    model->ranNum = lfsr16(model->ranNum);
    model->cacSpawnTimer = abs(model->ranNum % MaxCacSpawnTimeAdd) + MinCacSpawnTime - (model->score.value/100); /*70 ticks in a second*/
}

/*helper functions*/
/*function: abs
    gets absolute value of inputed num
    inputs:
    num - number to be returned in absolute value
*/
int abs(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    return num;
}
/*function lfsr16
    a 16 bit linear feedback shift register that uses maximal lenth taps
    intended to be fed a number out put that number then be given it again
    when randomness is needed
    inputs: seed 16 bit number that isn't 0
    lfsr info https://en.wikipedia.org/wiki/Linear-feedback_shift_register*/
int lfsr16(int seed)
{
    UINT16 lfsr = seed;
    UINT16 feedback;
    /*taps are at bits 0 2 3 5*/
    feedback = (lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) & 1;
    lfsr = (lfsr >> 1) | (feedback << 15);
    return lfsr;
}
