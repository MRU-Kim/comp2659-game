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
    Writes to the PSG to set the envelope's shape and sustain.

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
void setEnvelope(int shape, unsigned int sustain)
{
    int fine = 0x00F & sustain;
    int coarse = sustain >> 8;

    UINT8 shapeMask = 0x00;

    switch (shape) 
    {
        case Hold:
            if (sustain > 0) 
            {
                shapeMask |= MaskHold;
            }
            break;

        case Alt:
            if (sustain > 0) 
            {
                shapeMask |= MaskAlt;
            }
            break;
        
        case Att:
            if (sustain > 0) 
            {
                shapeMask |= MaskAtt;
            }
            break;

        case Cont:
            if (sustain > 0) 
            {
                shapeMask |= MaskCont;
            }
            break;
        
        default:
            break;
    }
    
    writePsg(EnvelopeShape, shapeMask);
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
void enableChannel(int channel, int toneOn, int noiseOn)
{
    UINT8 value = 0x3F;
    if (toneOn == ON)
    {
        value = value & ~(1 << channel);
    }

    if (noiseOn == ON)
    {
        value = value & ~(1 << channel + 3);
    }

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
