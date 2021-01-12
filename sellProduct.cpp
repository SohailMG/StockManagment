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
    std::string line , tempString;
    std::string id;
       // opening a temp file to store modified data temperarly  
       // opening a temp file to store modified data temperarly
       std::ofstream tempFile("temp.txt");
       std::ifstream datafile("Inventory.txt");
       std::ofstream sales("sales.txt", std::ios_base::app);
       if (!datafile.is_open())
       {
           std::cout << "File failed to open " << std::endl;
       }

       // displaying table of current stock details
       show_inventory();
       std::cout << "Enter Product ID: " << std::endl;
       std::cin >> id;
       std::cout << "Sold Quantity > ";
       std::cin >> sold_quantity;
       while ( getline(datafile, line))
       {
           if (line == "") continue;
           if (id == line.substr(0, 4))
           {
               std::stringstream ss(line);
               getline(ss, tempString, ':');
               set_product_id(stoi(tempString));
               getline(ss, tempString,   ':');
               set_product_name(tempString);
               getline(ss, tempString,   ':');
               set_product_type(tempString);
               getline(ss, tempString, ':');
               set_product_price(stoi(tempString));
               getline(ss, tempString, ':');
               set_product_quantity(stoi(tempString) - sold_quantity);
               // printing detials of item sold 
               std::cout << "Item Sold " << std::endl;
               std::cout << "ID    : "  << get_product_id()<< std::endl;
               std::cout << "Name  : "  << get_product_name()<< std::endl;
               std::cout << "Type  : "  << get_product_type()<< std::endl;
               std::cout << "Price : "  << get_product_price()<< std::endl;
               // storing data of item sold in a temp file
               tempFile
                   << get_product_id() << ':'
                   << get_product_name() << ':'
                   << get_product_type() << ':'
                   << get_product_price() << ':'
                   << get_product_quantity() << std::endl;
               // storing detials of item sold in sales file for sales report    
               sales
                   << get_product_id() << ':'
                   << get_product_name() << ':'
                   << get_product_type() << ':'
                   << get_product_price() << ':'
                   << get_product_quantity() << std::endl;
               
           }
           if (id != line.substr(0, 4))
           {
               std::stringstream ss(line);
               getline(ss, tempString, ':');
               set_product_id(stoi(tempString));
               getline(ss, tempString,   ':');
               set_product_name(tempString);
               getline(ss, tempString,   ':');
               set_product_type(tempString);
               getline(ss, tempString, ':');
               set_product_price(stoi(tempString));
               getline(ss, tempString, ':');
               set_product_quantity(stoi(tempString));
               tempFile
                   << get_product_id() << ':'
                   << get_product_name() << ':'
                   << get_product_type() << ':'
                   << get_product_price() << ':'
                   << get_product_quantity() << std::endl;
           }
       }
       tempFile.close();
       std::cout << "File failed to open " << std::endl;   
       }
/**
 opens sales file and reads all strings seperate by a colon then prints
 it's content into the console
*/
void SellProduct::view_sales()
{
    std::string line , tempString;

    std::ifstream sales("sales.txt");
    std::cout << "ID"
              << "\t\t"
              << "Name"
              << "\t\t"
              << "Type"
              << "\t\t"
              << "Price"
              << "\t\t" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
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

        std::cout << "\t\t" << '\n';
    }
    std::cout << "-----------------------------------------------------" << std::endl;
    sales.close();
}
