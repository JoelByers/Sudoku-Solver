#include <iostream>
#include <cstdlib>

using namespace std;

void printPuzzle(unsigned int** puzzle, int width){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            cout << puzzle[i][j] << " ";
        }

        cout << "\n";
    }
}

void zeroPuzzle(unsigned int** puzzle, int width){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            puzzle[i][j] = 0;
        }
    }
}

void generatePuzzle(unsigned int** puzzle, int width){
    // Populate randomly with numbers 1 through width
    int row = 0;
    int col = 0;

    // Fill first space
    row = rand() % width;
    col = rand() % width;
    puzzle[row][col] = 1;

    // Fill the remaining spaces
    for(int i = 1; i < width; i++){
        do{
            row = rand() % width;
            col = rand() % width;
        }
        while(puzzle[row][col] != 0);
        
        puzzle[row][col] = i + 1;
    }

    // "Solve" the puzzle to fill spaces
    
}

int main(){
    srand(0);

    unsigned int **puzzle;
    puzzle = new unsigned int *[9];
    for(int i = 0; i < 9; i++){
        puzzle[i] = new unsigned int [9];
    }

    zeroPuzzle(puzzle, 9);
    generatePuzzle(puzzle, 9);
    printPuzzle(puzzle, 9);

    return 0;
}