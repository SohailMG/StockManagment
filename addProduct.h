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

using namespace std;

/*
 derived class that adds a new product into a text file
*/
class AddProduct : public Product
{
public:
    AddProduct();
    void product_info();
    void store_product();
    bool valid_Type(string type);
    string stringToUpper(string str);

private:
    string product_types[4] = {"CD", "DVD", "Magazin", "Book"};
    ofstream outfile;
    string tmp;
    bool valid;
};

#endif