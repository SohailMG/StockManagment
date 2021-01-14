#include "Magazines.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
/**
 * Magazines.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/


/*
    derived class from products which contains
    all methods and attributes relating to magazine
    such as person on conver,comapny,and genre.

*/
Magazines::Magazines()
{
}

/**
 * inherits the add_product() method from abstract class
 * and add person on cover,company,and genre of Magazine into the
 * item_data vector.
*/
void Magazines::add_Magazine_details()
{
    add_product();

    std::cout << "Person on Cover  : " << std::endl;
    std::cin >> cover_person;
    std::cout << "Company Name     : " << std::endl;
    std::cin >> company;
    std::cout << "Magazin Genre    :" << std::endl;
    std::cin >> genre;

    item_data.push_back(cover_person);
    item_data.push_back(company);
    item_data.push_back((genre));
    item_data.push_back("ln");

    store_product("Magazines.txt");
}
/**
 * parses through a file of Magazines data and
 * checks if passed id matches a stored id
 * when match is found quantity is Increased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be sold
*/
void Magazines::sell_Magazine(int id)
{
    int sold_quantity;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("Magazines.txt");
    std::ofstream sales("sales.txt", std::ios_base::app);

    std::cout << "Sold Quantity > ";
    std::cin >> sold_quantity;
    while (getline(datafile, line))
    {
        if (line == "")
            continue;
        if (std::to_string(id) == line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));
            getline(ss, tempString, ':'); //name
            set_product_name(tempString);
            getline(ss, tempString, ':'); //type
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString) - sold_quantity);
            getline(ss, tempString, ':'); //title
            cover_person = tempString;
            getline(ss, tempString, ':'); //author
            company = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << cover_person << ':'
                << company << ':'
                << genre << ':'
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
            getline(ss, tempString, ':'); //name
            set_product_name(tempString);
            getline(ss, tempString, ':'); //type
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString));
            getline(ss, tempString, ':'); //title
            cover_person = tempString;
            getline(ss, tempString, ':'); //author
            company = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << cover_person << ':'
                << company << ':'
                << genre << ':'
                << std::endl;
        }
    }
}

/**
 * parses through a file of Magazine data and
 * checks if passed id matches a stored id
 * when match is found quantity is increased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be restocked
*/
void Magazines::restock_magazines(int id)
{
    int restock_amount;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("Magazines.txt");

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
            getline(ss, tempString, ':'); //name
            set_product_name(tempString);
            getline(ss, tempString, ':'); //type
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString) + restock_amount);
            getline(ss, tempString, ':'); //title
            cover_person = tempString;
            getline(ss, tempString, ':'); //author
            company = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << cover_person << ':'
                << company << ':'
                << genre << ':'
                << std::endl;
        }
        if (std::to_string(id) != line.substr(0, 4))
        {
            std::stringstream ss(line);
            getline(ss, tempString, ':'); //id
            set_product_id(stoi(tempString));
            getline(ss, tempString, ':'); //type
            set_product_name(tempString);
            getline(ss, tempString, ':'); //type
            set_product_type(tempString);
            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));
            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString));
            getline(ss, tempString, ':'); //title
            cover_person = tempString;
            getline(ss, tempString, ':'); //author
            company = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << cover_person << ':'
                << company << ':'
                << genre << ':'
                << std::endl;
        }
    }
}
/*
    parses through datafile and prints its
    content into the console as a table
*/
void Magazines::show_inventory()
{
    std::string line;
    std::string tempString;
    std::ifstream inventory("Magazines.txt");
    std::cout << "\n"
              << std::endl;
    std::cout << "ID"
              << "\t\t"
              << "Price"
              << "\t\t"
              << "Quantity"
              << "\t\t"
              << "Cover Person"
              << "\t\t"
              << "Company"
              << "\t\t"
              << "Catgory"
              << "\t\t"
              << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;

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
        cover_person = tempString;
        std::cout << cover_person << "\t\t\t";

        getline(ss, tempString, ':'); //company
        company = tempString;
        std::cout << company << "\t\t";

        getline(ss, tempString, ':'); //catagory
        genre = tempString;
        std::cout << genre << "\t\t" << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "\n"
              << std::endl;
}