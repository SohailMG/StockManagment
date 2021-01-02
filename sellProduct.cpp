#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"





class SellProduct : public Product
{

public:
    string line;
    string tempString;

    void readInventory(){
        ifstream datafile("Inventory.txt");
        if (!datafile.is_open())
        {
            cout << "File failed to open "<<endl;
        
        }


        while (getline(datafile, line))
        {
            stringstream ss(line);

            getline(ss, tempString,':');
            itemCode = stoi(tempString);
            getline(ss, itemName,':');
            getline(ss, itemType,':');
            getline(ss, tempString,':');
            itemPrice = stoi(tempString);

            cout << itemCode << itemType << itemName << itemPrice << endl;
        }
        
        



        
    }

    int sellProduct(int ID)
    {


        cout << " Item Sold : " << ID << endl;
    }
};