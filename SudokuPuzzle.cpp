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

void SudokuPuzzle::insert(int value, int row, int col){
    puzzle[row][col] = value;
}

