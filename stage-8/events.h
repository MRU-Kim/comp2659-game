/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
File name       events.h
Professor       Steve Kalmar

Purpose:
Declares all asynchronous, synchronous, and cascade event handlers
used by the game engine to manage player input, object scrolling, 
obstacle spawning, and score tracking. These functions interact with 
the game model to reflect changes in game state and behavior.

Assumptions:
- The model struct contains all game-relevant entities, including 
    player, cacti, score, etc.
- These functions are called by a game loop or event loop at appropriate times.

Limitations:
- Functions assume valid and initialized pointers to model and player objects.

*/

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

/*async events*/
void evKBInputHandle(Model *model, char input);
void evJump(Model *model);
void evCrouch(DinoPlayer *player);
void evStartGame(Model *model);

/*sync events*/
void evScroll(Model *model);
void evPlayerUpdate(Model *model);
void evCactusSpawn(Model *model);
void evSaveModel(Model *model);
void evModelUpdate(Model *model);
void evScoreIncrement(Model *model);


/*cascade events*/
void evPlayerNeutal(Model *model);
void evDeath(Model *model);
void evMilestone( Model *model);
void evUpdateHighscore(Model *model);
#endif