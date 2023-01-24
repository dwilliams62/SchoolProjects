#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "BinaryTree.h"

using namespace std;
using namespace std::chrono;

/* 
The tree sorting tends to be slower than the quick and merge, but still has it's uses nonetheless.
The slowest is most certainly tree, while the fastest appears to be quick
*/

template<class T>
bool sorted(T A[], int size);

template<class T>
void print(T A[], int size);

template<class T>
void outputSorted(T A[], int size);

int main() {
	bool printarrays = false;
	//printarrays = true;

	int size = 0;
	cout << "Input Array Size: ";
	cin >> size;

	int *A = new int[size];
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		A[i] = rand();

	outputSorted(A, size);

	if (printarrays)
		print(A, size);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	BinaryTree<int> bTree;
	bTree.treeSort(A, size);

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "Exe Time: " << time_span.count() << " seconds." << endl;

	if (printarrays)
		print(A, size);

	outputSorted(A, size);

	return 0;
}

//  Support functions

template<class T>
bool sorted(T A[], int size) {
	for (int i = 0; i < size - 1; i++)
		if (A[i] > A[i + 1])
			return false;

	return true;
}

template<class T>
void print(T A[], int size) {
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";

	cout << endl;
}

template<class T>
void outputSorted(T A[], int size) {
	if (sorted(A, size))
		cout << "Sorted" << endl;
	else
		cout << "Not Sorted" << endl;
}

