/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
File name       events.c
Professor       Steve Kalmar

Purpose:
Handles all game events in response to user input or game state updates.
This includes player actions (jump, crouch), game progression (scrolling,
obstacle spawning, score tracking), and game state transitions (death, restart).
It updates the model accordingly and coordinates interactions between player and environment.
different from earlier stages in that it incorperated sound effects
*/

#include "const.h"
#include "model.h"
#include "events.h"
#include "EFFECTS.H"

/*tester libs*/
#include <stdio.h>

/*ASYNC EVENTS*/

/*function: evKBInputHandle
    manages async events calling also
    if game has not started or needs to be restarted
    does so on jump input
    inputs:
    model - model object
    input - inputted character
*/
void evKBInputHandle(Model *model, char input)
{
    DinoPlayer *player = &(model->player);
    model->hasInput = true;

    if (model->scrollSpeed.delta_x)
    {

        if (input == 'w')
        {
            evJump(model);
        }
        else if (input == 's')
        {
            evCrouch(player);
        }
    }
    else if (input == 'w')
    {
        evStartGame(model);
    }
}
/*function: evJump
    gives dino upward velocity if they are on the ground
    if they are in the air and havent reached the jump limit they keep their velocity
    otherwise they begin to fall
    plays jump sound if on ground
    input:
    player - pointer to player*/
void evJump(Model *model)
{
    DinoPlayer *player = &(model->player);

    if (player->y == DinoY || player->y >= MaxJump && player->delta_y == JumpSpeed)
    { /* on the ground or below maxjump and hasn't decelerated yet*/
        dinoJump(player);
        dinoStand(player);
        if (player->y == DinoY)
        {
            playJumpSound();
        }
        
    }
    else
    {
        model->hasInput = false;
    }
}

/*function: evCrouch
    if dino is on ground activate dino's crouch flag
    else makes dino go down even faster
    input:
    player - pointer to player*/
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
    reset model to after death sate, start scroll, reset score,
    activate dinoMove flag
    input:
    model - pointer to model*/
void evStartGame(Model *model)
{
    modelResetNonePersists(model);
    scrollStart(&model->scrollSpeed);
    dinoMove(&model->player);
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

    for (i = 0; i < MaxCactus; i++)
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

/* function: evPlayerUpdate
    on update change dino Y according to delta_y.
    stops dino from clipping below ground.
    changes dino's run sprite flag every 35 ticks
*/
void evPlayerUpdate(Model *model)
{
    DinoPlayer *player = &model->player;
    /*update player position*/
    player->y += player->delta_y;
    if (player->y > DinoY) /*dino below bounds*/
    {
        player->y = DinoY;
        player->delta_y = 0;
    }
    /*check if 35 ticks has passed, if so, change run sprite flag*/
    if (player->runAnimationTimer <= 0)
    {
        dinoRunCycleAdvance(player);
        player->runAnimationTimer = DinoRunTimerLength;
    }
    player->runAnimationTimer--;
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
        for (i = 0; i < MaxCactus; i++)
        /*check if a cactus is in play and spawn if not*/
        {
            if (model->cactiMed[i].x <= leftLimit && cactusSpawned == false)
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
   Progress game state if player is alive, puts player into neutral state
   if there is no acceptable input
   updating player state
   scrolling obsticles
   spawning
    input:
    model - pointer to model
*/
void evModelUpdate(Model *model)
{
    /*update to new state*/
    if (!model->hasInput)
    {
        evPlayerNeutal(model);
    }

    model->hasInput = false;

    if (model->player.isAlive)
    {
        evPlayerUpdate(model);
        evScroll(model); /*move cactus and check if dino needs to die*/
        evCactusSpawn(model);
        evScoreIncrement(model);
        evMilestone(model);
        modelIncrmentTick(model);
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

/* function evPlayerNeutal
    accelerate downwards if player is in air and grav timer is 0,
    decrements otherwise
    and sets dino to standing
    input:
    player - pointer to player*/
void evPlayerNeutal(Model *model)
{
    DinoPlayer *player = &model->player;

    if (model->gravTimer <= 0)
    {
        dinoFall(player);
        model->gravTimer = GravityTime;
    }
    else
    {
        model->gravTimer--;
    }
    dinoStand(player);
}

/* function: evMilestone
    after 1000 points increase the speed of the evScroll
    then sets next milestone
    inputs:
    model - pointer to model
*/
void evMilestone(Model *model)
{
    if (model->nextMilestone < model->score.value)
    {
        model->scrollSpeed.delta_x++;
        model->nextMilestone += MileStoneScore;
    }
}
/*function: evDeath
    to be triggered when the dino intersects with a cactus hitbox
    stops evScroll, dino dies, sets new high score, plays death sound
    input:
    model - pointer to model
*/
void evDeath(Model *model)
{
    playDeathSound();
    dinoDie(&model->player);
    scrollStop(&model->scrollSpeed);
    evUpdateHighscore(model);
}

/*  function: evUpdateHighscore
    sets highscore to current score if current score
    is larger than current highscore
    input:
    model - pointer to model
    */
void evUpdateHighscore(Model *model)
{
    if (model->score.value > model->highScore.value)
    {
        model->highScore.value = model->score.value;
    }
}