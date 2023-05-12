#include <iostream>
#include <vector>
using namespace std;
#include "ShoppingCart.h"

void printMenu(ShoppingCart myCart);
void printOptions();

int main() {
    string customerName;
    string datePurchased;
    cout << "Enter customer's name: ";
    getline(cin, customerName);
    cout << endl;
    cout << "Enter today's date: ";
    getline(cin, datePurchased);
    cout << endl << endl;

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << datePurchased << endl << endl;

    ShoppingCart myCart(customerName, datePurchased);
    printMenu(myCart);

    return 0;
}

void printOptions() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
}
void printMenu(ShoppingCart myCart) {
    string userItemName;
    string userItemDescription;
    int userItemPrice;
    int userItemQuantity;
    char userOption;
    ItemToPurchase myItem;
    printOptions();

    cout << "Choose an option: ";
    cin >> userOption;
    cout << endl;

    while (userOption != 'q') {
        if (userOption == 'o') {
            cout << endl;
            cout << "OUTPUT SHOPPING CART" << endl;
            myCart.printTotal();
            cout << endl;
            printOptions();
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
        else if (userOption == 'i') {
            cout << endl;
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            myCart.printDescriptions();
            cout << endl;
            printOptions();
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
        else if (userOption == 'a') {
            cout << endl;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: ";
            cin.ignore();
            getline(cin, userItemName);
            cout << endl << "Enter the item description: ";
            getline(cin, userItemDescription);
            cout << endl << "Enter the item price: ";
            cin >> userItemPrice;
            cout << endl << "Enter the item quantity: ";
            cin >> userItemQuantity;
            cout << endl << endl;

            myItem.setName(userItemName);
            myItem.setDescription(userItemDescription);
            myItem.setPrice(userItemPrice);
            myItem.setQuantity(userItemQuantity);

            myCart.addItem(myItem);

            printOptions();
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
        else if (userOption == 'd') {
            cout << endl;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: ";
            cin.ignore();
            getline(cin, userItemName);
            cout << endl;
            myCart.removeItem(userItemName);
            cout << endl;
            printOptions();
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
        else if (userOption == 'c') {
            cout << endl;
            ItemToPurchase myModifiedItem;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: ";
            cin.ignore();
            getline(cin, userItemName);
            cout << endl << "Enter the new quantity: ";
            cin >> userItemQuantity;
            cout << endl;

            myModifiedItem.setQuantity(userItemQuantity);
            myModifiedItem.setName(userItemName);
            myCart.modifyItem(myModifiedItem);
            cout << endl;

            printOptions();
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
        else {
            cout << "Choose an option: ";
            cin >> userOption;
            cout << endl;
        }
    }
}