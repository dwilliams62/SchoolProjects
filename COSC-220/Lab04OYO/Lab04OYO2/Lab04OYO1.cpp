#include <iostream>
#include "IntegerList.h"

using namespace std;

void PopulateList(IntegerList &L, int size)
{
    cout << "In Populate List" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i; 
     cout << "Out Populate List" << endl;   
}

void PopulateList2(IntegerList L, int size)
{
    cout << "In Populate List 2" << endl;
    for (int i = 0; i < size; i++)
        L[i] = i;    
     cout << "Out Populate List2" << endl;
}

int main()
{
    IntegerList l1(7);
    IntegerList l2(17);

    for (int i = 0; i < 7; i++)
        l1[i] = i * i;

    PopulateList2(l1, 7); 
    PopulateList(l2, 17);

    l1.displayList();
    l2.displayList();

    IntegerList l3(30);
    l3 = l1 + l2;
    l3.displayList();

    l3[4] = 100;
    l3.displayList();

    IntegerList l4 = l3.sublist(3, 8);
    l4.displayList();

    IntegerList l5 = l3.sublist(8);
    l5.displayList();

    IntegerList l6 = l3.sublist(3, 800);
    l6.displayList();

    l6.resize(5);
    l4.resize(30);
    l6.displayList();
    l4.displayList();

    IntegerList l7 = l3.sort();
    l3.displayList();
    l7.displayList();

    IntegerList l8 = l7;
    l8.displayList();

    return 0;
}

//2-a: The big difference between populatelist and populatelist2 is that the first uses a reference to an integerlist
//object, while the second just accepts the integerlist as a value. The difference being that the first will modify
//any data already in the integerlist. Also, populatelist2 is being called with a larger number.

//2-b:
//Entering Constructor - l3 is being constructed
//The + operator is being entered - l2 + l1 is occuring
//Entering Constructor - newList, in the + consturctor, is happening
//The + operator is being exited - l2 + l1 is finished being added
//Entering Assignment Statement - l3 = newList is occuring
//Entering Copy Constructor newlist is being copied into l3
//Entering Deconstructor - deconstructing l2
//Entering Deconstructor - deconstructing l1
//0 1 4 9 16 25 36 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 -displaying output of l3

//2-c: All four call the typical constructor using an int value

//2-d: The copy constructor is being called

