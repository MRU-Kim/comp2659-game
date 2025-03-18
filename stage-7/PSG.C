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

#include "PSG.H"

/*
-------------------------------------------------------------------
    function: writePsg

    Writes to the given PSG registers with the given value.

    input:
        reg  -  value of PSG register.
        val  -  value to be written to the given register.
    output:
        Void.
-------------------------------------------------------------------
*/
UINT8 value = 0x3F;

void writePsg(int reg, UINT8 val) {
    volatile char *regSelect = PSGSelectAddress;
    volatile char *regWrite = PSGWriteAddress;
    long oldSsp = Super(0);

    if (reg >= 0 && reg <= 15) {
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
UINT8 readPsg(int reg) {
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
void setTone(int channel, int tuning) {
    int fineTune, coarseTune, fineReg, coarseReg;
    int fineRegisters[] = {AFine, BFine, CFine};
    int coarseRegisters[] = {ACoarse, BCoarse, CCoarse};

    if (channel >= ChannelA && channel <= ChannelC) {
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

    Initializes the game's Plane struct with starting properties 

    input:
        model  -   pointer to the game's Model struct
    output:
        Void.
-------------------------------------------------------------------
*/
void setNoise(int tuning) {
    writePsg(NoiseReg, tuning);
    
    printf("setNoise\n");

    return;
}

/*
-------------------------------------------------------------------
    function: set_volume

    Sets the volume level for a specified audio channel in the PSG
    the volume value is passed as a paramenter, and the funcation
    writes it to the corresponding PSG register.

    input:
        channel -   audio channel to adjust
        volume  -   desired volume level
    output:
        Void.
-------------------------------------------------------------------
*/
void setVolume(int channel, int volume) {
    
    writePsg(channel+ GotoVolume, volume);

   /**printf("set_volume\n");*/

    return;
}

/*
-------------------------------------------------------------------
    function: set_envelope

    Configures the envelope and sustain level for the PSG. 
    Writes to the PSG to set the envelope's shape and sustain.

    input:
        shape   -  envelope's shape
        sustain -  The sustain level
    output:
        Void.
-------------------------------------------------------------------
*/
void setEnvelope(int shape, unsigned int sustain) {
    writePsg(1, 1);

    printf("setEnvelope\n");

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
void enableChannel(int channel, int toneOn, int noiseOn) {
    /* UINT8 value = 0x3F; */
    if (toneOn == ON) {
        value = value & ~(1 << channel);
    }

    if (noiseOn == ON) {
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
void stopSound(){
    writePsg(Mixer,0x3F);
}
