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

    
    initializeSplashScreen(base8, playerOneString, playerTwoString, quitString);

    while (!quit) 
    { 
        if (getKey()) 
        {
            input = getKey();

            switch (input) {
                case UpKey:
                    if (userChoice > MenuChoice1) {
                        userChoice--;
                    }
                    break;
                case DownKey:
                    if (userChoice < MenuChoice2) {
                        userChoice++;
                    }
                    break;
                case EnterKey:
                    selectOption(userChoice);
                    return; 
                default:
                    break;
            }

            clearArrow(prevChoice);
            drawArrow(userChoice);
        }
    }
}

