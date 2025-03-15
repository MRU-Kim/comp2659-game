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

/*ASYNC EVENTS*/
void evJump(DinoPlayer *player)
{
    if (player->y == GroundY + DinoHeight &&
        player->delta_y < MaxJump)
    { /* on the ground and below maxjump*/
        jump(player);
    }
}

void evCrouch(DinoPlayer *player)
{
    crouch(player);
}

void evAircrouch(DinoPlayer *player)
{
    aircrouch(player);
}

/* function startGame
    on jump input start game
    */
void startGame(Model *model)
{
    startScroll(&model->scrollSpeed);
}

/*SYNC EVENTS*/

/* function: evScroll
    scrolls all scrollable objects to the left
    so far this is only cactusMed
    inputs:
    CactusMed - array of cactusMed
    ScrollSpeed - ScrollSpeed speed to be forced on all side scrolling objects

*/
void evScroll(CactusMed *cacti[], ScrollSpeed scrollSpeed)
{
    int i;
    for (i = 2; i >= 0; i--)
    {
        scrollMedCactus(cacti[i], scrollSpeed);
    }
}

/* function: evPlayerUpdate
    on update change dino Y according to delta_y
    don't place dino above MaxJump, or dinoY
    check if dino is hitting cactus, if so, call death
*/
void evPlayerUpdate(DinoPlayer *player)
{
    player->y += player->delta_y;
    if (player->y>DinoY) /*dino below bounds*/
    {
        player->y = DinoY;
    }
    else if (player->y < MaxJump)/*dino above bounds*/
    {
        player->y = MaxJump;
    }
    else if (player->delta_y>=0 && player->y < DinoY) /*dino in air and  */
    {
        
    }
    
    
    
}

void evSpawnMedCactus(CactusMed *cactusMed)
{
}

void evDinoFall(DinoPlayer *evDinoDeath)
{
    
}

/* fucntion: evInitializeModel
    initializes model to start conditions
    inputs:
    Model- model to be initialized

*/
void evInitializeModel(Model *model)
{
    int i;
    model->player.x = 100; /*init player*/
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
/*cascade events*/

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
