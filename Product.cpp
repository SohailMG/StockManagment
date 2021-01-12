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

// getters and setters 
int Product::get_product_id(){
    return itemCode;
}
void Product::set_product_id(int id){
    itemCode = id;
}
std::string Product::get_product_name(){
    return itemName;
}
void Product::set_product_name(std::string name){
    itemName = name;
}
std::string Product::get_product_type(){
    return itemType;
}
void Product::set_product_type(std::string type){
    itemType = type;
}

double Product::get_product_price(){
    return itemPrice;
}
void  Product::set_product_price(double price){
    itemPrice = price;
}
int Product::get_product_quantity(){
    return quantity;

}
void Product::set_product_quantity(int qtty){
    quantity = qtty;
}

/**
 * parses through the inventory file and displays
 * data of all currently stored items as a table 
*/
void Product::show_inventory()
{
    std::string line;
    std::string tempString;
    std::ifstream sales("Inventory.txt");
    std::cout << "ID"
              << "\t\t"
              << "Name"
              << "\t\t"
              << "Type"
              << "\t\t"
              << "Price"
              << "\t\t"
              << "Quantity"
              << "\t\t" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    while (getline(sales, line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        getline(ss, tempString, ':');
        set_product_id(stoi(tempString));

        std::cout << get_product_id() << "\t\t";

        getline(ss, tempString, ':');
        set_product_name(tempString);

        std::cout << get_product_name() << "\t\t";

        getline(ss, tempString, ':');
        set_product_type(tempString);

        std::cout << get_product_type() << "\t\t";

        getline(ss, tempString, ':');
        set_product_price(stoi(tempString));


        std::cout << "£" << get_product_price() << "\t\t";

        getline(ss, tempString, ':');
        set_product_quantity(stoi(tempString));
        std::cout << get_product_quantity() << "\t\t";

        std::cout << "\t\t" << '\n';
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
    
}

/**
 * parses through the datafile and reads custom data of
 * passed id and prints them out to the console.
 * @param id product id
*/
void Product::show_product(std::string id)
{
    std::string tmpp,line;
    std::ifstream datafile("Inventory.txt");
    while (getline(datafile, line))
    {
        if (line == "")
            continue;

        if (id == line.substr(0, 4))
        {
            // updating product quantity that matches item to be sold
            std::stringstream ss(line);
            getline(ss, tmpp, ':');
            itemCode = stoi(tmpp);
            getline(ss, itemName, ':');
            getline(ss, itemType, ':');
            getline(ss, tmpp, ':');
            itemPrice = stoi(tmpp);
            getline(ss, tmpp, ':');
            quantity = stoi(tmpp) ;
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
