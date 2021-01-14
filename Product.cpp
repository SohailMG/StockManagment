#include <iostream>
#include <fstream>
#include <sstream>
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

void Product::add_product()
{

    // storing info of new item into a vector

    std::cout << " Enter Product ID: " << std::endl;
    std::cin >> item_id;

    // checking if input is not an integer
    if (!std::cin)
    {
        std::cout << "\n\n"
                  << "Item Code must be an Integer" << '\n'
                  << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // checking if ID is not 4 digits long
    item_data.push_back(std::to_string(item_id));



    std::cout << " Enter Item Name    : " << std::endl;
    std::cin >> item_name;
    item_data.push_back(item_name);
    std::cout << " Enter Item tpye    : " << std::endl;
    std::cin >> item_type;
    item_data.push_back(item_type);
    std::cout << " Enter Item Price    : " << std::endl;
    std::cin >> item_price;

    std::string tmp = std::to_string(item_price);
    item_data.push_back(tmp.substr(0, 5));

    std::cout << " Enter Item Quantity : " << std::endl;
    std::cin >> item_quantity;

    item_data.push_back(std::to_string(item_quantity));
}

// looping through vector and writing new item data into a file

void Product::store_product(std::string location)
{
    std::fstream outfile;
    outfile.open(location, std::ios_base::app);
    for (int i = 0; i < item_data.size(); i++)
    {
        if (item_data[i] == "ln")
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
int Product::sell_product()
{
    int id;
    std::cout << "Enter Item ID > ";
    std::cin >> id;

    return id;
}
int Product::restock_product()
{
    int id;
    int restock_amount;
    std::cout << "Enter Item ID > ";
    std::cin >> id;



    return id;
}

void Product::update_stock(std::string location)
{
    std::string lines;
    std::ofstream outfile;

    bool deleted_old;

    outfile.open(location, std::ios_base::app);
    if (remove(location.c_str()))
        deleted_old = true;
    else
        deleted_old = false;

    outfile.close();

    std::ifstream temp("temp.txt");
    if (deleted_old)
    {
        outfile.open(location, std::ios_base::app);
    }
    while (getline(temp, lines))
    {

        std::ofstream outfile(location, std::ios_base::app);
        outfile << lines;
        outfile << '\n';
    }
    outfile.close();
    std::cout << "\n\n"
              << std::endl;
    std::cout << "\t"
              << " *Stock Has been Update*" << std::endl;
}
void Product::view_sales(){

    std::string line, tempString;

    std::ifstream sales("sales.txt");
    
    std::cout << "\n";
    std::cout << "ID"
              << "\t\t"
              << "Price"
              << "\t\t"
              << "Quantity"
              << "\t\t" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    while (getline(sales, line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        getline(ss, tempString, ':');
        set_product_id(stoi(tempString));
        std::cout << get_product_id() << "\t\t";

        getline(ss, tempString, ':');
        set_product_price(stoi(tempString));
        std::cout << "£"<<get_product_price() << "\t\t";

        getline(ss, tempString, ':');
        set_product_quantity(stoi(tempString));
        std::cout << get_product_quantity() << "\t\t" << std::endl;

    }
    std::cout << "------------------------------------------------" << std::endl;
    sales.close();
}


// getters and setters
int Product::get_product_id()
{
    return item_id;
}
void Product::set_product_id(int id)
{
    item_id = id;
}
std::string Product::get_product_type()
{
    return item_type;
}
std::string Product::get_product_name()
{
    return item_name;
}
void Product::set_product_type(std::string type)
{
    item_type = type;
}
void Product::set_product_name(std::string name)
{
    item_name = name;
}

double Product::get_product_price()
{
    return item_price;
}
void Product::set_product_price(double price)
{
    item_price = price;
}
int Product::get_product_quantity()
{
    return item_quantity;
}
void Product::set_product_quantity(int qtty)
{
    item_quantity = qtty;
}