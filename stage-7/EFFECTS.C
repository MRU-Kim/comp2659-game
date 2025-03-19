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
#include "MUSIC.H" /* getTime() function */
#include "../stage-2/CONST.H"

void initPsg() {
    int i;

    for(i=0; i<16; i++) {
        writePsg(i,0x00);
        printf("reset register\n");
    }

    enableChannel(ChannelA, OFF, OFF);
    printf("enable\n");
    enableChannel(ChannelB, OFF, OFF);
    printf("enable\n");
    enableChannel(ChannelC, OFF, OFF);
    printf("enable\n");

    setVolume(ChannelA,0x00);
    printf("volume\n");
    setVolume(ChannelB,0x00);
    printf("volume\n");
    setVolume(ChannelC,0x00);
    printf("volume\n");

    setNoise(0x00);
    printf("noise\n");

    printf("PSG initialized\n");

}

void playJumpSound() {
    long startTime, nowTime;
    int jumpTone = G5;

    startTime=getTime();
    nowTime=getTime();

    setEnvelope(0x09,0x5000);

    while ((nowTime-startTime) < (64/2)) {
        setTone(ChannelA, jumpTone);
        enableChannel(ChannelA, ON, OFF); 
        setVolume(ChannelA, 12);  
        nowTime = getTime();
    }
    printf("JUMP\n");
    stopSound();
}

void playDeathSound() {
 
}


