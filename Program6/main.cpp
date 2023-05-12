#include <iostream>
using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {
    SortedSet test1;
    SortedSet test2;
    cout << test1.in(3) << endl;
    test1.push_front(1);
    test1.push_back(2);
    test1.push_back(5);
    cout << test1.in(2) << endl;
    cout << test1 << endl;
    test2.push_back(4);
    test2.insert_ordered(5);
    test2.insert_ordered(6);
    cout << test2 << endl;
    SortedSet test3 = test1&test2;
    cout << test3 << endl;
    SortedSet test4 = test1|test2;
    cout << test4 << endl;
    SortedSet test5 = test1|=test2;
    cout << test5 << endl << test1 << endl;
    SortedSet test6 = test1&=test2;
    cout << test6 << endl << test1 << endl;


    return 0;
}