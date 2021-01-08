#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "Product.h"
/**
 * menu.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 06/01/2021
 * Updated: 08/01/2021
 * 
*/
#ifndef menue_H
#define menue_H

using namespace std;

class Menue : public Product
{

private:
     string active_menue, menue, sell, add,
        restock, update, view;
    

public:
    Menue();
    void currentMenu(int menueOption);
    int showMenu();
    void check_action(bool status);
};

#endif