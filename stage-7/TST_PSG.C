#include "psg.h"
#include "music.h"

int main() {
   
int i;

 helpInitialize();
 start_music();
 while(!Cconis())
 {
 for(i=0; i <26;i++)
 {
    update_music();
 }
 helpInitialize();
 start_music();
 }
   /**   set_noise(1) ;

    set_tone(CHANNEL_A, 0x1AC);
   set_tone(CHANNEL_B, 0x153);
    set_tone(CHANNEL_C, 0x11D);


enable_channel(CHANNEL_A, ON, ON) ;    
 enable_channel(CHANNEL_B, ON, ON) ;
     enable_channel(CHANNEL_C, ON, ON) ;    

set_volume( CHANNEL_A, 10);
set_volume( CHANNEL_A,30);
set_volume( CHANNEL_A, 45);

while(!Cconis())
;
stop_sound();
*/
     
    return 0;
}
