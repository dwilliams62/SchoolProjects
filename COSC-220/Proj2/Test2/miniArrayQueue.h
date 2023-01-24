#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
 class miniArrayQueue {
    private:
DataType* arr;		// The array of items
int	capacity;	// The size of the current array
int	front;	// The location of the front element
int	rear;	// The location of the rear element
int queueSize;

 public:
miniArrayQueue();	// Constructor 
miniArrayQueue(const miniArrayQueue<DataType> &); // Copy Constructor
~miniArrayQueue();	//   Destructor
int   size()   const;	// get the number of elements in the queue
bool isEmpty() const;	// Check if the queue is empty
void  enqueue(const  DataType& e); //throw(QueueFull), Enqueue element at rear
void  dequeue();     //throw(QueueEmpty), dequeue element at front 
const DataType& getFront() const ;//throw(QueueEmpty), return the front element but not remove
void  printQueue()  const;	// Prints the queue from the front to the rear
miniArrayQueue<DataType>& operator=(const miniArrayQueue<DataType>&); // Assignment operator
};


//implementations go below...

#endif

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue()
{
    capacity = 10;
    queueSize = 0;
    front = 0;
    rear = 0;
    arr = new DataType[capacity];
}

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType> &obj)
{
    DataType* arr = new DataType[obj.queueSize];
    queueSize = obj.queueSize;
    for (int i = 0; i < queueSize; i++)
    {
        arr[i] = obj.arr[i];
    }
    capacity = obj.capacity;
    front = 0;
    rear = queueSize - 1;
}

template <class DataType>
miniArrayQueue<DataType>::~miniArrayQueue()
{

}

template <class DataType>
int miniArrayQueue<DataType>::size() const
{
    return queueSize;
}

template <class DataType>
bool miniArrayQueue<DataType>::isEmpty() const
{
    if (queueSize == 0) {return true;}
    else {return false;}
}

template <class DataType>
void miniArrayQueue<DataType>::enqueue(const DataType& e)
{
    if (queueSize == capacity) {throw;}
    else {
        arr[queueSize] = e;
        queueSize++;
        rear++;
    }
}

template <class DataType>
void miniArrayQueue<DataType>::dequeue()
{
    if (queueSize == 0) {throw;}
    else {
        for (int i = 0; i < queueSize; i++) {
            arr[i] = arr[i+1];
        }
        queueSize--;
        rear--;
    }
}

template <class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const
{
    if (isEmpty()) {throw;}
    else {return arr[0];}
}

template <class DataType>
void miniArrayQueue<DataType>::printQueue() const
{
    for (int i = 0; i < queueSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class DataType>
miniArrayQueue<DataType>& miniArrayQueue<DataType>::operator=(const miniArrayQueue<DataType> &right) {
	delete[] arr;
	capacity = right.capacity;
    queueSize = right.queueSize;
	DataType* arr = new DataType[capacity];
	for (int i = 0; i < capacity; i++) \
    { 
        arr[i] = right.arr[i];
    }
	return *this;
}