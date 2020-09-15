H1=../../include
H2=../include
H3=include

#SRCS=$(wildcard src/*.c)

# ソースのファイル名を取得
SRCFILES=$(shell find src -name *.c -printf "%f\n")

# ソースのファイル名の.cを.oに変えて、文頭にobj/を追加した文字を取得
OBJS=$(addprefix obj/, $(patsubst %.c, %.o, $(SRCFILES)))

CC=gcc
CFLAGS= -std=c11 -Wall -g -lm -pthread -I$(H1) -I$(H2) -I$(H3)

collect:$(OBJS)

$(OBJS):obj/%.o:src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -fr obj/*
