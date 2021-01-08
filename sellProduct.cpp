#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"

class SellProduct : public Product
{

public:
    string line , tempString;
    vector<string> items_sold;
    int num_of_sold = 1;
    int sold_quantity;

    void readInventory()
    {
        std::ofstream tempFile("temp.txt");
        std::ifstream datafile("Inventory.txt");
        std::ofstream sales("sales.txt", std::ios_base::app);
        if (!datafile.is_open())
        {
            cout << "File failed to open " << endl;
        }

        string id = to_string(Product::getProductID(itemCode));
        cout << "Sold Quantity > ";
        cin >> sold_quantity;
        cout << "Item sold...." << endl;

        while ( getline(datafile, line))
        {
            if (line == "") continue;

            if (id == line.substr(0, 4))
            {
                stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);
                getline(ss, itemName,   ':');
                getline(ss, itemType,   ':');
                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);
                getline(ss, tempString, ':');
                quantity = stoi(tempString) - sold_quantity;

                tempFile
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << endl;
                sales
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << endl;

                

            }
            if (id != line.substr(0, 4))
            {
                stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);
                getline(ss, itemName, ':');
                getline(ss, itemType, ':');
                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);
                getline(ss, tempString, ':');
                quantity = stoi(tempString);

                tempFile
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << endl;
            }
        }
        tempFile.close();
    }



    void view_sales()
    {

        ifstream sales("sales.txt");


        while ( getline(sales, line))
        {
            if (line == "") continue;

        cout << "--------Product " << num_of_sold++ << "--------"<< endl;
                stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);

                cout << "ID      : " <<itemCode << endl;

                getline(ss, itemName, ':');

                cout << "Name    : " <<itemName << endl;

                getline(ss, itemType, ':');

                cout << "Type    : " <<itemType << endl;

                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);

                cout << "Price   : £" << itemPrice << endl;
                
                

                cout << '\n';
            
        }
        
        
    }
};