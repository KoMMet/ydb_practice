OBJS=exec/obj/bfpmain.o alm/obj/Bfpalmdrive.o com/obj/Bfpcommod.o
INCS=-Iinclude -Ialm/include -Icom/include

collect:
	cd alm;make;
	cd com;make;
	cd exec;make;

clean:
	cd alm;make clean;
	cd com;make clean;
	cd exec;make clean;

exec:exec/obj/bfpmain.o
	gcc $(OBJS) $(INCS) -L../lib -lUdv -o bin/Bfpmainproc

execclean:
	rm -fr bin/*
