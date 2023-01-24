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

PreferredCustomer.o: PreferredCustomer.cpp PreferredCustomer.h
	${CC} ${CFLAGS} -c PreferredCustomer.cpp

main.o: main.cpp	 
	${CC} ${CFLAGS} -c main.cpp

main: main.o PreferredCustomer.o CustomerData.o PersonData.o 
	${CC} ${CFLAGS} -o main main.o PreferredCustomer.o PersonData.o CustomerData.o

clean:
	${RM} *.o main