Rm -f rast_asm.o test8.o test8 raster.o

cc68x -g -c test8.c
cc68x -g -c raster.c
gen -D -L2 -o rast_asm.s

cc68x -g rast_asm.o test8.o raster.o font.o -o test8