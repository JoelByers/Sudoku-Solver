#include <iostream>
#include "SudokuPuzzle.h"
#include "IO.h"
#include <omp.h>

using namespace std;

//#define TIME_OUTPUT_ONLY

int main(int argc, char** argv){

    if(argc < 2){
        cout << "Missing input file" << endl;
        return 1;
    }

    SudokuPuzzle puzzle = getPuzzleFromFile(argv[1]);

    #ifndef TIME_OUTPUT_ONLY
    cout << "   _______________" << endl;
    cout << "  | Sudoku Solver |" << endl;
    cout << "  |    Serial     |" << endl;
    cout << "  '---------------'" << endl;
    cout << "=======================" << endl;
    cout << endl << "    [ Unsolved ]" << endl;
    puzzle.printPuzzle();
    #endif

    double time = omp_get_wtime();
    puzzle.solveSerial(0,0,0);
    time = omp_get_wtime() - time;

    #ifndef TIME_OUTPUT_ONLY
    cout << endl << "    [  Solved  ]" << endl;;
    puzzle.printPuzzle();
    cout << "Duration: " << time << endl;
    #else
    cout << time;
    #endif

    return 0;
}