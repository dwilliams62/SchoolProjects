#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

/*
Description: Templated Priority Queue class that uses the STL vector as the underlying
storage structure.
Note: The template class T must
1. overloaded =
2. Have a default constructor
3. Overloaded >>
4. Copy Constructor
*/

using namespace std;

// Node data type that holds the data and
// priority of the item.

template<class T>
class PQNode {
    public:
        T data;
        int priority;

    PQNode(T Data) {
        data = Data;
        priority = 1;
    }

    PQNode(T Data, int Priority) {
        data = Data;
        if (Priority < 1)
        Priority = 1;

        priority = Priority;
    }
};

template<class T>
class PriorityQueue {
    private:
        vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

    public:
        // Constructors and Destructor
        PriorityQueue();
        PriorityQueue(const PriorityQueue &obj);
        ~PriorityQueue();

        // Acessors and Mutators
        void enqueue(T Data, int Priority = 1);
        T dequeue();

        // Other Functions
        void print();
        bool isEmpty();
        void clear();
        int size();
};

#endif

template <class T>
PriorityQueue<T>::PriorityQueue() {
    
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj) {
    queue = obj.queue;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    
}


template <class T>
void PriorityQueue<T>::enqueue(T Data, int Priority) {
    PQNode<T> temp(Data, Priority);
    queue.push_back(temp);
}

template <class T>
T PriorityQueue<T>::dequeue() {
    T temp;
    if (isEmpty()) return temp;
    bool isDeleted = false;

    for (int i = 0; i < queue.size(); i++) {
        if (queue[i].priority == 3) {
            T temp = queue[i].data;
            queue.erase(queue.begin() + i);
            isDeleted = true;
            return temp;
        }
    }

    if (!isDeleted) {
        for (int i = 0; i < queue.size(); i++) {
            if (queue[i].priority == 2) {
                T temp = queue[i].data;
                queue.erase(queue.begin() + i);
                isDeleted = true;
                return temp;
            }
        } 
    }

    if (!isDeleted) {
        T temp = queue[0].data;
        queue.erase(queue.begin());
        return temp;
    }
}

template <class T>
void PriorityQueue<T>::print() {
    for (auto elem : queue) {
        cout << elem.data << " --- " << elem.priority << endl; 
    }
}

template <class T>
bool PriorityQueue<T>::isEmpty() {
    if (queue.size() == 0) {return true;}
    else return false;
}

template <class T>
void PriorityQueue<T>::clear() {
    queue.clear();
}

template <class T>
int PriorityQueue<T>::size() {
    return queue.size();
}