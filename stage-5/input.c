/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 5
Deadline        March 17, 2024
File name       input.c
Professor     	Steve Kalmar
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

/*
char getKey(char input)
{
    volatile UINT8 *const IKBD_control = 0xFFFC00;
    volatile const UINT8 *const IKBD_status = 0xFFFC00;
    volatile const SCANCODE *const IKBD_RDR = 0xFFFC02;

    SCANCODE scanCode = 0;
    char output = NULL;

    long old_ssp = Super(0);
    *IKBD_control = 0x16;

    if (!(*IKBD_status & RDR_full))
    {
        scanCode = *IKBD_RDR;
        *IKBD_control = default_control;
    }

    *IKBD_control = 0x96;
    Super(old_ssp);

    return output;

    /*
    if (Cconis()) {
        return (char)Cnecin();
    }

    return NULL;
}*/
char getKey()
{
    if (Cconis()) {
        return (char)Cnecin();
    }

    return NULL;
}