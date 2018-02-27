//Kevin Nguyen, kdn433
//redone: 10/24/2015

#ifndef __LINKED_LIST_CPP_9F4861BC
#define __LINKED_LIST_CPP_9F4861BC

/* your includes */
#include <stdio.h>
#include <ostream>
#include <istream>
#include <iostream>
using namespace std;

//Struct for generic node
template <typename T>
struct node {
public:
	T data;
	node *next;
};

//LinkedList generic class	
template <typename T>
class LinkedList : public node<T> {
public: //where functions are implemented
	node<T> *head = NULL;
	node<T> *current = NULL;

	void push(T a);
	void print();
	int getSize();

	template <class Q> friend class PriorityQueue;

	template <class Q>
	friend ostream& operator <<(ostream& out, const LinkedList<Q>& list);

	template <class Q>
	friend istream& operator >>(istream& in, LinkedList<Q>& list);

	//Sets the current list obj equal to the parameter list obj
	LinkedList& operator =(const LinkedList<T>& list) {
		this->head = list.head;
		return *this;
	}

	//Checks if every element in both lists are the same
	bool operator ==(const LinkedList<T>& list) const { //const?
		//Declarations
		bool ans = false;
		node<T> *tmp = head;
		node<T> *currentTmp = head;
		node<T> *parameterCurrent = list.head;

		while ((currentTmp->next != NULL) && (parameterCurrent->next != NULL)) {
			if (currentTmp->data == parameterCurrent->data) {
				ans = true;
			}
			else {
				ans = false; break;
			}
			currentTmp = currentTmp->next; parameterCurrent = parameterCurrent->next;
		} 
		return ans;
	}

	//iterate through and compare each node, if false return true
	bool operator !=(const LinkedList& list) {
		//Declarations
		bool ans = false;
		//obj list pointers
		node<T> *currentTmp = head;
		node<T> *tmp = head;

		//parameter list pointers
		node<T> *parameterCurrent = list.head;
		node<T> *parameterTemp = list.head;

		while ((currentTmp != NULL) && (parameterCurrent != NULL)) {
			if (currentTmp->data == parameterCurrent->data) {
				ans = true;
			}
			else {
				ans = false; break;
			}
			currentTmp = currentTmp->next; parameterCurrent = parameterCurrent->next;
		} 
		return !ans;
	}

	//Adds data to the list
	LinkedList operator +(const T v) const {
		//Declarations
		LinkedList<T> result;

		node<T> *n = new node<T>;
		n->next = NULL;
		n->data = v;

		node<T> *currentTmp = head;
		node<T> *rTmp = result.head;
		node<T> *rTmp2 = result.head;
		int iteration = 0;

		if (currentTmp != NULL) {
			if (currentTmp->next == NULL) {
				node<T> *copyNode = new node<T>;
				copyNode->data = currentTmp->data;
				copyNode->next = NULL;
				
				rTmp = copyNode;
				rTmp->next = n;			
			}
			else {
				while (currentTmp->next != NULL) {
					node<T> *copyNode = new node<T>;
					copyNode->data = currentTmp->data;
					copyNode->next = currentTmp->next;

					
						rTmp = copyNode;
						if (iteration == 0) {
							rTmp2 = rTmp; iteration++;
						}
						rTmp = rTmp->next;
						if (rTmp->next == NULL) {
							rTmp->next = n; rTmp = rTmp2; break;
						}
					currentTmp = currentTmp->next;
				}
			}
		}
		else {
			rTmp = n;
		}
		result.head = rTmp;
		return result;
	}

	//iterate through each node in list and mylist add each to list then return it
	LinkedList operator +(const LinkedList& list) const {
		//Declarations
		LinkedList<T> result, copy;
		node<T> *tmp = head;
		node<T> *paraCurrent = list.head;
		int iterations = 0;
		
		while (paraCurrent != NULL) {
			copy.push(paraCurrent->data);
			paraCurrent = paraCurrent->next;
		}
		paraCurrent = head;
		if (*this == list) {
			while (paraCurrent != NULL) {
				copy.push(paraCurrent->data);
				paraCurrent = paraCurrent->next;
			}
			result = copy;
		}
		else {
		while (tmp != NULL) {
			node<T> *copyNode1 = new node<T>;
			copyNode1->data = tmp->data;
			copyNode1->next = tmp->next;

			if (iterations == 0) {
				result.head = copyNode1; result.current = copyNode1; iterations++;
			}

			if (tmp->next != NULL) {
				result.current = result.current->next;
			}
			tmp = tmp->next;
		}
		iterations = 0;

		while (paraCurrent != NULL) {
			node<T> *copyNode2 = new node<T>;
			copyNode2->data = paraCurrent->data;
			copyNode2->next = paraCurrent->next;

			if (iterations == 0) {
				result.current->next = copyNode2; iterations++;
			}

			if (paraCurrent->next != NULL) {
				result.current = result.current->next;
			}
			else {
				result.current->next = paraCurrent;
			}
			paraCurrent = paraCurrent->next;
		}
		}	
		return result;
	}

