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


/* stage 7 - sounds */

#define OFF                 0
#define ON                  1

#define CHANNEL_A           0
#define CHANNEL_B           1
#define CHANNEL_C           2

/* fine and coarse registers of each channels */
#define A_FINE              CHANNEL_A
#define A_COARSE            CHANNEL_A + 1
#define B_FINE              CHANNEL_B + 1
#define B_COARSE            CHANNEL_B + 2
#define C_FINE              CHANNEL_C + 2
#define C_COARSE            CHANNEL_C + 3
#define NOISE_REG           6
#define GOTO_VOLUME         8

#define MIXER               7

#define PSG_SELECT_ADDRESS  0xFF8800
#define PSG_WRITE_ADDRESS   0xFF8802

#endif
