//Kevin Nguyen, kdn433
//re-done: 10/24/2015

#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class
/* your includes */
#include <stdio.h>
#include <ostream>
#include <istream>
#include <iostream>

using namespace std;

//main class for priority queue
template <typename Q>
class PriorityQueue : public LinkedList<Q> {
public:
	node<Q> *head = NULL;
	node<Q> *current = NULL;

	void push(Q a);
	void print();
	int getSize();



	//Sets the current list obj equal to the parameter list obj
	PriorityQueue& operator =(const PriorityQueue<Q>& list) {
		this->head = list.head;
		return *this;
	}

	//add element to pList and return it
	PriorityQueue operator +(const Q v) const {
		PriorityQueue<Q> result = *this;
		result.push(v);
		return result;
	}

	//iterate through each node to p.list and return it
	PriorityQueue operator +(const PriorityQueue<Q> list) const {	
		PriorityQueue<Q> result = *this;
		node<Q> *paraCurrent = list.head;
		while (paraCurrent != NULL) {
			result.push(paraCurrent->data);
			paraCurrent = paraCurrent->next;
		}
		return result;
	}
};

//pushes value on to prioritylist
template <typename Q>
void PriorityQueue<Q>::push(Q v) {
	int size = getSize();
	node<Q> *tmp = head;
	node<Q> *back = head;
	node<Q> *newNode = new node<Q>;
    newNode->data = v; newNode->next = NULL;
   	if (tmp == NULL){
       head = newNode;
    }
    else {
    	
    		while (tmp->next != NULL && tmp->next->data < newNode->data) { //>= newNode->data) {
    			tmp = tmp->next;
    		}
    		
    		if (tmp->data <= newNode->data && tmp->next != NULL) {
    			if (tmp->next->data > newNode->data) {
    				back = tmp->next;
    				tmp->next = newNode;
    				tmp = tmp->next;
    				tmp->next = back;
    			}
    		}
    		else if (tmp->data <= newNode->data && tmp->next == NULL) {
    			tmp->next = newNode;
    		}
 			else {			
    			back = newNode;
    			newNode->next = tmp;
    			tmp = back;
    			head = tmp;
    		}
    		
    		
    }
}

//prints the priority queue
template<typename Q>
void PriorityQueue<Q>::print() {
	node<Q> *tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

//get size of list
template <typename Q>
int PriorityQueue<Q>::getSize() {
	int iteration = 0;
	node<Q> *current = head;
	while (current != NULL) {
		++iteration;
		current = current->next;
	}
	return iteration;
}

//outstream
template <class Q>
ostream& operator << (ostream& out, const PriorityQueue<Q>& list) {
	node<Q> *tmp = list.head;
	while (tmp != NULL) {
		out << tmp->data << " "; 
		tmp = tmp->next;
	} 
	return out;
}

//in steam
template <class Q>
istream& operator >> (istream& in, PriorityQueue<Q>& list) {
	PriorityQueue<Q> newList;
	node<Q> *tmp = list.head;
	while (tmp != NULL) {
		newList.push(tmp->data);
	}
	return in;
}

#endif