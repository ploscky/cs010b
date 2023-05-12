#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int charCnt(string fileName, char c);

int main() {
    string fileName;
    char c;
    int count = 0;
    cout << "Enter the name of the input file: ";
    cin >> fileName;
    cout << endl;
    cout << "Enter a character: ";
    cin.ignore();
    cin.get(c);
    cout << endl;
    count = charCnt(fileName , c);
    cout << "# of " << c << "'s: " << count << endl;
    return 0;
}

int charCnt(string fileName, char c) {
    ifstream inFS;
    char fileC;
    int count = 0;
    inFS.open(fileName);

    if (!inFS.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while (inFS.get(fileC)) {
        if (fileC == c) {
            ++count;
        }
    }
    inFS.close();
    return count;
}