#makefile for compiling Lab03OYO1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

Complex.o: Complex.cpp Complex.h
	${CC} ${CFLAGS} -c Complex.cpp

main.o: main.cpp	 
	${CC} ${CFLAGS} -c main.cpp

main: main.o Complex.o
	${CC} ${CFLAGS} -o main main.o Complex.o

clean:
	${RM} *.o main
