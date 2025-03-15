
#include "music.h"
#include "../stage-2/CONST.H"
#include "psg.h"

const int theMusic[27] = 
{
    C5,G5,F5_Charp,G5,Pause,
C5,G5,F5_Charp,G5,D5_Sharp,C4,Pause,
C5,G5,F5_Charp,G5,Pause,
D5_Sharp,F5,G5,D5_Sharp,F5,D5,D5_Sharp,C4,D5,C4
};
const time[27]={2,1,2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,4,4,2,2,2,2,2,2,1,2}; 
/*this is the time the tempo needs to be divided by*/
song theSong;
void helpInitialize( )
{
    int i=0;
  
    for(i=0; i<27; i++)
    {
        theSong.theActualMusic[i].value= theMusic[i];
        theSong.theActualMusic[i].time= time[i];
    }
    theSong.index =0;
}
void start_music()
{
    long  nowTime, elapsedTime;
    int theTone= theSong.theActualMusic[theSong.index].value;
    int time_divide = theSong.theActualMusic[theSong.index].time;
     printf("%X\n",theTone);

theSong.previousTime = get_time();
nowTime = get_time();

while((nowTime -theSong.previousTime ) < (64/time_divide))
{
        set_tone(CHANNEL_A, theTone);
       enable_channel(CHANNEL_A, ON, OFF) ; 
       set_volume( CHANNEL_A, 10);
       nowTime = get_time();
}
theSong.previousTime = get_time();
  printf("%X\n",theSong.previousTime );
theSong.index++;

       /*while(!Cconis())
;*/
stop_sound();
}
void update_music()
{
     long  nowTime, elapsedTime;
     int time_divide = theSong.theActualMusic[theSong.index].time;
    int theTone= theSong.theActualMusic[theSong.index].value;
     nowTime =  get_time();

  printf("%X\n",theSong.previousTime );
     while((nowTime - theSong.previousTime) < (64/time_divide))
     {
        if(theTone != Pause)
        {
         set_tone(CHANNEL_A, theTone);
       enable_channel(CHANNEL_A, ON, OFF) ; 
       set_volume( CHANNEL_A, 10);
        }
       nowTime = get_time();
        
     }
theSong.previousTime = get_time();
theSong.index++;
stop_sound();


}

long get_time() {
    long timeNow;
    long *timer = (long *)0x462;
    long old_ssp;

    old_ssp = Super(0);
    timeNow = *timer;
    Super(old_ssp);

    return timeNow;
}