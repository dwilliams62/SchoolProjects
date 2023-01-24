main: StackQueueTest.o
	g++ -o main StackQueueTest.o

StackQueueTest.o: StackQueueTest.cpp ListCollection.h Stack.h Queue.h
	g++ -g -Wall -std=c++11 -c StackQueueTest.cpp

clean:
	rm -f main *.o

rebuild:
	make clean
	make

