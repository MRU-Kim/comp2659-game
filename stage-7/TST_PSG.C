/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 7
File name       tst_psg.c
Professor     	Steve Kalmar

Purpose:
This file is the test file for Stage 7, it plays
the game's music, and the jump and death sound effects.
*/

#include "psg.h"
#include "music.h"
#include "effects.h"
#include "../stage-5/clock.h"
#include "CONST7.h"
#include "../stage-2/CONST.H"

int main()
{
    UINT32 timeThen, timeNow, timeElapsed;
    initPsg();

    
    startMusic();
    while (!Cconis())
    {
        timeNow = get_Time();
        updateMusic(timeNow);
    }
    stopSound();

    Cnecin();

    playJumpSound();
    Cnecin();
    playJumpSound();
    Cnecin();
    playJumpSound();
    Cnecin();
    playJumpSound();
    Cnecin();
    playDeathSound();
    Cnecin();
    playDeathSound();
    Cnecin();
    playDeathSound();
    Cnecin();

    return 0;
}
