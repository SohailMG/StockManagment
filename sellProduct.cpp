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
    int sold_quantity;

    void readInventory()
    {
        ofstream tempFile("temp.txt");
        ifstream datafile("Inventory.txt");
        if (!datafile.is_open())
        {
            cout << "File failed to open " << endl;
        }

        string id = to_string(getProductID(itemCode));
        cout << "Sold Quantity > ";
        cin >> sold_quantity;

        while ( getline(datafile, line))
        {
            if (line == "") continue;

            if (id == line.substr(0, 4))
            {
                stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);
                getline(ss, itemName, ':');
                getline(ss, itemType, ':');
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

    int sellProduct(int ID)
    {

        cout << " Item Sold : " << ID << endl;
    }
};