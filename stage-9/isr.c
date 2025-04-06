/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       isr.c
Professor     	Steve Kalmar
*/
#include "clock.h"
#include "isr.h"
#include "osbind.h"


unsigned long keyValues[] = {0, 0, 0, 0, 0, 0, 0, 0};
unsigned int lastValue = 0;
unsigned long time = 0;
unsigned int stateIKBR = 0;
unsigned long mouseXlocation = 128;
unsigned long mouseYlocation = 128;
unsigned long mousePress = 0;

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
	vbCounter += 1;
}

/*
Purpose:
	adds a keycode to the buffer and handle mouse movements
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
		unsigned int lower = value & 0x000F;
		unsigned int index = (value & 0x0070) >> 4;
		if (value < 128)
		{
			keyValues[index] |= (0x00000001 << lower);
		}
		else
		{
			keyValues[index] &= ~(0x00000001 << lower);
		}
	}
	else
	{
		if (stateIKBR == 1)
		{
			mouseYlocation += ((char)value);
		}
		else
		{
			mouseXlocation += ((char)value);
		}
		stateIKBR--;
	}
}