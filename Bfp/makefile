OBJS=exec/obj/bfpmain.o alm/obj/Bfpalmdrive.o com/obj/Bfpcommod.o com/obj/Bfpcomcreatedafacs.o
INCS=-Iinclude -Ialm/include -Icom/include -I../include
YDB=-I/usr/local/lib/yottadb/r130 -L/usr/local/lib/yottadb/r130 -lyottadb -Wl,-rpath,/usr/local/lib/yottadb/r130

collect:
	cd alm;make;
	cd com;make;
	cd exec;make;

clean:
	cd alm;make clean;
	cd com;make clean;
	cd exec;make clean;

exec:exec/obj/bfpmain.o
	gcc -std=gnu11 $(OBJS) $(INCS) -Wall -g -L../lib -lUdv -lDaf -lUtl $(YDB) -o bin/Bfpmainproc

execclean:
	rm -fr bin/*
