#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"

#ifndef sellProduct_H
#define sellProduct_H

using namespace std;

class SellProduct : public Product
{
    public:
    SellProduct();


    string line , tempString;
    vector<string> items_sold;
    int num_of_sold ;
    int sold_quantity;

    void readInventory();
    void view_sales();
    
    

};










#endif