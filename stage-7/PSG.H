/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
Deadline        March 17, 2024
File name       PSG.H
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

#ifndef PSG_H
#define PSG_H

#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "../stage-2/CONST.H"

void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_noise(int tuning);
void set_volume(int channel, int volume);
void set_envelope(int shape, unsigned int sustain);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();


#endif