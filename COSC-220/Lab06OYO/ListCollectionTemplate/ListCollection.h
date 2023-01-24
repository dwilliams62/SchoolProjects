#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class ListCollection
{
  private:
    T *list;                 // Pointer to the array.
    int numElements;           // Number of elements.
    int numCapacity;           // Maximum number of elements.
    bool isValid(T) const;   // Validates subscripts.
    void resize(int);          // Resizes list, moved to private.
    
  public:
    ListCollection(int sz = 10);   // Constructor
    ~ListCollection();             // Destructor
    void setElement(int, T);     // Sets an element to a value
    int getElement(int) const;     // Returns an element
    void displayList(bool nl = false) const;      // Display list

    ListCollection(const ListCollection &obj);
    const ListCollection operator=(const ListCollection &right);

    // Updated functions
    const ListCollection operator+(const ListCollection &right);
    const ListCollection sublist(int, int);
    const ListCollection sublist(int);
    const ListCollection sort();
    
    // New functions
    void clear();
    int size();
    int capacity();
    void pushFront(T);
    void pushBack(T);
    T popFront();
    T popBack();
    void insertOrdred(T);
    void removeElement(T);
    void insert(int, T);
	  void remove(int);
};

#endif

//check if the element number is in the list
template <typename T>
bool ListCollection<T>::isValid(T element) const 
{
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}

//resize the list to be a new specific size, keeping the content and adding 0's if bigger than before
template <typename T>
void ListCollection<T>::resize(int num)
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

    list = new T[num];
    for (int i = 0; i < num; i++)
    {
        list[i] = newList.list[i];
    }

    numElements = num;
    while (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//costructor
template <typename T>
ListCollection<T>::ListCollection(int size) 
{
	list = new T[size];
	numElements = 0;
    numCapacity = size;
	for (int ndx = 0; ndx < size; ndx++)
		list[ndx] = 0;
    
}

//deconstructor
template <typename T>
ListCollection<T>::~ListCollection() 
{
	delete[] list;
}

//set an element at a specific position
template <typename T>
void ListCollection<T>::setElement(int element, T value) 
{
	if (element <= 0) {list[0] = value;}
    if (element >= numElements) {list[numElements] = value;}
    if (element > 0 && element < numElements) {list[element] = value;}
}

//retrieve an element at a specific position
template <typename T>
int ListCollection<T>::getElement(int element) const 
{
	if (element <= 0) {return list[0];}
    if (element >= numElements) {return list[numElements - 1];}
    return list[element];
}

//print out the list in either vertical or horizontal format
template <typename T>
void ListCollection<T>::displayList(bool nl) const 
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
template <typename T>
ListCollection<T>::ListCollection(const ListCollection<T> &obj) 
{
	numElements = obj.numElements;
    numCapacity = obj.numCapacity;
	list = new T[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = obj.list[i];
}

//overload the = operator to act like a copy constructor
template <typename T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection<T> &right)
{
	delete[] list;
	numElements = right.numElements;
    numCapacity = right.numCapacity;
	list = new T[numElements];
	for (int i = 0; i < numElements; i++)
		list[i] = right.list[i];

	return *this;
}

//overload the + operator to work with two ListCollection objects
template <typename T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection<T> &right)
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
template <typename T>
const ListCollection<T> ListCollection<T>::sublist(int num1, int num2)
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
template <typename T>
const ListCollection<T> ListCollection<T>::sublist(int num1)
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
template <typename T>
const ListCollection<T> ListCollection<T>::sort()
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
template <typename T>
void ListCollection<T>::clear()
{
    delete[] list;
    numElements = 0;
}

//return the amount of elements in the list
template <typename T>
int ListCollection<T>::size()
{
    return numElements;
}

//return the current max capacity of the list
template <typename T>
int ListCollection<T>::capacity()
{
    return numCapacity;
}

//put a new element at the start of the list and push back the rest
template <typename T>
void ListCollection<T>::pushFront(T n)
{
    ListCollection newList(numElements + 1);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i+1] = list[i];
    }
    newList.list[0] = n;
    list = new T[numElements + 1];
    for (int i = 0; i <= numElements; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//put a new element at the end of the list
template <typename T>
void ListCollection<T>::pushBack(T n)
{
    ListCollection newList(numElements + 1);
    for (int i = 0; i < numElements; i++)
    {
        newList.list[i] = list[i];
    }
    newList.list[numElements] = n;
    list = new T[numElements + 1];
    for (int i = 0; i <= numElements; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//remove the first element and return it
template <typename T>
T ListCollection<T>::popFront()
{
    T tempValue = list[0];
    ListCollection newList(numElements - 1);
    for (int i = 0; i < numElements - 1; i++)
    {
        newList.list[i] = list[i+1];
    }
    list = new T[numElements - 1];
    for (int i = 0; i < numElements - 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements--;
    return tempValue;
}

//remove the last element and return it
template <typename T>
T ListCollection<T>::popBack()
{
    T tempValue = list[numElements - 1];
    ListCollection newList(numElements - 1);
    for (int i = 0; i < numElements - 1; i++)
    {
        newList.list[i] = list[i];
    }
    list = new T[numElements - 1];
    for (int i = 0; i < numElements - 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements--;
    return tempValue;
}

//insert a new element into the list where it belongs in order
template <typename T>
void ListCollection<T>::insertOrdred(T n)
{
    if (numElements == 0)
    {
        list = new T[1];
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
        list = new T[numElements + 1];
        for (int i = 0; i < numElements + 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements++;
        if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
    }

}

//search for the first instance of an element and remove it
template <typename T>
void ListCollection<T>::removeElement(T n)
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
        list = new T[numElements - 1];
        for (int i = 0; i < numElements - 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements--;
    }
}

//insert an element into a position given
template <typename T>
void ListCollection<T>::insert(int element, T value) 
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
    list = new T[numElements + 1];
    for (int i = 0; i < numElements + 1; i++)
    {
        list[i] = newList.list[i];
    }
    numElements++;
    if (numElements > numCapacity) {numCapacity = numCapacity * 2;}
}

//remove an element at a position
template <typename T>
void ListCollection<T>::remove(int n)
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
        list = new T[numElements - 1];
        for (int i = 0; i < numElements - 1; i++)
        {
            list[i] = newList.list[i];
        }
        numElements--;
    }
}
