#include "psg.h"
#include "music.h"
#include "effects.h"
#include "../stage-5/clock.h"

int main()
{

    int i;
    UINT32 timeThen, timeNow, timeElapsed;


    startMusic();
    while (!Cconis())
    {
        timeNow = get_Time();
        updateMusic(timeNow);
    }
    /*
    initPsg();
    playJumpSound();
    playDeathSound();
    */return 0;
}
