#include "DVD.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
/**
 * DVD.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

/*
    DVD derived class form products and contains
    all methods and attributes of DVD such as
    title,year released and dvd catagory.
*/
DVD::DVD()
{
}
/**
 * inherits the add_product() method from abstract class
 * and add title,year released,and catagory of DVD into the
 * item_data vector.
*/
void DVD::add_DVD_details()
{
    add_product();

    std::cout << "Enter Title  : " << std::endl;
    std::cin >> title;
    std::cout << "Enter Year released : " << std::endl;
    std::cin >> year_released;
    std::cout << "Enter Catagory  ;" << std::endl;
    std::cin >> dvd_type;

    item_data.push_back(title);
    item_data.push_back(year_released);
    item_data.push_back(dvd_type);
    item_data.push_back("ln");

    store_product("DVDs.txt");
}

/**
 * parses through a file of DVD data and
 * checks if passed id matches a stored id
 * when match is found quantity is decreased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be sold
*/
void DVD::sell_DVD(int id)
{
    int sold_amount;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ofstream sales("sales.txt", std::ios_base::app);
    std::ifstream datafile("DVDs.txt");

    std::cout << "Sold Quantity > ";
    std::cin >> sold_amount;
    while (getline(datafile, line))
    {
        if (line == "")
            continue;
        if (std::to_string(id) == line.substr(0, 4))
        {

            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));

            getline(ss, tempString, ':'); // name
            set_product_name(tempString);

            getline(ss, tempString, ':'); //type
            set_product_type(tempString);

            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));

            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString) - sold_amount);

            getline(ss, tempString, ':'); //title
            title = tempString;

            getline(ss, tempString, ':'); //author
            year_released = tempString;

            getline(ss, tempString, ':'); //genre
            dvd_type = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << year_released << ':'
                << dvd_type << ':'
                << std::endl;

            sales
                << get_product_id() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << std::endl;
        }
        if (std::to_string(id) != line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));
            getline(ss, tempString, ':');
            set_product_name(tempString);
            getline(ss, tempString, ':');
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString));
            getline(ss, tempString, ':'); //title
            title = tempString;
            getline(ss, tempString, ':'); //author
            year_released = tempString;
            getline(ss, tempString, ':'); //genre
            dvd_type = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << year_released << ':'
                << dvd_type << ':'
                << std::endl;
            std::cout
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << year_released << ':'
                << dvd_type << ':'
                << std::endl;
        }
    }
}
/**
 * parses through a file of DVD data and
 * checks if passed id matches a stored id
 * when match is found quantity is increased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be restocked
*/
void DVD::restock_DVD(int id)
{
    int restock_amount;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("DVDs.txt");

    std::cout << "Restock Amount > ";
    std::cin >> restock_amount;
    while (getline(datafile, line))
    {
        if (line == "")
            continue;
        if (std::to_string(id) == line.substr(0, 4))
        {

            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));

            getline(ss, tempString, ':'); // name
            set_product_name(tempString);

            getline(ss, tempString, ':'); //type
            set_product_type(tempString);

            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));

            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString) + restock_amount);

            getline(ss, tempString, ':'); //title
            title = tempString;

            getline(ss, tempString, ':'); //author
            year_released = tempString;

            getline(ss, tempString, ':'); //genre
            dvd_type = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << year_released << ':'
                << dvd_type << ':'
                << std::endl;
        }
        if (std::to_string(id) != line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));
            getline(ss, tempString, ':');
            set_product_name(tempString);
            getline(ss, tempString, ':');
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString));
            getline(ss, tempString, ':'); //title
            title = tempString;
            getline(ss, tempString, ':'); //author
            year_released = tempString;
            getline(ss, tempString, ':'); //genre
            dvd_type = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << year_released << ':'
                << dvd_type << ':'
                << std::endl;
        }
    }
}

/*
    parses through datafile and prints its
    content into the console as a table
*/
void DVD::show_inventory()
{
    std::string line;
    std::string tempString;
    std::ifstream inventory("DVDs.txt");
    std::cout << "\n"
              << std::endl;
    std::cout << "ID"
              << "\t\t"
              << "Price"
              << "\t\t"
              << "Quantity"
              << "\t\t"
              << "Title"
              << "\t\t"
              << "Year Released"
              << "\t\t"
              << "Catagory"
              << "\t\t"
              << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;

    while (getline(inventory, line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        getline(ss, tempString, ':'); //id
        set_product_id(stoi(tempString));

        std::cout << get_product_id() << "\t\t";

        getline(ss, tempString, ':');
        set_product_name(tempString);

        getline(ss, tempString, ':');
        set_product_type(tempString);

        getline(ss, tempString, ':'); //price
        set_product_price(stoi(tempString));
        std::cout << get_product_price() << "\t\t";

        getline(ss, tempString, ':'); //quantity
        set_product_quantity(stoi(tempString));
        std::cout << get_product_quantity() << "\t\t\t";

        getline(ss, tempString, ':'); //title
        title = tempString;
        std::cout << title << "\t\t";

        getline(ss, tempString, ':'); //author
        year_released = tempString;
        std::cout << year_released << "\t\t";

        getline(ss, tempString, ':'); //genre
        dvd_type = tempString;
        std::cout << dvd_type << "\t\t" << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "\n"
              << std::endl;
}
