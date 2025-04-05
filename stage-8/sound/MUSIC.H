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

#include "PSG.H"

typedef struct{
  int value;
  int duration;
} note;

typedef struct{
  note arrangment[NoteAMT];
  int index;
  UINT32 previousTime;
} song;

void startMusic();
void updateMusic(UINT32 time_elapsed);
