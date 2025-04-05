#include <osbind.h>
#include <stdio.h>
#include "../stage-2/const.h"

#define VideoBaseHi 0xFFFF8201
#define VideoBaseMi 0xFFFF8203

UINT8 *get_video_base();
void set_video_base(UINT8 * add);

int main()
{
    volatile UINT8 *vhi = VideoBaseHi;
    volatile UINT8 *vmi = VideoBaseMi;
    volatile UINT8 *fb5 = 0xF8000;
    UINT32 oldSsp;
    UINT8 *fb;
    UINT8 *buffer1 = Physbase();

    printf("%p address\n", buffer1);
    oldSsp = Super(0);
    printf("%X address\n", *vhi);
    printf("%X address\n", *vmi);
    Super(oldSsp);
    fb = get_video_base();
    printf("%p address\n", fb);
    set_video_base(fb5);
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
    volatile UINT8 *vhi = VideoBaseHi;
    volatile UINT8 *vmi = VideoBaseMi;

    *vhi = (UINT32)add>>16 & 0xFF;
    *vmi = (UINT32)add>>8 & 0xFF;
    Super(oldSsp);
}