prog: ListTest.o FeetInches.o
	g++ -o prog ListTest.o FeetInches.o

ListTest.o: ListTest.cpp ListCollection.h
	g++ -g -Wall -std=c++11 -c ListTest.cpp

FeetInches.o: FeetInches.cpp FeetInches.h
	g++ -g -Wall -std=c++11 -c FeetInches.cpp

clean:
	rm -f prog *.o

rebuild:
	make clean
	make

