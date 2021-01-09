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

/**
 * opens Inventory file and parses through for a product ID matches
 * user input. if match found, item quantity is decreased by given input.
 * updated data is stored in temp file and sold item is stored in sales file
*/
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
    std::string id = std::to_string(Product::get_product_id(itemCode));
    show_product(id);
    std::cout << "Sold Quantity > ";
    std::cin >> sold_quantity;


    while (getline(datafile, line))
    {
        if (line == "")
            continue;


        
        if (id == line.substr(0, 4))
        {
            // updating product quantity that matches item to be sold
            std::stringstream ss(line);
            getline(ss, tempString, ':');
            itemCode = stoi(tempString);
            getline(ss, itemName, ':');
            getline(ss, itemType, ':');
            getline(ss, tempString, ':');
            itemPrice = stoi(tempString);
            getline(ss, tempString, ':');
            quantity = stoi(tempString) - sold_quantity;

            // printing detials of item sold
            std::cout << "\n\n"
                      << std::endl;
            std::cout << "\t\t"
                      << "Item Sold " << std::endl;
            std::cout << "\t\t"
                      << "ID    : " << itemCode << std::endl;
            std::cout << "\t\t"
                      << "Name  : " << itemName << std::endl;
            std::cout << "\t\t"
                      << "Type  : " << itemType << std::endl;
            std::cout << "\t\t"
                      << "Price : " << itemPrice << std::endl;

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
            // storing products not matching given id to temp file unchanged
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
/**
 * opens sales file and reads all strings seperate by a colon then prints
 * it's content into the console
*/
void SellProduct::view_sales()
{

    std::ifstream sales("sales.txt");

    while (getline(sales, line))
    {
        if (line == "")
            continue;
        std::cout << "\n\n"
                  << std::endl;
        std::cout << "\t\t"
                  << "--------Product " << num_of_sold++ << "--------" << std::endl;
        std::stringstream ss(line);
        getline(ss, tempString, ':');
        itemCode = stoi(tempString);

        std::cout << "\t\t"
                  << "ID      : " << itemCode << std::endl;

        getline(ss, itemName, ':');

        std::cout << "\t\t"
                  << "Name    : " << itemName << std::endl;

        getline(ss, itemType, ':');

        std::cout << "\t\t"
                  << "Type    : " << itemType << std::endl;

        getline(ss, tempString, ':');
        itemPrice = stoi(tempString);

        std::cout << "\t\t"
                  << "Price   : £" << itemPrice << std::endl;

        std::cout << "\t\t" << '\n';
    }
}
