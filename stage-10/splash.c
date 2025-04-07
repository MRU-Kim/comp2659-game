/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       splash.c
Professor     	Steve Kalmar

purpose:
driver for splash screen

takes mouse and kb input for starting game or quitting
*/

#include "splash.h"
#include "CONST.H"
#include "RASTER.H"
#include "CONST8.h"
#include "input.h"
#include "objects.h"
#include "clock.h"



int welcomeScreen(UINT8 *base)
{

    int selection = 0;
    long input = 0;
    int result = 0;
    int x, y, click;

    int i = 0;

    input = 0;
    while (selection == 0)
    {
        x = getMouseX();
        y = getMouseY();
        click = getMouseClick();

        plot16Bitmap(base, DinoStandSprite, x, y, 16);

        plotSplash(base);

        waitVBlank();

        clear16Bitmap(base, DinoStandSpriteClear, x, y, 16);

 

        if (click)
        {
            if (x >= P1BoxLX && x <= P1BoxRX && y >= P1BoxTY && y <= P1BoxBY)
            {
                selection = 1;
            }
            else if (x >= ExitBoxLX && x <= ExitBoxRX && y >= ExitBoxTY && y <= ExitBoxBY)
            {
                selection = 3;
            }

        }

        input = getKey();
        if (input != 0)
        {
            switch (input)
            {
            case '1':
                selection = 1;
                break;

            case '2':
                break;

            case '3':
                selection = 3;
                break;

            default:
                break;
            }
        }
    }
    return selection;
}

void plotSplash(UINT8 *base)
{
    char *playerOneString = "1P(1)";
    char *playerTwoString = "2P(2)";
    char *quitString = "Quit(3)";

    plot16Bitmap(base, bigD, BigDX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigI, BigIX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigN, BigNX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigO, BigOX, BigLettY, BigLettHeight);

    plotRectangle(base, P1BoxY, BoxHeight);

    plot16Bitmap(base, boxP, MiddleScreen + 8, P1BoxY + 20, BigLettHeight);
    plot16Bitmap(base, box1, MiddleScreen - 8, P1BoxY + 20, BigLettHeight);

    plotRectangle(base, P2BoxY, BoxHeight);
    plot16Bitmap(base, boxP, MiddleScreen + 8, P2BoxY + 20, BigLettHeight);
    plot16Bitmap(base, box2, MiddleScreen - 8, P2BoxY + 20, BigLettHeight);

    plotRectangle(base, ExitBoxY, BoxHeight);
    plot16Bitmap(base, boxExit, MiddleScreen, ExitBoxY + 20, BigLettHeight);
}
