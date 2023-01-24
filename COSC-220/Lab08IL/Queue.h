#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include "ListCollection.h"

using namespace std;

template<class T>
class Queue {
    private:
        ListCollection<T> queue;

    public:
        Queue();
        ~Queue();
        void displayQueue(bool nl = false) const;

        Queue(const Queue &obj);
        const Queue operator=(const Queue &right);

        void clear();
        int size();
        void enqueue(T);
        T dequeue();
        bool isEmpty();
};

#endif

template<class T>
Queue<T>::Queue() {
    ListCollection<T> queue;
}

template<class T>
Queue<T>::~Queue() { }

template<class T>
void Queue<T>::displayQueue(bool nl) const {
    queue.displayList(nl);
}

template<class T>
Queue<T>::Queue(const Queue &obj) {
    ListCollection<T> queue = obj.queue;
}

template<class T>
const Queue<T> Queue<T>::operator=(const Queue &obj) {
    Queue<T> newQueue;
    newQueue.queue = obj.queue;
    return newQueue;
}

template<class T>
void Queue<T>::clear() {
    queue.clear();
}

template<class T>
int Queue<T>::size() {
    return queue.size();
}

template<class T>
void Queue<T>::enqueue(T val) {
    queue.pushBack(val);
}

template<class T>
T Queue<T>::dequeue() {
    T newValue = queue.popFront();
    return newValue;
}

template<class T>
bool Queue<T>::isEmpty() {
    if (queue.size() == 0) {return true;}
    else {return false;}
}

