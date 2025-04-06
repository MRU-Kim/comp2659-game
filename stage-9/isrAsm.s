
        xdef _vblIsr,_IkbrIsr
        xref _incVbCounter
        xref _addBuff

MFPBYTE equ $FFFFFA11
IKBRREAD equ $00FFFC02

_vblIsr:
    link    a6,#0
    movem.l d0-d3/a0-a2,-(sp)
    
    jsr _incVbCounter

	movem.l	(sp)+,d0-d3/a0-a2
    unlk    a6
    rte

_IkbrIsr:
	link    a6,#0
	movem.l d0-d1/a0-1,-(sp)
	lea     IKBRREAD,a0
	clr.l   d0
	move.b  (a0),d0
	move.w  d0,-(sp)
	jsr     _addBuff
	move.w  (sp)+,d0
	lea     $FFFFFA11,a1
	move.b	(a1),d1
	and.b   $BF,d1
	move.b	d1,(a1)
	movem.l (sp)+,d0-d1/a0-1
	unlk    a6
	rte