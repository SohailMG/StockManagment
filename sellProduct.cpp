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
        // opening a temp file to store modified data temperarly
        std::ofstream tempFile("temp.txt");
        std::ifstream datafile("Inventory.txt");
        std::ofstream sales("sales.txt", std::ios_base::app);
        if (!datafile.is_open())
        {
            std::cout << "File failed to open " << std::endl;
        }

        // getting product ID from user and sold quantity
        std::string id = std::to_string(Product::getProductID(itemCode));
        std::cout << "Sold Quantity > ";
        std::cin >> sold_quantity;

        while ( getline(datafile, line))
        {
            if (line == "") continue;

            if (id == line.substr(0, 4))
            {
                std::stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);
                getline(ss, itemName,   ':');
                getline(ss, itemType,   ':');
                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);
                getline(ss, tempString, ':');
                quantity = stoi(tempString) - sold_quantity;

                // printing detials of item sold 
                std::cout << "Item Sold " << std::endl;
                std::cout << "ID    : "  << itemCode<< std::endl;
                std::cout << "Name  : "  << itemName<< std::endl;
                std::cout << "Type  : "  << itemType<< std::endl;
                std::cout << "Price : "  << itemPrice<< std::endl;

                // storing data of item sold in a temp file
                tempFile
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << std::endl;

                // storing detials of item sold in sales file for sales report    
                sales
                    << itemCode << ':'
                    << itemName << ':'
                    << itemType << ':'
                    << itemPrice << ':'
                    << quantity << std::endl;

                

            }
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



    void SellProduct::view_sales()
    {

        std::ifstream sales("sales.txt");


        while ( getline(sales, line))
        {
            if (line == "") continue;

        std::cout << "--------Product " << num_of_sold++ << "--------"<< std::endl;
                std::stringstream ss(line);
                getline(ss, tempString, ':');
                itemCode = stoi(tempString);

                std::cout << "ID      : " <<itemCode << std::endl;

                getline(ss, itemName, ':');

                std::cout << "Name    : " <<itemName << std::endl;

                getline(ss, itemType, ':');

                std::cout << "Type    : " <<itemType << std::endl;

                getline(ss, tempString, ':');
                itemPrice = stoi(tempString);

                std::cout << "Price   : £" << itemPrice << std::endl;
                
                

                std::cout << '\n';
            
        }
        
        
    }
