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
    G5,G5,F5_Sharp,G5,Pause,
    G5,G5,F5_Sharp,G5,D5_Sharp,C4,Pause,
    G5,G5,F5_Sharp,G5,Pause,
    D5_Sharp,F5,G5,D5_Sharp,F5,D5,D5_Sharp,C4,D5,C4
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
void helpInitialize( ){
    int i;
  
    for(i=0; i<27; i++){
        theSong.theActualMusic[i].value= theMusic[i];
        theSong.theActualMusic[i].time= time[i];
    }

    theSong.index=0;
}

/*
-------------------------------------------------------------------
    function: start_music
    plays the current note for a specific duration based on the
    time value. 

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void start_music(){
    long nowTime, elapsedTime;
    int theTone = theSong.theActualMusic[theSong.index].value;
    int time_divide = theSong.theActualMusic[theSong.index].time;
    printf("%X\n",theTone);

    theSong.previousTime = get_time();
    nowTime = get_time();

    while((nowTime-theSong.previousTime) < (64/time_divide)){
        set_tone(CHANNEL_A, theTone);
        enable_channel(CHANNEL_A, ON, OFF); 
        set_volume(CHANNEL_A, 10);
        nowTime = get_time();
    }

    theSong.previousTime = get_time();
    printf("%X\n",theSong.previousTime);
    theSong.index++;

    stop_sound();
}

/*
-------------------------------------------------------------------
    function: update_music
    updates the song by playing the next note. Checks if the note
    is a pause and only plays the non-pause notes.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void update_music(){
    long  nowTime, elapsedTime;
    int time_divide = theSong.theActualMusic[theSong.index].time;
    int theTone= theSong.theActualMusic[theSong.index].value;
    nowTime = get_time();

    printf("%X\n",theSong.previousTime );
    
    while((nowTime - theSong.previousTime) < (64/time_divide)){
        if(theTone != Pause){
            set_tone(CHANNEL_A, theTone);
            enable_channel(CHANNEL_A, ON, OFF) ; 
            set_volume(CHANNEL_A, 10);
        }

       nowTime = get_time();        
    }

    theSong.previousTime = get_time();
    theSong.index++;
    stop_sound();
}

/*
-------------------------------------------------------------------
    function: get_time
    retrieves the current system time by reading the timer. Uses
    Super() to access system-level memory

    input:
        None.
    output:
        timeNow - current system's time
-------------------------------------------------------------------
*/
long get_time() {
    long timeNow;
    long *timer = (long *)0x462;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}