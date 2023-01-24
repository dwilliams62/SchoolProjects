#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;


template <class DataType>
 class miniArrayStack{
private:
enum {DEF_CAPACITY =100}; 	//default stack capacity
DataType* arr;	// The array of items
int	capacity;	// The size of the current array
int	top;	// The location of the top element
int stackSize;
 

 public:
 miniArrayStack (int cap= DEF_CAPACITY);	// Constructor for ArrStack
miniArrayStack(const miniArrayStack<DataType> &); 	// Copy contstructor
~miniArrayStack();	// Destructor
int  size()  const;	// get the number of elements in the stack
 bool isEmpty() const;	// Check if the stack is empty
const DataType& getTop() const; //throw(StackEmpty);       //get the top emement without popping it
void push(const DataType&); //throw(StackFull);	// Pushes  an  object  onto  the  stack
void pop() ;//throw(StackEmpty);	// Pop an object off the stack 
 void  printStack()  const;	// Prints the stack from the top, down
miniArrayStack<DataType>& operator=(const  miniArrayStack<DataType>&);  //  Assignment  operator
};

//implementations go below...


#endif

template <class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap)
{
    capacity = cap;
    stackSize = 0;
    top = 0;
    arr = new DataType[capacity];
}

template <class DataType>
miniArrayStack<DataType>::miniArrayStack(const miniArrayStack<DataType> &obj)
{
    DataType* arr = new DataType[obj.capacity];
    stackSize = obj.stackSize;
    for (int i = 0; i <= stackSize; i++)
    {
        arr[i] = obj.arr[i];
    }
    capacity = obj.capacity;
    top = 0;
}

template <class DataType>
miniArrayStack<DataType>::~miniArrayStack()
{

}

template <class DataType>
int miniArrayStack<DataType>::size() const
{
    return stackSize;
}

template <class DataType>
bool miniArrayStack<DataType>::isEmpty() const
{
    if (stackSize == 0) {return true;}
    else {return false;}
}

template <class DataType>
void miniArrayStack<DataType>::push(const DataType& e)
{
    if (stackSize == capacity) {throw;}
    else {
        if (stackSize == 0) {
            arr[0] = e;
        }
        else {
            for (int i = stackSize; i > 0; i--) {
            arr[i] = arr[i-1];
            }
            arr[0] = e;
        }
        stackSize++;
    }
}

//
template <class DataType>
void miniArrayStack<DataType>::pop()
{
    if (stackSize == 0) {throw;}
    else {
        for (int i = 0; i < stackSize; i++) {
            arr[i] = arr[i+1];
        }
        stackSize--;
    }
}

template <class DataType>
const DataType& miniArrayStack<DataType>::getTop() const
{
    if (isEmpty()) {throw;}
    else {return arr[0];}
}

template <class DataType>
void miniArrayStack<DataType>::printStack() const
{
    for (int i = 0; i < stackSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class DataType>
miniArrayStack<DataType>& miniArrayStack<DataType>::operator=(const miniArrayStack<DataType> &right) {
	delete[] arr;
	capacity = right.capacity;
    stackSize = right.stackSize;
	DataType* arr = new DataType[capacity];
	for (int i = 0; i < capacity; i++) \
    { 
        arr[i] = right.arr[i];
    }
	return *this;
}