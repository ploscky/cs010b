#include <iostream>
using namespace std;
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
    public: 

    //default constructor
    ItemToPurchase();

    //parameterized constructor
    ItemToPurchase(string name, string description, int price, int quantity);

    //mutators to set name, price, quantity
    void setName(string name);

    void setPrice(int price);

    void setQuantity(int quantity);

    //accessors to get name, price, quantity
    string name() const;

    int price() const;

    int quantity() const;

    //description mutator and accessor
    void setDescription(string description);

    string description() const;

    //outputs the item name followed by the quantity, price, and subtotal
    void printItemCost() const;

    //outputs the item name and description
    void printItemDescription() const;



    private:

    string _name;
    int _price;
    int _quantity;
    string _description;
};

#endif