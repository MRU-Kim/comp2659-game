/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       model.h
Professor       Steve Kalmar
*/
typedef struct {
    unsigned int x, y;
    int delta_y;        
} Dino;

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
} CactusSmall; 

typedef struct {
    unsigned int y;       
} Terrain;

typedef struct {
    unsigned int value;      
} Score;

typedef struct {
    unsigned int value;      
} HighScore;

typedef struct {
    Dino player;
    Cactus cacti[3];    /* never making more than 3 cacti on screen*/
    Terrain terrain;
    Score score;
    HighScore highScore;
} Model;
