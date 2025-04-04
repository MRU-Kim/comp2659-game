	cc68x -g -c -I ../stage-2 -I ../stage-3 -I ../stage-4 -I ../stage-5 dino.c
    cc68x -g  objects.o raster.o font.o model.o events.o render.o clock.o input.o dino.o -o dino
