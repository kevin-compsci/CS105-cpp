/** 
Name: Kevin Nguyen
Eid: kdn433
*/

#include <iostream> /// for cout, cin
#include <fstream> /// for ifstream
#include "PriorityQueue.h" /// make sure we include our PriorityQueue
#include "LinkedList.h" // include linked list too?

using namespace std;

int main (int argc, char const **argv) {
    /* your program */
    
    //Declarations
 	PriorityQueue dataMaxP; 
 	LinkedList dataMaxL;

	int value = 0, data = 0;
	char arrayOfLetters[50], letter = cin.get(); cin.get();
	
	

	//Loop to process with data
	while(cin.getline(arrayOfLetters, 51, '\0')) {
		while (value < 50) {
			if (letter == 'l') {
				if (arrayOfLetters[value] == '+') {
					data = arrayOfLetters[value+2] - '0';
					dataMaxL.push(data);
				}
				else if (arrayOfLetters[value] == '-') {
					dataMaxL.pop();
					cout << endl;
				}
				else if (arrayOfLetters[value] == '=') {
					dataMaxL.peek();
					cout << endl;
				}
				else if (arrayOfLetters[value] == 'p') {
					dataMaxL.print();
					cout << endl;
				}
			}
			else if (letter == 'q') {
				if (arrayOfLetters[value] == '+') {
					data = arrayOfLetters[value+2] - '0';
					dataMaxP.push(data);
				}
				else if (arrayOfLetters[value] == '-') {
					dataMaxP.pop();
					cout << endl;
				}
				else if (arrayOfLetters[value] == '=') {
					dataMaxP.peek();
					cout << endl;
				}
				else if (arrayOfLetters[value] == 'p') {
					dataMaxP.print();
					cout << endl;
				}
			}
			value++;
		}
		value = 0;
	}
    return 0;
}