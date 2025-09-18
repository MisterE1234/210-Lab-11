//COMSC-210|Lab 11|Ethan Aylard
//Ide used: Visual Studio Code

#include <iostream>
using namespace std;

struct order{
   
    string customerName;
    string* itemName;
    int* itemCount;
    double* itemPrice;
    double totalPrice;
}


int main(){
    
    int numItems;
    order customerOrder;

    cout << "Enter customer name: ";
    getline(cin, customerOrder.customerName);

    cout << "Enter number of items: ";
    cin >> numItems;

    customerOrder.itemName = new string[numItems];
    customerOrder.itemCount = new int[numItems];
    customerOrder.itemPrice = new double[numItems];

    for(int i = 0; i < numItems; i++){
        cout << "Enter item name: ";
        cin >> customerOrder.itemName[i];
        cout << "Enter item count: ";
        cin >> customerOrder.itemCount[i];
        cout << "Enter item price: ";
        cin >> customerOrder.itemPrice[i];
    }

    customerOrder.totalPrice = 0;
    for(int i = 0; i < numItems; i++){
        customerOrder.totalPrice += customerOrder.itemCount[i] * customerOrder.itemPrice[i];
    }

    cout << "\nCustomer Name: " << customerOrder.customerName << endl;
    cout << "Total Price: $" << customerOrder.totalPrice << endl;

    delete[] customerOrder.itemName;
    delete[] customerOrder.itemCount;
    delete[] customerOrder.itemPrice;

    return 0;
}