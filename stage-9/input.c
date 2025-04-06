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
    if (keyValues[0]&2)
    {
        output = '`'; /*grave for escape rep and back compatability*/
    }
    else if (keyValues[0]&4)
    {
        output = '1';
    }
    else if (keyValues[0]&8)
    {
        output = '2';
    }
    else if (keyValues[0]&16)
    {
        output = '3';
    }
    else if (keyValues[1]&1<<15)
    {
        output = 's';
    }
    else if (keyValues[1]&2)
    {
        output = 'w';
    }
    
    
    return output;
}