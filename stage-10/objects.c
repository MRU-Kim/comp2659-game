/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
File name       objects.c
Professor     	Steve Kalmar

Purpose:
This source file contains the sprite data definitions for all major objects used in the
Dino game, including the dinosaur in its different states (standing, moving, crouching,
and dead) and various obstacles like cacti. These sprites are 16-bit hexadecimal values
representing each object's bitmap, which will be rendered on the screen.

Assumptions:
- Each sprite is defined as a 16-element array of UINT16 values.

Limitations:
- No functions are defined in this file—only sprite values.
*/

#include "objects.h"
#include "CONST.H"

UINT16 DinoStandSprite[] = {
    0x0000,
    0x0078,
    0x00ff,
    0x00df,
    0x00ff,
    0x80f8,
    0x81fe,
    0xc3f8,
    0xe7f8,
    0x7ffe,
    0x7ff0,
    0x3fe0,
    0x1fe0,
    0x0640,
    0x0240,
    0x0360};
UINT16 DinoStandSpriteClear[] = {
    ~0x0000,
    ~0x0078,
    ~0x00ff,
    ~0x00df,
    ~0x00ff,
    ~0x80f8,
    ~0x81fe,
    ~0xc3f8,
    ~0xe7f8,
    ~0x7ffe,
    ~0x7ff0,
    ~0x3fe0,
    ~0x1fe0,
    ~0x0640,
    ~0x0240,
    ~0x0360};

UINT16 DinoDeadSprite[] = {
    0x0000,
    0x0078,
    0x008f,
    0x00af,
    0x008f,
    0x80f8,
    0x81fe,
    0xc3f8,
    0xe7f8,
    0x7ffe,
    0x7ff0,
    0x3fe0,
    0x1fe0,
    0x0640,
    0x0240,
    0x0360};

UINT16 DinoDeadSpriteClear[] = {
    ~0x0000,
    ~0x0078,
    ~0x008f,
    ~0x00af,
    ~0x008f,
    ~0x80f8,
    ~0x81fe,
    ~0xc3f8,
    ~0xe7f8,
    ~0x7ffe,
    ~0x7ff0,
    ~0x3fe0,
    ~0x1fe0,
    ~0x0640,
    ~0x0240,
    ~0x0360};

UINT16 DinoMove1Sprite[] = {
    0x0000,
    0x0078,
    0x00ff,
    0x00df,
    0x00ff,
    0x80f8,
    0x81fe,
    0xc3f8,
    0xe7f8,
    0x7ffe,
    0x7ff0,
    0x3fe0,
    0x1fe0,
    0x0e40,
    0x0260,
    0x0300};

UINT16 DinoMove1SpriteClear[] = {
    ~0x0000,
    ~0x0078,
    ~0x00ff,
    ~0x00df,
    ~0x00ff,
    ~0x80f8,
    ~0x81fe,
    ~0xc3f8,
    ~0xe7f8,
    ~0x7ffe,
    ~0x7ff0,
    ~0x3fe0,
    ~0x1fe0,
    ~0x0e40,
    ~0x0260,
    ~0x0300};

UINT16 DinoMove2Sprite[] = {
    0x0000,
    0x0078,
    0x00ff,
    0x00df,
    0x00ff,
    0x80f8,
    0x81fe,
    0xc3f8,
    0xe7f8,
    0x7ffe,
    0x7ff0,
    0x3fe0,
    0x1fe0,
    0x0e60,
    0x0340,
    0x0060};

UINT16 DinoMove2SpriteClear[] = {
    ~0x0000,
    ~0x0078,
    ~0x00ff,
    ~0x00df,
    ~0x00ff,
    ~0x80f8,
    ~0x81fe,
    ~0xc3f8,
    ~0xe7f8,
    ~0x7ffe,
    ~0x7ff0,
    ~0x3fe0,
    ~0x1fe0,
    ~0x0e60,
    ~0x0340,
    ~0x0060};

UINT16 DinoCrouchSprite[] = {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0078,
    0x00ff,
    0x00df,
    0x00ff,
    0x80f8,
    0x81fe,
    0xc3f8,
    0xe7f8,
    0x7ffe,
    0x7ff0,
    0x3fe0,
    0x0360};

UINT16 DinoCrouchSpriteClear[] = {
    ~0x0000,
    ~0x0000,
    ~0x0000,
    ~0x0000,
    ~0x0078,
    ~0x00ff,
    ~0x00df,
    ~0x00ff,
    ~0x80f8,
    ~0x81fe,
    ~0xc3f8,
    ~0xe7f8,
    ~0x7ffe,
    ~0x7ff0,
    ~0x3fe0,
    ~0x0360};

UINT16 CactusMedSprite[] = {
    0x0180,
    0x03C0,
    0x03C0,
    0xC3C3,
    0xC3C3,
    0xC3C3,
    0xC3C3,
    0xE3CF,
    0xFFDF,
    0x7FF8,
    0x07F0,
    0x03C0,
    0x03C0,
    0x03C0,
    0x03C0,
    0x03C0,
};

UINT16 CactusMedSpriteClear[] = {
    ~0x0180,
    ~0x03C0,
    ~0x03C0,
    ~0xC3C3,
    ~0xC3C3,
    ~0xC3C3,
    ~0xC3C3,
    ~0xE3CF,
    ~0xFFDF,
    ~0x7FF8,
    ~0x07F0,
    ~0x03C0,
    ~0x03C0,
    ~0x03C0,
    ~0x03C0,
    ~0x03C0,
};