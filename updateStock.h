#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"

#ifndef updateStock_H
#define updateStock_H

using namespace std;

class UpdateStock : public Product
{
public:
    UpdateStock();

    string line;
    ofstream outfile;
    ifstream temp;
    bool deleted_old;

    void delete_old();

    void update_inventory();
};

#endif