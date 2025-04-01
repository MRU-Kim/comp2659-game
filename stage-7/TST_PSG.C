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

    /*
        startMusic();
        while (!Cconis())
        {
            timeNow = get_Time();
            updateMusic(timeNow);
        }
    */
   Cnecin();

   playJumpSound();
    Cnecin();
    playDeathSound();
    Cnecin();
    Cnecin();
    playDeathSound();
    Cnecin();
    Cnecin();
    playDeathSound();
    Cnecin();

    return 0;
}
