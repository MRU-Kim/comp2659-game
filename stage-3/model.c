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
    cactusMed->x = 639 + 16;
    cactusMed->y = GroundY;
}
void medCactusScroll(CactusMed *cactusMed, ScrollSpeed scrollSpeed)
{
    if (cactusMed->x > -16)
    { /*if the cactus is on screen */
        cactusMed->x -= scrollSpeed.delta_x;
    }
}

/*------score behaviors------*/
/* Increments the player's score */
void scoreIncrement(Score *score)
{
    score->value++;
}

/*------high score behaviors------*/
/* Updates the high school if the current score is higher */
void scoreUpdate(HighScore *highScore, Score *score)
{
    if (score->value > highScore->value)
    {
        highScore->value = score->value;
    }
}

void scrollStart(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 5;
}

void scrollStop(ScrollSpeed *scrollSpeed)
{
    scrollSpeed->delta_x = 0;
}