	//iterate through and remove all instances of v
	LinkedList operator -(const T v) {
		LinkedList<T> result;
		node<T> *n = new node<T>; 
		n->next = NULL;
		n->data = v;

		node<T> *tmp = result.head;
		node<T> *tmp2 = result.head;
		node<T> *original = result.head;
		node<T> *currentTmp = head;
		int iterations = 0;

		while (currentTmp->next != NULL) {
			if (iterations == 0) {
				if (currentTmp->data != n->data) {
					node<T> *copyNode = new node<T>;
					copyNode->data = currentTmp->data;
					copyNode->next = NULL;

					tmp = copyNode; original = tmp;
					iterations++;
				}
			}
			else {
				if (currentTmp->data != n->data) {
					node<T> *copyNode = new node<T>;
					copyNode->data = currentTmp->data;
					copyNode->next = NULL;

					tmp2 = copyNode;
					tmp->next = tmp2;
					tmp = tmp->next;
					iterations++;
				}
			}
			currentTmp = currentTmp->next;
			if (currentTmp->next == NULL) {
				if (currentTmp->data != n->data) {
					node<T> *copyNode = new node<T>;
					copyNode->data = currentTmp->data;
					copyNode->next = NULL;
					tmp->next = copyNode;
				}
				tmp = original;
			}
		}
		result.head = tmp;
		return result;
	}

	//iterate through and remove all instances from current list
	LinkedList operator -(const LinkedList& list) {
		LinkedList<T> result;
		node<T> *tmp = result.head;
		node<T> *tmp2 = result.head;
		node<T> *original = result.head;
		node<T> *currentTmp = head;
		node<T> *paraCurr = list.head;
		int iterations = 0;

		while (paraCurr != NULL) {			
			while (currentTmp->next != NULL) {
				if (iterations == 0) {
					if (currentTmp->data != paraCurr->data) {
						node<T> *copyNode = new node<T>;
						copyNode->data = currentTmp->data;
						copyNode->next = NULL;
						tmp = copyNode; original = tmp;
						iterations++;
					}
				}
				else {
					if (currentTmp->data != paraCurr->data) {
						node<T> *copyNode = new node<T>;
						copyNode->data = currentTmp->data;
						copyNode->next = NULL;

						tmp2 = copyNode;
						tmp->next = tmp2;
						tmp = tmp->next;
						iterations++;
					}
				}
				currentTmp = currentTmp->next;
				if (currentTmp->next == NULL) {
					if (currentTmp->data != paraCurr->data) {
						node<T> *copyNode = new node<T>;
						copyNode->data = currentTmp->data;
						copyNode->next = NULL;
						tmp->next = copyNode;
					}
					tmp = original;
				}
				if (currentTmp->next == NULL && paraCurr != NULL) {
					currentTmp = tmp;
					iterations = 0; break;
				}
			}
			paraCurr = paraCurr->next;
		}
		result.head = tmp;
		return result;	
	}
	
	//iterate through given the index and return it…throw if out-of-bound
	T& operator [](const int index) {
		//Declarations
		node<T> *result = new node<T>;
		node<T> *currentTmp = head;
		result->next = NULL;
		int max = getSize(), iteration = 0;
		
		if (index >= max || index < 0) {
			throw -1; //throws if out-of-bounds
		}
		else {
			while (iteration < max && currentTmp != NULL) {
				if (iteration == index) {
					result->data = currentTmp->data;
					break;
				}
				currentTmp = currentTmp->next;
				iteration++;
			}
		}
		return result->data;
	}

	//Returns true if the current Node object value is “<” the parameter Node obj value
	bool operator < (const node<T>& node) const {
		return (head->data < node->data);
	}

	//Rtrns true if the current Node obj value is “<=”l the parameter Node obj value
	bool operator <= (const node<T>& node) const {
		return (head->data <= node->data);
	}

	//Returns true if the current Node obj value is “>”  than the parameter Node obj val
	bool operator > (const node<T>& node) const {
		return (head->data > node->data);
	}

	//Returns true if the current Node obj value is “>=” the parameter Node object val
	bool operator >= (const node<T>& node) const {
		return (head->data >= node->data);
	}
};

//outstream
template <class T>
ostream& operator << (ostream& out, const LinkedList<T>& list) {
	node<T> *tmp = list.head;
	while (tmp != NULL) {
		out << tmp->data << " "; 
		tmp = tmp->next;
	} 
	return out;
}

//in steam
template <class T>
istream& operator >> (istream& in, LinkedList<T>& list) {
	LinkedList<T> newList;
	node<T> *tmp = list.head;
	while (tmp != NULL) {
		newList.push(tmp->data);
	}
	return in;
}

//pushes value on to linklist
template <typename T>
void LinkedList<T>::push(T v){
	int size = getSize();
	node<T> *tmp = head;
	node<T> *newNode = new node<T>;
    newNode->data = v; newNode->next = NULL;

   	if (tmp == NULL){
       head = newNode; 
    }
    else {
    	while (tmp->next != NULL) {
    		tmp = tmp->next;
    	}
    	tmp->next = newNode;
    }
}

template<typename T>
void LinkedList<T>::print() {
	node<T> *tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

//get size of list
template <typename T>
int LinkedList<T>::getSize() {
	int iteration = 0;
	node<T> *current = head;
	while (current != NULL) {
		++iteration;
		current = current->next;
	}
	return iteration;
}

#endif