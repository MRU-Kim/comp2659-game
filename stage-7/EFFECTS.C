/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
Deadline        March 17, 2024
File name       EFFECTS.C
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

#include "PSG.H"
#include "EFFECTS.H"
#include "../stage-2/CONST.H"

void set_noise(int tuning){
    writePsg(6,tuning);
}

void set_envelope(int shape, unsigned int sustain){
    writePsg(11,sustain & 0xFF);
    writePsg(12,(sustain>>8) & 0xFF);
    writePsg(13,shape);
}

