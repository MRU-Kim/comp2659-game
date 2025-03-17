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
    function: write_psg

    Writes to the given PSG registers with the given value.

    input:
        reg  -  value of PSG register.
        val  -  value to be written to the given register.
    output:
        Void.
-------------------------------------------------------------------
*/
UINT8 value = 0x3F;

void write_psg(int reg, UINT8 val) {
    volatile char *reg_select = PSG_SELECT_ADDRESS;
    volatile char *reg_write = PSG_WRITE_ADDRESS;
    long old_ssp = Super(0);

    if (reg >= 0 && reg <= 15) {
        *reg_select = reg;
        *reg_write = val; 
    }
    
    Super(old_ssp);
    
    return;
}
/*
-------------------------------------------------------------------
    function: read_psg
    -
    input:
        reg  -  value of PSG register.
    output:
        Void.
-------------------------------------------------------------------
*/
UINT8 read_psg(int reg) {
    /* optional */
    return reg;
}

/*
-------------------------------------------------------------------
    function: set_tone

    Sets the given channel's tone with the given tuning value.

    input:
        channel  -   valid value of channel
        tuning   -   12-bit tuning value
    output:
        Void.
-------------------------------------------------------------------
*/
void set_tone(int channel, int tuning) {
    int fine_tune, coarse_tune, fine_reg, coarse_reg;
    int fine_registers[] = {A_FINE, B_FINE, C_FINE};
    int coarse_registers[] = {A_COARSE, B_COARSE, C_COARSE};

    if (channel >= CHANNEL_A && channel <= CHANNEL_C) {
        fine_reg = fine_registers[channel];
        coarse_reg = coarse_registers[channel];

        fine_tune = tuning & 0x0FF;
        coarse_tune = tuning >> 8;

        write_psg(fine_reg, fine_tune);
        write_psg(coarse_reg, coarse_tune);
    }
    
    return;
}

/*
-------------------------------------------------------------------
    function: set_noise

    Initializes the game's Plane struct with starting properties 

    input:
        model  -   pointer to the game's Model struct
    output:
        Void.
-------------------------------------------------------------------
*/
void set_noise(int tuning) {
    write_psg(NOISE_REG, tuning);
    
    printf("set_noise\n");

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
void set_volume(int channel, int volume) {
    
    write_psg(channel+ GOTO_VOLUME, volume);

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
void set_envelope(int shape, unsigned int sustain) {
    write_psg(1, 1);

    printf("set_envelope\n");

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
void enable_channel(int channel, int tone_on, int noise_on) {
    /* UINT8 value = 0x3F; */
    if (tone_on == ON) {
        value = value & ~(1 << channel);
    }

    if (noise_on == ON) {
        value = value & ~(1 << channel + 3);
    }

    write_psg(MIXER, value);

    return;
}

/*
-------------------------------------------------------------------
    function: stop_sound

    End the sound.

    input:
        None.
    output:
        Void.
-------------------------------------------------------------------
*/
void stop_sound(){
    write_psg(MIXER,0x3F);
}
