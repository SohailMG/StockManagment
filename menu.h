#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "header.h"

#ifndef menue_H
#define menue_H

using namespace std;

class Menue : public Product
{
public:
    Menue();
    string ActiveMenue, MENUE, SELL, ADD,
        RESTOCK, UPDATE, VIEW;

    void currentMenu(int menueOption);
    int showMenu();

};

#endif