main: tokencpp.o
	g++ -o main tokencpp.o

tokencpp.o: tokencpp.cpp ListCollection.h Stack.h Queue.h
	g++ -g -Wall -std=c++11 -c tokencpp.cpp

clean:
	rm -f main *.o

rebuild:
	make clean
	make

