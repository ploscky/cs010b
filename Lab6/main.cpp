#include <iostream>
#include "IntVector.h"
#include <cassert>
using namespace std;

int main() {
    //testing default constructor
    cout << "testing started" << endl;
    IntVector v1;
    cout << "testing completed" << endl;

    //testing parameter constructor
    cout << "testing started" << endl;
    IntVector v2(5, 2);
    IntVector v3(0, 3);
    cout << "testing completed" << endl;

    //testing size const
    cout << "testing started" << endl;
    assert(v1.size() == 0);
    assert(v2.size() == 5);
    assert(v3.size() == 0);
    cout << "testing completed" << endl;

    //testing capacity const
    cout << "testing started" << endl;
    assert(v1.capacity() == 0);
    assert(v2.capacity() == 5);
    assert(v3.capacity() == 0);
    cout << "testing completed" << endl;

    //testing empty
    cout << "testing started" << endl;
    assert(v1.empty() == true);
    assert(v2.empty() == false);
    assert(v3.empty() == true);
    cout << "testing completed" << endl;

    //testing at
    /*cout << "testing started" << endl;
    IntVector v4(10, 4);
    cout << v4.at(10) << endl;
    cout << "testing completed" << endl;*/

    //testing front
    cout << "testing started" << endl;
    assert(v1.front() == 0);
    assert(v2.front() == 2);
    assert(v3.front() == 3);
    cout << "testing completed" << endl;

    //testing back
    cout << "testing started" << endl;
    assert(v1.back() == 0);
    assert(v2.back() == 2);
    assert(v3.back() == 3);
    cout << "testing completed" << endl;
    
    return 0;
}