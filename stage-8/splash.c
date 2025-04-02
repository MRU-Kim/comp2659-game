/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 8
Deadline        March 24, 2024
File name       splash.c
Professor     	Steve Kalmar
*/

#include "splash.h"
#include "CONST8.h"
#include "input.h"

void welcomeScreen()
{
    char playerOneString[11] = {'O','n','e',' ','P','l','a','y','e','r','\n'};
    char playerTwoString[12] = {'T','w','o',' ','P','l','a','y','e','r','s','\n'};
    char quitString[5] = {'Q','u','i','t','\n'};
    UINT8 *base8 = Physbase();
    bool quit = false;
    long input = 0; 
    int result = 0;

    
    initSplash(base8, playerOneString, playerTwoString, quitString);

    while (!quit) 
    { 
        if (getKey()) 
        {
            input = getKey();

            switch (input) 
            {
                case Enter:
                    if (i == 2) 
                    {
                        result = 2;
                        quit = TRUE;
                    }
                    else if (i == 1)
                    {
                        result = 1;
                        quit = TRUE;
                    }
                    else 
                    {
                        result = 0;
                        quit = TRUE;
                    }
                    return;

                case UpKey:
                    if (i == 2) 
                    {
                        pressUpKey(base8, 280, 300, 200, 10, 4, playerTwoString, quitString);
                        i--;
                    }
                    else if (i == 1)
                    {
                        pressUpKey(base8, 280, 300, 200, 10, 4, playerOneString, playerTwoString);
                        i--;
                    }
                    break;

                case downKey:
                    if (i == 0)
                    {
                        pressDownKey(base8, 280, 280, 100, 10, 10, playerOneString, playerTwoString);
                        i++;
                    }
                    else if (i == 1)
                    {
                        pressDownKey(base8, 280, 300, 200, 10, 4, playerTwoLabel, quitLabel);
                        i++;
                    }

                default:
                    break;
            }

            clearArrow(prevChoice);
            drawArrow(userChoice);
        }
    }
}

void initSplash(UINT8 *base8, char playerOneString[], char playerTwoString[], char quitString[])
{
    plotRectangle(base, 220, 40, 200, 50);
    plotRectangle(base, 220, 140, 200, 50);
    plotRectangle(base, 220, 240, 200, 50);

    printString(base, 240, 100, playerOneString);
    printString(base, 240, 200, playerTwoString);
    printString(base, 340, 300, quitString);
}

void pressDownKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[])
{
    clearRectangle(base, x1, y, 80, 16);
    clearRectangle(base, x2, (y + 100), 80, 16);
    
    printString(base, x1, y, width1, string1);
    printString(base, x2, (y + 100), width2, label2);
}

void pressUpKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[])
{
    clearRectangle(base, x1, y, 80, 16);
    clearRectangle(base, x2, (y + 100), 80, 16);
    
    printString(base, x1, y, width1, string1);
    printString(base, x2, (y + 100), width2, label2);
}
