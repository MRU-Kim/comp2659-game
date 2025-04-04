foreach i {raster font objects model events render clock input dino}
	if { -f $i.tos }
		echo Rm $i.tos
		Rm $i.tos
	endif
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor

Rm dino.o
echo Rm dino.o

Rm dino
echo Rm dino

cd ..\stage-2
cp objects.o raster.o font.o "..\stage-6"


cd ..\stage-3
cp model.o events.o "..\stage-6"


cd ..\stage-4
cp render.o render.o  "..\stage-6"

cd ..\stage-5
cp input.o clock.o "..\stage-6"

cd ..\stage-6

cc68x -g -c -I ../stage-2 -I ../stage-3 -I ../stage-4 -I ../stage-5 dino.c
make