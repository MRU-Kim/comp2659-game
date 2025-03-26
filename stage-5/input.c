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

/*
-------------------------------------------------------------------
    function: getKey


    input:
        
    output:
        Voids
-------------------------------------------------------------------
*/



char getKey() {
    if (Cconis()) { 
        return (char)Cnecin(); /*Read and return the character immediately*/
    }
    return NULL; /*Return null character if no input is available*/
}