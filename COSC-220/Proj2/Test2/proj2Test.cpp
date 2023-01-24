#include <iostream>
#include "miniDList.h"
#include "miniDListQueue.h"
#include "miniDListStack.h"
#include "miniArrayQueue.h"
#include "miniArrayStack.h"

using namespace std;

int main() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "HomeMade Program For Testing" << endl;
	cout << "First Up Is Doubly Linked List" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniDList<int> l1;
	l1.addFront(1);
	l1.addFront(2);	
	l1.addFront(3);
	l1.addFront(4);
	l1.display();
	cout << l1.size() << endl;
	cout << endl;

	l1.addBack(1);
	l1.addBack(2);
	l1.addBack(3);
	l1.addBack(4);
	l1.display();
	cout << l1.size()  << endl;
	cout << endl;

	l1.removeFront();
	l1.removeBack();
	l1.display();
	cout << l1.size() << endl;
	cout << endl;


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "ArrayStack Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniArrayStack<int> iArrS; 
	iArrS.push(4);
	iArrS.push(3);
	iArrS.push(2);
	iArrS.push(1);
	iArrS.printStack();
	cout << endl;

	cout<< iArrS.getTop()<<endl;
	iArrS.printStack();

	iArrS.pop();
	iArrS.pop();
	iArrS.printStack();


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "ArrayQueue Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniArrayQueue<double> dArrQ;
	dArrQ.enqueue(50);
	dArrQ.enqueue(60);
	dArrQ.enqueue(70);
	dArrQ.printQueue();

	cout<< dArrQ.getFront()<<endl;
	dArrQ.printQueue();

	miniArrayQueue<double> dArrQ2;
	dArrQ2 = dArrQ;
	dArrQ2.printQueue();

	dArrQ.dequeue();
	dArrQ.dequeue();
	dArrQ.printQueue();


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "DListStack Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniDListStack<double> dDLStack;
	dDLStack.push(7.5);
	dDLStack.push(5.0);
	dDLStack.push(2.5);
	dDLStack.push(0.0);
	dDLStack.printStack();

	cout<< dDLStack.top() <<endl;
	dDLStack.printStack();

	dDLStack.pop();
	dDLStack.printStack();


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "DListQueue Tester" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	miniDListQueue<int> iDLQ;
	iDLQ.enqueue(3);
	iDLQ.enqueue(4);
	iDLQ.enqueue(6);
	iDLQ.printQueue();

	cout<< iDLQ.front()<<endl;
	iDLQ.printQueue();

	miniDListQueue<int> iDLQ2=iDLQ;
	iDLQ2.printQueue();

	iDLQ.dequeue();
	iDLQ.dequeue();
	iDLQ.printQueue();
	iDLQ.dequeue();
	iDLQ.dequeue();		


	return 0;
}
