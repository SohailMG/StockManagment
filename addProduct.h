#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "header.h"

#ifndef addProduct_H
#define addProduct_H

using namespace std;

class AddProduct : public Product
{
public:
    AddProduct();

    string product_types[4] = {"CD", "DVD", "Magazin", "Book"};
    ofstream outfile;
    string tmp;
    bool valid;

    void product_info();
    void store_product();
    bool valid_Type(string type);
    string stringToUpper(string str);
};

#endif