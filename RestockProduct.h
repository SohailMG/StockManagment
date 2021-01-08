#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Product.h"

#ifndef RestockProduct_H
#define RestockProduct_H

/**
 * RestockProduct.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

using namespace std;

class RestockProduct : public Product
{


    private:
    string line , tempString;
    ofstream outfile;
    ifstream temp;
    bool deleted_old;
    int restock_amount;

    public:
    void readInventory();
    RestockProduct();

};



#endif