
#include "RASTER.H"
#include "CONST8.H"
#include "splash.h"
#include <stdio.h>
#include <osbind.h>
#include"RASTER.H"


int main()
{
    
    UINT8 *base = Physbase();

    Cnecin();
    clearScreen(base);
    Cnecin();
    welcomeScreen();
    Cnecin();
    return 0;
}