# -*-Makefile-*-

CC = clang
OPT = -o

all: install

run: build
	${TMPDIR}hhpp

build: main.c
	$(CC) ./main.c $(OPT) ${TMPDIR}hhpp

install:
	${CC} ./main.c ${OPT} ~/Developer/system_script/ren
	ren *