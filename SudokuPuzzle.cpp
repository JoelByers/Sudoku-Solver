#include "SudokuPuzzle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

SudokuPuzzle::SudokuPuzzle(int width){
    SudokuPuzzle::width = width;
    SudokuPuzzle::sqrtOfWidth = (int)sqrt(width);

    // Initialize Puzzle
    puzzle = new int*[width];
    for(int i = 0; i < width; i++){
        puzzle[i] = new int[width];
        for(int j = 0; j < width; j++){
            puzzle[i][j] = 0;
        }
    }

    // Initialize Possible numbers
    possibleValues = new bool**[width];
    for(int i = 0; i < width; i++){
        possibleValues[i] = new bool*[width];
        
        for(int j = 0; j < width; j++){
            possibleValues[i][j] = new bool[width];
            for(int k = 0; k < width; k++){
                possibleValues[i][j][k] = false;
            }
        }
    }

    // Initialize Puzzle
    givenValues = new bool*[width];
    for(int i = 0; i < width; i++){
        givenValues[i] = new bool[width];
        for(int j = 0; j < width; j++){
            givenValues[i][j] = false;
        }
    }
}

void SudokuPuzzle::printPuzzle(){
    // find width to print
    int printWidth = 0;
    int widthCopy = width;
    while(widthCopy != 0) {
        widthCopy = widthCopy / 10;
        printWidth++;
    }

    int lineLength = width * (printWidth + 1) + sqrtOfWidth + 1;

    for(int k = 0; k < lineLength; k++){
        cout << "-";
    }
    cout << "\n";

    for(int i = 0; i < width; i++){
        cout << "|";
        for(int j = 0; j < width; j++){
            cout << setw(printWidth) << puzzle[i][j] << " ";

            if((j + 1) % sqrtOfWidth == 0){
                cout << "|";
            }
        }
        cout << "\n";

        if ((i + 1) % sqrtOfWidth == 0){
            for(int k = 0; k < lineLength; k++){
                cout << "-";
            }
            cout << "\n";
        }
    }
}

// Insert value into the puzzle and mark this cell as given
void SudokuPuzzle::insertGivenValue(int value, int row, int col){
    puzzle[row][col] = value;

    if(value != 0){
        addGivenValue(row, col);
    }
}

// Get the all the values that are in a row and return them through 'values'.
// Values will start to fill the array from left to right. The number of
// nonzero values is returned through numValues.
void SudokuPuzzle::findValuesInRow(int row, int* values, int &numValues){
    int valueCount = 0;
    for(int i = 0; i < width; i++){
        if(puzzle[row][i] != 0){
            values[valueCount] = puzzle[row][i];
            valueCount++;
        }
    }

    numValues = valueCount;
}

// Get the all the values that are in a column and return them through 'values'.
// Values will start to fill the array from left to right. The number of
// nonzero values is returned through numValues.
void SudokuPuzzle::findValuesInCol(int col, int* values, int &numValues){
    int valueCount = 0;
    for(int i = 0; i < width; i++){
        if(puzzle[i][col] != 0){
            values[valueCount] = puzzle[i][col];
            valueCount++;
        }
    }

    numValues = valueCount;
}

void SudokuPuzzle::findValuesInBox(int row, int col, int* values, int &numValues){
    int valueCount = 0;
    int boxX = row / sqrtOfWidth;
    int boxY = col / sqrtOfWidth;
    int rowOffset = boxX * sqrtOfWidth;
    int colOffset = boxY * sqrtOfWidth;

    for(int i = 0; i < sqrtOfWidth; i++){
        for(int j = 0; j < sqrtOfWidth; j++){
            if(puzzle[i + rowOffset][j + colOffset] != 0){
                values[valueCount] = puzzle[i + rowOffset][j + colOffset];
                valueCount++;
            }
        }
    }

    numValues = valueCount;
}

void SudokuPuzzle::addPossibleValue(int value, int row, int col){
    possibleValues[row][col][value - 1] = true;
}

void SudokuPuzzle::removePossibleValue(int value, int row, int col){
    possibleValues[row][col][value - 1] = false;
}

// Returns the value of the possible value at the index position
// If there is no value in that position, -1 is returned
int SudokuPuzzle::getPossibleValue(int row, int col, int index){

    int valuesIndex = 0;
    for(int i = 0; i < SudokuPuzzle::width; i++){
        if(SudokuPuzzle::possibleValues[row][col][i] == true){
            if(valuesIndex == index){
                return i + 1;
            }
            else{
                valuesIndex++;
            }
        }
    }

    return -1;
}

int SudokuPuzzle::getNumPossibleValues(int row, int col){
    int count = 0;
    for(int i = 0; i < width; i++){
        if(possibleValues[row][col][i] == true){
            count++;
        }
    }

    return count;
}

