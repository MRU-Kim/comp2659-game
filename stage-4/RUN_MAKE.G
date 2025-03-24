foreach i {tst_rnd raster font objects model events render }
	if { -f $i.tos }
		echo Rm $i.tos
		Rm $i.tos
	endif
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor
Rm tst_rnd.o

cd ..
cd stage-2

cp objects.o raster.o font.o "..\stage-4"


cd ..
cd stage-3

cp model.o events.o "..\stage-4"

cd ..
cd stage-4

cc68x -g -c -I ../stage-2 ../stage-3 render.c
make