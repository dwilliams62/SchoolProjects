#makefile for compiling Proj1 Exercise1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

NumDays.o: NumDays.cpp NumDays.h
	${CC} ${CFLAGS} -c NumDays.cpp

TimeOff.o: TimeOff.cpp TimeOff.h
	${CC} ${CFLAGS} -c TimeOff.cpp

main.o: main.cpp	 
	${CC} ${CFLAGS} -c main.cpp

main: main.o TimeOff.o NumDays.o
	${CC} ${CFLAGS} -o main main.o NumDays.o TimeOff.o

clean:
	${RM} *.o main