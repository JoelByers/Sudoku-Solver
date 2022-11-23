#include <iostream>
#include "SudokuPuzzle.h"
#include "IO.h"

using namespace std;

int main(int argc, char** argv){

    if(argc < 2){
        cout << "Missing input file" << endl;
        return 1;
    }

    SudokuPuzzle puzzle = getPuzzleFromFile(argv[1]);
    puzzle.printPuzzle();
    puzzle.solveSerial(0,0,0);
    puzzle.printPuzzle();
    return 0;
}