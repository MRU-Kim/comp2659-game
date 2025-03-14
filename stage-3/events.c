/*
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 3
Deadline        February 28, 2024
File name       events.c
Professor       Steve Kalmar
*/

#include "events.h"
#include "../stage-2/const.h"
#include "model.h"

void handleJump(DinoPlayer *player){
    if (player->y == GroundY+DinoHeight) { /* on the ground */
        jump(player);
    }
}

void handleJumpHeld(DinoPlayer *player){
    if (player->y > GroundY-DinoHeight && player-> y > MaxJump) { /* in the air */
        jump(player);
    }
    else {
        fall(player);
    }
}

void handleCrouch(DinoPlayer *player){
    crouch(player);
}

void handleAircrouch(DinoPlayer *player){
    aircrouch(player);
}

/*sync events*/

/* function: scroll
    scrolls all scrollable objects to the left 
    so far this is only cactusMed
    inputs:
    CactusMed - array of cactusMed
    ScrollSpeed - ScrollSpeed speed to be forced on all side scrolling objects

*/
void scroll(CactusMed *cacti[], ScrollSpeed scrollSpeed){
    int i;
    for (i = 2; i>+0; i--){
        scrollMedCactus(cacti[i],scrollSpeed);
    }
}

void spawnMedCactus(CactusMed *cactusMed){

}

/* fucntion: initializeModel
    initializes model to start conditions with up to 3 cactus in play
    inputs:
    Model- model to be initialized
    CactiInPlay amount of cactus, up to 3 to be be in play
*/
void initializeModel(Model *model, int cactiInPlay){
    int i;
    model->player.x = 100; /*init player*/
    model->player.y = DinoY;
    model->player.delta_y = 0;
    model->player.isAlive = true;
    model->player.isCrouched = false;

    /*init cacti*/
    for ( i = 0; i < 3; i++)
    {
        model->cactiMed[i].x = -16;
        model->cactiMed[i].y = CactMedY;
    }
    /*[put cactus into play]*/
    for (i = 0; i < cactiInPlay; i++)
    {
        model->cactiMed[i].x = 640+i*16;
    }
    model->ground.y = GroundY;

    model->score.x = ScoreX;
    model->score.y = ScoreY;
    model->score.value = 0;

    model->highScore.x = HighScoreX;
    model->highScore.y = HighScoreY;
    model->highScore.value = 0;

    model->scrollSpeed.delta_x = 0;
}
/*cascade events*/


/* function: milestone
    after 1000 points increase the speed of the scroll
    inputs:
    scrollspeed - object that controls speed of scrolling objects
*/
void milestone(ScrollSpeed *scrollspeed){
}
/*function: dinoDeath
    triggers on the dino hitbox intersects with a cactus hitbox
        stops scroll, dino dies, sets new high score, places game into new run after next jump input
*/
void dinoDeath(DinoPlayer *player){
    player->x = -5; /* start position */
    player->y = 0;
    player->delta_y = 0;
}

void updateHighscore(Score score, HighScore highscore){

}
/* function: resetAfterDeath
    a death reset everything into new run except high score
*/
void resetAfterDeath(Model *model, Model startconditions){

}
