#include <iostream>
#include <vector>
using namespace std;
#include "ShoppingCart.h"

//default constructor
ShoppingCart::ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

//parameterized constructor
ShoppingCart::ShoppingCart(string name, string date) {
    _customerName = name;
    _currentDate = date;
}

//accessors
string ShoppingCart::customerName() const {
    return _customerName;
}

string ShoppingCart::date() const {
    return _currentDate;
}

//other public member functions
void ShoppingCart::addItem(ItemToPurchase item) {
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(string itemName) {
    bool isFound = false;
    unsigned int removeIndex;
    for (unsigned int i = 0; i < _cartItems.size() && !isFound; ++i) {
        if (_cartItems.at(i).name() == itemName) {
            isFound = true;
            removeIndex = i;
        }
    }

    if (isFound) {
        _cartItems.erase(_cartItems.begin() + removeIndex);
    }
    else {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase item) {
    bool isFound = false;
    unsigned int modifyIndex;
    for (unsigned int i = 0; i < _cartItems.size() && !isFound; ++i) {
        if (_cartItems.at(i).name() == item.name()) {
            isFound = true;
            modifyIndex = i;
        }
    }

    if (isFound) {
        if (item.price() != 0) {
            _cartItems.at(modifyIndex).setPrice(item.price());
        }
        if (item.description() != "none") {
            _cartItems.at(modifyIndex).setDescription(item.description());
        }
        if (item.quantity() != 0) {
            _cartItems.at(modifyIndex).setQuantity(item.quantity());
        }
    }
    else {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::numItemsInCart() const {
    int totalQuantity = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        totalQuantity += _cartItems.at(i).quantity();
    }
    return totalQuantity;
}

int ShoppingCart::costOfCart() const {
    int totalCost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        totalCost += (_cartItems.at(i).price()) * (_cartItems.at(i).quantity());
    }
    return totalCost;
}

void ShoppingCart::printTotal() const {
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    if (numItemsInCart() != 0) {
        cout << "Number of Items: " << numItemsInCart() << endl << endl;
        for (unsigned int i = 0; i < _cartItems.size(); ++i) {
            cout << _cartItems.at(i).name() << " " << _cartItems.at(i).quantity() << " @ $" << _cartItems.at(i).price() << " = $" << _cartItems.at(i).quantity() * _cartItems.at(i).price() << endl;
        }
        cout << endl << "Total: $" << costOfCart() << endl;
    }
    else {
        cout << "Number of Items: 0" << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $0" << endl;
    }
}

void ShoppingCart::printDescriptions() const {
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        cout << _cartItems.at(i).name() << ": " << _cartItems.at(i).description() << endl;
    }
}

