#include <iostream>
#include <fstream>
#include "SudokuPuzzle.h"
#include <vector>
#include <cmath>

using namespace std;

SudokuPuzzle getPuzzleFromFile(string fileName){
    ifstream fileIn(fileName);
    vector<int> puzzleData;
    string line;
    string num;

    while(fileIn >> num){
        puzzleData.push_back(stoi(num));
    }

    int width = sqrt(puzzleData.size());
    int size = width * width;
    SudokuPuzzle puzzle = SudokuPuzzle(width);

    for(int i = width - 1; i >= 0; i--){
        for(int j = width - 1; j >= 0; j--){
            int thisNum = puzzleData.back();
            puzzle.insertGivenValue(thisNum, i, j);

            puzzleData.pop_back();
        }
    }

    puzzle.findAllPossibleValues();

    return puzzle;
}