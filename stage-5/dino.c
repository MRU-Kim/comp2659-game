/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
File name       dino.c
Professor     	Steve Kalmar

Purpose:
Main driver of game, initializes stuctures, runs main loop, 
calls event, rendering, input and time functions
*/


#include "../stage-2/const.h"
#include "../stage-3/events.h"
#include "../stage-3/model.h"
#include "../stage-4/render.h"

#include "clock.h"
#include "input.h"

#include <osbind.h>
#include <stdio.h>

char input;

int main()
{
    Model gameModel;

    RenderTracker tracker1;

    UINT32 timeThen,timeNow, timeElapsed;

    UINT8 *buffer1 = Physbase();

    modelInitialize(&gameModel);

    initTracker(&tracker1);
    forceDraw(&gameModel, &tracker1, buffer1);


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

            redraw(&gameModel, &tracker1, buffer1);

            waitVBlank();
            timeThen = timeNow;
        }
    }
    return 0;
}