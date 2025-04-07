/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       isr.c
Professor     	Steve Kalmar
*/
#include "clock.h"
#include "isr.h"
#include "osbind.h"


UINT16 keyValues[] = {0, 0, 0, 0, 0, 0, 0, 0}; /*global variable*/

UINT16 stateIKBR = 0;
int mouseXlocation = 320;
int mouseYlocation = 200;
int mousePress = 0;

/*function: install_vector*/
Vector installVector(int num, Vector vector)
{
	Vector orig;
	Vector *vectp = (Vector *)((long)num << 2);
	long old_ssp = Super(0);
	orig = *vectp;
	*vectp = vector;

	Super(old_ssp);
	return orig;
}


void incVbCounter(){
	vbCounter += 1; /*global variable in clock.h*/
}

/*
function addBuff
Purpose:
	adds a keycode to the gloval keyValue buffer and handle mouse movements
	also controls the global mouse state
	handles each accordingly

input: 
value - value frome the IKBR output register
*/

void addBuff(signed int value)
{
	int negitive = ((char)value) < 0;

	if (stateIKBR == 0 && value >= 248)
	{
		mousePress = value & 0x0003;
		stateIKBR = 2;
	}
	else if (stateIKBR == 0 && value < 248)
	{
		/*toggle keypress at the low nibble of value place of keypress
		at the index of high nibble of value in keyValues
		ingoring the break marker*/
		unsigned int lower = value & 0x000F;
		unsigned int index = (value & 0x0070) >> 4;
		if (value < 128)
		{
			keyValues[index] |= (1 << lower);
		}
		else
		{
			keyValues[index] &= ~(1 << lower);
		}
	}
	else
	{
		/*state 1 or 2 both for mouse delta position input, decrement state when visited
		if low byte high bit 1 set high byte*/


		if (value&0x80)
		{
			value |= 0xFF00;
		}
		


		if (stateIKBR == 1)
		{
			mouseYlocation += (value);
		}
		else
		{
			mouseXlocation += (value);
		}
		stateIKBR--;
	}
}