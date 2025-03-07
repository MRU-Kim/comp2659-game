/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       events.c
Professor       Steve Kalmar
*/

#include "events.h"

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

void scroll(Terrain *terrain){
    terrain->x += 5; 
}

void spawnObsticle(CactusSmall *cactusSmall){
    cactusSmall->x = 500;
    cactusSmall->delta_x = -10;
}

void dinoDeath(DinoPlayer *player){
    player->x = -5; /* start position */
    player->y = 0;
    player->delta_y = 0;
}

void speedUp(Terrain *terrain){
    terrain->y += 10;
}