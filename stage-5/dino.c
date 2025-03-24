/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 5
Deadline        March 17, 2024
File name       dino.c
Professor     	Steve Kalmar
*/

#include "clock.h"
#include "input.h"
#include "../stage-3/model.h"
#include "../stage-4/renderer.h"

int main(){

    Model gameModel;
    RenderTracker tracker;

    UINT8 *base = Physbase(); /* 8-bit */
    modelInitialize(&gameModel);

    input = NULL;

    while (input != ' ')
    {
        input = Cnecin();
    }
    forceDraw(&gameModel,&tracker,base);
    evStartGame(&gameModel);
}
