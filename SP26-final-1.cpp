// COMSC-210 | SP26-Final-1 | Gabriel Marquez

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

const string FILE_NAME = "210-final-1-SP26.txt";
const int MIN1 = 5, MIN2 = 9, MAX1 = 8, MAX2 = 12;

void print_airports_in_range(const map<string, int>&, int, int);

int main() {
    //Milestone 1 code
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
        cout << pair.first << " " << pair.second << endl;
    }

    //Milestone 2 code
    map<string, int> busiest_airports;
    int tracker = 0;
    for (const auto &pair : airports) {
        if (pair.second > tracker) {
            busiest_airports.clear();
            tracker = pair.second;
            busiest_airports[pair.first] = pair.second;
        }
        else if (pair.second == tracker) {
            busiest_airports[pair.first] = pair.second;
        }
    }

    cout << "\nBusiest airport(s) with count " << tracker << ":" << endl;
    for (const auto &pair : busiest_airports) {
        cout << pair.first << " " << pair.second << endl;
    }

    //Milestone 3 code using print_airports_in_range() function
    print_airports_in_range(airports, MIN1, MAX1);
    print_airports_in_range(airports, MIN2, MAX2);

    return 0; 
}

void print_airports_in_range(const map<string, int> &map, int min, int max) {
    cout << "\nAirports with traffic in range [" << min << ", " << max << "]:" << endl;
    for (const auto &pair : map) {
        if (pair.second >= min && pair.second <= max)
            cout << pair.first << " " << pair.second << endl;
    }
}