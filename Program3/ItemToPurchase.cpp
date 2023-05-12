#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

//default constructor
ItemToPurchase::ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

//parameterized constructor
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    _name = name;
    _description = description;
    _price = price;
    _quantity = quantity;
}

//mutators definitions
void ItemToPurchase::setName(string name) {
    _name = name;
}

void ItemToPurchase::setPrice(int price) {
    _price = price;
}

void ItemToPurchase::setQuantity(int quantity) {
    _quantity = quantity;
}

void ItemToPurchase::setDescription(string description) {
    _description = description;
}

//accessors definitions
string ItemToPurchase::name() const {
    return _name;
}

int ItemToPurchase::price() const {
    return _price;
}

int ItemToPurchase::quantity() const {
    return _quantity;
}

string ItemToPurchase::description() const {
    return _description;
}

//public functions
void ItemToPurchase::printItemCost() const {
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << (_quantity * _price) << endl;
}

void ItemToPurchase::printItemDescription() const {
    cout << _name << ": " << _description << endl;
}
