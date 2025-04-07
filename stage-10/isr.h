/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 9
Deadline        
File name       isr.h
Professor     	Steve Kalmar
*/
#include "CONST9.H"
#include "CONST.H"

#ifndef ISR_H
#define ISR_H

Vector installVector(int num, Vector vector);

extern volatile UINT16 keyValues[];
extern int mouseXlocation;
extern int mouseYlocation;
extern int mousePress;

void incVbCounter();

void addBuff(signed int value);

void vblIsr();

void IkbrIsr();


#endif