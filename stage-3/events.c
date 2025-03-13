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

void handleJump(DinoPlayer *player){
    if (player->y == GroundLevel+DinoHeight) { /* on the ground */
        jump(player);
    }
}

void handleJumpHeld(DinoPlayer *player){
    if (player->y > GroundLevel-DinoHeight && player-> y > MaxJump) { /* in the air */
        jump(player);
    }
    else {
        fall(player);
    }
}

void handleCrouch(DinoPlayer *player){
    crouch(player);
}

void handleAircrouch(DinoPlayer *player){
    aircrouch(player);
}

/*sync events*/

/* function: scroll
    scrolls all scrollable objects to the left 
    so far this is only cactusMed
    inputs:
    CactusMed - array of cactusMed
    ScrollSpeed - Scroll speed to be forced on all side scrolling objects

*/
void scroll(CactusMed *cacti[], ScrollSpeed scrollSpeed){
    int i;
    for (i = 2; i>+0; i--){
        scrollMedCactus(cacti[i],scrollSpeed);
    }
}

void spawnMedCactus(CactusMed *cactusMed){
}
/*cascade events*/


/* function: milestone
    after 1000 points increase the speed of the scroll
    inputs:
    scrollspeed - object that controls speed of scrolling objects
*/
void milestone(ScrollSpeed *scrollspeed){
}
/*function: dinoDeath
    triggers on the dino hitbox intersects with a cactus hitbox
        stops scroll, dino dies, sets new high score, places game into new run after next jump input
*/
void dinoDeath(DinoPlayer *player){
    player->x = -5; /* start position */
    player->y = 0;
    player->delta_y = 0;
}

void updateHighscore(Score score, HighScore highscore){

}
/* function: resetAfterDeath
    a death reset everything into new run except high score
*/
void resetAfterDeath(Model *model, Model startconditions){

}
