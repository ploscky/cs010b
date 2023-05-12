//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {

   // verify file name provided on command line
    string fileName = argv[1];
    if (argc != 2) {
        cout << endl << "./a.out fin" << endl;
        return 1;
    }

   // open file and verify it opened
    ifstream fin;
    fin.open(fileName);
    if (!fin.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }

   // Declare an array of doubles of size ARR_CAP.
    double labArray[ARR_CAP];

   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    double arrayVal;
    int size = 0;
    while (fin >> arrayVal && size < ARR_CAP ) {
        labArray[size] = arrayVal;
        ++size;
    }

   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << mean(labArray, size) << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    int userIndex;
    cout << "Enter index of value to be removed (0 to " << size - 1 << "): ";
    cin >> userIndex;
    cout << endl;

   // Call the display function to output the array.
    cout << "Before removing value: ";
    display(labArray, size);
    cout << endl;

   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(labArray, size, userIndex);
  
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: ";
    display(labArray, size);
    cout << endl;
   
   // Call the mean function again to get the new mean
    cout << "Mean: " << mean(labArray, size) << endl;
   
	return 0;
}

double mean(const double array[], int arraySize) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum = sum + array[i];
        ++count;
    }
    return (sum / count);
}

void remove(double array[], int &arraySize, int index) {
    for (int i = index; i < arraySize - 1; ++i) {
        array[i] = array[i + 1];
    }
    arraySize = arraySize - 1;
}

void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        if (i != arraySize - 1) {
            cout << array[i] << ", ";
        } 
        else {
            cout << array[i];
        }
    }
}