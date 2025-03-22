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
void evKBInputHandle(Model *model, char input);
void evJump(DinoPlayer *player);
void evCrouch(DinoPlayer *player);
void evStartGame(Model *model);

/*sync events*/
void evScroll(Model *model);
void evPlayerPosUpdate(DinoPlayer *player);
void evCactusSpawn(Model *model);
void evSaveModel(Model *model);
void evModelUpdate(Model *model);
void evModelSave(Model *model);
void evScoreIncrement(Model *model);


/*cascade events*/
void evNoInput(DinoPlayer *player);
void evDeath(Model *model);
void evMilestone( Model *model);
void evUpdateHighscore(Model *model);
#endif