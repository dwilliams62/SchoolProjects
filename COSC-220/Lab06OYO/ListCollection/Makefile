#makefile for compiling Lab06OYO
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

ListCollection.o: ListCollection.cpp ListCollection.h
	${CC} ${CFLAGS} -c ListCollection.cpp

ListTest.o: ListTest.cpp	 
	${CC} ${CFLAGS} -c ListTest.cpp

main: ListTest.o ListCollection.o
	${CC} ${CFLAGS} -o main ListTest.o ListCollection.o

clean:
	${RM} *.o main
