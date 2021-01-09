#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "RestockProduct.h"
/**
 * RestockProduct.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 06/01/2021
 * Updated: 08/01/2021
 * 
*/
RestockProduct::RestockProduct()
{

};

    /**
     * parses through text file of data seperate by colon 
     * and looks for data that matches ID given by user
     * if ID is found then a restock amount is added to the 
     * current quantity and then data is stored into a temperory file
     * 
     * 
    */
    void RestockProduct::readInventory()
    {
        std::ofstream tempFile("temp.txt");
        std::ifstream datafile("Inventory.txt");
        if (!datafile.is_open())
        {
            std::cout << "File failed to open " << std::endl;
        }

        // calling get_product_id and storing restock amount
        std::string id = std::to_string(get_product_id(itemCode));
        std::cout << "Restock Amount > ";
        std::cin >> restock_amount;

        // parsing through datafile
        while (getline(datafile, line))
        {
            if (line == "")
                continue;

            // checking if product id matches an exisiting id
            if (id == line.substr(0, 4))
            {
                std::stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);
                getline(ss, itemName, ':');
                getline(ss, itemType, ':');
                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);
                getline(ss, tempString, ':');
                quantity = stoi(tempString) + restock_amount;

                // storing line corrosponding to product in a temp file after restock
                tempFile
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << std::endl;

            }
            // storing products not matching given ID in temp file unmodified
            if (id != line.substr(0, 4))
            {
                std::stringstream ss(line);
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
                    << quantity << std::endl;
            }
        }
        tempFile.close();
    }