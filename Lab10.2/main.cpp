#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool rCopy(const string& inputName, const string& outputName);
void copyHelp(ifstream& fin, ofstream& fout);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "./a.out fin fout" << endl;
        return 1;
    }
    if (rCopy(argv[1], argv[2])) {
        cout << "Copy completed" << endl;
    }
    else {
        cout << "Copy not completed" << endl;
    }

    return 0; 
}

void copyHelp(ifstream& fin, ofstream& fout, string& fileStuff) {
    char c;
    if (fin.get(c)) {
        fileStuff = c + fileStuff;
        copyHelp(fin, fout, fileStuff);
    }
    else {
        fout << fileStuff;
    }
}

bool rCopy(const string& inputName, const string& outputName) {
    ifstream fin;
    ofstream fout;

    fin.open(inputName);
    if (!fin.is_open()) {
        cout << "Error opening " << inputName << endl;
        return false;
    }
    fout.open(outputName);
    if (!fout.is_open()) {
        cout << "Error opening " << outputName << endl;
        return false;
    }
    string fileStuff = "";
    copyHelp(fin, fout, fileStuff);
    fin.close();
    fout.close();
    return true;
}

