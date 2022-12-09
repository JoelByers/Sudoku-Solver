#include <iostream>
#include "SudokuPuzzle.h"
#include "IO.h"

using namespace std;

int main(){
    SudokuPuzzle p = getPuzzleFromFile("puzzles/9x9/9x9_1.txt");
    p.printPuzzle();
    SudokuPuzzle a = p.copy();
    a.printPuzzle();
    return 0;
}