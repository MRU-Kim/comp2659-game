
				
				
				xdef        _asm_set_video_base

address			equ         8

VideoBaseHiMin1		equ			$FFFF8200
VideoBaseMiMin1		equ			$FFFF8202

;function: _asm_set_video_base:
;assembly implementation of set video base
;utiliziing movep.
;needs to be in superviser mode before call
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