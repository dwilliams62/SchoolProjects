#makefile for compiling Lab03OYO1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

NumberArray.o: NumberArray.cpp
	${CC} ${CFLAGS} -c NumberArray.cpp

Lab03OYO2.o: Lab03OYO2.cpp	 
	${CC} ${CFLAGS} -c Lab03OYO2.cpp

main: Lab03OYO2.o NumberArray.o
	${CC} ${CFLAGS} -o main Lab03OYO2.o NumberArray.o

clean:
	${RM} *.o main
