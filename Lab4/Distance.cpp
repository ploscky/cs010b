#include <iostream>
#include <cmath>
using namespace std;

#include "Distance.h"


//private helper function
void Distance::init() {
    if (_inches < 0) {
        _inches = _inches * -1;
    }

    while (_inches >= 12) {
        _feet = _feet + 1;
        _inches = _inches - 12;
    }
}

//constructors
Distance::Distance() {
    _feet = 0;
    _inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in) {
    _feet = 0;
    _inches = in;
    init();
}

//returns private vars
unsigned Distance::getFeet() const {
    return _feet;
}

double Distance::getInches() const {
    return _inches;
}

//public class functions
double Distance::distanceInInches() const {
    return ((_feet * 12.0) + _inches);
}

double Distance::distanceInFeet() const {
    double ft = _inches / 12.0;
    return (_feet + ft);
}

double Distance::distanceInMeters() const {
    double in = (_feet * 12) + _inches;
    double meters = in * 0.0254;
    return meters;
}

Distance Distance::operator+(const Distance &rhs) const {
    Distance distanceSum;
    distanceSum._feet = _feet + rhs.getFeet();
    distanceSum._inches = _inches + rhs.getInches();
    while (distanceSum._inches >= 12) {
        distanceSum._feet += 1;
        distanceSum._inches -= 12;
    }
    return distanceSum;
}

Distance Distance::operator-(const Distance &rhs) const {
    Distance distanceDiff;
    if (_feet > rhs.getFeet()) {
        distanceDiff._feet = _feet - rhs.getFeet();
        distanceDiff._inches = _inches - rhs.getInches();
    }
    else if (_feet < rhs.getFeet()){
        distanceDiff._feet = rhs.getFeet() - _feet;
        distanceDiff._inches = rhs.getInches() - _inches;
    }
    else {
        distanceDiff._feet = 0;
        distanceDiff._inches = fabs(rhs.getInches() - _inches);
    }
    while (distanceDiff._inches < 0) {
        distanceDiff._feet -= 1;
        distanceDiff._inches += 12;
    }
    return distanceDiff;
}

//friend function
ostream& operator<< (ostream &out, const Distance &rhs) {
    out << rhs._feet << "\' " << rhs._inches << "\"";
    return out;
}