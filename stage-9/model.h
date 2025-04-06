/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
File name       model.h
Professor       Steve Kalmar

Purpose:
Defines the data structures and function prototypes for the core game model,
including the Dino player, scrolling terrain, obstacles, score, high score,
and related behaviors. These functions control logical state changes that 
occur throughout the game, such as jumping, scrolling, spawning obstacles,
and tracking game progress.

Assumptions:
- The Model struct is the central container for all game state data.
- Functions operate on valid, initialized Model or component pointers.
- Constants like MaxCactus, DinoY, and CactMedY are defined in CONST.H.

Limitations:
- This file only declares state logic; no rendering or direct input handling occurs here.
*/

#ifndef MODEL_H
#define MODEL_H
#include "CONST.H"


typedef struct {
    int x, y, delta_y;
    bool isCrouched;
    bool isAlive;
    bool walkCycle; /*false for 1st walk sprite , true for second walk sprite*/
    bool isMoving;
    int runAnimationTimer;
} DinoPlayer;

typedef struct
{
    int delta_x;
} ScrollSpeed;


typedef struct {
    int x, y;
} CactusSmall;

typedef struct {
    int x, y;
} CactusMed;

typedef struct {
    int x, y;
} CactusLarge;

typedef struct {
    int y;
} Ground;

typedef struct {
    int value;
} Score;

typedef struct {
    int value;
} HighScore;

typedef struct {
    DinoPlayer player;
    CactusMed cactiMed[MaxCactus];
    Ground ground;
    Score score;
    HighScore highScore;
    ScrollSpeed scrollSpeed;


    UINT16 ranNum;
    int cacSpawnTimer;
    UINT16 gravTimer;
    bool hasInput;
    char lastInput;

    int nextMilestone;
    UINT16 runTicksPassed; /*redundant??*/
} Model;




/*dino behaviors*/
void dinoJump(DinoPlayer *player);
void dinoFall(DinoPlayer *player);
void dinoAirCrouch(DinoPlayer *player);
void dinoLand(DinoPlayer *player);
void dinoCrouch(DinoPlayer *player);
void dinoStand(DinoPlayer *player);
void dinoDie(DinoPlayer *player);
void dinoMove(DinoPlayer *player);
void dinoRunCycleAdvance(DinoPlayer *player);

/*cactus behaviors*/
/*med cactus*/
void medCactusSpawn(CactusMed *cactusMed);
void medCactusScroll(CactusMed *cactusMed,ScrollSpeed scrollSpeed);

/*score behaviors*/
void scoreIncrement(Model *model);
void scoreReset(Score *score);

/*high score behaviors*/
void scoreUpdate(HighScore *highScore, Score *score);

/*Scroll speed behaviors*/
void scrollStart(ScrollSpeed *scrollSpeed);
void scrollStop(ScrollSpeed *scrollSpeed);

/*model behaviors*/
void modelInitialize(Model *model);
void modelResetNonePersists(Model *model);
void modelGetSeed(Model *model);
void modelIncrmentTick(Model *model);
void modelTicksPassedReset(Model *model);
void modelResetCacSpawnTimer(Model *model);


/*helper functions*/
int abs(int num);
int lfsr16(int seed);

#endif