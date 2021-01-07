#include <iostream>
#include <string>
#include <vector>
#include "header.h"


using namespace std;

class Product
{
public:
    vector<string> item_data;
    string itemName , itemType;
    int itemCode , quantity;
    double itemPrice;
    bool validinpt;

    int getProductID(int itemCode)
    {

        cout << "Enter Product ID: ";
        cin >> itemCode;
        return itemCode;
    }
    int showMenu()
    {

        int menu;
        cout << " Stock Managment System"
             << "\n\n"
             << endl;
        cout << " Sell Item--------------- >1" << endl;
        cout << " Add new item------------ >2" << endl;
        cout << " Restock Product--------- >3" << endl;
        cout << " Update Stock------------ >4" << endl;
        cout << " View Reports------------ >5" << endl;
        cout << " Quit Program------------ >6" << endl;
        cout << " Choose an Option > ";
        cin >> menu;

        return menu;
    }
};
