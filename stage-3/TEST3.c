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

void modelState(*Model model);

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
        /*show status of model*/
        modelState(*gameModel);
        printf("choose input\n");
        input = Cnecin();
        evKBInputHandle(&gameModel, input);
        input = NULL;
        evModelUpdate(&gameModel);

        /*reset input*/
        input = NULL;
    }

    return 0;
}

void modelState(const Model gameModel)
{
    printf("player x,y=%d,%d, dy=%d, isCrch=%d, isAlive=%d\n",
           gameModel->Lplayer.x, gameModel->player.y, gameModel->player.delta_y,
           gameModel->player.isCrouched, gameModel->player.isAlive);
    printf("medCactus1 x,y=%d,%d medCactus2 x,y=%d,%d medCactus3 x,y=%d,%d\n",
           gameModel->cactiMed[0].x, gameModel->cactiMed[0].y,
           gameModel->cactiMed[1].x, gameModel->cactiMed[1].y,
           gameModel->cactiMed[2].x, gameModel->cactiMed[2].y, );
    printf("random num = %d, cactus spawn timer =%d ticks\n",
           gameModel->ranNum, gameModel->cacSpawnTimer);
    printf("score = %d highscore = %d\n", gameModel->score.value, gameModel->highScore.value);
}