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
void calculateTotal(order*,int);
void displayOrder(order*,int);

int main(){
    //Prompt the user to enter the number of items they would like to order.
    int orderAmount;
    bool validInput = false;
    char response;

    cout << "Welcome to the order system!" << endl;
    cout << "How many orders would you like to place? ";
    cin >> orderAmount;
    cin.ignore();

    //Dynamically allocate an array of structures of type order based on the number of items the user wants to order.
    order *custOrder = nullptr;
    custOrder = new order[orderAmount];
    

    //Use a loop to call the getOrder(), calculateTotal(), and displayOrder() functions for each order.
    for (int i = 0; i < orderAmount; i++){ 
       
        //Prompt the user to enter the number of items they would like to order.
        cout << "Enter the number of items you would like to order: ";
        cin >> custOrder[i].itemSize;
        cin.ignore();

        //Dynamically allocate the arrays for item names, counts, and prices based on the number of items the user wants to order.
        custOrder[i].itemName = nullptr;
        custOrder[i].itemName = new string[custOrder[i].itemSize];
        custOrder[i].itemCount = nullptr;
        custOrder[i].itemCount = new int[custOrder[i].itemSize];
        custOrder[i].itemPrice = nullptr;
        custOrder[i].itemPrice = new double[custOrder[i].itemSize];

        //Call the getOrder(), calculateTotal(), and displayOrder() functions for each order.
        
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

//getOrder() is meant to gather user input for a specific order.
//Arguments: a structure of type order and an integer representing the order's position in the array.
//Returns: nothing.
void getOrder(order* custOrder, int orderPlace){
    //Prompt the user to enter the customer name.
    cin.clear();
    cin.ignore(1000, '\n');
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

//calculateTotal() is meant to calculate the total price of a specific order.
//Arguments: a structure of type order and an integer representing the order's position in the array
//Returns: nothing.
void calculateTotal(order* custOrder, int orderPlace){
    //Use a loop to calculate the total price of the order by multiplying each item's count by its price and summing the results.
    custOrder[orderPlace].totalPrice = 0;
    for (int i = 0; i < custOrder[orderPlace].itemSize; i++){
        custOrder[orderPlace].totalPrice += custOrder[orderPlace].itemCount[i] * custOrder[orderPlace].itemPrice[i];
    }
}

//displayOrder() is meant to display the details of all orders added so far.
//Arguments: a structure of type order and an integer representing the order's position in the array
//Returns: nothing.
void displayOrder(order* custOrder, int orderAmount){
    
    //Use a loop to display the details of each order.
    for (int x = 0; x < orderAmount; x++){
        //Display the customer name.
        cout << "Order " << x + 1 << ":" << endl;
        
    
    cout << "Customer Name: " << custOrder[x].customerName << endl;

    //Use a loop to display each item's name, count, and price.
    for (int i = 0; i < custOrder[x].itemSize; i++){
        cout << "Item Name: " << custOrder[x].itemName[i] << endl;
        cout << "Price per: $" << custOrder[x].itemPrice[i] << ", ";
        cout << "Count: " << custOrder[x].itemCount[i] << endl;
        
    }

    //Display the total price of the order.
    cout << "Total Price: $" << custOrder[x].totalPrice << "\n" << endl;
    }
}