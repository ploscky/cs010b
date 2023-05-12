#include <iostream>
#include <vector>
using namespace std;
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "ItemToPurchase.h"

class ShoppingCart {
    public:

    //default constructor
    ShoppingCart();

    //parameterized constructor
    ShoppingCart(string name, string date);

    //name and date accessors
    string customerName() const;

    string date() const;

    /*Adds an item to cart items vector. 
    Has a parameter of type ItemToPurchase. Does not return anything.*/
    void addItem(ItemToPurchase item);

    /*Removes item from cart items vector. 
    Has a parameter of type string (an item's name). Does not return anything. 
    If item name cannot be found, output this message: Item not found in cart. Nothing removed.*/
    void removeItem(string itemName);

    /*Modifies an item's description, price, and/or quantity.
    Has a parameter of type ItemToPurchase. Does not return anything.
    If item can be found (by name) in cart, check if parameter variable has default values for description, price, and/or quantity.
    For each of the non-default values in parameter, set the item in the cart to the non-default value.
    For example, if the parameter has non-default values for quantity and price but a default value for the description, then just set the quantity and price in the cart item to the parameter's values for quantity and price and leave the cart item's description alone.
    If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.*/
    void modifyItem(ItemToPurchase item);

    //Returns quantity of all items in cart. Has no parameters.
    int numItemsInCart() const;

    //Determines and returns the total cost of items in cart. Has no parameters.
    int costOfCart() const;

    /*Outputs total of objects in cart.
    If cart is empty, output this message: SHOPPING CART IS EMPTY*/
    void printTotal() const;

    //Outputs each item's description.
    void printDescriptions() const;


    private:

    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};
#endif