#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputFile;
    ofstream outputFile;
    vector<int> vec;
    int num;
    char trash;

    if (argc != 3) {
        cout << endl << "./a.out inputFile outputFile" << endl;
        return 1;
    }

    inputFile.open(argv[1]);
    if (!inputFile.is_open()) {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    while (inputFile >> num) {
        vec.push_back(num);
        inputFile >> trash;
    }

    int count = 0;
    int sum = 0;
    int average;
    
    for (unsigned int i = 0; i < vec.size(); ++i) {
        ++count;
        sum = sum + vec.at(i);
    }
    average = sum / count;

    for (unsigned int i = 0; i < vec.size(); ++i) {
        vec.at(i) = vec.at(i) - average;
    }

    outputFile.open(argv[2]);
    if (!outputFile.is_open()) {
        cout << "Could not open file " << argv[2] << endl;
        return 1;
    }

    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (i != vec.size() - 1) {
            outputFile << vec.at(i) << ',';
        }
        else {
            outputFile << vec.at(i);
        }
    }
    outputFile.close();
    inputFile.close();
    return 0;
}