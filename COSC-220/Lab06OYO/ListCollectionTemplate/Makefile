#makefile for compiling Lab06OYO
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

ListTest.o: ListTest.cpp	 
	${CC} ${CFLAGS} -c ListTest.cpp

main: ListTest.o
	${CC} ${CFLAGS} -o main ListTest.o

clean:
	${RM} *.o main
