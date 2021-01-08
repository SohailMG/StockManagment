#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "sellProduct.h"
/**
 * sellProduct.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 02/01/2021
 * Updated: 08/01/2021
 * 
*/

 SellProduct::SellProduct()
{
    num_of_sold = 1;

};

    void SellProduct::readInventory()
    {
        ofstream tempFile("temp.txt");
        ifstream datafile("Inventory.txt");
        ofstream sales("sales.txt", std::ios_base::app);
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



    void SellProduct::view_sales()
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
