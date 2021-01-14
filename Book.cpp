#include "Book.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
/**
 * Book.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

/*
    derived class Books represents
    the methods and attributes for a book
    such as Author,title..etc
*/
Books::Books()
{
}

/**
 * inherits the add_product() method from abstract class
 * and add title,author,and genre of books into the
 * item_data vector.
*/
void Books::add_book_details()
{

    add_product();

    std::cout << "Enter Title  : " << std::endl;
    std::cin >> title;
    std::cout << "Enter Author : " << std::endl;
    std::cin >> author;
    std::cout << "Enter Genre  ;" << std::endl;
    std::cin >> genre;

    item_data.push_back(title);
    item_data.push_back(author);
    item_data.push_back(genre);
    item_data.push_back("ln");

    store_product("Books.txt");
}

/**
 * parses through a file of book data and
 * checks if passed id matches a stored id
 * when match is found quantity is decreased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be sold
*/
void Books::sell_book(int id)
{

    int sold_quantity;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("Books.txt");
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

            getline(ss, tempString, ':'); // name
            set_product_name(tempString);

            getline(ss, tempString, ':'); //type
            set_product_type(tempString);

            getline(ss, tempString, ':'); //price
            set_product_price(stoi(tempString));

            getline(ss, tempString, ':'); //quantity
            set_product_quantity(stoi(tempString) - sold_quantity);

            getline(ss, tempString, ':'); //title
            title = tempString;

            getline(ss, tempString, ':'); //author
            author = tempString;

            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << author << ':'
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
            author = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << author << ':'
                << genre << ':'
                << std::endl;

        }
    }
    sales.close();
}
/**
 * parses through a file of book data and
 * checks if passed id matches a stored id
 * when match is found quantity is increased by given amount
 * products not matching id are stored unchanged.
 * 
 * @param id product id to be restocked
*/
void Books::restock_book(int id)
{
    int restock_amount;
    std::string tempString, line;
    std::ofstream tempFile("temp.txt");
    std::ifstream datafile("Books.txt");

    std::cout << "Restock Amount > ";
    std::cin >> restock_amount;
    while (getline(datafile, line))
    {
        // ignoring emtpy first line of file
        if (line == "")
            continue;
         //checking if id matches a stored item
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
            author = tempString;

            getline(ss, tempString, ':'); //genre
            genre = tempString;

            // writing modified data into a temp file
            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << author << ':'
                << genre << ':'
                << std::endl;

        }
        // storing products not matching given id into temp file unchanged
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
            author = tempString;
            getline(ss, tempString, ':'); //genre
            genre = tempString;

            // writing unmodified data into tmep file
            tempFile
                << get_product_id() << ':'
                << get_product_name() << ':'
                << get_product_type() << ':'
                << get_product_price() << ':'
                << get_product_quantity() << ':'
                << title << ':'
                << author << ':'
                << genre << ':'
                << std::endl;
        }
    }
    tempFile.close();
}
/*
    parses through datafile and prints its
    content into the console as a table
*/
void Books::show_inventory()
{
    std::string line;
    std::string tempString;
    std::ifstream inventory("Books.txt");
    std::cout << "\n"<<std::endl;
    std::cout << "ID"
              << "\t\t"
              << "Price"
              << "\t\t"
              << "Quantity"
              << "\t\t"
              << "Title"
              << "\t\t"
              << "Author"
              << "\t\t"
              << "Genre"
              << "\t\t" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    while (getline(inventory, line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        getline(ss, tempString, ':'); //id
        set_product_id(stoi(tempString));

        std::cout << get_product_id() << "\t\t";

        getline(ss, tempString, ':'); // name
        set_product_name(tempString);

        getline(ss, tempString, ':'); //type
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
        author = tempString;
        std::cout << author << "\t\t";

        getline(ss, tempString, ':'); //genre
        genre = tempString;
        std::cout << genre << "\t\t" << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
}
