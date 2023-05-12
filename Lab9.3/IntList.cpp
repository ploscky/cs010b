#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

//helper exist function
bool IntList::exists(IntNode *listNode, int value) const {
    if (listNode == nullptr) {
        return false;
    }
    if (listNode->value == value) {
        return true;
    }
    else {
        listNode = listNode->next;
        if (exists(listNode, value)) {
            return true;
        }
        else {
            return false;
        }
    }
}

//exist function
bool IntList::exists(int value) const {
    return exists(head, value);
}

//helper ostream function
ostream & operator<<(ostream &out, IntNode *listNode) {
    if (listNode == nullptr) {
        return out;
    }
    if (listNode->next == nullptr) {
        out << listNode->value;
        return out;
    }
    else {
        out << listNode->value << ' ';
        listNode = listNode->next;
        operator<<(out, listNode);
        return out;
    }
}

//friend function
ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* node = rhs.head;
    operator<<(out, node);
    return out;
}