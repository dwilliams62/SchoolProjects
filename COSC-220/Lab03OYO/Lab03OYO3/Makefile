#makefile for compiling Lab03OYO1
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

coin.o: Coin.cpp
	${CC} ${CFLAGS} -c Coin.cpp

Lab03OYO3.o: Lab03OYO3.cpp	 
	${CC} ${CFLAGS} -c Lab03OYO3.cpp

main: Lab03OYO3.o Coin.o
	${CC} ${CFLAGS} -o main Lab03OYO3.o Coin.o

clean:
	${RM} *.o main