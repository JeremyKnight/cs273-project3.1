#include <iostream>
#include <string>
#include <fstream>
#include "Reader.h"


using namespace std;

int main() {
    string fileName = "C:/Users/jknight22/desktop/cs273-project3.1/list.txt";

    /*
    fstream fn("C:/Users/jknight22/desktop/cs273-project3.1/list.txt", ios::in | ios::out);
    if(fn.fail()) {
        cout << "file not found form main" << endl;
    }
    */
    
    Reader read = Reader(fileName);
    read.setStack();
    read.checkStack();

    return 0;
}