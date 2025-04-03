foreach i { splash splsh raster }
	if { -f $i.tos }
		echo Rm $i.tos
		Rm $i.tos
	endif
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor

cd ..\stage-2

cp raster.o ..\stage-8

cd ..\stage-8

make