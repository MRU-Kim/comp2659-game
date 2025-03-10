/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       test3.C
Professor     	Steve Kalmar
    Model gameModel = {
        .player = {319,200,0,0},
        .cactiMed = {{360,200},{-20,200},{-20,200}},
        .ground = {200},
        .score = {0},
        .highScore = {0},
        .scrollSpeed = {5}
    };
*/

#include <osbind.h>
#include "events.h"
#include "model.h"
#include "../stage-2/const.h"

int main()
{
    Model gameModel = {
        {319,200,0,0},
        {{360,200},{-20,200},{-20,200}},
        {200},
        {0},
        {0},
        {5}
    };
    return 0;
}