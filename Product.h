#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "header.h"

#ifndef Product_H
#define Product_H

using namespace std;

class Product
{

public:
    Product();

    vector<string> item_data;
    string itemName, itemType;
    int itemCode, quantity;
    double itemPrice;
    bool validinpt;

    int getProductID(int itemCode);
    int showMenu();
};

#endif