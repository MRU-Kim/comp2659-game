#include "../stage-2/RASTER.H"
#include "../stage-2/objects.h"
#include "CONST8.H"

int main()
{
    UINT8 *base = Physbase();

    Cnecin();
    clearScreen(base);
    Cnecin();
    welcomeScreen();
    Cnecin();
}