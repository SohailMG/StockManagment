#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Product.h"
/**
 * Product.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 02/01/2021
 * Updated: 08/01/2021
 * 
*/

Product::Product()
{
}
/**
 * gets product id from user input
 * @param itemCode 
 * @returns product id as integer
*/
int Product::get_product_id(int itemCode)
{

    std::cout << "Enter Product ID: ";
    std::cin >> itemCode;
    return itemCode;
}
void Product::show_product(std::string id)
{
    std::string tempString,line;
    std::ifstream datafile("Inventory.txt");
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
            quantity = stoi(tempString) ;

            // printing detials of item sold
            std::cout << "\n\n"
                      << std::endl;
            std::cout << "\t\t"
                      << "Item details " << std::endl;
            std::cout << "\t\t"
                      << "ID             : " << itemCode << std::endl;
            std::cout << "\t\t"         
                      << "Name           : " << itemName << std::endl;
            std::cout << "\t\t"         
                      << "Type           : " << itemType << std::endl;
            std::cout << "\t\t"         
                      << "Price          :£" << itemPrice << std::endl;
            std::cout << "\t\t"
                      << "stock quantity : " << quantity << std::endl;
        }
    }
}
/**
 * checks for invalid user input and clears cin  
 * 
 * @returns boolean value if cin fails or succeeds
*/
bool Product::valid_inpt()
{
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
    {
        return true;
    }
}
