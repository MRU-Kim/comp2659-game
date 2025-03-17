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

/* function evStartGame
    on jump input start scroll and set up
    */
void evStartGame(Model *model)
{
    scrollStart(&model->scrollSpeed);
    scoreReset(&model->score);
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
        evResetCacSpawnTimer(model);
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
    evScoreIncrement(model);
    modelIncrmentTick(model);
}

/*function: evScoreIncrement
    if tick is evenly divisible by 10 increment score by speed
    input: 
    model - pointer to model
*/
void evScoreIncrement(Model *model){
    if (model->runTicksPassed %10 == 0)
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
    if (model->lastMilestone < model->score.value-1000 == 0){
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


/*function: evResetCacSpawnTimer
    after spawning a cactus this is called to reset to 1-2 seconds*/
void evResetCacSpawnTimer(Model *model)
{
    model->ranNum = lfsr16(model->ranNum);
    model->cacSpawnTimer = model->ranNum % 70 + 70; /*70 ticks in a second*/
}