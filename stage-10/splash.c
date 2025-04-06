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

int welcomeScreen(UINT8 *base)
{

    int selection = 0;
    long input = 0;
    int result = 0;
    int i;

    initSplash(base);

    input = 0;
    while (selection == 0)
    {
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

void initSplash(UINT8 *base)
{
    char *playerOneString = "1P(1)";
    char *playerTwoString = "2P(2)";
    char *quitString = "Quit(3)";
    
    clearScreen(base);

    plot16Bitmap(base, bigD, BigDX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigI, BigIX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigN, BigNX, BigLettY, BigLettHeight);
    plot16Bitmap(base, bigO, BigOX, BigLettY, BigLettHeight);

    plotRectangle(base, P1BoxY, BoxHeight);
    printString(base, MiddleScreen - 2, P1TextY, playerOneString);

    plotRectangle(base, P2BoxY, BoxHeight);
    printString(base, MiddleScreen - 2, P2TextY, playerTwoString);

    plotRectangle(base, ExitBoxY, BoxHeight);
    printString(base, MiddleScreen - 8, ExitTextY, quitString);
}
