/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       events.c
Professor       Steve Kalmar
*/

#include "../stage-2/const.h"
#include "model.h"
#include "events.h"

/*tester libs*/
#include <stdio.h>

/*ASYNC EVENTS*/

/*  function: evKBInputHandle
    manages async event calling including restarting game after death
    and soon, starting the game
    inputs:
    model - model object*/
void evKBInputHandle(Model *model, char input)
{
    DinoPlayer *player = &(model->player);
    if (model->player.isAlive)
    {

        if (input == 'w')
        {
            evJump(player);
        }
        else if (input == 's')
        {
            evCrouch(player);
        }
        else
        {
            evNoInput(player);
        }
    }
    else if (input == 'w')
    {
        evStartGame(model);
    }
}

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

/* function evStartGame
    on jump input, set model to after death sate, start scroll, reset score
    */
void evStartGame(Model *model)
{
    modelResetAfterDeath(model);
    scrollStart(&model->scrollSpeed);
    scoreReset(&model->score);
}

/*SYNC EVENTS*/

/* function: evScroll
    scrolls all scrollable objects to the left
    and checks if new location would cause player death, if so, kills
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
        /*check if new pos would kill player with a small margin of error*/
        ydiff = abs(model->cactiMed[i].y - player->y);
        xdiff = abs(model->cactiMed[i].x - player->x);
        if (ydiff < DinoHeight - HitErrorMargin && xdiff < DinoWidth - HitErrorMargin)
        {
            evDeath(model);
            return;
        }
    }
}

/* function: evPlayerPosUpdate
    on update change dino Y according to delta_y
    don't allow dino to clip below ground
*/
void evPlayerPosUpdate(DinoPlayer *player)
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
        bool cactusSpawned = false;
        for (i = 2; i >= 0; i--)
        /*check if a cactus is in play and spawn if not*/
        {
            if (model->cactiMed[i].x < -15 && cactusSpawned == false)
            {
                medCactusSpawn(&model->cactiMed[i]);
                cactusSpawned = true;
            }
        }
        modelResetCacSpawnTimer(model);
    }
    else
    {
        model->cacSpawnTimer--;
    }
}
/* funtion: evModelUpdate
    saves prev stateruns player update, performs hit detection, runs cactus spawn management
*/
void evModelUpdate(Model *model)
{
    /*update to new state*/
    if (model->player.isAlive)
    {
        evPlayerPosUpdate(&model->player);
        evScroll(model); /*move cactus and check if dino needs to die*/
        evCactusSpawn(model);
        evScoreIncrement(model);
        modelIncrmentTick(model);
    }
    else
    {
    }
}

void evModelSave(Model *model)
{
    int i;
    /*save old states for sprite redraw*/
    model->prevPlayer.isAlive = model->player.isAlive;
    model->prevPlayer.isCrouched = model->player.isCrouched;
    model->prevPlayer.x = model->player.x;
    model->prevPlayer.y = model->player.y;

    for (i = 0; i < 2; i++)
    {
        model->prevCactiMed[i].x = model->cactiMed[i].x;
        model->prevCactiMed[i].y = model->cactiMed[i].y;
    }
}

/*function: evScoreIncrement
    if tick is evenly divisible by 10 increment score by speed
    input:
    model - pointer to model
*/
void evScoreIncrement(Model *model)
{
    if (model->runTicksPassed % 10 == 0)
    {
        model->score.value += model->scrollSpeed.delta_x;
    }
}

/*CASCADE EVENTS*/

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
    model - pointer to model
*/
void evMilestone(Model *model)
{
    if (model->lastMilestone < model->score.value - 1000 == 0)
    {
        model->scrollSpeed.delta_x++;
    }
}
/*function: evDeath
    to be triggered when the dino intersects with a cactus hitbox
        stops evScroll, dino dies, sets new high score, places game into new run after next jump input
*/
void evDeath(Model *model)
{
    dinoDie(&model->player);
    scrollStop(&model->scrollSpeed);
    evUpdateHighscore(model);
}

void evUpdateHighscore(Model *model)
{
    if (model->score.value > model->highScore.value)
    {
        model->highScore.value = model->score.value;
    }
}