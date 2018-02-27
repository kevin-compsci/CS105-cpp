/** 
Name: Kevin Nguyen
Eid: kdn433

Q1: Why are the arrays passed to both print life functions const? <your answer>

Const is read only so our 2D array (grid) can't be edited. They can be accessed to
show the contents.

Q2: Why are the arrays passed to both play life functions not const? <your answer>

The arrays are not const because we need to edit them to update the 2D array with the
final results. Otherwise, the 2D array may look the same at each generation or an error
can occur if we try to edit a const 2D array.

Q3: If we did change the arrays passed to play life functions to make them const, 
	what else would have to happen to make play life work? <your answer>

We would need a global variable that wasn't a const; we would technically need some
2D array to edit. We could also hardcopy the const array into a separate 2D array for 
managing along with the game.

*/

#include <iostream>

using namespace std;

/// global constant for fixed rows and cols of the 2D array
const int NUM_ROWS = 10;
const int NUM_COLS = 10;

 //Global Declarations
int iterationsR = 0, iterationsC = 0, gameCounter = 0, gameCounterMax = 0, aliveCounters = 0, temp = 0;
bool gridCopy[NUM_ROWS][NUM_COLS];

/** function declarations
	you will need to write the definitions of these functions below.
	DO NOT MODIFY the declarations.
	You may create your own functions, but you must use these.
*/

/** 2d array functions, notice that for 2d arrays the second size 
	needs to be fixed, or more precisely it needs to be a const.
	if you typed a literal, like 5, it would be a literal constant,
	which also works.
*/
void printLife2DArray(const bool grid[][NUM_COLS]); //prints current board
void playLife2DArray(bool grid[][NUM_COLS]); //starts playing game, iterates through
void getGrid(char line[], bool grid[][NUM_COLS]); //gets grid from txt file
void getGridCopy(bool grid[][NUM_COLS]); //hard copies created grid for game use
void elementResult(int rows, int columns, int aliveCounters, bool grid[][NUM_COLS]);//GetAliveCounters --> fate of element
void updateGrid(bool grid[][NUM_COLS]);
int getAliveCounters(int rows, int columns, int aliveCounters, bool grid[][NUM_COLS]); //get number of alive
int specialCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]);
int normalCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]);
int edgeCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]);

//GetGrid function will get the 2D array for the board and make a hard copy for editing
void getgrid(char line[], bool grid[][NUM_COLS]) {
	//Local Declarations
	char c;
	int iterationsC = 0;
	while (iterationsC < NUM_COLS) {
		c = line[iterationsC];
		cout << c;
		 if ((c == '.') && ((c != '\0') || (c != 32))) {
			 grid[iterationsR][iterationsC] = false;
		 }
		else if ((c == '*') && ((c != '\0') || (c != 32))) {
			grid[iterationsR][iterationsC] = true;
		 }
		 iterationsC++;
	}
	iterationsR++;
	cout << endl;
	if (iterationsR >= 10) {
		getGridCopy(grid);
	}
}

//Get hard copy of a grid to edit
void getGridCopy(bool grid[][NUM_COLS]) {
	//Declarations
	iterationsR = 0, iterationsC = 0;

	while (iterationsR < NUM_ROWS) {
		while (iterationsC < NUM_COLS) {
			gridCopy[iterationsR][iterationsC] = grid[iterationsR][iterationsC];
			iterationsC++;
		}
		iterationsR++; iterationsC = 0;
	}
}

//Updates original grid with edited grid for next generation in game
void updateGrid(bool grid[][NUM_COLS]) {
	//Declarations
	iterationsR = 0, iterationsC = 0;

	while (iterationsR < NUM_ROWS) {
		while (iterationsC < NUM_ROWS) {
			grid[iterationsR][iterationsC] = gridCopy[iterationsR][iterationsC];
			iterationsC++;
		}
		iterationsR++; iterationsC = 0;
	}
}

int specialCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]) {
	//rows low and max limit
	if (rows <= 0) { 
		currentPosR = 0; specialRow = NUM_ROWS-1; //wrap around
	}
	else if (rows > 0) {
		currentPosR = rows-1; specialRow = rows-1;
	}

	if (rows >= NUM_ROWS-1) {
		rowMaxCheck = rows; specialRow = 0; //wrap around
	}
	else if (rows < NUM_ROWS-1) {
		rowMaxCheck = rows+1;
	}

	//columns max and low limits
	if (columns <= 0) {
		currentPosC = 0; specialCols = NUM_COLS-1; //wrap
	}
	else if (columns > 0) {
		currentPosC = columns-1; specialCols = columns-1;
	}

	if (columns >= NUM_COLS-1) {
		colMaxCheck = columns; specialCols = 0; //wrap
	}
	else if (columns < NUM_COLS-1) {
		colMaxCheck = columns+1;
	}

	//scan row that wraps around
	if ((rows == 0) || (rows == NUM_ROWS-1) && (specialRow == 0) || (specialRow == NUM_ROWS-1)) {
		while (currentPosC <= colMaxCheck) {
			if (grid[specialRow][currentPosC] == 1) {
				aliveCounters++;
			}
			currentPosC++;
		}
	}
	
	//scan columns that wrap around
	if ((columns == 0) || (columns == NUM_COLS-1) && (specialCols == 0) || (specialCols == NUM_COLS-1)) {
		while (currentPosR <= rowMaxCheck) {
			if (grid[currentPosR][specialCols] == 1) {
				aliveCounters++;
			}
			currentPosR++;
		}
	}
	return aliveCounters;
}

int normalCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]) {
	//rows low and max limit
	if (rows <= 0) { 
		currentPosR = 0; specialRow = NUM_ROWS-1; //wrap around
	}
	else if (rows > 0) {
		currentPosR = rows-1; specialRow = rows-1;
	}

	if (rows >= NUM_ROWS-1) {
		rowMaxCheck = rows; specialRow = 0; //wrap around
	}
	else if (rows < NUM_ROWS-1) {
		rowMaxCheck = rows+1;
	}

	//columns max and low limits
	if (columns <= 0) {
		currentPosC = 0; specialCols = NUM_COLS-1; //wrap
	}
	else if (columns > 0) {
		currentPosC = columns-1; specialCols = columns-1;
	}

	if (columns >= NUM_COLS-1) {
		colMaxCheck = columns; specialCols = 0; //wrap
	}
	else if (columns < NUM_COLS-1) {
		colMaxCheck = columns+1;
	}
	temp = currentPosC;

	//Normal checking, no wrap-around special checks
	while (currentPosR <= rowMaxCheck) {
		while (currentPosC <= colMaxCheck) {
			if ((grid[currentPosR][currentPosC] == 1) && ((currentPosR != rows) || (currentPosC != columns))) {
				aliveCounters++;
			}
			currentPosC++;
		}
		currentPosC = temp; currentPosR++;
	}
	return aliveCounters;
}

int edgeCases(int rows, int columns, int currentPosR, int currentPosC, int rowMaxCheck, int colMaxCheck, int specialRow, int specialCols, bool grid[][NUM_COLS]) {
	//Check corners of the board, they wrap around too
	if ((rows == 0) && (columns == 0) && (grid[NUM_ROWS-1][NUM_COLS-1] == 1)) {
		aliveCounters++;
	}
	else if ((rows == NUM_ROWS-1) && (columns == 0) && (grid[0][NUM_COLS-1] == 1)) {
		aliveCounters++;
	}
	else if ((rows == 0) && (columns == NUM_COLS-1) && (grid[NUM_ROWS-1][0] == 1)) {
		aliveCounters++;
	}
	else if ((rows == NUM_ROWS-1) && (columns == NUM_COLS-1) && (grid[0][0] == 1)) {
		aliveCounters++;
	}
	return aliveCounters;
}

//Gets number of neighbors that are alive
int getAliveCounters(int rows, int columns, int aliveCounters, bool grid[][NUM_COLS]) {
	//Declarations
	int currentPosR = rows, currentPosC = columns, rowMaxCheck = rows, colMaxCheck = columns, 
	specialRow = rows, specialCols = columns;

	aliveCounters = specialCases(rows, columns, currentPosR, currentPosC, rowMaxCheck, colMaxCheck, specialRow, specialCols, grid);
	currentPosR = rows; currentPosC = columns;
	aliveCounters = normalCases(rows, columns, currentPosR, currentPosC, rowMaxCheck, colMaxCheck, specialRow, specialCols, grid);
	aliveCounters = edgeCases(rows, columns, currentPosR, currentPosC, rowMaxCheck, colMaxCheck, specialRow, specialCols, grid);	
	return aliveCounters;
}

//Parses element to be dead or alive for next generation
void elementResult(int rowCounter, int colCounter, int aliveCounters, bool grid[][NUM_COLS]) {
	if ((aliveCounters < 2) || (aliveCounters > 3)) {
		gridCopy[rowCounter][colCounter] = 0;
	}
	else if ((aliveCounters == 3) && (aliveCounters != 2)) {
		gridCopy[rowCounter][colCounter] = 1;
	}
}

//Prints current grid of the game
void printLife2DArray(const bool grid[][NUM_COLS]) {
	//Declarations
	iterationsR = 0, iterationsC = 0;
	while (iterationsR < NUM_ROWS) {
		while (iterationsC < NUM_COLS) {
			if (grid[iterationsR][iterationsC] == false) {
				cout << '.';
			}
			else {
				cout << '*';
			}
			iterationsC++;
		}
		cout << endl;
		iterationsC = 0; iterationsR++;
	}
}

//Plays the game, all proceses found here
void playLife2DArray(bool grid[][NUM_COLS]) {
	iterationsR = 0, iterationsC = 0;
	while (iterationsR < NUM_ROWS) { 
		while (iterationsC < NUM_COLS) {
			aliveCounters = getAliveCounters(iterationsR, iterationsC, aliveCounters, grid);
			elementResult(iterationsR, iterationsC, aliveCounters, grid);
			aliveCounters = 0; iterationsC++;
		}
		iterationsC = 0; iterationsR++;
	}
	cout << endl;
}

//Main Function for program
int main() {
	//Declarations
	char line[10], number[1];
	bool grid[NUM_ROWS][NUM_COLS];
	int value = 0;

	//Gets number of iterations for game
	cin.getline(number, 2);//gets value from txt
	value = number[0] - '0'; //value to integer
	gameCounterMax = value; //Game Counter Max is global
	cout << endl;

	/// read in the number of iterations to run

	/** make a 2d bool array with the number of rows and cols
	Some input examples and explanation of game of life
	Look at http://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns
	*/

	/** print out what game we are playing */
	cout << "Game Of Life rows= " <<  NUM_ROWS  << ", cols= " << NUM_COLS << 
		  ", iterations= " << gameCounterMax << endl;
	/** 
		start your code
	*/
  
	//Make 2D Game Grid, get copy as well for managing
	while (cin.getline(line, 11)) {
		getgrid(line, grid);
	}

	//Begin Game
	while (gameCounter < gameCounterMax) {
		playLife2DArray(grid);
		updateGrid(grid);
		printLife2DArray(grid);
		gameCounter++;
	}
	return 0; /// return a ok
}