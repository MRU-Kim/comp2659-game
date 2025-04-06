/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       CONST.H
Professor     	Steve Kalmar

Purpose:
Holds constants for rendering and gameplay logic
*/

#ifndef CONST_H
#define CONST_H

/* types */
typedef unsigned char UINT8;
typedef unsigned int UINT16;
typedef unsigned long UINT32;
typedef int bool;
#define true 1
#define false 0

/* screen */
#define ScreenWidth 640
#define ScreenHeight 400
#define BytesPerScreen 32000
#define ScreenCentreX 319
#define ScreenCentreY 199

/* object */
#define DinoHeight 16
#define DinoWidth 16
#define CactMedHeight 16
#define CactMedWidth 16

/*Model location  constants*/
#define GroundY 200
#define DinoY GroundY - DinoHeight
#define DinoX 16 * 8
#define CactMedY GroundY - CactMedHeight
#define ScoreX 639 - 100
#define ScoreY 10
#define HighScoreX ScoreX - 50
#define HighScoreY ScoreY

/*Model game logic constants*/
#define GravityTime 3
#define MaxJump DinoY -30
#define AirCrouchSpeed 10
#define JumpSpeed -3
#define HitErrorMargin 3
#define MileStoneScore 500
#define StartScrollSpeed 3
#define leftLimit -30

/*cactus logic*/
#define MaxCactus 10
#define MinCacSpawnTime 30
#define MaxCacSpawnTimeAdd 70

/*Animation logic*/
#define DinoRunTimerLength 15

/*frame buffer*/
#define VideoBaseHi 0xFFFF8201
#define VideoBaseMi 0xFFFF8203


#endif
