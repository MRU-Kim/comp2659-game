#include "../stage-2/RASTER.H"
#include "../stage-2/objects.h"
#include "CONST8.H"

int main(){
    UINT8 *base = Physbase();

    clearScreen(base);

    void printString(base, welcomeX, welcomeY, "Jump To Start");
    void printString(base, player1X, player1Y, "Single Player");
    void printString(base, player2X, player2Y, "2-Player");
}