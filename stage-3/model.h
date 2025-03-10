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

typedef struct {
    unsigned int x, y;
    int delta_y;
    int isCrouched;
} DinoPlayer;

typedef struct
{
    int delta_x;
} ScrollSpeed;


typedef struct {
    unsigned int x, y;
} CactusSmall;

typedef struct {
    unsigned int x, y;
} CactusMed;

typedef struct {
    unsigned int x, y;
} CactusLarge;

typedef struct {
    unsigned int x, y;
} Ground;

typedef struct {
    unsigned int x,y,value;
} Score;

typedef struct {
    unsigned int x,y,value;
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
    .player = {319,200, 0, 0},
    .cactiMed = {{360,200},{-20,200},{-20,200}},
    .ground = {200},
    .score = {0},
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


/*cactus behaviors*/
/*med cactus*/
void spawnMedCactus(CactusMed *cactusMed);

/*score behaviors*/
void increment(Score *score);

/*high score behaviors*/
void updateScore(HighScore *highScore, Score *score);

#endif