void SudokuPuzzle::findValidNumbersForTile(int row, int col){
    int valInRow[width] = {0};
    int valInCol[width] = {0};
    int valInBox[width] = {0};
    int numValuesInRow = 0;
    int numValuesInCol = 0;
    int numValuesInBox = 0;

    int validNumbers[width] = {0};
    for(int i = 0; i < width; i++){
        validNumbers[i] = i + 1;
    }

    findValuesInRow(row, valInRow, numValuesInRow);
    findValuesInCol(col, valInCol, numValuesInCol);
    findValuesInBox(row, col, valInBox, numValuesInBox);

    for(int i = 0; i < numValuesInRow; i++){
        for(int j = 0; j < width; j++){
            // Check validNumbers for the value in the row,
            // remove if found
            if(valInRow[i] == validNumbers[j]){
                validNumbers[j] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < numValuesInCol; i++){
        for(int j = 0; j < width; j++){
            // Check validNumbers for the value in the column,
            // remove if found
            if(valInCol[i] == validNumbers[j]){
                validNumbers[j] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < numValuesInBox; i++){
        for(int j = 0; j < width; j++){
            // Check validNumbers for the value in the box,
            // remove if found
            if(valInBox[i] == validNumbers[j]){
                validNumbers[j] = 0;
                break;
            }
        }
    }

    // write result to output array
    int numValues = 0;
    for(int i = 0; i < width; i++){
        if(validNumbers[i] != 0){
            possibleValues[row][col][i] = true;
            numValues++;
        }
        else{
            possibleValues[row][col][i] = false;
        }
    }
}

bool SudokuPuzzle::puzzleIsSolved(){
    bool* found = new bool[width];
    for(int i = 0; i < width; i++){
        found[i] = false;
    }

    int numValues = 0;
    int* values = new int[width];
    for(int i = 0; i < width; i++){
        values[i] = 0;
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(puzzle[i][j] == 0){
                return false;
            }
        }
    }

    // check rows
    for(int i = 0; i < width; i++){
        findValuesInRow(i, values, numValues);

        for(int j = 0; j < numValues; j++){
            if(found[values[j] - 1] == true){
                return false;
            }
            else{
                found[values[j] - 1] = true;
            }
        }

        // reset found array
        for(int i = 0; i < width; i++){
            found[i] = false;
        }
    }

    // check rows
    for(int i = 0; i < width; i++){
        findValuesInCol(i, values, numValues);

        for(int j = 0; j < numValues; j++){
            if(found[values[j] - 1] == true){
                return false;
            }
            else{
                found[values[j] - 1] = true;
            }
        }

        // reset found array
        for(int i = 0; i < width; i++){
            found[i] = false;
        }
    }

    // check boxes
    for(int i = 0; i < width; i++){
        findValuesInBox((i * sqrtOfWidth) / width, (i * sqrtOfWidth) % width, values, numValues);

        for(int j = 0; j < numValues; j++){
            if(found[values[j] - 1] == true){
                return false;
            }
            else{
                found[values[j] - 1] = true;
            }
        }

        // reset found array
        for(int i = 0; i < width; i++){
            found[i] = false;
        }
    }

    return true;
}

void SudokuPuzzle::addGivenValue(int row, int col){
    givenValues[row][col] = true;
}

bool SudokuPuzzle::valueIsGiven(int row, int col){
    return givenValues[row][col];
}

void SudokuPuzzle::insertValue(int row, int col, int value){
    puzzle[row][col] = value;
    findAllPossibleValues();
}

void SudokuPuzzle::findAllPossibleValues(){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            findValidNumbersForTile(i, j);
        }
    }
}

bool SudokuPuzzle::solveLoneRangers(){
    bool rangersFound = false;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(puzzle[i][j] == 0 && getNumPossibleValues(i, j) == 1){
                insertValue(i, j, getPossibleValue(i, j, 0));
                rangersFound = true;
            }
        }
    }

    return rangersFound;
}

bool SudokuPuzzle::solveSerial(int row, int col, int tile){

    // Move to next open space
    while(tile < (widthDoubled) && puzzle[row][col] != 0){
        tile++;
        row = tile / width;
        col = tile % width;
    }

    // if the last tile is reached, check
    // to see if the puzzle is solvd
    if(tile >= (widthDoubled) && puzzleIsSolved()){
        return true;
    }

    int numValues = 0;
    if(!valueIsGiven(row, col) && puzzle[row][col] == 0 && (numValues = getNumPossibleValues(row, col)) > 0){
        for(int i = 0; i < numValues; i++){

            // try next valid number
            insertValue(row, col, getPossibleValue(row, col, i));

            if(solveSerial(row, col, tile)){
                return true;
            }
            else{
                // reset value and reset possible values
                insertValue(row, col, 0);
            }
        }

        // No more values for this tile
        return false;
    }

    return false;
}