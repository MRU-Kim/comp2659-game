/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino 
Course name   	COMP 2659-002
Stage	    	Stage 2
Deadline        February 10, 2024
File name       CONST.H
Professor     	Steve Kalmar
*/

#ifndef CONST_H
#define CONST_H

/* types */
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef int bool;
#define true 1
#define false 0

/* screen */
#define ScreenWidth 640
#define ScreenHeight 400
#define BytesPerScreen 32000

/* object */
#define DinoHeight 16
#define DinoWidth 16
#define CactMedHeight 16
#define CactMedWidth 16

/*Model location  constants*/
#define GroundY 200
#define DinoY GroundY-DinoHeight
#define DinoX 100
#define CactMedY GroundY-CactMedHeight
#define ScoreX 639-5*8
#define ScoreY 10
#define HighScoreX ScoreX-40
#define HighScoreY ScoreY

/*Model game logic constants*/
#define MaxJump DinoY-30
#define airCrouchSpeed 10
#define JumpSpeed -5
#define HitErrorMargin 1


/* stage 7 - sounds */
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
