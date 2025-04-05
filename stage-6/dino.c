/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 6
File name       dino.c
Professor     	Steve Kalmar

Purpose:
Main driver of game, initializes stuctures, runs main loop,
calls event, rendering, input and time functions.
Has added double buffering over previous stage
*/

#include "../stage-2/const.h"
#include "../stage-3/events.h"
#include "../stage-3/model.h"
#include "../stage-4/render.h"
#include "../stage-5/clock.h"
#include "../stage-5/input.h"

#include <osbind.h>
#include <stdio.h>

bool selectBuffer(UINT8 *buff1, UINT8 *buff2, bool select);

char input;

int main()
{
    Model gameModel;

    RenderTracker tracker1, tracker2;

    UINT32 timeThen, timeNow, timeElapsed;

    bool bufferSelect;

    UINT8 *buffer1 = Physbase();

    static UINT8 buffer2Arr[32000 + 256];
    UINT8 *buffer2 = buffer2Arr;
    UINT16 buffer2IntAdd = (UINT16)buffer2Arr;

    /*find displacement of buffer2 from being 256 byte alligned
    then add displacement */
    UINT16 displacement = 256 - buffer2IntAdd % 256;
    buffer2 += displacement;

    modelInitialize(&gameModel);

    initTracker(&tracker1);
    initTracker(&tracker2);
    forceDraw(&gameModel, &tracker1, buffer1);
    forceDraw(&gameModel, &tracker2, buffer2);

    bufferSelect = true;
    input = NULL;
    while (input != '`')
    {

        timeNow = get_Time();
        timeElapsed = timeNow - timeThen;

        /*async*/
        input = getKey();
        if (input != NULL)
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
                redraw(&gameModel, &tracker1, buffer1);
            }
            else
            {
                redraw(&gameModel, &tracker2, buffer2);
            }
            waitVBlank();
            bufferSelect = selectBuffer(buffer1, buffer2, bufferSelect);
            timeThen = timeNow;
        }
    }
    selectBuffer(buffer1, buffer1, bufferSelect);
    return 0;
}

/*funtion: selectBuffer
    given two frame buffers, sets screen to the second if select is true
    the first if select is false returns the negation of the select bool
    input:
    buff1 - first frame buffer
    buff2 - second frame buffer
    select - false to select buff1, true to select buff2*/
bool selectBuffer(UINT8 *buff1, UINT8 *buff2, bool select)
{
    if (select)
    {
        Setscreen(-1, buff2, -1);
    }
    else
    {
        Setscreen(-1, buff1, -1);
    }
    return !select;
}