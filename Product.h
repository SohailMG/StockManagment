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
private:
    std::string item_type,item_name;
    int item_id, item_quantity;
    double item_price;

public:
    std::vector<std::string> item_data;
    Product();
    void add_product();
    int sell_product();
    int restock_product();
    void update_stock(std::string location);
    void store_product(std::string location);
    void view_sales();

    // getters and setters
    int get_product_id();
    void set_product_id(int id);
    std::string get_product_type();
    std::string get_product_name();
    void set_product_type(std::string type);
    void set_product_name(std::string name);
    double get_product_price();
    void set_product_price(double price);
    int get_product_quantity();
    void set_product_quantity(int qtty);
};

#endif