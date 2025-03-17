/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       model.h
Professor       Steve Kalmar
*/

#ifndef MODEL_H
#define MODEL_H
#include "../stage-2/CONST.H"


typedef struct {
    int x, y, delta_y;
    bool isCrouched;
    bool isAlive;
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
    int x,y,value;
} Score;

typedef struct {
    int x,y,value;
} HighScore;

typedef struct {
    DinoPlayer player;
    CactusMed cactiMed[3];
    Ground ground;
    Score score;
    HighScore highScore;
    ScrollSpeed scrollSpeed;
    UINT16 ranNum;
    int cacSpawnTimer;
    int lastMilestone;
    UINT16 runTicksPassed;
} Model;


/*dino behaviors*/
void dinoJump(DinoPlayer *player);
void dinoFall(DinoPlayer *player);
void dinoAirCrouch(DinoPlayer *player);
void dinoLand(DinoPlayer *player);

void dinoCrouch(DinoPlayer *player);
void dinoStand(DinoPlayer *player);
void dinoDie(DinoPlayer *player);


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
void modelGetSeed(Model *model);
void modelIncrmentTick(Model *model);
void modelTicksPassedReset(Model *model);
#endif