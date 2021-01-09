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

/*
abstract base class for product attributes with public members to be inherited
by derived classes
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

    int get_product_id(int itemCode);
    void show_product(std::string id);
    bool valid_inpt();
};

#endif