#ifndef MINIDLISTSTACK_H
#define MINIDLISTSTACK_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
 class miniDListStack{
private:
miniDList<DataType> list;
class StackEmpty : public RuntimeException{
public:
    StackEmpty(const string& err):RuntimeException(err){}
};
 public:
miniDListStack();        // Constructor for ListStack
miniDListStack(const miniDListStack<DataType> &); 	// Copy contstructor
~miniDListStack();	// Destructor
int  size()  const;	// get the number of elements in the stack
bool isEmpty() const;	// Check if the stack is empty
const DataType& top() const ;//throw(StackEmpty);       //get the top emement without popping it
void push(const DataType&);	// Pushes  an  object  onto  the  stack
void pop(); //throw(StackEmpty);	// Pop an object off the stack 
 void  printStack()  const;	// Prints the stack from the top, down
miniDListStack<DataType>& operator=(const  miniDListStack<DataType>&);  //  Assignment  operator
};


//implementations go below...

#endif

template <class DataType>
miniDListStack<DataType>::miniDListStack()        // Constructor for ListStack
{

}

template <class DataType>
miniDListStack<DataType>::miniDListStack(const miniDListStack<DataType> &obj) 	// Copy contstructor
{
    list = obj.list;
}

template <class DataType>
miniDListStack<DataType>::~miniDListStack()	// Destructor
{

}

template <class DataType>
int  miniDListStack<DataType>::size()  const	// get the number of elements in the stack
{
    return list.size();
}

template <class DataType>
bool miniDListStack<DataType>::isEmpty() const	// Check if the stack is empty
{
    if (list.size() == 0) {return true;}
    else {return false;}
}

template <class DataType>
const DataType& miniDListStack<DataType>::top() const //throw(StackEmpty)       //get the top emement without popping it
{
    if (isEmpty()) {throw;}
    return list.front();
}

template <class DataType>
void miniDListStack<DataType>::push(const DataType& e)	// Pushes  an  object  onto  the  stack
{
    list.addFront(e);
}

template <class DataType>
void miniDListStack<DataType>::pop() //throw(StackEmpty)	// Pop an object off the stack 
{
    list.removeFront();
}

template <class DataType>
void  miniDListStack<DataType>::printStack()  const	// Prints the stack from the top, down
{
    list.display();
}

template <class DataType>
miniDListStack<DataType>& miniDListStack<DataType>::operator=(const  miniDListStack<DataType>& obj)  //  Assignment  operator
{
    miniDListStack<DataType> newStack;
    newStack.list = obj.list;
    return newStack;
}