#include <iostream>
#include <algorithm>
#include "IntList.h"
using namespace std;

//default constructor
IntList::IntList() 
    : head(nullptr),
      tail(nullptr)
{
}

//copy constructor
IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    for (IntNode* curr = cpy.head; curr != nullptr; curr = curr->next) {
        push_back(curr->value);
    }
}

//copy assignment
IntList & IntList::operator=(const IntList &rhs) {
    if (this == &rhs) {
        return *this;
    }

    if (!empty()) {
        clear();
    }

    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next) {
        push_back(curr->value);
    }
    return *this;
}

//destructor
IntList::~IntList() {
    IntNode* pointerToBeDeleted = head;
    while (pointerToBeDeleted != nullptr) {
        IntNode* nextLink = pointerToBeDeleted->next;
        delete pointerToBeDeleted;
        pointerToBeDeleted = nextLink;
    }
}

//push_front
void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }
}

//empty
bool IntList::empty() const {
    return (head == nullptr);
}

//pop_front
void IntList::pop_front() {
    if (empty()) {
        return;
    }

    IntNode* pointerToBeDeleted = head;
    head = head->next;
    delete pointerToBeDeleted;
    
    if (empty()) {
        tail = nullptr;
    }
}

//front
const int& IntList::front() const {
    return head->value;
}

//back
const int& IntList::back() const {
    return tail->value;
}

//friend function
ostream & operator<<(ostream &out, const IntList &rhs) {
    for (IntNode* p = rhs.head; p != nullptr; p = p->next) {
        if (p != rhs.tail) {
            out << p->value << ' ';
        }
        else {
            out << p->value;
        }
    }
    return out;
}

//push_back
void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    if (empty()) {
        head = newNode;
        tail = newNode;
        tail->next = nullptr;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = nullptr;
    }
}

//clear
void IntList::clear() {
    if (empty()) {
        return;
    }
    IntNode* pointerToBeDeleted = head;
    while (pointerToBeDeleted != nullptr) {
        IntNode* nextLink = pointerToBeDeleted->next;
        delete pointerToBeDeleted;
        pointerToBeDeleted = nextLink;
    }
    head = nullptr;
    tail = nullptr;
}

//selection sort
void IntList::selection_sort() {
    for (IntNode* p = head; p != nullptr; p = p->next) {
        IntNode* min = p;
        for (IntNode* q = p; q != nullptr; q = q->next) {
            if (q->value < min->value) {
                min = q;
            }
        }
        swap(p->value, min->value);
    }
}

//insert_ordered
void IntList::insert_ordered(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* prev = head;
    IntNode* curr = nullptr;
    if (empty()) {
        push_back(newNode->value);
        return;
    }
    if (newNode->value <= head->value) {
        push_front(newNode->value);
        return;
    }
    if (newNode->value >= tail->value) {
        push_back(newNode->value);
        return;
    }
    curr = head->next;
    while (curr != nullptr) {
        if (newNode->value <= curr->value) {
            newNode->next = prev->next;
            prev->next = newNode;
            prev = prev->next;
            return;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
}

//remove duplicates
void IntList::remove_duplicates() {
    for (IntNode* p = head; p != nullptr; p = p->next) {
        IntNode* prev = p;
        IntNode* curr = p->next;
        while (curr != nullptr) {
            if (curr->value != p->value) {
                prev = prev->next;
                curr = curr->next;
            }
            else {
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev;
                }
                delete curr;
                curr = prev->next;
            
            }
        }
    }
}

//min
IntNode * IntList::min(IntNode *) {
    return nullptr;
}

//copy
void IntList::copy(const IntList &) {
    return;
}