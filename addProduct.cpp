#include <iostream>
#include <string>
#include "header.h"

using namespace std;





class AddProduct : public Product
{
    public:
    void product_info()
    {

        cout << " Enter Item Code     : " << endl;
        cin >> itemCode;
        cout << " Enter Item Name     : " << endl;
        cin >> itemName;
        cout << " Enter Item Type     : " << endl;
        cin >> itemType;
        cout << " Enter Item Price    : " << endl;
        cin >> itemPrice;
        cout << " Enter Item Quantity : " << endl;
        cin >> quantity;
        
    }

    void show_added(){

        cout << "New Product added" << endl;
        cout << "ID       : "<< itemCode << endl;
        cout << "Name     : "<< itemName << endl;
        cout << "Type     : "<< itemType << endl;
        cout << "Price    : "<< itemPrice << endl;
        cout << "quantity : "<< quantity << endl;

    }
    
    

};