//Kevin Nguyen, kdn433

#include "PriorityQueue.h" /// include the header file for the priority queue

/* your class implementation*/
#include <stddef.h> //To use NULL
#include <iostream> /// for cout, cin

using namespace std;

/* your class implementation*/

//function definitions below
//Push node onto list
void PriorityQueue::push(int addData) { 
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;
	if (head != NULL) {
		current = head; 
		while (current != NULL) {
			if (current->data > n->data) {
				n->next = head;
				head = n;
			}
			else if (current->data < n->data && current->next == NULL) {
				current->next = n;
			}
			else if (current->data < n->data && current->next != NULL) {
			 	n->next = current->next;
			 	current->next = n;
			 	break;
			}
			current = current->next;
		}
	}
	else {
		head = n;
	}
}
