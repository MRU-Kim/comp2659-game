/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 8
Deadline        March 24, 2024
File name       splash.c
Professor     	Steve Kalmar
*/

#include <osbind.h>
#include <stdio.h>
#include "splash.h"
#include "CONST.H"
#include "RASTER.H"
#include "CONST8.h"
#include "input.h"

void welcomeScreen()
{
    char *playerOneString = "One Player";
    char *playerTwoString = "Two Players";
    char *quitString = "Quit";
    UINT8 *base = get_video_base();
    bool quit = false;
    long input = 0;
    int result = 0;
    int i;

    initSplash(base, playerOneString, playerTwoString, quitString);

    while (!quit)
    {
        if (getKey())
        {
            input = getKey();

            switch (input)
            {
            case EnterKey:
                if (i == 2)
                {
                    result = 2;
                    quit = true;
                }
                else if (i == 1)
                {
                    result = 1;
                    quit = true;
                }
                else
                {
                    result = 0;
                    quit = true;
                }
                return;

            case UpKey:
                if (i == 2)
                {
                    pressUpKey(base, 280, 300, 200, 10, 4, playerTwoString, quitString);
                    i--;
                }
                else if (i == 1)
                {
                    pressUpKey(base, 280, 300, 200, 10, 4, playerOneString, playerTwoString);
                    i--;
                }
                break;

            case DownKey:
                if (i == 0)
                {
                    pressDownKey(base, 280, 280, 100, 10, 10, playerOneString, playerTwoString);
                    i++;
                }
                else if (i == 1)
                {
                    pressDownKey(base, 280, 300, 200, 10, 4, playerTwoString, quitString);
                    i++;
                }

            default:
                break;
            }
        }
    }
}

void initSplash(UINT8 *base, char playerOneString[], char playerTwoString[], char quitString[])
{
    plotRectangle(base, 220, 40, 200, 50);
    plotRectangle(base, 220, 140, 200, 50);
    plotRectangle(base, 220, 240, 200, 50);

    printString(base, 240, 100, playerOneString);
    printString(base, 240, 200, playerTwoString);
    printString(base, 240, 300, quitString);
}

void pressDownKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[])
{
    clearRectangle(base, x1, y, 80, 16);
    clearRectangle(base, x2, (y + 100), 80, 16);

    printString(base, x1, y, string1);
    printString(base, x2, (y + 100), string2);
}

void pressUpKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[])
{
    clearRectangle(base, x1, y, 80, 16);
    clearRectangle(base, x2, (y + 100), 80, 16);

    printString(base, x1, y, string1);
    printString(base, x2, (y + 100), string2);
}
