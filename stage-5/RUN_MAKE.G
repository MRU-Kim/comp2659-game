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

cd ..\stage-2

cp objects.o raster.o font.o "..\stage-5"


cd ..\stage-3

cp model.o events.o "..\stage-5"

cd ..\stage-4

cp render.o "..\stage-5"


cp render.o "..\stage-5"

cd ..\stage-7

cp music.o "..\stage-5"
cp psg.o "..\stage-5"
cp effects.o "..\stage-5"



cd ..\stage-5

cc68x -g -c -I ../stage-2 -I ../stage-3 -I ../stage-4 input.c


make