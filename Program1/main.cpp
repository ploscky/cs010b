#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <float.h>
using namespace std;

void readData(const string &fileName, vector<double> &flightAngles, vector<double> &coeffLifts);
double interpolation(double userAngle, const vector<double> &flightAngles, const vector<double> &coeffLifts);
bool isOrdered(const vector<double> &flightAngles);
void reorder(vector<double> &flightAngles, vector<double> &coeffLifts);

int main(int argc, char *argv[]) {
    string fileName = argv[1];
    if (argc != 2) {
        cout << endl << "./a.out fin" << endl;
        return 1;
    }

    vector<double> flightAngles;
    vector<double> coeffLifts;

    readData(fileName, flightAngles, coeffLifts);
    reorder(flightAngles, coeffLifts);

    double userAngle;
    cout << "Please enter flight-path angle: ";
    cin >> userAngle;
    cout << endl;
    cout << interpolation(userAngle, flightAngles, coeffLifts) << endl;

    string userResponse;
    cout << "Do you want to enter another flight-path angle: ";
    cin >> userResponse;
    cout << endl;
    while (userResponse == "Yes") {
        cout << "Please enter flight-path angle: ";
        cin >> userAngle;
        cout << endl;
        cout << interpolation(userAngle, flightAngles, coeffLifts) << endl;
        cout << "Do you want to enter another flight-path angle: ";
        cin >> userResponse;
        cout << endl;
    }

return 0;
}

void readData(const string &fileName, vector<double> &flightAngles, vector<double> &coeffLifts) {
    ifstream fin;

    fin.open(fileName);
    if (!fin.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

    double column1;
    double column2;
    while (fin >> column1) {
        flightAngles.push_back(column1);
        fin >> column2;
        coeffLifts.push_back(column2);
    }
    fin.close();
}

bool isOrdered(const vector<double> &flightAngles) {
    bool isAscending = true;
    if (flightAngles.size() != 0) {
        for (unsigned int i = 0; i < flightAngles.size() - 1; ++i) {
            if (flightAngles.at(i) > flightAngles.at(i + 1)) {
                isAscending = false;
            }
        }
    }
    return isAscending;
}

void reorder(vector<double> &flightAngles, vector<double> &coeffLifts) {
    double temp1;
    double temp2;
    if (flightAngles.size() != 0 && coeffLifts.size() != 0) {
        if (!isOrdered(flightAngles)) {
            for (unsigned int i = 0; i < flightAngles.size() - 1; ++i) {
                for (unsigned int j = 0; j < flightAngles.size() - 1 - i; ++j) {
                    if (flightAngles.at(j) > flightAngles.at(j + 1)) {
                        temp1 = flightAngles.at(j);
                        flightAngles.at(j) = flightAngles.at(j + 1);
                        flightAngles.at(j + 1) = temp1;
                        temp2 = coeffLifts.at(j);
                        coeffLifts.at(j) = coeffLifts.at(j + 1);
                        coeffLifts.at(j + 1) = temp2;
                    }
                }
            }
        }
    }
}

double interpolation(double userAngle, const vector<double> &flightAngles, const vector<double> &coeffLifts) {
    double bLift;
    double bAngle;
    int index;
    bool isExisting = false;
    for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        if (userAngle == flightAngles.at(i)) {
            index = i;
            isExisting = true;
        }
    }

    if (isExisting == true) {
        bLift = coeffLifts.at(index);
    }
    else {
        int aIndex;
        int cIndex;
        for (unsigned int i = 0; i < flightAngles.size() - 1; ++i) {
            if (userAngle > flightAngles.at(i) && userAngle < flightAngles.at(i + 1)){
                bAngle = userAngle;
                aIndex = i;
                cIndex = i + 1;
            }
        }   
        bLift = coeffLifts.at(aIndex) + ((bAngle - flightAngles.at(aIndex))/(flightAngles.at(cIndex) - flightAngles.at(aIndex))) * (coeffLifts.at(cIndex) - coeffLifts.at(aIndex));
    }
    
    return bLift;
}

