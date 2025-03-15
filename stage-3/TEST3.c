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
#include <time.h>
#include <osbind.h>
#include <stdio.h>


unsigned int ticks70;
char input;

int main()
{
    Model gameModel;
    evInitializeModel(&gameModel);
    

    input = Cnecin();

    while (input != '`')
    {
        /*show status of objects*/

        printf("player x=%d, y=%d, dy=%d, isCrch=%d, isAlive=%d\n", 
            gameModel.player.x, gameModel.player.y, gameModel.player.delta_y, 
            gameModel.player.isCrouched, gameModel.player.isCrouched);

        while (input != ' ')
        {
            printf("%c\n", input);
            input = Cnecin();
        }
        startGame(&gameModel);

        while (input != ' ')
        {
            printf("%c\n", input);
            input = Cnecin();
            switch (input)
            {
                if (input == 'w')
                {
                    evJump(&gameModel.player);
                }
                else{
                    evDinoFall(&gameModel.player);
                }
            }
        }
        /*advance time*/
        evPlayerUpdate(&gameModel.player);
        evScroll(&gameModel.cactiMed,ScrollSpeed);
    }

    return 0;
}