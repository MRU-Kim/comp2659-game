/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
File name       MUSIC.C
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------
    Description:
        The file manages PSG music playback on the Atari ST.abort
        It initializes and plays a pre-defined song using the PSG.
-----------------------------------------------------------------------------
*/

#include "PSG.H"
#include "MUSIC.H"
#include "CONST7.h"
#include "../stage-5/clock.h"

const int theMusic[NoteAMT] = {
    G5, G5, F5Sharp, G5, Pause,
    G5, G5, F5Sharp, G5, D5Sharp, C4, Pause,
    G5, G5, F5Sharp, G5, Pause,
    D5Sharp, F5, G5, D5Sharp, F5, D5, D5Sharp, C4, D5, C4,
    D5, D5, Pause};
const duration[NoteAMT] = {
    Whole, Whole, Half, Whole, Half,
    Quarter, Quarter, Quarter, Quarter, Half, Whole, Half,
    Half, Whole, Half, Half, Half,
    Quarter, Quarter, Quarter, Quarter, Half, Half, Half, Half, Whole, Half,
    Half, Whole, Half};
song theSong;

/*
-------------------------------------------------------------------
    function: startMusic
    loads song sructure and starts the first note

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void startMusic()
{
    int i;

    for (i = 0; i < NoteAMT; i++)
    {
        theSong.arrangment[i].value = theMusic[i];
        theSong.arrangment[i].duration = duration[i];
    }

    theSong.index = 0;

    theSong.previousTime = get_Time();

    setTone(ChannelA, theSong.arrangment->value);
    enableChannel(ChannelA, ON, OFF);
    setVolume(ChannelA, 10);

}

/*
-------------------------------------------------------------------
    function: updateMusic
    if the duration of the note playing has passed since the note started, plays the next note 
    Checks if the note is a pause and only plays the non-pause notes.

    input:
        time - current value of the VB clock
    output:
        Void.
-------------------------------------------------------------------
*/
void updateMusic(UINT32 time)
{
    int duration = theSong.arrangment[theSong.index].duration;
    int theTone = theSong.arrangment[theSong.index].value;

    UINT32 timeElapsed = time - theSong.previousTime;

    /*if time since start is greater than note duration */
    if (timeElapsed > duration)
    {
        /*progress to next note, if out of array go to start*/
        theSong.index++;
        theSong.previousTime = time;
        if (theSong.index >= NoteAMT)
        {
            theSong.index = 0;
        }
        if (theTone != Pause)
        {
            setTone(ChannelA, theTone);
            enableChannel(ChannelA, ON, OFF);
            setVolume(ChannelA, 10);
        }
        else
        {
            setVolume(ChannelA, 0);
        }
    }
}
