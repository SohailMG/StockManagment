#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;





class AddProduct : public Product
{
    public:
        ofstream outfile;
        string tmp;
    
    void product_info()
    {
        // opening file in append mode
        outfile.open("Inventory.txt",std::ios_base::app);

        // storing info of new item into a vector
        cout << " Enter Item Code     : " << endl;
        cin >> itemCode;
        item_data.push_back(to_string(itemCode));

        cout << " Enter Item Name     : " << endl;
        cin >> itemName;
        item_data.push_back(itemName);

        cout << " Enter Item Type     : " << endl;
        cin >> itemType;
        item_data.push_back(itemType);

        cout << " Enter Item Price    : " << endl;
        cin >> itemPrice;
        tmp = to_string(itemPrice);
        item_data.push_back(tmp.substr(0,5));
        

        cout << " Enter Item Quantity : " << endl;
        cin >> quantity;
        item_data.push_back(to_string(quantity));

        // looping through vector and writing new item data into a file
        for (size_t i = 0; i < item_data.size(); i++)
        {
            outfile << item_data[i] << ':';
            
        }
        outfile << '\n';
        
        
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