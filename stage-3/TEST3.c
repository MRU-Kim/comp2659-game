/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 3
Deadline        February 28, 2024
File name       test3.C
Professor     	Steve Kalmar
*/

#include <osbind.h>
#include "events.h"
#include "model.h"
#include "../stage-2/const.h"

DinoPlayer player = {100,GroundY+DinoHeight,false,true}; 
/*initializes player where x=200, y=groundlevel+dinohieght,not crouched, is alive*/

CactusMed cacti[3] = {{200,CactMedY},{-16,CactMedY},{-16,CactMedY}};
/*initializes 3 med cactus 1 in play 2 out of play*/

Ground ground = {GroundY};

Score score = {639-5*8,10,0};
/*initiallizes score to the top right of the screen and sets to 0*/
HighScore highScore = {639-5*8-5*8,10,0};
/*initiallizes high score to the left of score and sets to 0*/

ScrollSpeed scrollSpeed = {0};
/*sets scroll speed to 0*/


int main()
{
    Model gameModel = {
        {100,GroundY+DinoHeight,false,true},
        cacti,
        ground,
        score,
        highScore,
        ScrollSpeed
    };
    return 0;
}