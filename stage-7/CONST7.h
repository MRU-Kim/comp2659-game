/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 7
File name       const7.h
Professor     	Steve Kalmar

Purpose:
Holds constants relating to manipulating the psg
*/

#ifndef CONST7_H
#define CONST7_H

#define NoteAMT 30
#define TimeSig 70
#define Whole TimeSig / 1
#define Half TimeSig / 2
#define Quarter TimeSig / 4

#define OFF 0
#define ON 1
#define PSGSelectAddress 0xFF8800
#define PSGWriteAddress 0xFF8802

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
#define ChannelA 0
#define ChannelB 1
#define ChannelC 2

/* fine and coarse registers of each channels */
#define AFine ChannelA
#define ACoarse 1
#define BFine 2
#define BCoarse 3
#define CFine 4
#define CCoarse 5
#define NoiseReg 6
#define Mixer 7

#define GotoVolume 8

#define EnvelopeFine 0x0B
#define EnvelopeCoarse 0x0C
#define EnvelopeShape 0x0D
#endif