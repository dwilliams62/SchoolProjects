#makefile for compiling Lab05IL
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

PersonData.o: PersonData.cpp PersonData.h
	${CC} ${CFLAGS} -c PersonData.cpp

CustomerData.o: CustomerData.cpp CustomerData.h
	${CC} ${CFLAGS} -c CustomerData.cpp

main.o: main.cpp	 
	${CC} ${CFLAGS} -c main.cpp

main: main.o CustomerData.o PersonData.o
	${CC} ${CFLAGS} -o main main.o PersonData.o CustomerData.o

clean:
	${RM} *.o main