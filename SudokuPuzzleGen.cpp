#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

int main(int argc, char** argv){

    int width = 0;
    int fill = 0;

    if(argc <= 2){
        cerr << "Not enough arguments. Usage: <size> <%fill>" << endl;
        return 1;
    }
    else{
        width = atoi(argv[1]);
        fill = atoi(argv[2]);
    }

    int sqrtWidth = (int)sqrt(width);
    srand(time(NULL));
    
    // find width to print
    int printWidth = 0;
    int widthCopy = width;
    while(widthCopy != 0) {
        widthCopy = widthCopy / 10;
        printWidth++;
    }

    int offset = 0;
    int number = 0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            number = (((j + (i * sqrtWidth) + offset) % width) + 1);
            if(rand() % 100 > fill){
                number = 0;
            }

            cout << setw(printWidth) << number << " ";
        }

        cout << "\n";

        if((i + 1) % sqrtWidth == 0){
            offset++;
        }
    }
}