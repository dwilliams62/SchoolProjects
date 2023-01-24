#include <iostream>
#include <cstdlib>
#include "IntegerList.h"

using namespace std;

IntegerList::IntegerList(int size) {
	list = new int[size];
	numElements = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
}

IntegerList::~IntegerList() {
	delete[] list;
}

IntegerList::IntegerList(const IntegerList &obj) {
	numElements = obj.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

const IntegerList IntegerList::operator=(const IntegerList &right) {
	delete[] list;
	numElements = right.numElements;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

bool IntegerList::isValid(int element) const {
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

void IntegerList::setElement(int element, int value) {
	if (element <= 0) {list[0] = value;}
    if (element >= numElements) {list[numElements] = value;}
    if (element > 0 && element < numElements) {list[element] = value;}
}

int IntegerList::getElement(int element) const 
{
	if (element <= 0) {return list[0];}
    if (element >= numElements) {return list[numElements - 1];}
    return list[element];
}

void IntegerList::displayList() const {
	for (int i = 0; i < numElements; i++)
		cout << list[i] << " ";
	cout << endl;
}

int& IntegerList::operator[](const int &sub) 
{
	if (sub < 0) {return list[0];}
    else if (sub >= numElements) {return list[numElements - 1];}
    else {return list[sub];}
}

const IntegerList IntegerList::operator+(const IntegerList &right)
{
    int tempSize = numElements + right.numElements;
    IntegerList newList(tempSize);
    int tempCount = 0;
    
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i] = list[i];
    }
    for (int i = numElements; i < tempSize; i++)
    {
        newList.list[i] = right.list[tempCount];
        tempCount++;
    }

    return newList;
}

void IntegerList::resize(int num)
{
    IntegerList newList(num);

    if (num < numElements)
    {
        for (int i = 0; i < num; i++)
        {
            newList.list[i] = list[i];
        }
    }
    else if (num == numElements)
    {
        for (int i = 0; i < numElements; i++)
        {
            newList.list[i] = list[i];
        }
    }
    else if (num > numElements)
    {
        for (int i = 0; i < numElements; i++)
        {
            newList.list[i] = list[i];
        }
        for (int i = numElements; i < num; i++)
        {
            newList.list[i] = 0;
        }
    }

    list = new int[num];
    for (int i = 0; i < num; i++)
    {
        list[i] = newList.list[i];
    }
}

const IntegerList IntegerList::sublist(int num1, int num2)
{
    if (num2 > numElements) {num2 = numElements;}
    if (num1 < 0) {num1 = 0;}
    IntegerList newList(num2 - num1 + 1);
    int tempCount = 0;
    for (int i = num1; i <= num2; i++)
    {
        newList.list[tempCount] = list[i];
        tempCount++;
    }
    return newList;
}

const IntegerList IntegerList::sublist(int num1)
{
    if (num1 > numElements) {num1 = numElements;}
    if (num1 < 0) {num1 = 0;}
    IntegerList newList(numElements - num1);
    int tempCount = 0;
    for (int i = num1; i < numElements; i++)
    {
        newList.list[tempCount]= list[i];
        tempCount++;
    }
    return newList;
}

const IntegerList IntegerList::sort()
{
    IntegerList newList(numElements);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i] = list[i];
    }

    for (int i = 0; i < numElements; i++)
    {
        for (int n = 0; n < numElements - 1; n++)
        {
            if (newList.list[n] > newList.list[n+1])
            {
                int temp = newList.list[n + 1];
                newList.list[n + 1] = newList.list[n];
                newList.list[n] = temp;
            }
        }
    }

    return newList;
}
