foreach i { splash splsh raster input objects font}
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
cp objects.o font.o ..\stage-8

cd ..\stage-5
cp input.o ..\stage-8

cd ..\stage-8

make