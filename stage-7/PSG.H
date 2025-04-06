/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
File name       PSG.H
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

#ifndef PSG_H
#define PSG_H

#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>

#include "CONST7.h"
#include "../stage-2/CONST.H"

void writePsg(int reg, UINT8 val);
UINT8 readPsg(int reg);
void setTone(int channel, int tuning);
void setNoise(int tuning);
void setVolume(int channel, int volume);
void setEnvelope(UINT8 shape, UINT16 sustain);
void enableChannel(UINT16 channel, int toneOn, int noiseOn);
void stopSound();


#endif