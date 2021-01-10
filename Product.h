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

private:
    std::string itemName, itemType;
    int itemCode, quantity;
    double itemPrice;
    bool validinpt;

public:
    Product();
    std::vector<std::string> item_data;
    int get_product_id();
    void set_product_id(int id);

    std::string get_product_name();
    void set_product_name(std::string name);

    std::string get_product_type();
    void set_product_type(std::string type);

    double get_product_price();
    void set_product_price(double price);

    int get_product_quantity();
    void set_product_quantity(int qtty);





    void show_product(std::string id);
    void show_inventory();
    bool valid_inpt();
};

#endif