#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char** argv){

    int width = 0;

    if(argc <= 1){
        cerr << "Size arg not given" << endl;
    }
    else{
        width = atoi(argv[1]);
    }

    int sqrtWidth = (int)sqrt(width);
    
    // find width to print
    int printWidth = 0;
    int widthCopy = width;
    while(widthCopy != 0) {
        widthCopy = widthCopy / 10;
        printWidth++;
    }

    int offset = 0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            cout << setw(printWidth) << (((j + (i * sqrtWidth) + offset) % width) + 1) << " ";
        }

        cout << "\n";

        if((i + 1) % sqrtWidth == 0){
            offset++;
        }
    }
}