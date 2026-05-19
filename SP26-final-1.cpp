// COMSC-210 | SP26-Final-1 | Gabriel Marquez

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

const string FILE_NAME = "210-final-1-SP26.txt";

int main() {
    map<string, int> airports;

    string airport;
    string airport2;
    //code for reading a file taken from lab 38
    ifstream fin(FILE_NAME);
    if (fin.good( )) {
        while (fin >> airport) {
            airports[airport]++;
            fin >> airport2;
            airports[airport2]++;
        }
        fin.close( );
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }

    cout << "All airport traffic counts:" << endl;
    for (const auto &pair : airports) {
        
    }
}