#makefile for compiling Proj1 Exercise2
#Dylan Williams

CC = g++
CFLAGS = -g -Wall
RM = /bin/rm -f


all: main

Course.o: Course.cpp Course.h
	${CC} ${CFLAGS} -c Course.cpp

Student.o: Student.cpp Student.h
	${CC} ${CFLAGS} -c Student.cpp

main.o: main.cpp	 
	${CC} ${CFLAGS} -c main.cpp

main: main.o Student.o Course.o
	${CC} ${CFLAGS} -o main main.o Course.o Student.o

clean:
	${RM} *.o main