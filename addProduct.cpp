#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "addProduct.h"

/**
 * addProduct.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 02/01/2021
 * Updated: 08/01/2021
 * 
*/



AddProduct::AddProduct(){

};
/**
     * reads user input for product info such as
     * prodocut ID,Type,Name,Price and Quantity.
     * then stores these in a vector of strings
    */
void AddProduct::product_info()
{

    // storing info of new item into a vector
    std::cout << " Enter Item Code     : " << std::endl;
    std::cin >> itemCode;
    // checks if itemCode matches existing id
    item_exists(std::to_string(itemCode));
    

    // checking if input is not an integer
    if (!std::cin)
    {
        valid = false;
        std::cout << '\n'
             << "Item Code must be an Integer" << '\n'
             << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    // checking if ID is not 4 digits long
    else if (std::to_string(itemCode).length() != 4)
    {
        std::cout << "ID Must be 4 digits...." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // checking if item already exists
    else if(exists){
        std::cout << " item with " << itemCode << "already exists"<<std::endl;
    }
    else
    {

        item_data.push_back(std::to_string(itemCode));

        std::cout << " Enter Item Name     : " << std::endl;
        std::cin >> itemName;
        item_data.push_back(itemName);

        std::cout << " Enter Item Type     : " << std::endl;
        std::cin >> itemType;
        itemType = stringToUpper(itemType);
        // checking if type is either CD DVD Book or Magazine
        if (!valid_Type(itemType))
        {
            std::cout << "not found" << std::endl;
            std::cin.clear();
            item_data.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {

            item_data.push_back(itemType);

            std::cout << " Enter Item Price    : " << std::endl;
            std::cin >> itemPrice;
            tmp = std::to_string(itemPrice);
            item_data.push_back(tmp.substr(0, 5));

            std::cout << " Enter Item Quantity : " << std::endl;
            std::cin >> quantity;
            item_data.push_back(std::to_string(quantity));
            item_data.push_back("nl");
        }
    }
    // looping through vector and writing new item data into a file
}
/**
     * opens a text file in append mode,
     * then loops through item_data vector and writes
     * each elment in the vector into the text file
    */
void AddProduct::store_product()
{
    outfile.open("Inventory.txt", std::ios_base::app);
    for (size_t i = 0; i < item_data.size(); i++)
    {
        if (item_data[i] == "nl")
        {
            outfile << '\n';
        }
        else
        {

            outfile << item_data[i] << ':';
        }
    }
    outfile.close();
}
/**
     * checks if prduct type entered by user
     * matches any of the four below
     * @param type
     * @returns boolean value
    */
bool AddProduct::valid_Type(std::string type)
{
    if (type == "CD" ||
        type == "DVD" ||
        type == "BOOK" ||
        type == "MAGAZINE")
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
     * converts product type entered by the user to upper case
     * for easier string comparison.
     * @param str
     * @returns uppercase string
    */
std::string AddProduct::stringToUpper(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}
/**
 * parses through inventory file and checks if 
 * itemCode matches an existing item ID
 * if matches, exists = true
 * 
 * @param id product id entered by the user
*/
void AddProduct::item_exists(std::string id)
{
    std::string line;
    std::ifstream ReadFile;
    ReadFile.open("Inventory.txt");

    if (ReadFile.is_open()) {
        while(getline(ReadFile, line))
        {
            if (id == line.substr(0,4))
            {
                exists = true;
                break;
            }else{
                exists = false;
            }
            
        }
        ReadFile.close();
    }
    
}
