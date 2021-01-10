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
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("Inventory.txt");
    if (!datafile.is_open())
    {
        std::cout << "File failed to open " << std::endl;
    }

    // calling get_product_id and storing restock amount
     int id;
    std::cout << "Enter Product ID: " << std::endl;
    std::cin >> id;
    std::cout << "Restock Amount > ";
    std::cin >> restock_amount;
    set_product_id(id);
    show_product(std::to_string(id));

    // parsing through datafile
    while (getline(datafile, line))
    {
        if (line == "")
            continue;

        // checking if product id matches an exisiting id
        if (std::to_string(get_product_id()) == line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':');
            set_product_id(stoi(tempString));

            getline(ss, tempString, ':');
            set_product_name(tempString);

            getline(ss, tempString, ':');
            set_product_type(tempString);

            getline(ss, tempString, ':');
            set_product_price(stoi(tempString));

            getline(ss, tempString, ':');
            set_product_quantity(stoi(tempString) + restock_amount);

            // storing line corrosponding to product in a temp file after restock
            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << std::endl;
        }
        // storing products not matching given ID in temp file unmodified
        if (std::to_string(get_product_id()) != line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':');
            set_product_id(stoi(tempString));

            getline(ss, tempString, ':');
            set_product_name(tempString);

            getline(ss, tempString, ':');
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
        show_product(std::to_string(id));
    }
    tempFile.close();
}