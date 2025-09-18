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
void getOrder(order* ,int );
void calculateTotal(order *,int );
void displayOrder(order *,int ,int);

int main(){
    //Prompt the user to enter the number of items they would like to order.
    int size;
    int orderAmount;
    bool validInput = false;
    char response;

    cout << "Welcome to the order system!" << endl;
    cout << "How many orders would you like to place? ";
    cin >> orderAmount;
    cin.ignore();


    order *custOrder = nullptr;
    custOrder = new order[];
    custOrder->itemName = new string[size];
    custOrder->itemCount = new int[size];
    custOrder->itemPrice = new double[size];


    for (int i = 0; i < orderAmount; i++){ {
       
    
        cout << "Enter the number of items you would like to order: ";
        cin >> size;
        cin.ignore();

        

        getOrder(custOrder[i], size);
        calculateTotal(custOrder[i], size);
        displayOrder(custOrder[], size, orderAmount);
    }    

    delete[] custOrder->itemName;
    delete[] custOrder->itemCount;
    delete[] custOrder->itemPrice;
    delete custOrder;
    

    return 0;
}

void getOrder(order* custOrder, int size){
    //Prompt the user to enter the customer name.
    cout << "Enter customer name: ";
    getline(cin, custOrder->customerName);

    //Use a loop to prompt the user to enter the item names, counts, and prices for each item.
    for (int i = 0; i < size; i++){
        cout << "Enter item name: ";
        getline(cin, custOrder->itemName[i]);
        cout << "Enter item count: ";
        cin >> custOrder->itemCount[i];
        cout << "Enter item price: ";
        cin >> custOrder->itemPrice[i];
        cin.ignore();
    }
}

void calculateTotal(order* custOrder, int size){
    //Use a loop to calculate the total price of the order by multiplying each item's count by its price and summing the results.
    custOrder->totalPrice = 0;
    for (int i = 0; i < size; i++){
        custOrder->totalPrice += custOrder->itemCount[i] * custOrder->itemPrice[i];
    }
}

void displayOrder(order* custOrder, int size, int orderAmount){
    //Display the customer name.
    cout << "Customer Name: " << custOrder->customerName << endl;

    //Use a loop to display each item's name, count, and price.
    for (int i = 0; i < size; i++){
        cout << "Item Name: " << custOrder->itemName[i] << endl;
        cout << "Item Count: " << custOrder->itemCount[i] << endl;
        cout << "Item Price: $" << custOrder->itemPrice[i] << endl;
    }

    //Display the total price of the order.
    cout << "Total Price: $" << custOrder->totalPrice << endl;
}