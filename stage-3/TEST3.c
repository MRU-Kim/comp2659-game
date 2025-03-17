/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       test3.C
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
                printf("You died, press w to try again\n", input);
                input = Cnecin();
            }
            modelResetAfterDeath(&gameModel);
            evStartGame(&gameModel);
        }

        /*show status of model*/
        printf("player x,y=%d,%d, dy=%d, isCrch=%d, isAlive=%d\n",
               gameModel.player.x, gameModel.player.y, gameModel.player.delta_y,
               gameModel.player.isCrouched, gameModel.player.isAlive);
        printf("medCactus1 x,y=%d,%d medCactus2 x,y=%d,%d medCactus3 x,y=%d,%d\n",
               gameModel.cactiMed[0].x, gameModel.cactiMed[0].y,
               gameModel.cactiMed[1].x, gameModel.cactiMed[1].y,
               gameModel.cactiMed[2].x, gameModel.cactiMed[2].y, );
        printf("random num = %d, cactus spawn timer =%d\n",
               gameModel.ranNum, gameModel.cacSpawnTimer);
        printf("score = %d", gameModel.score.value);

        printf("choose input\n");
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