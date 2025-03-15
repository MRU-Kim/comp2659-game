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
} Model;
/*init ex:
    Model gameModel = {
    .player = {319,GroundY-16, 0, false, true},
    .cactiMed = {{360,GroundY-16},{-20,GroundY-16},{-20,GroundY-16}},
    .ground = {GroundY},
    .player = {319,200, 0, 0},
    .cactiMed = {{360,200},{-20,200},{-20,200}},
    .ground = {200},
    .highScore = {0},
    .scrollSpeed = {5}
    };
*/


/*dino behaviors*/
void jump(DinoPlayer *player);
void fall(DinoPlayer *player);
void aircrouch(DinoPlayer *player);
void land(DinoPlayer *player);

void crouch(DinoPlayer *player);
void stand(DinoPlayer *player);
void die(DinoPlayer *player);


/*cactus behaviors*/
/*med cactus*/
void evSpawnMedCactus(CactusMed *cactusMed);
void scrollMedCactus(CactusMed *cactusMed,ScrollSpeed scrollSpeed);

/*score behaviors*/
void increment(Score *score);

/*high score behaviors*/
void updateScore(HighScore *highScore, Score *score);

/*evScroll speed behaviors*/
void startScroll(ScrollSpeed *scrollSpeed);
void stopScroll(ScrollSpeed *scrollSpeed);

/*model behaviors*/

#endif