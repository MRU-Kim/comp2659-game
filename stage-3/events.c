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
    else{
        printf("illegal jump %d \n",player->delta_y);
        dinoFall(player);
    }
}

void evCrouch(DinoPlayer *player)
{
    if (player->y == DinoY)
    {
        dinoCrouch(player);
    }
    else{
        dinoAirCrouch(player);
    }
    
    
}

/* function startGame
    on jump input start game
    */
void startGame(Model *model)
{
    scrollStart(&model->scrollSpeed);
}

/*SYNC EVENTS*/

/* function: evScroll
    scrolls all scrollable objects to the left
    so far this is only cactusMed
    inputs:
    CactusMed - array of cactusMed
    ScrollSpeed - ScrollSpeed speed to be forced on all side scrolling objects

*/
void evScroll(Model *model)
{
    int i;
    for (i = 2; i >= 0; i--)
    {
        medCactusScroll(&model->cactiMed[i], model->scrollSpeed);
    }
}

/* function: evPlayerUpdate
    on update change dino Y according to delta_y
    don't place dino above MaxJump, or dinoY
    check if dino is hitting cactus, if so, call death
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
    else if (player->y < MaxJump) /*dino above bounds*/
    {
        player->y = MaxJump;
        player->delta_y++;
    }
    /*hit registration*/
}
/* function: evCactusSpawn
    chooses what obsticles to spawn based on some randomeness
    ideally spawning them every 1 to 2 seconds
    inputs:
    model - pointer to the whole model
*/
void evCactusSpawn(Model *model)
{
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
}
/*Cascade Events*/

/* function noInput
    accelerate downwards if player is in air with jump input
    otherwise make dino stand*/
    void noInput(DinoPlayer *player){
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
void evDinoDeath(DinoPlayer *player)
{
    player->x = -5; /* start position */
    player->y = 0;
    player->delta_y = 0;
}

void evUpdateHighscore(Score score, HighScore highscore)
{
}
/* function: evResetAfterDeath
    a death reset everything into new run except high score
*/
void evResetAfterDeath(Model *model, Model startconditions)
{
}
