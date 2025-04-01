/*
-----------------------------------------------------------------------------
Names           Talah Al-Zamel, Ethan Sigfusson, Kim Carino
Course name     COMP 2659-002
Stage           Stage 7
Deadline        March 17, 2024
File name       PSG.C
Professor       Steve Kalmar
-----------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------
    Description:
        The file provides the functions with the PSG on the Atari ST
        It allows setting tones, noise, volume, and envelope configurations
        for sound generation.
-----------------------------------------------------------------------------
*/

#include "CONST7.h"
#include "..\stage-2\CONST.H"
#include "PSG.H"

/*
-------------------------------------------------------------------
    function: writePsg

    Loads the given PSG registers with the given value.

    input:
        reg  -  value of PSG register.
        val  -  value to be written to the given register.
    output:
        Void.
-------------------------------------------------------------------
*/
void writePsg(int reg, UINT8 val)
{
    volatile char *regSelect = PSGSelectAddress;
    volatile char *regWrite = PSGWriteAddress;
    long oldSsp = Super(0);

    if (reg >= 0 && reg <= 15)
    {
        *regSelect = reg;
        *regWrite = val;
    }

    Super(oldSsp);

    return;
}
/*
-------------------------------------------------------------------
    function: readPsg
    -
    input:
        reg  -  value of PSG register.
    output:
        Void.
-------------------------------------------------------------------
*/
UINT8 readPsg(int reg)
{
    /* optional */
    return reg;
}

/*
-------------------------------------------------------------------
    function: setTone

    Sets the given channel's tone with the given tuning value.

    input:
        channel  -   valid value of channel
        tuning   -   12-bit tuning value
    output:
        Void.
-------------------------------------------------------------------
*/
void setTone(int channel, int tuning)
{
    int fineTune, coarseTune, fineReg, coarseReg;
    int fineRegisters[] = {AFine, BFine, CFine};
    int coarseRegisters[] = {ACoarse, BCoarse, CCoarse};

    if (channel >= ChannelA && channel <= ChannelC)
    {

        fineReg = fineRegisters[channel];
        coarseReg = coarseRegisters[channel];

        fineTune = tuning & 0x0FF;
        coarseTune = tuning >> 8;

        writePsg(fineReg, fineTune);
        writePsg(coarseReg, coarseTune);
    }

    return;
}

/*
-------------------------------------------------------------------
    function: setNoise

    Sets the NoiseReg tone with the given tuning value.

    input:
        tuning  -
    output:
        Void.
-------------------------------------------------------------------
*/
void setNoise(int tuning)
{
    if (0 <= tuning && tuning <= 31)
    {
        writePsg(NoiseReg, tuning);
    }
    return;
}

/*
-------------------------------------------------------------------
    function: set_volume

    Sets the volume level of an audio channel in the PSG.
    The volume value is passed as a paramenter, and the function
    writes it to the corresponding PSG register.

    input:
        channel -   audio channel to adjust
        volume  -   desired volume level
    output:
        Void.
-------------------------------------------------------------------
*/
void setVolume(int channel, int volume)
{

    writePsg(channel + GotoVolume, volume);

    return;
}

/*
-------------------------------------------------------------------
    function: set_envelope

    Configures the envelope and sustain level for the PSG.
    Writes to the PSG to set the envelope's shape and sustain for channel B.

    HOLD - Holds at max or min volume
    ALT  - Alternate between high and low
    ATT  - Gradual increase to full vol
    CONT - Continuous loop

    input:
        shape   -  gives the register with the given shape
        sustain -  16-bit value loaded into the fine and
                    coarse envelope register
    output:
        Void.
-------------------------------------------------------------------
*/
void setEnvelope(UINT8 shape, UINT16  sustain)
{
    UINT16 fine = 0x00FF & sustain;
    UINT16 coarse = sustain >> 8;

    writePsg(EnvelopeShape, shape);
    writePsg(EnvelopeFine, fine);
    writePsg(EnvelopeCoarse, coarse);
    return;
}

/*
-------------------------------------------------------------------
    function: enable_channel

    Enables a specified audio channel's tone and noise
    in the PSG. Adjusts the mixer register to control the
    tone or noise for the active channel.

    input:
        channel - audio channel.
        tone_on - tone state (on/off)
        noise_on - noise state (on/off)
    output:
        Void.
-------------------------------------------------------------------
*/
void enableChannel(UINT16 channel, int toneOn, int noiseOn)
{
    UINT16 value;

    if (channel == ChannelA)
    {
        value = 1;
    }
    else if(channel == ChannelB)
    {
        value = 2;
    }
    else if(channel == ChannelC)
    {
        value = 4;
        /*printf("jbkfgdbjkfdsuijkh\n");*/

    }
    else
    {
        value = 0;
    }
    /*return of both noise and tone are on, else shift value for noise, else use value*/
    if (toneOn && noiseOn )
    {
        return;
    }
    else if (!(toneOn && noiseOn))
    {
        value = 0;
    }
    else if (noiseOn)
    {
        value = value << 3;
    }
    /*printf("%x\n", value);*/
    writePsg(Mixer, value);

    return;
}

/*
-------------------------------------------------------------------
    function: stopSound

    End the sound.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void stopSound()
{
    writePsg(Mixer, 0x3F);
    return;
}
