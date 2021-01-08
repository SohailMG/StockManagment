#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"

#ifndef RestockProduct_H
#define RestockProduct_H

using namespace std;

class RestockProduct : public Product
{

    public:
    RestockProduct();



    string line , tempString;
    ofstream outfile;
    ifstream temp;
    bool deleted_old;
    int restock_amount;

    void readInventory();

};



#endif