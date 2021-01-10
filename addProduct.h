#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "Product.h"

/**
 * addProduct.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

#ifndef addProduct_H
#define addProduct_H



/*
 derived class that adds a new product into a text file
*/
class AddProduct : public Product
{
public:
    AddProduct();
    void product_info();
    void store_product();
    bool valid_Type(std::string type);
    bool exists;
    void item_exists(std::string id);
    std::string stringToUpper(std::string str);

private:
    std::string product_types[4] = {"CD", "DVD", "Magazin", "Book"};
    std::ofstream outfile;
    std::string tmp;
    bool valid;
    int id , qntty;
    std::string name ,itm_type;
    double price;
};

#endif