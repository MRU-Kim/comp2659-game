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
#include "../stage-2/const.h"

/*------dino behaviors------*/
/* Makes Dino jump by setting its vertical velocity */
void jump(DinoPlayer *player){
    player->delta_y = -10;
}
void fall(DinoPlayer *player){
    player->delta_y = 10;
}
void land(DinoPlayer *player){
    player->delta_y = 0;
}
/* Allows Dino to crouch mid-air */
void aircrouch(DinoPlayer *player){
    player->delta_y = 20;
}
/* Makes Dino crouch by decreasing its y-position */
void crouch(DinoPlayer *player){
    player->isCrouched = 1;
}
void stand(DinoPlayer *player){
    player->isCrouched = 0;
}




/*------cactus behaviors------*/
/* Spawns a cactus at a fixed starting position */
void spawnCactusMed(CactusMed *cactusMed){
    cactusMed->x = 639+16;
    cactusMed->y = 100;
    cactusMed->delta_x = -5;
}

/* Moves a cactus towards the left side, accross the screen */
void moveCactusMed(CactusMed *cactusMed){
    cactusMed->x += cactusMed->delta_x;
}

/*------score behaviors------*/
/* Increments the player's score */
void increment(Score *score){
    score->value++;
}

/*------high score behaviors------*/
/* Updates the high school if the current score is higher */
void updateScore(HighScore *highScore, Score *score){
    if (score->value > highScore->value){
        highScore->value = score->value;
    }
}
