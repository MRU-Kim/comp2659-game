/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 8
File name       dino.c
Professor     	Steve Kalmar

Purpose:
Main driver of game, initializes stuctures, runs main loop,
calls event, rendering, input and time functions.
Has added double buffering over previous stage
*/

#include <osbind.h>
#include <stdio.h>

#include "const.h"
#include "events.h"
#include "model.h"
#include "render.h"
#include "RASTER.H"
#include "MUSIC.H"
#include "PSG.H"
#include "splash.h"

#include "clock.h"
#include "input.h"

runGame(UINT8 *base1, UINT8 *base2);

char input;

int main()
{
    UINT8 *defaultBuffer = get_video_base();

    static UINT8 buffer2Arr[32000 + 256];
    static UINT8 buffer3Arr[32000 + 256];
    static UINT8 buffer4Arr[32000 + 256];

    /*find displacement of buffer2 from being 256 byte alligned
    then add displacement */
    UINT8 *buffer2 = buffer2Arr;
    UINT16 buffer2IntAdd = (UINT16)buffer2Arr;
    UINT16 displacement2 = 256 - buffer2IntAdd % 256;

    UINT8 *buffer3 = buffer3Arr;
    UINT16 buffer3IntAdd = (UINT16)buffer3Arr;
    UINT16 displacement3 = 256 - buffer3IntAdd % 256;

    UINT8 *buffer4 = buffer4Arr;
    UINT16 buffer4IntAdd = (UINT16)buffer4Arr;
    UINT16 displacement4 = 256 - buffer4IntAdd % 256;

    int menuSelect = 0;

    buffer2 += displacement2;
    buffer3 += displacement3;
    buffer4 += displacement4;


    set_video_base(buffer2);
    menuSelect = welcomeScreen(buffer2);

    if (menuSelect == 1)
    {
        runGame(buffer3, buffer4);
    }
    
    set_video_base(defaultBuffer);
    stopSound();
    return 0;
}

runGame(UINT8 *base1, UINT8 *base2)
{
    Model gameModel;

    RenderTracker tracker1, tracker2;

    UINT32 timeThen, timeNow, timeElapsed;

    bool bufferSelect;

    modelInitialize(&gameModel);
    initTracker(&tracker1);
    initTracker(&tracker2);
    forceDraw(&gameModel, &tracker1, base1);
    forceDraw(&gameModel, &tracker2, base2);
    startMusic();

    bufferSelect = true;
    input = 0;
    while (input != '`')
    {

        timeNow = get_Time();
        timeElapsed = timeNow - timeThen;

        /*async*/
        input = getKey();
        if (input != 0)
        {
            evKBInputHandle(&gameModel, input);
        }

        /*sync*/
        if (timeElapsed > 0)
        {
            evModelUpdate(&gameModel);

            /*draw backbuffer*/
            if (bufferSelect)
            {
                redraw(&gameModel, &tracker1, base1);
            }
            else
            {
                redraw(&gameModel, &tracker2, base2);
            }
            waitVBlank();
            bufferSelect = selectBuffer(base1, base2, bufferSelect);
            updateMusic(timeNow);
            timeThen = timeNow;
        }
    }
}
