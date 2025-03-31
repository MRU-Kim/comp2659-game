foreach i { music effects psg tst_psg clock}
	if { -f $i.tos }
		echo Rm $i.tos
		Rm $i.tos
	endif
	if { -f $i.o }
		echo Rm $i.o
		Rm $i.o
	endif
endfor



cd ..\stage-5

cp clock.o ..\stage-7

cd ..\stage-7

make
