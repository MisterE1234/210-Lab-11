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
    int itemSize;
    string* itemName;
    int* itemCount;
    double* itemPrice;
    double totalPrice;
};

//Function prototypes
void getOrder(order* ,int);
void calculateTotal(order *,int);
void displayOrder(order *,int);

int main(){
    //Prompt the user to enter the number of items they would like to order.
    int orderAmount;
    bool validInput = false;
    char response;

    cout << "Welcome to the order system!" << endl;
    cout << "How many orders would you like to place? ";
    cin >> orderAmount;
    cin.ignore();


    order *custOrder = nullptr;
    custOrder = new order[orderAmount];
    


    for (int i = 0; i < orderAmount; i++){ {
       
    
        cout << "Enter the number of items you would like to order: ";
        cin >> custOrder[i].itemSize;
        cin.ignore();

        custOrder[i].itemName = nullptr;
        custOrder[i].itemName = new string[custOrder[i].itemSize];
        custOrder[i].itemCount = nullptr;
        custOrder[i].itemCount = new int[custOrder[i].itemSize];
        custOrder[i].itemPrice = nullptr;
        custOrder[i].itemPrice = new double[custOrder[i].itemSize];

        getOrder(custOrder, i);
        calculateTotal(custOrder,i);
        displayOrder(custOrder, orderAmount);
    }    

    for (int i = 0; i < orderAmount; i++){
        delete[] custOrder[i].itemName;
        delete[] custOrder[i].itemCount;
        delete[] custOrder[i].itemPrice;
    }
    delete[] custOrder;
    

    return 0;
}

void getOrder(order* custOrder, int orderPlace){
    //Prompt the user to enter the customer name.
    cout << "Enter customer name: ";
    getline(cin, custOrder[orderPlace].customerName);

    //Use a loop to prompt the user to enter the item names, counts, and prices for each item.
    for (int i = 0; i < custOrder[orderPlace].itemSize; i++){
        cout << "Enter item name: ";
        getline(cin, custOrder[orderPlace].itemName[i]);
        cout << "Enter item count: ";
        cin >> custOrder[orderPlace].itemCount[i];
        cout << "Enter item price: ";
        cin >> custOrder[orderPlace].itemPrice[i];
        cin.ignore();
    }
}

void calculateTotal(order* custOrder, int orderPlace){
    //Use a loop to calculate the total price of the order by multiplying each item's count by its price and summing the results.
    custOrder[orderPlace].totalPrice = 0;
    for (int i = 0; i < custOrder[orderPlace].itemSize; i++){
        custOrder[orderPlace].totalPrice += custOrder[orderPlace].itemCount[i] * custOrder[orderPlace].itemPrice[i];
    }
}

void displayOrder(order* custOrder, int orderAmount){
    //Display the customer name.
    for (int x = 0; x < orderAmount; x++){
        cout << "Order " << x + 1 << ":" << endl;
        
    
    cout << "Customer Name: " << custOrder[x].customerName << endl;

    //Use a loop to display each item's name, count, and price.
    for (int i = 0; i < custOrder[x].itemSize; i++){
        cout << "Item Name: " << custOrder[x].itemName[i] << endl;
        cout << "Item Count: " << custOrder[x].itemCount[i] << endl;
        cout << "Item Price: $" << custOrder[x].itemPrice[i] << endl;
    }

    //Display the total price of the order.
    cout << "Total Price: $" << custOrder.totalPrice << endl;
    }
}