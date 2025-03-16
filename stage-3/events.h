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
void evJump(DinoPlayer *player);
void evCrouch(DinoPlayer *player);
void startGame(Model *model);

/*sync events*/
void evScroll(Model *model);
void evPlayerUpdate(DinoPlayer *player);
void evCactusSpawn(Model *model);

void evInitializeModel(Model *model);

/*cascade events*/
void noInput(DinoPlayer *player);
void evDinoDeath(DinoPlayer *player);
void evMilestone(ScrollSpeed *scrollspeed);
void evUpdateHighscore(Score score, HighScore highscore);
void evResetAfterDeath(Model *model, Model startconditions);
#endif