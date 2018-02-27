/** 
Name: Kevin Nguyen
Eid: kdn433
*/

#include <iostream> /// for cout, cin
#include <fstream> /// for ifstream

using namespace std;

//Global Declarations
int rowCounter = 0, rowMax = 0, colCounter = 0, colMax = 0, arrayType = 0, wordCounter = 0, i = 0;
char *lineCopy, **gridCopy;

/** function declarations
    you will need to write the definitions of these functions below.
    DO NOT MODIFY the declarations.
    You may create your own functions, but you must use these.
*/
char* findMatch1D(char* line, char* word, const int rows, const int columns);
void print1D(char* line, const int rows, const int columns);
char** findMatch2D(char** grid, char* word, const int rows, const int columns);
void print2D(char** grid, const int rows, const int columns);

/**
    1D array version
    Use pointer arithmetic to go through the array
    input:  char*: board
            char*: a word
            int: num rows
            int: num cols
    output: char*: the solution board
*/
char* findMatch1D(char* line, char* word, const int rows, const int columns) {
    rowCounter = 0; colCounter = 0;
    while (rowCounter < rows) {
        while (colCounter < columns) {
            for (wordCounter = 0; ((word[wordCounter] != '\0') && (wordCounter < 100)); wordCounter++) {          
                if (((int) line[rowCounter*rows+colCounter+i]) != ((int) word[wordCounter])) {
                    lineCopy[rowCounter*rows+colCounter+i] = '.';
                }
                else if (((int) line[rowCounter*rows+colCounter+i]) == ((int) word[wordCounter])) {
                    lineCopy[rowCounter*rows+colCounter+i] = line[rowCounter*rows+colCounter+i];
                    wordCounter = 100;
                }
            }
            colCounter++;
        }
        rowCounter++; colCounter = 0; i++;
    }    
}

/**
    print the board
    1D array version
    Use pointer arithmetic to go through the array
    input:  char*: board
            int: num rows
            int: num cols
*/
void print1D(char* line, const int rows, const int columns) {
    rowCounter = 0; colCounter = 0; i = 0;
    while (rowCounter < rows) {
        while (colCounter < columns) {
            cout << lineCopy[rowCounter*rows+colCounter+i];
            colCounter++;
        }
        rowCounter++; colCounter = 0; i++; cout << endl;
    }
}

/**
    2D array version
    Use array indexing to go through the array
    input:  char**: board
            char*: a word
            int: num rows
            int: num cols
    output: char**: the solution board
*/
char** findMatch2D(char** grid, char* word, const int rows, const int columns) {
    rowCounter = 0; colCounter = 0;
    while (rowCounter < rows) {
        while (colCounter < columns) {
            for (wordCounter = 0; ((word[wordCounter] != '\0') && (wordCounter < 100)); wordCounter++) {          
                if (((int) grid[rowCounter][colCounter]) != ((int) word[wordCounter])) {
                    gridCopy[rowCounter][colCounter] = '.';
                }
                else if (((int) grid[rowCounter][colCounter]) == ((int) word[wordCounter])) {
                    gridCopy[rowCounter][colCounter] = grid[rowCounter][colCounter];
                    wordCounter = 100;
                }
            }
            colCounter++;
        }
        rowCounter++; colCounter = 0; i++;
    }
}

/**
    print the board
    2D array version
    input:  char**: board
            int: num rows
            int: num cols
*/
void print2D(char** grid, const int rows, const int columns) {
    rowCounter = 0; colCounter = 0;
    while (rowCounter < rows) {
        while (colCounter < columns) {
            cout << gridCopy[rowCounter][colCounter];
            colCounter++;
        }
        rowCounter++; colCounter = 0; cout << endl;
    }
}


int main(int argc, char const **argv) {    
    /* get the word and the filename from our command line input
        This can be done using input file stream (ifstream) which is an input
         stream (istream). cin is also a (istream), so once you get you file
         stream you can use it nearly the same as cin
        int i;
        ifstream file("nameOfYourFile");
        file >> i; 
    */
    /// read in filename from command line argument
    /// read in word from command line argument
    /// read in board dimensions from file
    /// read in 1D or 2D array file (1 for 1D, 2 for 2D)
    /// read in board from file
    /** 
        your code
    */

    //Local Declarations
    char filename[100], word[100]; char *textLine, *line, **grid;
    ifstream file;

    //Prints out user prompt
    cout << "Enter word: "; cin >> word;
    cout << "Enter file name: "; cin >> filename;
       
    //collects data from file
    file.open(filename);
    file >> rowMax >> colMax >> arrayType;
    file.getline(0,0); //gets white space?
    cout << endl;

    //get char array from txt file
    textLine = new char[colMax];

    if (arrayType == 1) {
        //get 1D array space
        line = new char[rowMax*rowMax+colMax];
        lineCopy = new char[rowMax*rowMax+colMax];
    }
    else {
        //get 2D array space
        grid = new char *[rowMax];
        gridCopy = new char *[rowMax];
        while (rowCounter < rowMax) {
            grid[rowCounter] = new char [colMax];
            gridCopy[rowCounter] = new char [colMax];
            rowCounter++;
        }
        rowCounter = 0;
    }

    //Read and fill original dynamic arrays with content, copy will be edited;
    while (file.getline(textLine, colMax+1) && rowCounter < rowMax) { 
        while (colCounter < colMax) {
            if (arrayType == 1) {
                line[rowCounter*rowMax+colCounter+i] = textLine[colCounter];    
            }
            else {
                grid[rowCounter][colCounter] = textLine[colCounter];
            }
            colCounter++;
        }
        rowCounter++; colCounter = 0; i++;
    }
    rowCounter = 0; colCounter = 0; i = 0;

    //Process match and delete arrays after use
    if (arrayType == 1) {
        findMatch1D(line, word, rowMax, colMax);
        print1D(line, rowMax, colMax);
        delete[] line, lineCopy;
    }
    else {
        findMatch2D(grid, word, rowMax, colMax);
        print2D(grid, rowMax, colMax);
        for (rowCounter = 0; rowCounter < rowMax; rowCounter++) {
            delete[] grid[rowCounter], gridCopy[rowCounter];
        }
        delete grid, gridCopy;
    }
    delete[] textLine; cout << endl;

    //gets prints data
    cout << "Rows: " << rowMax << endl << "Cols: " << colMax << endl << "Array Type: " << arrayType << endl << "Word: " << word << endl;    
    return 0; /// return a ok
}