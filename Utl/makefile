collect:
	cd bit;make;

clean:
	cd bit;make clean;

lib:bit/obj/*.o
	ar rcs ../lib/libUtl.a bit/obj/*

libclean:
	rm -fr ../lib/libUtl.a
