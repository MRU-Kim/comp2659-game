#include "psg.h"
#include "music.h"
#include "effects.h"

int main() {

    /*
    int i;

    helpInitialize();
    startMusic();
    while(!Cconis()){
        for(i=0; i <26;i++){
            updateMusic();
        }
        helpInitialize();
        startMusic();
    }
    */

    initPsg();
    playJumpSound();
    playDeathSound();
    return 0;
}
