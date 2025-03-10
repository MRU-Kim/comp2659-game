/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       events.h
Professor       Steve Kalmar
*/

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/*async events*/
void handleJump(DinoPlayer *player);
void handleJumpHeld(DinoPlayer *player);
void handleCrouch(DinoPlayer *player);
void handleAircrouch(DinoPlayer *player);

/*sync events*/
void scroll(CactusMed cacti[], ScrollSpeed scrollspeed);
void spawnMedCactus(CactusMed *CactusMed);

/*cascade events*/
void dinoDeath(DinoPlayer *player);
void speedUp(ScrollSpeed *scrollspeed);
#endif