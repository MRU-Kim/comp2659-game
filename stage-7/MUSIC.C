/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
Deadline        March 17, 2024
File name       MUSIC.C
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

#include "PSG.H"
#include "MUSIC.H"
#include "../stage-2/CONST.H"

const int theMusic[27] = {
    G5,G5,F5Sharp,G5,Pause,
    G5,G5,F5Sharp,G5,D5Sharp,C4,Pause,
    G5,G5,F5Sharp,G5,Pause,
    D5Sharp,F5,G5,D5Sharp,F5,D5,D5Sharp,C4,D5,C4
};
const time[27]={1,1,2,1,2,4,4,4,4,2,1,2,2,1,2,2,2,4,4,4,4,2,2,2,2,1,2}; 
/*this is the time the tempo needs to be divided by*/
song theSong;

/*
-------------------------------------------------------------------
    function: helpInitialize
    initialize theSong structure by setting up theMysic and time arrays 
    into theActualMusic array.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void helpInitialize(){
    int i;
  
    for(i=0; i<27; i++){
        theSong.theActualMusic[i].value= theMusic[i];
        theSong.theActualMusic[i].time= time[i];
    }

    theSong.index=0;
}

/*
-------------------------------------------------------------------
    function: startMusic
    plays the current note for a specific duration based on the
    time value. 

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void startMusic(){
    long nowTime, elapsedTime;
    int theTone = theSong.theActualMusic[theSong.index].value;
    int timeDivide = theSong.theActualMusic[theSong.index].time;
    printf("%X\n",theTone);

    theSong.previousTime = getTime();
    nowTime = getTime();

    while((nowTime-theSong.previousTime) < (64/timeDivide)){
        setTone(ChannelA, theTone);
        enableChannel(ChannelA, ON, OFF); 
        setVolume(ChannelA, 10);
        nowTime = getTime();
    }

    theSong.previousTime = getTime();
    printf("%X\n",theSong.previousTime);
    theSong.index++;

    stopSound();
}

/*
-------------------------------------------------------------------
    function: updateMusic
    updates the song by playing the next note. Checks if the note
    is a pause and only plays the non-pause notes.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void updateMusic(){
    long  nowTime, elapsedTime;
    int timeDivide = theSong.theActualMusic[theSong.index].time;
    int theTone= theSong.theActualMusic[theSong.index].value;
    nowTime = getTime();

    printf("%X\n",theSong.previousTime );
    
    while((nowTime - theSong.previousTime) < (64/timeDivide)){
        if(theTone != Pause){
            setTone(ChannelA, theTone);
            enableChannel(ChannelA, ON, OFF) ; 
            setVolume(ChannelA, 10);
        }

       nowTime = getTime();        
    }

    theSong.previousTime = getTime();
    theSong.index++;
    stopSound();
}

/*
-------------------------------------------------------------------
    function: getTime
    retrieves the current system time by reading the timer. Uses
    Super() to access system-level memory

    input:
        None.
    output:
        timeNow - current system's time
-------------------------------------------------------------------
*/
long getTime() {
    long timeNow;
    long *timer = (long *)0x462;
    long oldSsp;

    oldSsp = Super(0);
    timeNow = *timer;
    Super(oldSsp);

    return timeNow;
}