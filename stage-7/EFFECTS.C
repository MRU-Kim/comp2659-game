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

/*
-----------------------------------------------------------------------------
    Description:
        The file contains functions for initializing and controlling the PSG
        for the Atari ST. It provides functionalities for sound effects,
        specifically jumping, and dying.
-----------------------------------------------------------------------------
*/

#include "PSG.H"
#include "EFFECTS.H"
#include "MUSIC.H"
#include "CONST7.h"

/*
-------------------------------------------------------------------
    function: initPsg
    Resets the register and its value to 0x00; turns all Channels
    A, B, and C off; sets the Channels' Volume to 0x00; and noise
    to 0x00.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void initPsg()
{
    int i;

    for (i = 0; i < 16; i++)
    {
        writePsg(i, 0x00);
    }

    enableChannel(ChannelA, OFF, OFF);
    enableChannel(ChannelB, OFF, OFF);
    enableChannel(ChannelC, OFF, OFF);

    setVolume(ChannelA, 0x00);
    setVolume(ChannelB, 0x00);
    setVolume(ChannelC, 0x00);

    setNoise(0x00);

}
/*
-------------------------------------------------------------------
    function: playJumpSound and playDeathSound
    Dino's jump/death sound. Loops through a jump/death sound effect
    using the envelope's 0x09 shape in 0x2000/0x7000 duration.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void playJumpSound()
{
    long startTime, nowTime;
    int jumpTone = G5;


    setEnvelope(0x09, 0x2000);

    while ((nowTime - startTime) < (TimeSig / 2))
    {
        setTone(ChannelA, jumpTone);
        enableChannel(ChannelA, ON, OFF);
        setVolume(ChannelA, 12);
    }
    stopSound();
}

void playDeathSound()
{
    long startTime, nowTime;
    int jumpTone = F5;

    setEnvelope(0x09, 0x7000);

    while ((nowTime - startTime) < (TimeSig / 2))
    {
        setTone(ChannelA, jumpTone);
        enableChannel(ChannelA, ON, OFF);
        setVolume(ChannelA, 12);
    }
    stopSound();
}
