//Kevin Nguyen, kdn433

#ifndef __PRIORITY_QUEUE_CPP_9F4861BC
#define __PRIORITY_QUEUE_CPP_9F4861BC

#include "LinkedList.h" /// need to include the parent class
/* your includes */

using namespace std;


/* your class */
class PriorityQueue : public LinkedList {
public:
	PriorityQueue()
	: LinkedList()
	{
		//bank
	}

public: //where functions go
	void push(int addData); 
};

#endif