/*
Names 			Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name   	COMP 2659-002
Stage	    	Stage 2
File name       RASTER.C
Professor     	Steve Kalmar

Purpose:
Implements graphics functions for plotting, clearing, and 
printing 8-bit and 16-bit bitmaps, drawing horizontal lines,
and rendering text and numbers using a font bitmap, plotting 
the sprites in objects.c.

*/

#include <stdio.h>
#include <osbind.h>

#include "RASTER.H"
#include "CONST.H"
#include "font.h"

/*
    function: clearScreen

    clears the entire screen by setting all pixels in the framebuffer to white.

    input:
        base    - pointer to starting address of framebuffer.
    return:
        Void.
*/

void clearScreen(UINT8 *base)
{
    register int i = 0;
    register UINT32 *location = (UINT32 *)base;

    while (i++ < BytesPerScreen / 4)
    {
        *(location++) = 0x00000000;
    }
}

/*
    functions: clear8Bitmap, clear16Bitmap

    Clears a 8/16 px bitmap. given the correct clear mask
    given that the same (x,y).Can clear bitmaps plotted partially off screen. In the case that the cordinates would clear
    the bitmap entirely off of the screen nothing is cleared.

    inputs:
        base    - pointer to starting address of framebuffer
        bitmap  - pointer to start of 8/16px wide bit map
        y       - vertical cord to be cleared
        x       - horizontal cord to be cleared
        height - height of bitmap
    output:
        Void.
*/
void clear8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height)
{
    int i;

    int offset = x & 7; /*x%8* how far on horizontal plane the x is from being byte alligned*/
    UINT8 *plotLocation;
    int usedHeight = height;

    if (y < 0)
    { /*if above screen by n amount, advance bit map n times, remove used height*/
        if (y < height)
            ; /*if not entirely off screen*/
        {
            bitmap += -y;
        }
        usedHeight += y;
        y = 0;
    }
    else if (y > 399 - height)
    {
        usedHeight -= y - (399 - height);
    }

    /*plot location is a byte, y rows down, and x/8 bytes right*/
    plotLocation = base + (y * 80) + (x >> 3);

    /*check if x is in bounds*/
    if (x > -8 && x < 640)
    {
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single bitwidth*/
        if (x < 0)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted abs(x) to the left
                x is negative*/
                *(plotLocation + 1) &= *(bitmap++) << -x;
                plotLocation += 80;
            }
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639 - 8)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) &= *(bitmap++) >> offset;
                plotLocation += 80;
            }
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else
        {
            for (i = 0; i < usedHeight; i++)
            {
                *plotLocation &= *(bitmap) >> offset;
                if (offset != 0)
                {
                    *(plotLocation + 1) &= *(bitmap) << (8 - offset);
                }
                plotLocation += 80;
                bitmap++;
            }
        }
    }
}

void clear16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height)
{
    int i;

    int offset = x & 15; /*x%16* how far on horizontal plane the x is from being word alligned*/
    UINT16 *location;
    int usedHeight = height;

    if (y < 0)
    { /*if above screen by n amount, advance bit map n times, remove used height*/
        if (y < height)
            ; /*if not entirely off screen*/
        {
            bitmap += -y;
        }
        usedHeight += y;
        y = 0;
    }
    else if (y > 399 - height)
    {
        usedHeight -= y - (399 - height);
    }

    /*location is a word, y rows down, and x/16 words right*/
    location = (UINT16 *)base + (y * 40) + (x >> 4);

    /*check if x is in bounds*/
    if (x > -16 && x < 640)
    {
        /*check if bitmap is off of left screen edge,
        if so offset and togglr single wordwidth*/
        if (x < 0)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*toggle the bitmap shifted abs(x) to the left
                x is negative*/
                *(location + 1) &= *(bitmap++) << -x;
                location += 40;
            }
        }
        /*check if bitmap is off of right screen edge,
        if so, offset and toggle single wordwidth*/
        else if (x > 639 - 16)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*toggle the bitmap shifted  to the left */
                *(location) &= *(bitmap++) >> offset;
                location += 40;
            }
        }
        /*If x is not word alligned toggle over 2 words width, else use 1*/
        else
        {
            for (i = 0; i < usedHeight; i++)
            {
                *location &= *(bitmap) >> offset;
                if (offset != 0)
                {
                    *(location + 1) &= *(bitmap) << (16 - offset);
                }
                location += 40;
                bitmap++;
            }
        }
    }
}

