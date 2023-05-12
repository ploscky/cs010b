#include "IntList.h"
#include <iostream>
#include <algorithm>

using namespace std;

// basically the helper function but starting from head lol
bool IntList::bubbleUp() {
    return bubbleUp(head);
}

/*helper function is recursively called until listNode reaches the end of the list, where the swapping will begin;
once it reaches the end of the list, it goes back towards the head, swapping depending on what value is smaller-- 
if a swap occurs, return true; if no swap occurs, return false*/
bool IntList::bubbleUp(IntNode *listNode) {
    if (listNode == nullptr) {
        return false;
    }
    if (listNode->next == nullptr) {
        return false;
    }

    bool swapVal = false;
    swapVal = bubbleUp(listNode->next); 
    if (listNode->next->value < listNode->value) {
        swap(listNode->value, listNode->next->value);
        return true;
    }
    return swapVal;
}
