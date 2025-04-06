				xdef        _asm_set_video_base

address			equ         8

VideoBaseHiMin1		equ			$FFFF8200
VideoBaseMiMin1		equ			$FFFF8202

_asm_set_video_base:
			link		a6,#0
			movem.l		d0-d3/a0-a1,-(sp)
			move.l		#VideoBaseHiMin1,a0
			
			move.l		address(a6),d0
			lsr.l		#8,d0
			movep.w		d0,1(a0)
			

			movem.l	(sp)+,d0-d3/a0-a1
			unlk	a6
			rts

;		xdef		_clearScreen

;base		equ		8

;_clearScreen:		link		a6,#0
;					movem.l		d0-1/a0,-(sp)
;					movea.l		base(a6),a0
;					move.w		#7999,d0
;					clr.l		d1
;clearScreenloop:	move.l		d1,(a0)+        
;					dbra		d0,clear_loop
;					movem.l		(sp)+,d0-1/a0
;					unlk		a6
;					rts
; recall: cc68x assumes d0-2/a0-2 are *not* preserved across subroutine calls!
