H1=../../include
H2=../include
H3=include

#SRCS=$(wildcard src/*.c)
SRCFILES=$(shell find src -name *.c -printf "%f\n")
OBJS=$(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

CC=gcc
CFLAGS= -std=c11 -Wall -g -lm -pthread -I$(H1) -I$(H2) -I$(H3)
YDB=-I/usr/local/lib/yottadb/r130 -L/usr/local/lib/yottadb/r130 -lyottadb -Wl,-rpath,/usr/local/lib/yottadb/r130

collect:$(OBJS)

$(OBJS):obj/%.o:src/%.c
	$(CC) $(CFLAGS) $(YDB) -o $@ -c $^

clean:
	rm -fr obj/*
