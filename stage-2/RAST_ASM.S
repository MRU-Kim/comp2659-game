;		xdef		_clear_screen

;base		equ		8

;clearScreen:		link		a6,#0
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
