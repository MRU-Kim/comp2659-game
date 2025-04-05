/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
File name       input.c
Professor     	Steve Kalmar

Purpose:
Holds Input function that will be modified later
*/

#include <stdio.h>
#include <osbind.h>
#include "input.h"
#include "../stage-3/events.h"
#include "../stage-3/model.h"

#define esc 0x01
#define esc_break 0x81
#define RDR_full 0x01
#define default_control 0x96
#define wMake = 0x11
#define wBreak = wMake ^ 0x80
#define sMake = 0x1f
#define sBreak = sMake ^ 0x80
/*
-------------------------------------------------------------------
    function: getKey
    Function checks to see if a key from the keyboard is pressed.
    If a key is pressed, the function returns the char representation
    of the key, if not, it returns NULL ('\0').

    input: 
        None.
    output:
        Char representation of the pressed key
        or NULL ('\0').
-------------------------------------------------------------------
*/
char getKey()
{
    if (Cconis()) {
        return (char)Cnecin();
    }

    return NULL;
}