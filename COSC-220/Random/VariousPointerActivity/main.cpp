#include <iostream>
using namespace std;

int *fncl (const int*, int);
void displayArray(const int*, int);

int main() 
{
	const long SIZE = 7;
	int *A = new int[SIZE];
	int *a;
	int *b;

	for (int i = 0; i < SIZE; i++)
		A[i] = i + 1;

	int *B = fncl(A, SIZE);

	cout << "Line 19: "; displayArray(A, SIZE);
	cout << "Line 20: "; displayArray(B, SIZE);

	a=B;
	b = A+4;

	cout << "Line 25: "; cout << *a << endl;
	a += 2;
	cout << "Line 27: "; cout << *a << endl;
	cout << "Line 28: "; cout << ++(*a) << endl;
	cout << "Line 29: "; displayArray(B,SIZE);
	a++;

	cout << "Line 32: "; cout << *b << endl;
	cout << "Line 33: "; cout << *b++ << endl;
	cout << "Line 34: "; cout << *b << endl;
	cout << "Line 35: "; cout << *(b - *a + 1) << endl;

	b = --a;
	b--;
	cout << "Line 39: "; cout << *a << " " << *b << endl;

	delete[] A;
	return 0;
}

int *fncl(const int *a, int size)
{
	int *newArray = nullptr;

	if (size <= 0)
		return nullptr;

	newArray = new int[size];
	for (int index = 0; index < size; index++)
		newArray[index] = *(a+((3*index) % size));

	return newArray;
}

void displayArray(const int arr[], int size)
{
	for (int index = 0; index < size; index++)
		cout << arr[index] << " ";
	cout << endl;
}