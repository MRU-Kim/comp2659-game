/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       events.c
Professor       Steve Kalmar
*/

#include "events.h"
#include "../stage-2/const.h"
#include "model.h"

/*tester libs*/
#include <stdio.h>

/*ASYNC EVENTS*/
void evJump(DinoPlayer *player)
{
    if (player->y == DinoY ||
        player->y >= MaxJump && player->delta_y == JumpSpeed)
    { /* on the ground or below maxjump and hasn't decelerated yet*/
        dinoJump(player);
    }
    else
    {
        printf("illegal jump %d \n", player->delta_y);
        dinoFall(player);
    }
}

void evCrouch(DinoPlayer *player)
{
    if (player->y == DinoY)
    {
        dinoCrouch(player);
    }
    else
    {
        dinoAirCrouch(player);
    }
}

/* function startGame
    on jump input start scroll and set up cactusspawn timer
    */
void startGame(Model *model)
{
    scrollStart(&model->scrollSpeed);
}

/*SYNC EVENTS*/

/* function: evScroll
    scrolls all scrollable objects to the left
    and checks if new location
    adds score aswell
    inputs:
    model - pointer to model

*/
void evScroll(Model *model)
{
    DinoPlayer *player = &model->player;
    int i;
    int ydiff;
    int xdiff;

    for (i = 2; i >= 0; i--)
    {
        medCactusScroll(&model->cactiMed[i], model->scrollSpeed);
        /*check if new pos would kill player*/
        ydiff = abs(model->cactiMed[i].y - player->y);
        xdiff = abs(model->cactiMed[i].x - player->x);
        if (ydiff < DinoHeight && xdiff < DinoWidth)
        {
            evDeath(model);
        }
        else{
            scoreIncrement(&model->score, model->scrollSpeed);
        }
    }
}

/* function: evPlayerUpdate
    on update change dino Y according to delta_y
    don't allow dino to clip below ground
*/
void evPlayerUpdate(DinoPlayer *player)
{
    /*update player position*/
    player->y += player->delta_y;
    if (player->y > DinoY) /*dino below bounds*/
    {
        player->y = DinoY;
        player->delta_y = 0;
    }
}
/* function: evCactusSpawn
    chooses what obsticles to spawn based on some randomeness
    spawning them every 1 to 2 seconds
    inputs:
    model - pointer to the whole model
*/
void evCactusSpawn(Model *model)
{
    int i;
    if (model->cacSpawnTimer <= 0)
    {
        for (i = 2; i > 0; i--)
        /*check if a cactus is in play and spawn if not*/
        {
            if (model->cactiMed[i].x < -15)
            {
                medCactusSpawn(&model->cactiMed[i]);
            }
        }
        resetCacSpawnTimer(model);
    }
    else
    {
        model->cacSpawnTimer--;
    }
}
/* funtion: evModelUpdate
    runs player update, performs hit detection, runs cactus spawn management
*/
void evModelUpdate(Model *model)
{
    /*update player*/
    evPlayerUpdate(&model->player);
    evScroll(model); /*move cactus and check if dino needs to die*/
    evCactusSpawn(model);
}

/* fucntion: evInitializeModel
    initializes model to start conditions
    inputs:
    model - model to be to be initialized

*/
void evInitializeModel(Model *model)
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

    getSeed(model);
    model->cacSpawnTimer = model->ranNum % 70 + 70; /*70 ticks in a second*/
    model->lastMilestone = 0;
}
/*Cascade Events*/

/* function evNoInput
    accelerate downwards if player is in air with jump input
    otherwise make dino stand*/
void evNoInput(DinoPlayer *player)
{
    dinoFall(player);
    dinoStand(player);
}

/* function: evMilestone
    after 1000 points increase the speed of the evScroll
    inputs:
    scrollspeed - object that controls speed of scrolling objects
*/
void evMilestone(ScrollSpeed *scrollspeed)
{
}
/*function: evDinoDeath
    triggers on the dino hitbox intersects with a cactus hitbox
        stops evScroll, dino dies, sets new high score, places game into new run after next jump input
*/
void evDeath(Model *model)
{
    dinoDie(&model->player);
    scrollStop(&model->scrollSpeed);
}

void evUpdateHighscore(Score score, HighScore highscore)
{
}
/* function: evResetAfterDeath
    a death reset everything into new run except high score
*/
void evResetAfterDeath(Model *model)
{
    scoreReset(&model->score);
}

/*function: resetCacSpawnTimer
    after spawning a cactus this is called to reset to 1-2 seconds*/
void resetCacSpawnTimer(Model *model)
{
    model->ranNum = lfsr16(model->ranNum);
    model->cacSpawnTimer = model->ranNum % 70 + 70; /*70 ticks in a second*/
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
    /*taps are at bits 0 9 10 13 15*/
    feedback = (lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 5) ^ (lfsr >> 0) & 1;
    lfsr = (lfsr >> 1) | (feedback << 15);
    return lfsr;
}