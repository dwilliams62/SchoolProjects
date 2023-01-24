main: tokencpp.o
	g++ -o main tokencpp.o

tokencpp.o: tokencpp.cpp
	g++ -g -Wall -std=c++11 -c tokencpp.cpp

clean:
	rm -f main *.o

rebuild:
	make clean
	make

