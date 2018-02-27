//Kevin Nguyen, kdn433

#include "LinkedList.h" /// include the header file for the linked list
#include <stddef.h> //To use NULL
#include <iostream> /// for cout, cin

using namespace std;

/* your class implementation*/

//constructor
LinkedList::LinkedList() {
	head = NULL;
	current = NULL;
	temp = NULL;
}

//function definitions below
//Push node onto list
void LinkedList::push(int addData) { 
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;
	if (head != NULL) {
		current = head; 
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = n;
	}
	else {
		head = n;
	}
}

//pop node from end of list
void* LinkedList::pop() {
	temp = head;
	current = head;
	cout << head->data; //prints original head;
	current = current->next; //current is head, relink to next node and make it new head
	head = current; //new head is identified, both current and head point to same node
	temp->next = NULL; //destroy link from previous head
	temp = current;//temp now points to new head of list too
}

//peeks at the tail of the list
void* LinkedList::peek() {
	cout << head->data;
}

//prints entire list in order from head to tail
void LinkedList::print() {
	current = head;
	while (current != NULL) {
		cout << current->data;
		current = current->next;
	}
}

//gets the number of nodes in a linked list
int LinkedList::size() {
	int counter = 0;
	current = head;
	while (current != NULL) {
		counter++;
		current = current->next;
	}
	return counter;
}
