#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

    std::cout << " Enter Product ID: " << std::endl;
    std::cin >> id;
    item_exists(std::to_string(id));
    set_product_id(id);

    // checking if input is not an integer
    if (!std::cin)
    {
        valid = false;
        std::cout << "\n\n"
                  << "Item Code must be an Integer" << '\n'
                  << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // checking if ID is not 4 digits long
    else if (std::to_string(get_product_id()).length() != 4)
    {
        std::cout << "\n\n"
                  << "ID Must be 4 digits...."
                  << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // checking if item already exists
    else if (exists)
    {
        std::cout << "\n\n"
                  << "item with ID:"
                  << get_product_id()
                  << " already exists"
                  << std::endl;
    }
    else
    {
        set_product_id(id);
        item_data.push_back(std::to_string(get_product_id()));

        std::cout << " Enter Item Name     : " << std::endl;
        std::cin >> name;
        set_product_name(name);

        item_data.push_back(get_product_name());

        std::cout << " Enter Item Type     : " << std::endl;
        std::cin >> itm_type;
        itm_type = stringToUpper(itm_type);
        // checking if type is either CD DVD Book or Magazine
        if (!valid_Type(itm_type))
        {
            std::cout << "\n\n"
                      << "Invalid Type" << std::endl;
            std::cout << "Accepted Types: CD DVD BOOK MAGAZINE" << std::endl;
            std::cin.clear();
            item_data.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {

            set_product_type(itm_type);
            item_data.push_back(get_product_type());

            std::cout << " Enter Item Price    : " << std::endl;
            std::cin >> price;

            if (!valid_inpt())
            {
                std::cout << "Invalid Price";
                item_data.clear();
            }
            else
            {
                set_product_price(price);
                tmp = std::to_string(get_product_price());
                item_data.push_back(tmp.substr(0, 5));
            

            std::cout << " Enter Item Quantity : " << std::endl;
            std::cin >> qntty;

            if (!valid_inpt())
            {
                std::cout << "Invalid Price";
                item_data.clear();
            }
            else
            {
                set_product_quantity(qntty);
                item_data.push_back(std::to_string(get_product_quantity()));
                item_data.push_back("nl");

                std::cout << "\n"<<"Item has been saved" << "\n" << std::endl;
            
            }
            }
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

    if (ReadFile.is_open())
    {
        while (getline(ReadFile, line))
        {
            if (id == line.substr(0, 4))
            {
                exists = true;
                break;
            }
            else
            {
                exists = false;
            }
        }
        ReadFile.close();
    }
}