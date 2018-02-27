/** 
Name: Kevin Nguyen
Eid: kdn433
*/

#include <iostream>

using namespace std; /// so we don't need to prefix cout,cin,endl methods with std

const int MAX_ARRAY_SIZE = 256; /// How big our max sized line can be

/** declare our functions */
char getHighestFrequency(char c[]);
int getFrequencyCount(const char c[], char matchChar);

/**
    Given a line, find the character with the highest occurence
*/
char getHighestFrequency(char line[]) {
  //Declarations
  int iteration = 0, occurance = 0, highOccurance = 0;
	char currentChar, oldChar, resultChar;

  //loop through each element in array but only process alphabet chars
	while (iteration < 256) {   	 
    currentChar = line[iteration];
    if (currentChar != '\0' && ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z')) || currentChar == 32) {
      if (currentChar != 32) {
        occurance = getFrequencyCount(line, currentChar);   	
		    if (occurance > highOccurance) {
          highOccurance = occurance;
          oldChar = currentChar;
          resultChar = currentChar;
        }
        else if (occurance <= highOccurance) {
          currentChar = oldChar;
          resultChar = oldChar;
        }
        else if ((occurance = highOccurance) && ((int) currentChar < ((int) oldChar))) {
          resultChar = currentChar;
        }
        else if ((occurance = highOccurance) && ((int) currentChar > ((int) oldChar))) {
          resultChar = oldChar;
        }
      }
    }
    else {
      iteration = 9999999; //get out of loop
    }
    ++iteration;
  }
	return resultChar;
}

/**
    Given a character, count each occurrence of the char
*/
int getFrequencyCount(const char line[], char matchChar) {
	//Declarations
  int iteration = 0, occurances = 0;

  //while loop to iterate through array elements and count if match was found
  while (iteration < 256) {
    if ((tolower(line[iteration]) == ((int) matchChar)) || (toupper(line[iteration]) == ((int) matchChar)) || (((int) line[iteration]) == ((int) matchChar)) && (((line[iteration] >= 'A') && (line[iteration] <= 'Z')) || ((line[iteration] >= 'a') && (line[iteration] <= 'z')))) {
      occurances++; //match? then +1 to occurances
    }
    else if (line[iteration] == '\0') {
      iteration = 9999999; //stop loop
    }
    ++iteration;
	}
	return occurances;
}

/* Read the input using cin.
   Use cout or printf to print the char and count.
   Remember that you must also create(and use) the method getHighestFrequency
*/
int main(int argc, char *argv[]) {
  //Declarations
  int iteration = 0, occurances = 0;
	char arrayOfLetters[MAX_ARRAY_SIZE], letter;

	//reads line by line, each line is an array of chars, output best freq and count
	while(cin.getline(arrayOfLetters, MAX_ARRAY_SIZE)) {
    letter = getHighestFrequency(arrayOfLetters);
    if (((((int) letter) >= 'A') && (((int) letter) <= 'Z')) || ((((int) letter) >= 'a') && (((int) letter) <= 'z'))) {
		  occurances = getFrequencyCount(arrayOfLetters, letter);		
		  cout << ((char) tolower(letter)) << " " << occurances << endl;
		}
    iteration++;
	}
  return 0;
}