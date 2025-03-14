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
void scroll (CactusMed *cacti[], ScrollSpeed scrollspeed);
void changeDinoY (DinoPlayer *dino);
void spawnMedCactus(CactusMed *CactusMed);

void initializeModel(Model *model, int cactiInPlay);

/*cascade events*/
void dinoDeath(DinoPlayer *player);
void milestone(ScrollSpeed *scrollspeed);
void updateHighscore(Score score, HighScore highscore);
void resetAfterDeath(Model *model, Model startconditions);
#endif