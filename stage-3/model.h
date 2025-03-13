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
    bool isCrouched;
    bool isAlive
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
<<<<<<< HEAD
    .player = {319,GroundLevel-16, 0, false, true},
    .cactiMed = {{360,GroundLevel-16},{-20,GroundLevel-16},{-20,GroundLevel-16}},
    .ground = {GroundLevel},
=======
    .player = {319,200, 0, 0},
    .cactiMed = {{360,200},{-20,200},{-20,200}},
    .ground = {200},
>>>>>>> 059dc81df5a32576525598c1d80d267f5e91f5af
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
void die(DinoPlayer *player);


/*cactus behaviors*/
/*med cactus*/
void spawnMedCactus(CactusMed *cactusMed);
<<<<<<< HEAD
void scrollMedCactus(CactusMed *cactusMed,ScrollSpeed scrollSpeed);
=======
>>>>>>> 059dc81df5a32576525598c1d80d267f5e91f5af

/*score behaviors*/
void increment(Score *score);

/*high score behaviors*/
void updateScore(HighScore *highScore, Score *score);

/*model behaviors*/

#endif