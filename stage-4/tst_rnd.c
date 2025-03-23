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
#include "render.h"


#include <osbind.h>
#include <stdio.h>

char input;

int main()
{
    Model gameModel;
    UINT8 *base = Physbase(); /* 8-bit */
    modelInitialize(&gameModel);
    forceDraw(&gameModel,base);

    input = NULL;

    while (input != ' ')
    {
        input = Cnecin();
    }
    evStartGame(&gameModel);

    while (input != '`')
    {
        input = Cnecin();
        evKBInputHandle(&gameModel, input);
        input = NULL;

        evModelUpdate(&gameModel);
        
        redraw(&gameModel, base);
    }
    return 0;
}