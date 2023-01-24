#makefile for compiling Lab06OYO
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

FeetInches.o: FeetInches.cpp FeetInches.h
	${CC} ${CFLAGS} -c FeetInches.cpp

ListTest.o: ListTest.cpp	 
	${CC} ${CFLAGS} -c ListTest.cpp

main: ListTest.o FeetInches.o
	${CC} ${CFLAGS} -o main ListTest.o FeetInches.o

clean:
	${RM} *.o main
