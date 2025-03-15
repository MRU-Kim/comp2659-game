
#include "../stage-2/CONST.H"
#include "psg.h"

/*#define C5 0x0D6*/
/* MUSIC HEADER FILE
#define C4 0x0D6
 */
#define A5 0x00  /*not true*/
#define B5 0x00 /*not true*/
#define C5 0x06B
#define D5 0x0BE
#define E5 0x0AA
#define F5_Sharp 0x097
#define G5 0x08F
#define C4 0x0D6
#define D5_Sharp 0x0B4
#define F5 0x0A0
#define Pause 0


typedef struct
{
    int value;
    int time;

} note;

 typedef struct
{
  note theActualMusic[27];
  int index;
  long previousTime;
} song;
void start_music();
void update_music();
void helpInitialize();
long get_time();