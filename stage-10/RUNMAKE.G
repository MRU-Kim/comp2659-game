foreach i { objects raster rast_asm font render model events psg music effects clock input splash isr isrAsm testIsr dino}
	if { -f $i.tos }
		echo Rm $i.tos
		Rm $i.tos
	endif
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor
Rm -f dino.o
echo -f Rm dino.o

Rm -f test10.o
echo -f Rm test10.o

make