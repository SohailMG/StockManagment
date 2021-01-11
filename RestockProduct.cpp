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
RestockProduct::RestockProduct(){

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

    std::string line , tempString;
    std::string id;
    // opening a temp file to store modified data temperarly   std::ofstream tempFile("temp.txt");
       // opening a temp file to store modified data temperarly
       std::ofstream tempFile("temp.txt");
       std::ifstream datafile("Inventory.txt");
       std::ofstream sales("sales.txt", std::ios_base::app);
       if (!datafile.is_open())
       {
           std::cout << "File failed to open " << std::endl;
       }
       // getting product ID from user and sold quantity
       show_inventory();
       std::cout << "Enter Product ID: " << std::endl;
       std::cin >> id;
       std::cout << "Restock Amount > ";
       std::cin >> restock_amount;
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
               set_product_quantity(stoi(tempString) + restock_amount);
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
       }