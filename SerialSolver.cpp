#include <iostream>
#include "SudokuPuzzle.h"
#include "IO.h"
#include <omp.h>

using namespace std;

int main(int argc, char** argv){

    if(argc < 2){
        cout << "Missing input file" << endl;
        return 1;
    }

    SudokuPuzzle puzzle = getPuzzleFromFile(argv[1]);
    puzzle.printPuzzle();
    double time = omp_get_wtime();
    puzzle.solveSerial(0,0,0);
    time = omp_get_wtime() - time;
    puzzle.printPuzzle();
    cout << "Duration: " << time << endl;
    return 0;
}