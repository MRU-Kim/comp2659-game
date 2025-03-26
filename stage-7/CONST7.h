/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       soundconst.h
Professor     	Steve Kalmar
*/

#ifndef CONST7_H
#define CONST7_H

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

#define OFF                 0
#define ON                  1
#define Mixer               7
#define PSGSelectAddress    0xFF8800
#define PSGWriteAddress     0xFF8802

/* notes */
#define C5 0x06B
#define D5 0x0BE
#define E5 0x0AA
#define F5Sharp 0x097
#define G5 0x08F
#define C4 0x0D6
#define D5Sharp 0x0B4
#define F5 0x0A0
#define Pause 0

/* Channels */
#define ChannelA            0
#define ChannelB            1
#define ChannelC            2

/* fine and coarse registers of each channels */
#define AFine               ChannelA
#define ACoarse             ChannelA + 1
#define BFine               ChannelB + 1
#define BCoarse             ChannelB + 2
#define CFine               ChannelC + 2
#define CCoarse             ChannelC + 3
#define NoiseReg            6
#define GotoVolume          8

#endif