Rm -f rast_asm.o test8.o test8

cc68x -g -c test8.c

gen -D -L2 -o rast_asm.s

cc68x -g rast_asm.o test8.o -o test8