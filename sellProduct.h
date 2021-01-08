#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Product.h"

#ifndef sellProduct_H
#define sellProduct_H

/**
 * sellProduct.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

using namespace std;

class SellProduct : public Product
{
    public:
    SellProduct();
    void readInventory();
    void view_sales();

    private:
    string line , tempString;
    vector<string> items_sold;
    int num_of_sold ;
    int sold_quantity;

    
    
    

};










#endif