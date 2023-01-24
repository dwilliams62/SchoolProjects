#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include "ListCollection.h"

using namespace std;

template<class T>
class Stack {
    private:
        ListCollection<T> stack;

    public:
        Stack();
        ~Stack();
        void displayStack(bool nl = false) const;

        Stack(const Stack &obj);
        const Stack operator=(const Stack &right);

        void clear();
        int size();
        void push(T);
        T pop();
        bool isEmpty();
};

#endif

template<class T>
Stack<T>::Stack() {
    ListCollection<T> stack;
}

template<class T>
Stack<T>::~Stack() {}


template<class T>
void Stack<T>::displayStack(bool nl) const {
    stack.displayList(nl);
}

template<class T>
Stack<T>::Stack(const Stack &obj) {
    ListCollection<T> stack = obj.stack;
}

template<class T>
const Stack<T> Stack<T>::operator=(const Stack &obj) {
    Stack<T> newStack;
	newStack.stack = obj.stack;
    return newStack;
}

template<class T>
void Stack<T>::clear() {
    stack.clear();
}

template<class T>
int Stack<T>::size() {
    return stack.numElements;
}

template<class T>
void Stack<T>::push(T val) {
    stack.pushFront(val);
}

template<class T>
T Stack<T>::pop() {
    T newValue = stack.popFront();
    return newValue;
}

template<class T>
bool Stack<T>::isEmpty() {
    if (stack.size() == 0) {return true;}
    else {return false;}
}

