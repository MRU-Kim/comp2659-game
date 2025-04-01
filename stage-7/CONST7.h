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

#define NoteAMT 30
#define TimeSig 70
#define Whole TimeSig/1
#define Half TimeSig/2
#define Quarter TimeSig/4

#define OFF 0
#define ON 1
#define Mixer 7
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

/* Channelregisters */
#define ChannelA 0
#define ChannelB 1
#define ChannelC 3

/* fine and coarse registers of each channels */
#define AFine ChannelA
#define ACoarse ChannelA + 1
#define BFine ChannelB
#define BCoarse ChannelB 1
#define BLevel  9
#define CFine ChannelC
#define CCoarse ChannelC + 1
#define NoiseReg 6
#define GotoVolume 8

/**/

/* envelope shapes and masks */
#define Hold 0
#define Alt 1
#define Att 2
#define Cont 3
#define Non 15

#define MaskHold 0x01
#define MaskAlt 0x02
#define MaskAtt 0x04
#define MaskCont 0x08

#define EnvelopeShape 0x0D
#define EnvelopeFine 0x0B
#define EnvelopeCoarse 0x0C

#endif