#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Product.h"
/**
 * updateStock.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/
#ifndef updateStock_H
#define updateStock_H



class UpdateStock : public Product
{
public:
    UpdateStock();

    std::string line;
    std::ofstream outfile;
    std::ifstream temp;
    bool deleted_old;

    void delete_old();

    void update_inventory();
};

#endif