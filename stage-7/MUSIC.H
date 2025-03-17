/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
Deadline        March 17, 2024
File name       MUSIC.H
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

#include "../stage-2/CONST.H"
#include "PSG.H"

typedef struct{
  int value;
  int time;
} note;

typedef struct{
  note theActualMusic[27];
  int index;
  long previousTime;
} song;

void start_music();
void update_music();
void helpInitialize();
long get_time();