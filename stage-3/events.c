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


void handleJump(DinoPlayer *player){
    if (player->y == 0) { /* on the ground */
        jump(player);
    }
}

void handleJumpHeld(DinoPlayer *player){
    if (player->delta_y > 0) { /* in the air */
        player->delta_y += 1;
    }
}

void handleCrouch(DinoPlayer *player){
    crouch(player);
}

void handleAircrouch(DinoPlayer *player){
    aircrouch(player);
}

/*sync events*/
void scroll(CactusMed cacti[], ScrollSpeed scrollspeed){
    int i;
    for (i = 2; i>+0; i--){
        if(cacti[i].x>-15){ /*if the cactus is on screen */
            cacti[i].x+= scrollspeed.delta_x;
        }
    }
}

void spawnMedCactus(CactusMed *cactusMed){
}
/*cascade events*/

void dinoDeath(DinoPlayer *player){
    player->x = -5; /* start position */
    player->y = 0;
    player->delta_y = 0;
}

void speedUp(ScrollSpeed *scrollspeed){
}