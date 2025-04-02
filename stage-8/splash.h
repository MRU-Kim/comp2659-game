/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 8
Deadline        March 24, 2024
File name       splash.h
Professor     	Steve Kalmar
*/

#ifndef SPLASH_H
#define SPLASH_H

void welcomeScreen();
void initSplash(UINT8 *base8, char playerOneString[], char playerTwoString[], char quitString[]);
void pressDownKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[]);
void pressUpKey(UINT8 *base, int x1, int x2, int y, int width1, int width2, char string1[], char string2[]);

#endif