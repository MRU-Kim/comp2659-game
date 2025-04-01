#include "../stage-2/RASTER.H"
#include "../stage-2/objects.h"
#include "CONST8.H"

int main()
{
    UINT8 *base = Physbase();

    clearScreen(base);

    void printString(base, player1X, player1Y, "1 Player");
    void printString(base, player2X, player2Y, "2 Players");
    void printString(base, welcomeX, welcomeY, "Quit");    
}