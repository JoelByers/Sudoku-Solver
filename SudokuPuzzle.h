#ifndef _SUDOKU_PUZZLE_H
#define _SUDOKU_PUZZLE_H

class SudokuPuzzle{
    private:
        int** puzzle;
        bool*** possibleValues;
        int width;
        int sqrtOfWidth;
    public:
        SudokuPuzzle(int width);
        void printPuzzle();
        void insert(int value, int row, int col);
        void findValuesInRow(int row, int* values, int &numValues);
        void findValuesInCol(int col, int* values, int &numValues);
        void findValuesInBox(int boxX, int boxY, int* values, int &numValues);
        void findValidNumbersForTile(int row, int col, int* values, int &numValues);
        void addPossibleValue(int value, int row, int col);
        void removePossibleValue(int value, int row, int col);
        int getPossibleValue(int row, int col, int index);
        bool puzzleIsSolved();

};

#endif
