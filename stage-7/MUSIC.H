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

/* MUSIC HEADER FILE */
#define C5 0x06B
#define D5 0x0BE
#define E5 0x0AA
#define F5_Sharp 0x097
#define G5 0x08F
#define C4 0x0D6
#define D5_Sharp 0x0B4
#define F5 0x0A0
#define Pause 0

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