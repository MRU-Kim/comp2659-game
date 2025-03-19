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

#define JUMP_TONE 0x300  // Adjust for desired jump sound pitch
#define DEATH_TONE 0x100 // Adjust for desired death sound pitch
#define JUMP_NOISE 0x05  // Noise level for jump effect
#define DEATH_NOISE 0x07 // Noise level for death effect
#define JUMP_VOLUME 0x0F // Max volume
#define DEATH_VOLUME 0x08 // Lower volume for death effect
#define ENVELOPE_SHAPE 0x09 // Example envelope shape

void playJumpSound() {
    setTone(ChannelA, JUMP_TONE);
    setNoise(JUMP_NOISE);
    setVolume(ChannelA, JUMP_VOLUME);
    enableChannel(ChannelA, ON, OFF);
    setEnvelope(ENVELOPE_SHAPE, 0xFFFF);
}

void playDeathSound() {
    setTone(ChannelB, DEATH_TONE);
    setNoise(DEATH_NOISE);
    setVolume(ChannelB, DEATH_VOLUME);
    enableChannel(ChannelB, ON, OFF);
    setEnvelope(ENVELOPE_SHAPE, 0x7FFF);
}

