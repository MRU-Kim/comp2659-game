/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       splash.c
Professor     	Steve Kalmar
*/

#include <stdio.h>
#include "splash.h"
#include "CONST.H"
#include "RASTER.H"
#include "CONST8.h"
#include "input.h"
#include "objects.h"
#include "clock.h"
#include "isr.h"

UINT16 bigD[] = {
    0xfff8,
    0xfffc,
    0xfffe,
    0xf01f,
    0xf00f,
    0xf007,
    0xf007,
    0xf007,
    0xf007,
    0xf007,
    0xf007,
    0xf00f,
    0xf01f,
    0xfffe,
    0xfffc,
    0xfff8,
};

UINT16 bigI[] = {
    0xffff,
    0xffff,
    0xffff,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0x03c0,
    0xffff,
    0xffff,
    0xffff};

UINT16 bigN[] =
    {
        0xf00f,
        0xf80f,
        0xfc0f,
        0xfe0f,
        0xfe0f,
        0xff0f,
        0xff8f,
        0xf7cf,
        0xf3cf,
        0xf3ef,
        0xf1ff,
        0xf0ff,
        0xf07f,
        0xf01f,
        0xf00f,
        0xf00f};
UINT16 bigO[] =
    {
        0x7ffe,
        0xffff,
        0xffff,
        0xffff,
        0xf00f,
        0xf00f,
        0xf00f,
        0xf00f,
        0xf00f,
        0xf00f,
        0xf00f,
        0xf00f,
        0xffff,
        0xffff,
        0xffff,
        0x7ffe};

UINT16 box1[] =
    {
        0x0180,
        0x0380,
        0x0780,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180};
UINT16 boxP[] =
    {
        0x0fc0,
        0x0fe0,
        0x0c10,
        0x0c10,
        0x0c10,
        0x0fe0,
        0x0fc0,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00,
        0x0c00};

UINT16 box2[] =
    {
        0x07f8,
        0x0ffc,
        0x1c1c,
        0x181c,
        0x001c,
        0x0038,
        0x0070,
        0x00e0,
        0x01c0,
        0x0380,
        0x0700,
        0x0e00,
        0x0c00,
        0x1800,
        0x1ffc,
        0x1ffc};

UINT16 boxExit[] =
    {
        0x0000,
        0x0cfc,
        0x1e7c,
        0x1e7c,
        0x0c7c,
        0x7c7c,
        0x4f7c,
        0x4d7c,
        0x4c7c,
        0x0e7c,
        0x0a7c,
        0x7a7c,
        0x027c,
        0x027c,
        0x007c,
        0x0000};

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
