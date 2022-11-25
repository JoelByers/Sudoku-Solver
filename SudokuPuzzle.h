#ifndef _SUDOKU_PUZZLE_H
#define _SUDOKU_PUZZLE_H

class SudokuPuzzle{
    private:
        int** puzzle;
        int width;
        int sqrtOfWidth;
    public:
        SudokuPuzzle(int width);
        void printPuzzle();
        void insert(int value, int row, int col);
};

#endif
