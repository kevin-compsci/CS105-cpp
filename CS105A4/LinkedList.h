//Kevin Nguyen, kdn433

#ifndef __LINKED_LIST_CPP_9F4861BC
#define __LINKED_LIST_CPP_9F4861BC

/* your includes */
using namespace std;


class LinkedList {
protected: //where functions go
	typedef struct node {
		int data;
		node *next;
	} * nodePtr;

	nodePtr head;
	nodePtr current;
	nodePtr temp;

public: //where functions go
	LinkedList();	
	void push(int addData); 
	void* pop(); 
	void* peek();
	void print();
	int size();
};

#endif