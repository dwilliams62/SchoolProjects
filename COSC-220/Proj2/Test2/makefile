main: proj2Test.o
	g++ -o main proj2Test.o

proj2Test.o: proj2Test.cpp miniArrayQueue.h miniArrayStack.h miniDList.h miniDListQueue.h miniDListStack.h RuntimeException.h
	g++ -g -Wall -std=c++11 -c proj2Test.cpp

clean:
	rm -f main *.o

rebuild:
	make clean
	make

