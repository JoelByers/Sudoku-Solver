#ifndef _SUDOKU_PUZZLE_H
#define _SUDOKU_PUZZLE_H

class SudokuPuzzle{
    private:
        int** puzzle;
        bool*** possibleValues;
        bool** givenValues;
        int width;
        int sqrtOfWidth;
    public:
        SudokuPuzzle(int width);
        void printPuzzle();
        void insertGivenValue(int value, int row, int col);
        void findValuesInRow(int row, int* values, int &numValues);
        void findValuesInCol(int col, int* values, int &numValues);
        void findValuesInBox(int boxX, int boxY, int* values, int &numValues);
        void findValidNumbersForTile(int row, int col);
        void addPossibleValue(int value, int row, int col);
        void removePossibleValue(int value, int row, int col);
        int getPossibleValue(int row, int col, int index);
        int getNumPossibleValues(int row, int col);
        void findAllPossibleValues();
        bool puzzleIsSolved();
        void addGivenValue(int row, int col);
        bool valueIsGiven(int row, int col);
};

#endif
