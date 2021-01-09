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



class Menue : public Product
{

private:
     std::string active_menue, menue, sell, add,
        restock, update, view;
    

public:
    Menue();
    void currentMenu(int menueOption);
    int showMenu();
};

#endif