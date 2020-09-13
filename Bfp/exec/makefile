H1=../../include
H2=../include
H3=include

#SRCS=$(wildcard src/*.c)
SRCFILES=$(shell find src -name *.c -printf "%f\n")
OBJS=$(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

CC=gcc
CFLAGS= -std=gnu11 -Wall -g -lm -lpthread -I$(H1) -I$(H2) -I$(H3)

collect:$(OBJS)

$(OBJS):obj/%.o:src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -fr obj/*