/*
    functions: plot8Bitmap, plot16Bitmap

    Plots an 8/16 px wide bitmap onto the screen. The function renders
    an 8/16 px wide bitmap at a specified (x,y) coordinate position
    on the screen or slightly off the screen. In the case that the cordinates would plot
    the bitmap entirely off of the screen nothing is plotted.
    It uses an OR operation.

    inputs:
        base   - pointer to starting address of frame buffer
        bitmap -
        y - vertical cord to be cleared
        x - horizontal cord to be cleared
        height - number of rows affected
    output:
        Void.
*/

void plot8Bitmap(UINT8 *base, UINT8 bitmap[], int x, int y, int height)
{
    int i;

    int offset = x & 7; /*x%8* how far on horizontal plane the x is from being byte alligned*/
    UINT8 *plotLocation;
    int usedHeight = height;

    if (y < 0)
    { /*if above screen by n amount, advance bit map n times, remove used height*/
        if (y < height)
            ; /*if not entirely off screen*/
        {
            bitmap += -y;
        }
        usedHeight += y;
        y = 0;
    }
    else if (y > 399 - height)
    {
        usedHeight -= y - (399 - height);
    }

    /*plot location is a byte, y rows down, and x/8 bytes right*/
    plotLocation = base + (y * 80) + (x >> 3);

    /*check if x is in bounds*/
    if (x > -8 && x < 640)
    {
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single bitwidth*/
        if (x < 0)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted abs(x) to the left
                x is negative*/
                *(plotLocation + 1) |= *(bitmap++) << -x;
                plotLocation += 80;
            }
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639 - 8)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) |= *(bitmap++) >> offset;
                plotLocation += 80;
            }
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else
        {
            for (i = 0; i < usedHeight; i++)
            {
                *plotLocation |= *(bitmap) >> offset;
                if (offset != 0)
                {
                    *(plotLocation + 1) |= *(bitmap) << (8 - offset);
                }
                plotLocation += 80;
                bitmap++;
            }
        }
    }
}

void plot16Bitmap(UINT8 *base, UINT16 bitmap[], int x, int y, int height)
{
    int i;

    int offset = x & 15; /*x%16* how far on horizontal plane the x is from being word alligned*/
    UINT16 *plotLocation;
    int usedHeight = height;

    if (y < 0)
    { /*if above screen by n amount, advance bit map n times, remove used height*/
        if (y < height)
            ; /*if not entirely off screen*/
        {
            bitmap += -y;
        }
        usedHeight += y;
        y = 0;
    }
    else if (y > 399 - height)
    { /*if bit map would be printed below screen by n amount remove usedHight be n amount*/
        usedHeight -= y - (399 - height);
    }
    /*plot location is a word, y rows down, and x/16 words right*/
    plotLocation = (UINT16 *)base + (y * 40) + (x >> 4);

    /*check if x is in bounds*/
    if (x > -16 && x < 640)
    {
        /*check if bitmap is plotted off of left screen edge,
        if so offset and plot single wordwidth*/
        if (x < 0)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted abs(x) to the left
                x is negative*/
                *(plotLocation + 1) |= *(bitmap++) << -x;
                plotLocation += 40;
            }
        }
        /*check if bitmap is plotted off of right screen edge,
        if so, offset and plot single wordwidth*/
        else if (x > 639 - 16)
        {
            for (i = 0; i < usedHeight; i++)
            {
                /*plot the bitmap shifted  to the left */
                *(plotLocation) |= *(bitmap++) >> offset;
                plotLocation += 40;
            }
        }
        /*If x is not word alligned plot over 2 words width, else use 1*/
        else
        {
            for (i = 0; i < usedHeight; i++)
            {
                *plotLocation |= *(bitmap) >> offset;
                if (offset != 0)
                {
                    *(plotLocation + 1) |= *(bitmap) << (16 - offset);
                }
                plotLocation += 40;
                bitmap++;
            }
        }
    }
}

