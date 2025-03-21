/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       tstRnd.c
Professor     	Steve Kalmar
*/

#include "events.h"
#include "model.h"
#include "../stage-2/const.h"

#include <osbind.h>
#include <stdio.h>

char input;

int main()
{
    Model gameModel;
    modelInitialize(&gameModel);

    input = NULL;

    while (input != ' ')
    {
        printf("start? press space%c\n", input);
        input = Cnecin();
    }
    evStartGame(&gameModel);

    while (input != '`')
    {
        if (gameModel.player.isAlive == false) /*player dies previous tick*/
        {
            while (input != ' ')
            {
                printf("You died, press space to try again\n", input);
                input = Cnecin();
            }
            evStartGame(&gameModel);
        }

        input = Cnecin();

        if (input == 'w')
        {
            printf("jump!\n");
            evJump(&gameModel.player);
        }
        else if (input == 's')
        {
            printf("crouch!\n");
            evCrouch(&gameModel.player);
        }
        else
        {
            evNoInput(&gameModel.player);
        }
        evModelUpdate(&gameModel);
        /*reset input*/
        input = NULL;
    }

    return 0;
}