#makefile for compiling Lab03OYO1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

Circle.o: Circle.cpp Circle.h
	${CC} ${CFLAGS} -c Circle.cpp

Lab03OYO1.o: Lab03OYO1.cpp	 
	${CC} ${CFLAGS} -c Lab03OYO1.cpp

main: Lab03OYO1.o Circle.o
	${CC} ${CFLAGS} -o main Lab03OYO1.o Circle.o

clean:
	${RM} *.o main
