#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int fileSum (string fileName);

int main() {
    string fileName;
    int sum = 0;
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;
    sum = fileSum(fileName);
    cout << "Sum: " << sum << endl;
    return 0;
}

int fileSum(string fileName) {
    ifstream intsFS;
    int num;
    int sum = 0;
    intsFS.open(fileName);

    if (!intsFS.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while (!intsFS.eof() && intsFS.good()) {
        intsFS >> num;
        if (!intsFS.fail()) {
            sum = sum + num;
        }
    }
    intsFS.close();
    return sum;
}