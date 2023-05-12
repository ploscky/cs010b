#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

//default constructor
SortedSet::SortedSet()
    : IntList()
{}

//copy constructor
SortedSet::SortedSet(const SortedSet &copy)
    : IntList(copy)
{}

//IntList parameter constructor
SortedSet::SortedSet(const IntList &copy)
    : IntList(copy)
    {
        remove_duplicates();
        selection_sort();
    }


//destructor
SortedSet::~SortedSet() {}

//bool in
bool SortedSet::in(int value) {
    bool isMember = false;
    for (IntNode* p = head; p != nullptr; p = p->next) {
        if (value == p->value) {
            isMember = true;
        }
    }
    return isMember;
}

//union func
SortedSet SortedSet::operator|(const SortedSet& rhs) {
    SortedSet unionSet;
    for (IntNode* p = head; p != nullptr; p = p->next) {
        unionSet.push_back(p->value);
    }
    for (IntNode* i = rhs.head; i != nullptr; i = i->next) {
        unionSet.push_back(i->value);
    }
    unionSet.remove_duplicates();
    return unionSet;
}

//intersection func
SortedSet SortedSet::operator&(const SortedSet& rhs) {
    SortedSet intersection;
    for (IntNode* p = head; p != nullptr; p = p->next) {
        for (IntNode* i = rhs.head; i != nullptr; i = i->next) {
            if (p->value == i->value) {
                intersection.push_back(p->value);
            }
        }
    }
    return intersection;
}

//add
void SortedSet::add(int value) {
    if (!in(value)) {
        IntList::insert_ordered(value);
    }
    else {
        return;
    }
}

//push_front override
void SortedSet::push_front(int value) {
    add(value);
}

//push_back override
void SortedSet::push_back(int value) {
    add(value);
}

//insert_ordered override
void SortedSet::insert_ordered(int value) {
    add(value);
}

//operator |= (union assign)
SortedSet SortedSet::operator|=(const SortedSet& rhs) {
    SortedSet unionAssign;
    unionAssign = operator|(rhs);
    return IntList::operator=(unionAssign);

}

//operator &= (intersection assign)
SortedSet SortedSet::operator&=(const SortedSet& rhs) {
    SortedSet intersecAssign = operator&(rhs);
    return IntList::operator=(intersecAssign);
}