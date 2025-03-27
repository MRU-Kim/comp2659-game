/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       test3.C
Professor     	Steve Kalmar

Purpose:
Test driver for verifying game model behavior and event handling logic. This file
initializes the model, waits for user input to start the game, and continuously updates
and prints the state of the model. It simulates keyboard input to test jump, crouch,
scrolling, and score progression without graphical output.

*/

#include "events.h"
#include "model.h"
#include "../stage-2/const.h"

#include <osbind.h>
#include <stdio.h>


void modelState(const Model *model);

int main()
{
    char input;
    Model gameModel;
    modelInitialize(&gameModel);

    input = NULL;

    while (input != '`')
    {
        /*show status of model*/
        modelState(&gameModel);

        input = Cnecin();
        if (input != ' ')
        {
            evKBInputHandle(&gameModel, input);
        }
        
        input = NULL;
        evModelUpdate(&gameModel);

        /*reset input*/
        input = NULL;
    }

    return 0;
}

void modelState(const Model *gameModel)
{
    if (gameModel->scrollSpeed.delta_x)
    {
        printf("player x,y=%d,%d, dy=%d, isCrch=%d, isAlive=%d, run timer=%d, run state=%d\n",
               gameModel->player.x, gameModel->player.y, gameModel->player.delta_y,
               gameModel->player.isCrouched, gameModel->player.isAlive, gameModel->player.runAnimationTimer,
               gameModel->player.walkCycle);
        printf("medCactus1 x,y=%d,%d medCactus2 x,y=%d,%d medCactus3 x,y=%d,%d\n",
               gameModel->cactiMed[0].x, gameModel->cactiMed[0].y,
               gameModel->cactiMed[1].x, gameModel->cactiMed[1].y,
               gameModel->cactiMed[2].x, gameModel->cactiMed[2].y, );
        printf("random num = %d, cactus spawn timer =%d ticks\n",
               gameModel->ranNum, gameModel->cacSpawnTimer);
        printf("score = %d highscore = %d\n", gameModel->score.value, gameModel->highScore.value);
        printf("choose input\n");
    }
    else
    {
        printf("start? press w\n");
    }
}