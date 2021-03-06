﻿//Butler_Adrian_Number of Occurrences of 10 in a Linked List Project


//  I made a loop in the list that asked for the user to input a number. then i created a count program to 
//get the number of occurrences of 10 and increment count when there is a 10 . 

// ConsoleApplication16.cpp : Defines the entry point for the console application.


#include <iostream>
using namespace std;

class Node {
private:
	int data;    // different data type for other apps
	Node *next;  // the link pointer to next item
public:
	Node(int x = 0, Node * ptr = NULL); // constructor
	int getData();
	Node *getNext();
	void setData(int x);
	void setNext(Node *ptr);
};

Node::Node(int x, Node *p) { data = x; next = p; };
int Node::getData() { return data; };
Node * Node::getNext() { return next; };
void Node::setData(int x) { data = x; };
void Node::setNext(Node *ptr) { next = ptr; };

class List {
private:
	Node * head_ptr; Node *tail_ptr; int numOfItems;
public:
	List(); // constructor
	int size();       Node *getHead();      Node *getTail();
	bool isEmpty();
	Node *search(int x);         Node *itemAt(int position);
	void removeHead(); 	       void removeTail();
	void remove(int x); // delete leftmost item having x
	void insertHead(int x);       void insertTail(int x);
	void insert(Node *p, int x);
	int count(int x);



};


List::List() { head_ptr = NULL; tail_ptr = NULL; 				numOfItems = 0; };
int List::size() { return numOfItems; };
Node * List::getHead() { return head_ptr; };
Node * List::getTail() { return tail_ptr; };
bool List::isEmpty() { return (numOfItems == 0); };


Node *List::search(int x) {
	Node * currentPtr = getHead();
	while (currentPtr != NULL) {
		if (currentPtr->getData() == x)
			return currentPtr;
		else
			currentPtr = currentPtr->getNext();
	}
	return NULL;	// Now x is not, so return NULL
};


Node *List::itemAt(int position) {
	if (position<0 || position >= numOfItems)
		return NULL;
	Node * currentPtr = getHead();
	for (int k = 0; k != position; k++)
		currentPtr = currentPtr->getNext();
	return currentPtr;
};

void List::removeHead() {
	if (numOfItems == 0)
		return;
	Node * currentPtr = getHead();
	head_ptr = head_ptr->getNext();
	delete currentPtr;
	numOfItems--;
};

void List::removeTail() {
	if (numOfItems == 0)
		return;
	if (head_ptr == tail_ptr) {
		head_ptr = NULL; tail_ptr = NULL;
		numOfItems = 0; return;
	}
	Node * beforeLast = itemAt(numOfItems - 2);
	beforeLast->setNext(NULL); // beforeLast becomes last
	delete tail_ptr;   // deletes the last object 
	tail_ptr = beforeLast;
	numOfItems--;
};


void List::remove(int x) {
	if (numOfItems == 0)  return;
	if (head_ptr == tail_ptr && head_ptr->getData() == x) {
		head_ptr = NULL; tail_ptr = NULL; numOfItems = 0; return;
	}
	Node * beforePtr = head_ptr;  // beforePtr trails currentPtr
	Node * currentPtr = head_ptr->getNext();
	Node * tail = getTail();
	while (currentPtr != tail)
		if (currentPtr->getData() == x) { // x is found. Do the bypass
			beforePtr->setNext(currentPtr->getNext());
			delete currentPtr;     numOfItems--;
		}
		else {  // x is not found yet. Forward beforePtr & currentPtr.
			beforePtr = currentPtr;
			currentPtr = currentPtr->getNext();
		}
};


void List::insertHead(int x) {
	Node * newHead = new Node(x, head_ptr);
	head_ptr = newHead;
	if (tail_ptr == NULL) // only one item in list
		tail_ptr = head_ptr;
	numOfItems++;
};



void List::insertTail(int x) {
	if (isEmpty())
		insertHead(x);
	else {
		Node * newTail = new Node(x);
		tail_ptr->setNext(newTail);
		tail_ptr = newTail;  numOfItems++;
	}
};




// inserts item x after the item pointed to by p		
void List::insert(Node *p, int x) {
	Node *currentPtr = head_ptr;
	while (currentPtr != NULL && currentPtr != p)
		currentPtr = currentPtr->getNext();
	if (currentPtr != NULL) { // p is found
		Node *newNd = new Node(x, p->getNext());
		p->setNext(newNd);
		numOfItems++;
	}
};

int List::count(int x)
{
	Node *currentPtr = head_ptr;
	int count = 0;
	while (currentPtr != NULL)
	{
		if (currentPtr->getData() == x)
			count++;
		currentPtr = currentPtr->getNext();
	}
	return count;
}



int main()
{


	Node sp;
	List op;


	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> i;
		op.insertHead(i);

	}



	cout << "list " << op.size() << endl;

	cout << "occurence" << op.count(3) << endl;


	return 0;
}

