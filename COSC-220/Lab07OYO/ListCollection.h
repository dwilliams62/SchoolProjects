#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class ListCollection {
private:
	class Node 
	{
	public:
    	T data;
    	Node* next;
	};
	Node* head = NULL;
	bool isValid(int);

public:
	ListCollection(int sz = 10);
	~ListCollection();
	void setElement(int, T);
	T getElement(int);
	void displayList(bool nl = false) const;

	ListCollection(const ListCollection &obj);
	const ListCollection<T> operator=(const ListCollection &right);

	const ListCollection<T> operator+(const ListCollection &right);
	const ListCollection<T> sublist(int, int);
	const ListCollection<T> sublist(int);
	const ListCollection<T> sort();

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

template<class T>
ListCollection<T>::ListCollection(int size) {

}

template<class T>
ListCollection<T>::~ListCollection() {
	delete[] head;
}

template<class T>
ListCollection<T>::ListCollection(const ListCollection &obj) {
	Node* temp = obj.head;
	while (temp != NULL) {
		pushBack(temp->data);
		temp = temp->next;
	}
}

template<class T>
const ListCollection<T> ListCollection<T>::operator=(const ListCollection &right) {
	ListCollection<T> newList(0);
	Node* temp = right.head;
	while (temp != NULL) {
		newList.pushBack(temp->data);
		temp = temp->next;
	}
	return newList;
}

template<class T>
bool ListCollection<T>::isValid(int element) {
	bool status;
	int h = size();
	if (element < 0 || element >= h)
		status = false;
	else
		status = true;

	return status;
}

template<class T>
void ListCollection<T>::setElement(int element, T value) {
	if (isValid(element)) {
		Node* temp = head;
		if (element == 1) {
			pushFront(value);
		}
		else {
			int count = 0;
			while (count < element) {
				temp = temp->next;
				count++;
			}
			temp->data = value;
		}
	}
}

template<class T>
T ListCollection<T>::getElement(int pos) {
	T defaultret = 0;

	if (head == NULL)
		return defaultret;

	if (pos < 0)
		return head->data;

	if (pos >= 0)
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL) 
		{
			if (count == pos) { return temp->data;}
			else {
				temp = temp->next;
				count++;
			}
		}
	}

	return defaultret;
}

template<class T>
void ListCollection<T>::displayList(bool nl) const {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
		if (nl)
			cout << endl;
	}
	if (!nl)
		cout << endl;
}

template<class T>
const ListCollection<T> ListCollection<T>::operator+(
		const ListCollection &right) {
	ListCollection<T> newList(1);

	newList.head = head;
	Node* temp = newList.head->next;
	Node* temp2 = head->next;
	
	while (temp2 != NULL) {
		temp->data = temp2->data;
		temp = temp->next;
		temp2 = temp->next;
	}

	temp2 = right.head;

	while (temp2 != NULL) {
		temp->data = temp2->data;
		temp = temp->next;
		temp2 = temp->next;
	}

	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e) {
	if (b > e) {
		int temp = b;
		b = e;
		e = temp;
	}

	if (b < 0) {b = 0;}
	if (e < 0) {e = 0;}
	if (b >= size()) {b = size() - 1;}
	if (e >= size()) {e = size() - 1;}

	ListCollection<T> newList(e - b + 1);
	
	Node* temp = head;
	int count = 0;
	while (count < b) {
		temp = temp->next;
		count++;
	}

	newList.head = new Node;
	newList.head->data = temp->data;
	Node* newListTemp = newList.head;
	temp = temp->next;
	count++;

	while (count <= e) {
		Node* temp2 = new Node;
		temp2->data = temp->data;
		newListTemp->next = temp2;
		temp = temp->next;
		newListTemp = newListTemp->next;
		count++;
	}

	return newList;
}

template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b) {
	return sublist(b, size() - 1);
}

template<class T>
const ListCollection<T> ListCollection<T>::sort() {
	ListCollection<T> newList(0);
	int count;
	count = size();
	Node* temp1 = head;
	Node* temp2 = head;

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (temp1->data < temp2->data) {
				T tmp = temp2->data;
				temp2->data = temp1->data;
				temp1->data = tmp;
			}
			temp2 = temp2->next;
		}
		temp2 = head;
		temp1 = temp1->next;
	}
	return newList;
}

template<class T>
int ListCollection<T>::size() {
	Node* temp = head;
	int len = 0;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	return len;
}

template<class T>
int ListCollection<T>::capacity() {
	return size();
}

template<class T>
void ListCollection<T>::pushFront(T elt) {
	Node* temp = new Node;
	temp->data = elt;
	temp->next = head;
	head = temp;
}

template<class T>
void ListCollection<T>::pushBack(T elt) {
	Node* temp = new Node;
	temp->data = elt;
	temp->next = NULL;
	if (head == NULL) {head = temp;}
	else {
		Node* temp2 = head;
		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
}

template<class T>
T ListCollection<T>::popFront() {
	T defaultret = 0;
	if (head == NULL)
		return defaultret;

	T retval = head->data;

	head = head->next;

	return retval;
}

template<class T>
T ListCollection<T>::popBack() {
	T defaultret = 0;
	if (head == NULL)
		return defaultret;

	Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	T retval = temp->next->data;
	temp->next = NULL;

	return retval;
}

template<class T>
void ListCollection<T>::insertOrdred(T elt) {
	Node* current;
	Node* newNode = new Node;
	newNode->data = elt;

    if (head == NULL || head->data > newNode->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        current = head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

template<class T>
void ListCollection<T>::removeElement(T elt) {
	Node* temp = head;
	Node* var = new Node;
	var->data = elt;
	while (temp != NULL && temp->data != var->data) {
		temp = temp->next;
	}
	if (temp == NULL) {return;}
	Node* temp2 = temp->next;
	temp2 = temp2->next;
	temp->next = temp2;
}

template<class T>
void ListCollection<T>::insert(int pos, T elt) {
	if (pos >= size())
		pushBack(elt);
	else if (pos <= 0)
		pushFront(elt);
	else {
		Node* temp = head;
		int count = 0;
		while (temp->next != NULL && count != pos) {
			temp = temp->next;
			count++;
		}
		Node* newNode = new Node;
		newNode->data = elt;
		Node* temp2 = temp->next;
		temp->next = newNode;
		newNode->next = temp2;
	}
}

template<class T>
void ListCollection<T>::remove(int pos) {
	Node* temp = head;
	int count = 0;
	while (temp != NULL && count != pos - 1) {
		temp = temp->next;
		count++;
	}
	Node* temp2 = temp->next->next;
	temp->next = temp2;
}

template<class T>
void ListCollection<T>::clear() {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

#endif
