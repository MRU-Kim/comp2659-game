foreach i { tst_rast raster rast_asm objects font }
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor
make
