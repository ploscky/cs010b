#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;
    _data = new int[capacity];
    for (unsigned i = 0; i < capacity; ++i) {
        _data[i] = value;
    }    
}

IntVector::~IntVector() {
    delete[] (_data);
}

unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    bool isEmpty = false;
    if (_size == 0) {
        isEmpty = true;
    }
    return isEmpty;
}

const int& IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}

const int& IntVector::front() const {
    return _data[0];
}

const int& IntVector::back() const {
    return _data[_size - 1];
}