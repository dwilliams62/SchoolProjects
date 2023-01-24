main: main.o
	g++ -o main main.o

main.o: main.cpp PriorityQueue.h
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm -f main *.o

rebuild:
	make clean
	make

