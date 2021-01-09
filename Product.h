#pragma once
#include <iostream>
#include <string>
#include <vector>

#ifndef Product_H
#define Product_H

/**
 * Product.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/


class Product
{

public:
    Product();

    std::vector<std::string> item_data;
    std::string itemName, itemType;
    int itemCode, quantity;
    double itemPrice;
    bool validinpt;

    int getProductID(int itemCode);
    int showMenu();
};

#endif