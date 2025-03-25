/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
Deadline        March 17, 2024
File name       dino.c
Professor     	Steve Kalmar
*/

/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       tstRnd.c
Professor     	Steve Kalmar
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

    RenderTracker tracker;


    UINT8 *base = Physbase();
    modelInitialize(&gameModel);
    initTracker(&tracker);
    forceDraw(&gameModel, &tracker, base);

    

    input = NULL;
    while (input != '`')
    {
        UINT32 timeThen, timeNow, timeElapsed;

        timeNow = get_time();
        timeElapsed = timeNow - timeThen;



        /*async*/
        input = Cnecin();
        if (input != ' ')
        {
            evKBInputHandle(&gameModel, input);
        }
        input = NULL;

        /*sync*/
        if (timeElapsed > 0)
        {
            evModelUpdate(&gameModel);
            redraw(&gameModel, &tracker, base);
            timeThen = timeNow;
        }

    }
    return 0;
}
