/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       input.c
Professor     	Steve Kalmar

Purpose:
Holds Input function that will be modified later
*/

#include <stdio.h>
#include <osbind.h>
#include "input.h"
#include "isr.h"

/*
-------------------------------------------------------------------
    function: getKey
    purpose: checks what keys are pressed and outputs on priority


    output:

-------------------------------------------------------------------
*/
char getKey()
{
    char output = 0;
    if (keyValues[0] & 2)
    {
        output = '`'; /*grave for escape rep and back compatability*/
    }
    else if (keyValues[0] & 4)
    {
        output = '1';
    }
    else if (keyValues[0] & 8)
    {
        output = '2';
    }
    else if (keyValues[0] & 16)
    {
        output = '3';
    }
    else if (keyValues[1] & 1 << 15)
    {
        output = 's';
    }
    else if (keyValues[1] & 2)
    {
        output = 'w';
    }

    return output;
}

/*function: getMouseX
Purpose: returns mouse xposition and keeps pointer within bounds*/
int getMouseX()
{
    int x = mouseXlocation;
    if (x < 0)
    {
        x = 0;
        mouseXlocation = 0;
    }
    else if (x > 639)
    {
        x = 639;
        mouseXlocation = 639;
    }

    return x;
}

/*function: getMouseY
Purpose: returns mouse Y position and keeps pointer within bounds*/
int getMouseY()
{
    int y = mouseYlocation;
    if (y < 0)
    {
        y = 0;
        mouseYlocation = 0;
    }
    else if (y > 639)
    {
        y = 639;
        mouseYlocation = 639;
    }

    return y;
}
/*function: getMouseClick
Purpose: returns the current state of mouse buttons*/
int getMouseClick()
{
    return mousePress;
}
