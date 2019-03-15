#include <iostream>
#include <string>
#include <fstream>
#include "Reader.h"

using namespace std;

int main() {
    //file name used for project
    string fileName = "C:/Users/jknight22/desktop/cs273-project3.1/list.txt";
    
    Reader read = Reader(fileName);
    read.setStack();
    //this should throw an error because list.h has two brackets between parethesis on lines 32 and 34
    read.checkStack();

    read.printStac();
    cout << "finished! :)" << endl;
    return 0;
}