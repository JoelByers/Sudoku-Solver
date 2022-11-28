g++ src/SerialSolver.cpp src/SudokuPuzzle.cpp src/IO.cpp -fopenmp -o sudokuSerial.out
g++ src/ParallelSolver.cpp src/SudokuPuzzle.cpp src/IO.cpp -fopenmp -o sudokuParallel.out
g++ src/SudokuPuzzleGen.cpp src/SudokuPuzzle.cpp -o gen.out