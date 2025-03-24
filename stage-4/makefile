Stage-2 = objects.o raster.o font.o
Stage-3 = model.o events.o
Stage-4 = tst_rnd.o render.o
DEPENDNACIES =  $(Stage-2) $(Stage-3) $(Stage-4)


tst_rnd: $(DEPENDNACIES)
	cc68x -g $(DEPENDNACIES) -o tst_rnd

tst_rnd.o: tst_rnd.c
	cc68x -g -c -I ../stage-2 -I ../stage-3 tst_rnd.c

render.o: render.c
	cc68x -v -g -c -I ../stage-2 -I ../stage-3 render.c