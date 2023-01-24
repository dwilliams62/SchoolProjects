#makefile for compiling Lab03OYO1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

IntegerList.o: IntegerList.cpp IntegerList.h
	${CC} ${CFLAGS} -c IntegerList.cpp

Lab04OYO1.o: Lab04OYO1.cpp	 
	${CC} ${CFLAGS} -c Lab04OYO1.cpp

main: Lab04OYO1.o IntegerList.o
	${CC} ${CFLAGS} -o main Lab04OYO1.o IntegerList.o

clean:
	${RM} *.o main
