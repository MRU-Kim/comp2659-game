#include <osbind.h>
#include <stdio.h>
#include "const.h"

#define VideoBaseHi 0xFFFF8201
#define VideoBaseMi 0xFFFF8203

UINT8 *get_video_base();
void set_video_base(UINT8 *add);
void set_video_base_asm(UINT8 *add);

int main()
{
    UINT32 oldSsp;
    UINT8 *fb;
    static UINT8 buffer2Arr[32000 + 256];
    UINT8 *buffer2 = buffer2Arr;
    UINT16 buffer2IntAdd = (UINT16)buffer2Arr;

    /*find displacement of buffer2 from being 256 byte alligned
    then add displacement */
    UINT16 displacement = 256 - buffer2IntAdd % 256;
    buffer2 += displacement;


    fb = get_video_base();
    printf("%p address\n", fb);
    set_video_base(buffer2);
    /*modify via ass*/
    Cnecin();
    set_video_base(fb);
    fb = get_video_base();
    printf("%p address\n", fb);


    return 0;
}
/*function: get_video_base
provides the address of the beggining of the frame buffer
output: address of the beggining of the frame buffer*/
UINT8 *get_video_base()
{
    long oldSsp = Super(0);
    volatile UINT8 *vhi = VideoBaseHi;
    volatile UINT8 *vmi = VideoBaseMi;
    UINT32 output = 0x0;
    output += ((UINT32)(*vhi) << 16) | ((UINT32)(*vmi) << 8);
    Super(oldSsp);

    return (UINT8 *)output;
}
/*function: set_video_base
takes a 256 byte alligned address and changes
the start address of the frame buffer to that address
Input:
add- 256 byte alligned adress to change fb to*/

void set_video_base(UINT8 *add)
{
    long oldSsp = Super(0);
    set_video_base_asm(add);
    /*
    volatile UINT8 *vhi = VideoBaseHi;
    volatile UINT8 *vmi = VideoBaseMi;

    *vhi = (UINT32)add >> 16 & 0xFF;
    *vmi = (UINT32)add >> 8 & 0xFF;
    */
    Super(oldSsp);
}
    