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

/*------dino behaviors------*/
/* Makes Dino jump by setting its vertical velocity only if it
    does'nt have any downward momentum*/
void jump(DinoPlayer *player){
    if (player->delta_y<=0)
    {
        player->delta_y = -10;
    }
}

/* function fall
    cancels momentum or acclerates downwards
    inputs: 
    player - dinno object
*/
void fall(DinoPlayer *player){
    if (player->y < DinoY){

        if (player->delta_y>=0) /*if downward momentum*/
        {
            player->delta_y++;
        }
        else{
            player->delta_y = 0;
        }
        
        player->delta_y++;
    }
}
void land(DinoPlayer *player){
    player->delta_y = 0;
}
/* Allows Dino to crouch mid-air */
void aircrouch(DinoPlayer *player){
    player->delta_y = 20;
}
void updateY(DinoPlayer *player){
    player->y += player->delta_y;
}


/* Makes Dino crouch by decreasing its y-position */
void crouch(DinoPlayer *player){
    player->isCrouched = 1;
}
void stand(DinoPlayer *player){
    player->isCrouched = 0;
}

void die(DinoPlayer *player){
    player->isAlive = 0;
}





/*------cactus behaviors------*/
/* Spawns a cactus at a fixed starting position */
void spawnCactusMed(CactusMed *cactusMed){
    cactusMed->x = 639+16;
    cactusMed->y = GroundY;
}
void scrollMedCactus(CactusMed *cactusMed,ScrollSpeed scrollSpeed){
    if((*cactusMed).x>-16){ /*if the cactus is on screen */
        (*cactusMed).x-= scrollSpeed.delta_x;
    }
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

void startScroll(ScrollSpeed *scrollSpeed){
    scrollSpeed->delta_x = 5;
}

void stopScroll(ScrollSpeed *scrollSpeed){
    scrollSpeed->delta_x = 0;
}

