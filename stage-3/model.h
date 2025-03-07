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
} DinoPlayer;

typedef struct {
    unsigned int x, y;
    int delta_x;      
} CactusSmall;

typedef struct {
    unsigned int x, y;
    int delta_x;        
} CactusMed;

typedef struct {
    unsigned int x, y;
    int delta_x;        
} CactusLarge; 

typedef struct {
    unsigned int x, y;       
} Terrain;

typedef struct {
    unsigned int x,y,value;      
} Score;

typedef struct {
    unsigned int x,y,value;      
} HighScore;

typedef struct {
    DinoPlayer player;
    CactusSmall cactiSmall[3];    /* never making more than 3 cacti on screen*/
    CactusMed cactiMed[3];
    CactusLarge cactiLarge[3];
    Terrain terrain;
    Score score;
    HighScore highScore;
} Model;

/*dino behaviors*/
void jump(DinoPlayer *player);
void crouch(DinoPlayer *player);
void aircrouch(DinoPlayer *player);

/*cactus behaviors*/
void spawn(CactusSmall *cactusSmall);
void move(CactusSmall *cactusSmall);

/*score behaviors*/
void increment(Score *score);

/*high score behaviors*/
void updateScore(HighScore *highScore, Score *score);

#endif