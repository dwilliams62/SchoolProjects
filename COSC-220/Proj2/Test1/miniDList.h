#ifndef MINIDLIST_H
#define MINIDLIST_H
#include <iostream>     // For cout
using namespace std;


template <class DataType> 
class miniDList{
private:
struct   DNode{	// doubly linked list node
  DataType   data;	//  data stored in node   
  DNode*   next;	//  next node in list   
  DNode*   prev;	//  previous node  in list
};

 DNode* header;	// list sentinels
 DNode* trailer;	
public:
miniDList(){                      // constructor
header = new DNode;
trailer  = new DNode;         //have them point to each other
header->next = trailer;
trailer->prev = header;
}	
miniDList(const   miniDList<DataType>&  l);  // Copy constructor
~miniDList();	// Destructor
const DataType& front() const;      // get front element
const DataType& back() const;       // get back element
void   removeFront();	// Remove the front 
void   removeBack();             // Remove the back 
void addFront(const DataType& e);       // Add to the front 
void addBack(const DataType& e);           // Add to the back
int   size()   const;	// Returns the number of elements in list
bool contains(const DataType& e);   // Tests for membership
void  display()  const;	// Prints the elements of list
 miniDList<DataType>& operator=(const miniDList<DataType>& l);   //Overloaded assignment

protected:                          //local utilities
void add(DNode * v, const DataType& e); //insert new node  before  v
void remove(DNode* v);     //remove node v
};

//implementations go below...


#endif


template <class DataType>
miniDList<DataType>::miniDList(const   miniDList<DataType>&  l)  // Copy constructor
{
  DNode* temp = l.header->next;
	while (temp->next != NULL) {
		addBack(temp->data);
		temp = temp->next;
	}
}

template <class DataType>
miniDList<DataType>::~miniDList()	// Destructor
{
  delete[] header;
}

template <class DataType>
const DataType& miniDList<DataType>::front() const      // get front element
{
  return header->next->data;
}

template <class DataType>
const DataType& miniDList<DataType>::back() const       // get back element
{
  return trailer->prev->data;
}

template <class DataType>
void   miniDList<DataType>::removeFront()	// Remove the front 
{
  DNode* temp = new DNode;
  temp = header->next;
  header->next = header->next->next;
  header->next->prev = header;
  delete temp;
}

template <class DataType>
void   miniDList<DataType>::removeBack()             // Remove the back 
{
  DNode* temp = new DNode;
  temp = trailer->prev;
  trailer->prev = trailer->prev->prev;
  trailer->prev->next = trailer;
  delete temp;
}

template <class DataType>
void miniDList<DataType>::addFront(const DataType& e)       // Add to the front 
{
  DNode* newNode = new DNode;
  newNode->data = e;
  header->next->prev = newNode;
  newNode->prev = header;
  newNode->next = header->next;
  header->next = newNode;
}

template <class DataType>
void miniDList<DataType>::addBack(const DataType& e)          // Add to the back
{
  DNode* newNode = new DNode;
  newNode->data = e;
  trailer->prev->next = newNode;
  newNode->prev = trailer->prev;
  newNode->next = trailer;
  trailer->prev = newNode;

}

template <class DataType>
int   miniDList<DataType>::size()   const	// Returns the number of elements in list
{
  int count = 0;
  DNode* temp = header->next;

  while (temp->next) {
    count++;
    temp = temp->next;
  }

  return count;
}

template <class DataType>
bool miniDList<DataType>::contains(const DataType& e)   // Tests for membership
{
  bool found = false;
  DNode* temp = header->next;

  while (temp->next && !found) {
    if (temp->data == e) {found = true;}
    temp = temp->next;
  }

  return found;
}

template <class DataType>
void  miniDList<DataType>::display()  const	// Prints the elements of list
{
  DNode* temp = header->next;
	while (temp->next != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <class DataType>
miniDList<DataType>& miniDList<DataType>::operator=(const miniDList<DataType>& l)   //Overloaded assignment
{
  while (header->next != trailer) {
    removeBack();
  }

  DNode* temp = l.header->next;
	while (temp->next != NULL) {
		addBack(temp->data);
		temp = temp->next;
	}

  return *this;
}

template <class DataType>
void miniDList<DataType>::add(DNode * v, const DataType& e) {
  DNode* newNode = new DNode;
  newNode->data = e;
  newNode->prev = v->prev;
  newNode->next = v;
  v->prev->next = newNode;
  v->prev = newNode;
}

template <class DataType>
void miniDList<DataType>::remove(DNode* v) {
  v->prev->next = v->next;
  delete v;
}