/*
    function: plotHorizontalLine

    Plots a horizontal line accross the screen. The function
    sets all pixels in a single horizontal row to 1, effectively
    drawing a solid horizontal line. It modifies 20 full bytes
    at a specified y-coordinate.

    inputs:
        base   - pointer on the starting address of frame buffer
        row    - row to plot line in
    output:
        Void.
*/
void plotHorizontalLine(UINT8 *base, int y)
{
    int i;
    UINT32 *plotLocation = (UINT32 *)base + (y * 20);
    for (i = 0; i < 20; i++)
    {
        *plotLocation |= -1;
        plotLocation++;
    }
}
/*
    function: clearHorizontalLine

    Plots a horizontal line accross the screen. The function
    sets all pixels in a single horizontal row to 0, effectively
    drawing a clear  horizontal line at a specified y-coordinate.

    inputs:
        base   - pointer on the starting address of frame buffer
        row    - row to plot line in
    output:
        Void.
*/
void clearHorizontalLine(UINT8 *base, int y)
{
    int i;
    UINT32 *plotLocation = (UINT32 *)base + (y * 20);
    for (i = 0; i < 20; i++)
    {
        *plotLocation &= 0;
        plotLocation++;
    }
}
/*
    function: plotRectangle

    Plots a rectangle by calling plotHorizontalLine in "height" times.

    inputs:
        base   - pointer to starting address of framebuffer
        x      - horizontal coordinate
        y      - vertical coordinate
        width  - width of the rectangle
        height - the times plotHorizontalLine will be called
    output:
        Void.

*/
void plotRectangle(UINT8 *base, int x, int y, int width, int height)
{
    UINT8 *draw = base;
    int i = 0;
    int leftShift = (x % 32);
    int rightShift = (32 - ((width - (32 - leftShift)) % 32));

    for (i = 0; i < height; i++)
    {
        plotHorizontalLine(draw, y);
        draw += 20;

    }
    
    return;
}

/*
    function: clearRectangle

    Clears a rectangle by calling clearHorizontalLine in "height" times.

    inputs:
        base   - pointer to starting address of framebuffer
        x      - horizontal coordinate
        y      - vertical coordinate
        width  - width of the rectangle
        height - the times clearHorizontalLine will be called
    output:
        Void.

*/

void clearRectangle(UINT8 *base, int x, int y, int width, int height)
{
    UINT8 *clean = base;
    int i = 0;

    for (i = 0; i < height; i++)
    {
        clearHorizontalLine(clean, y);
        clean += 80;
    }

    return;
}


/*
    function: printChar

    Plots a bitmap character to the screen using font.h.
    Uses the ASCII value of the character to get its bitmap
    and renders it pixel by pixel.

    inputs:
        base   - pointer to starting address of framebuffer
        x      - horizontal coordinate
        y      - vertical coordinate
        ch     - ASCII character to be printed
    output:
        Void.

*/
void printChar(UINT8 *base, int x, int y, char ch)
{
    int i;

    UINT8 *charHexCode =(UINT8 *) GLYPH_START(ch);
    for (i = 0; i < 8; i++, charHexCode++)
    {
        *(base + (y + i) * 80 + (x >> 3)) |= *charHexCode;
    }
}
/*
    function: printString

    Prints a null-terminated string to the screen at the given (x, y) position.
    Calls printChar repeatedly, incrementing x by 8 pixels after each character.

    inputs:
        base    - pointer to framebuffer
        x       - starting x coordinate
        y       - y coordinate for baseline of text
        string  - null-terminated character array
    output:
        Void.
*/
void printString(UINT8 *base, int x, int y, char *string)
{
    int i = 0;

    while (string[i] != '\0')
    {
        printChar(base, x, y, string[i]);
        i++;
        x += 8;
    }
}
/*
    function: printNum

    Converts a 5-digit unsigned integer into characters and
    prints it to the screen using printChar. Prints leading 0s
    if number is less than 5 digits.

    inputs:
        base   - pointer to framebuffer
        x      - horizontal screen position
        y      - vertical screen position
        num    - unsigned 16-bit integer to print (0–65535)
    output:
        Void.
*/
void printNum(UINT8 *base, int x, int y, UINT16 num)
{
    char a, b, c, d, e;

    e = (num % 10) + '0';
    num /= 10;

    d = (num % 10) + '0';
    num /= 10;

    c = (num % 10) + '0';
    num /= 10;

    b = (num % 10) + '0';
    num /= 10;

    a = (num % 10) + '0';

    printChar(base, x, y, a);
    printChar(base, x + 8, y, b);
    printChar(base, x + 16, y, c);
    printChar(base, x + 24, y, d);
    printChar(base, x + 32, y, e);
}
