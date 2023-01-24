#include "ListCollection.h"

//check if the element number is in the list
bool ListCollection::isValid(int element) const 
{
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

//resize the list to be a new specific size, keeping the content and adding 0's if bigger than before
void ListCollection::resize(int num)
{
    ListCollection newList(num);

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

    numElements = num;
    while (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//costructor
ListCollection::ListCollection(int size) 
{
	list = new int[size];
	numElements = 0;
    numCapacity = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
    
}

//deconstructor
ListCollection::~ListCollection() 
{
	delete[] list;
}

//set an element at a specific position
void ListCollection::setElement(int element, int value) 
{
	if (element <= 0) {list[0] = value;}
    if (element >= numElements) {list[numElements] = value;}
    if (element > 0 && element < numElements) {list[element] = value;}
}

//retrieve an element at a specific position
int ListCollection::getElement(int element) const 
{
	if (element <= 0) {return list[0];}
    if (element >= numElements) {return list[numElements - 1];}
    return list[element];
}

//print out the list in either vertical or horizontal format
void ListCollection::displayList(bool nl) const 
{
    if (nl)
    {
        for (int i = 0; i < numElements; i++)
        {
            cout << list[i] << endl;
        }
    }

    if (!nl)
    {
        for (int i = 0; i < numElements; i++)
		{
            cout << list[i] << " ";
        }
    }

	cout << endl;
}

//copy constructor
ListCollection::ListCollection(const ListCollection &obj) 
{
	numElements = obj.numElements;
    numCapacity = obj.numCapacity;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

//overload the = operator to act like a copy constructor
const ListCollection ListCollection::operator=(const ListCollection &right)
{
	delete[] list;
	numElements = right.numElements;
    numCapacity = right.numCapacity;
	list = new int[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

//overload the + operator to work with two ListCollection objects
const ListCollection ListCollection::operator+(const ListCollection &right)
{
    int tempSize = numElements + right.numElements;
    ListCollection newList(tempSize);
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

//return a list with the elements between two positions in the original list
const ListCollection ListCollection::sublist(int num1, int num2)
{
    if (num2 > numElements) {num2 = numElements;}
    if (num1 < 0) {num1 = 0;}
    ListCollection newList(num2 - num1 + 1);
    int tempCount = 0;
    for (int i = num1; i <= num2; i++)
    {
        newList.list[tempCount] = list[i];
        tempCount++;
    }
    newList.numElements = num2 - num1 + 1;
    return newList;
}

//return a list with the elements from the position given onwards
const ListCollection ListCollection::sublist(int num1)
{
    if (num1 > numElements) {num1 = numElements;}
    if (num1 < 0) {num1 = 0;}
    ListCollection newList(numElements - num1);
    int tempCount = 0;
    for (int i = num1; i < numElements; i++)
    {
        newList.list[tempCount]= list[i];
        tempCount++;
    }
    newList.numElements = numElements - num1;
    return newList;
}

//sort the list
const ListCollection ListCollection::sort()
{
    ListCollection newList(numElements);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i] = list[i];
        newList.numElements++;
        if (newList.numElements > newList.numCapacity) {newList.numCapacity = newList.numCapacity * 2;}
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

//clear all data from the list
void ListCollection::clear()
{
    delete[] list;
    numElements = 0;
}

//return the amount of elements in the list
int ListCollection::size()
{
    return numElements;
}

//return the current max capacity of the list
int ListCollection::capacity()
{
    return numCapacity;
}

//put a new element at the start of the list and push back the rest
void ListCollection::pushFront(int n)
{
    ListCollection newList(numElements + 1);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i+1] = list[i];
    }
    newList.list[0] = n;
    list = new int[numElements + 1];
    for (int i = 0; i <= numElements; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//put a new element at the end of the list
void ListCollection::pushBack(int n)
{
    ListCollection newList(numElements + 1);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i] = list[i];
    }
    newList.list[numElements] = n;
    list = new int[numElements + 1];
    for (int i = 0; i <= numElements; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//remove the first element and return it
int ListCollection::popFront()
{
    int tempValue = list[0];
    ListCollection newList(numElements - 1);
    for (int i = 0; i < numElements - 1; i++)
    {
        newList.list[i] = list[i+1];
    }
    list = new int[numElements - 1];
    for (int i = 0; i < numElements - 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements--;
    return tempValue;
}

//remove the last element and return it
int ListCollection::popBack()
{
    int tempValue = list[numElements - 1];
    ListCollection newList(numElements - 1);
    for (int i = 0; i < numElements - 1; i++)
    {
        newList.list[i] = list[i];
    }
    list = new int[numElements - 1];
    for (int i = 0; i < numElements - 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements--;
    return tempValue;
}

//insert a new element into the list where it belongs in order
void ListCollection::insertOrdred(int n)
{
    if (numElements == 0)
    {
        list = new int[1];
        list[0] = n;
        numElements++;
    }
    else
    {
        bool added = false;
        ListCollection newList(numElements + 1);
        for (int x = 0; x < numElements + 1; x++)
        {
            if (added)
            {
                newList.list[x] = list[x - 1];
            }
            if (list[x] > n && !added) 
            {
                newList.list[x] = n;
                added = true;
            }       
            if (!added && x < numElements)
            {
                newList.list[x] = list[x];
            }
            if (!added && x == numElements)
            {
                newList.list[x] = n;
            }
        }
        list = new int[numElements + 1];
        for (int i = 0; i < numElements + 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements++;
        if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
    }

}

//search for the first instance of an element and remove it
void ListCollection::removeElement(int n)
{
    bool found = false;
    ListCollection newList(numElements - 1);
    for (int x = 0; x < numElements - 1; x++)
    {
        if (list[x] == n) 
        {
            found = true;
        }       
        if (!found)
        {
            newList.list[x] = list[x];
        }
        if (found)
        {
            newList.list[x] = list[x+1];
        }
    }
    if (found)
    {
        list = new int[numElements - 1];
        for (int i = 0; i < numElements - 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements--;
    }
}

//insert an element into a position given
void ListCollection::insert(int element, int value) 
{
	bool added = false;
    ListCollection newList(numElements + 1);
    if (element > numElements) {element = numElements;}
    for (int x = 0; x < numElements + 1; x++)
    {
        if (added)
        {
            newList.list[x] = list[x - 1];
        }
        if (x == element) 
        {
            newList.list[x] = value;
            added = true;
        }       
        if (!added)
        {
            newList.list[x] = list[x];
        }
    }
    list = new int[numElements + 1];
    for (int i = 0; i < numElements + 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//remove an element at a position
void ListCollection::remove(int n)
{
    bool found = false;
    ListCollection newList(numElements - 1);
    for (int x = 0; x < numElements - 1; x++)
    {
        if (x == n) 
        {
            found = true;
        } 
        if (found)
        {
            newList.list[x] = list[x+1];
        }      
        if (!found)
        {
            newList.list[x] = list[x];
        }
    }
    if (found)
    {
        list = new int[numElements - 1];
        for (int i = 0; i < numElements - 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements--;
    }
}