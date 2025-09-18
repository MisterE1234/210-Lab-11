//COMSC-210|Lab 11|Ethan Aylard
//Ide used: Visual Studio Code

#include <iostream>
using namespace std;

//Define a structure named order that contains the following members in order to create a customer order:
//A string to hold the customer name.
//A dynamic array of strings to hold the item names.
//A dynamic array of integers to hold the item counts.
//A dynamic array of doubles to hold the item prices.
//A double to hold the total price of the order.
struct order{
   
    string customerName;
    string* itemName;
    int* itemCount;
    double* itemPrice;
    double totalPrice;
}

//Function prototypes
void getOrder(order* custOrder, int size);
void calculateTotal(order *custOrder, int size);
void displayOrder(order *custOrder, int size);

int main(){
    //Prompt the user to enter the number of items they would like to order.
    int size;
    bool anotherOrder = true;
    char response;
    while (anotherOrder) {
        cout << "Would you like to place an order? (y/n): ";
        cin >> response;
        cin.ignore();
        if (response == 'y' || response == 'Y') {
            anotherOrder = true;
        } else if (response == 'n' || response == 'N') {
            anotherOrder = false;
            cout << "Thank you for using the order system. Goodbye!" << endl;
            return 0;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            continue;
        }
    
    cout << "Enter the number of items you would like to order: ";
    cin >> size;
    cin.ignore();

    order *custOrder = nullptr;
    custOrder = new order[];
    custOrder->itemName = new string[size];
    custOrder->itemCount = new int[size];
    custOrder->itemPrice = new double[size];

    getOrder(custOrder, size);
    calculateTotal(custOrder, size);
    displayOrder(custOrder, size);

    delete[] custOrder->itemName;
    delete[] custOrder->itemCount;
    delete[] custOrder->itemPrice;
    delete custOrder;
    }

    return 0;
}

