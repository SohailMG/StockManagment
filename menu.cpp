#include <iostream>
#include <string>
#include "menu.h"
/**
 * menu.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 06/01/2021
 * Updated: 08/01/2021
 * 
*/
Menue::Menue()
{

    menue   = "-------Main Menue--------";
    sell    = "-------Sell Item---------";
    add     = "--------Add Item---------";
    restock = "------Restock Item-------";
    update  = "-------Update Item-------";
    view    = "-------Sales Report------";
};

void Menue::currentMenu(int menu_option)
{

    if (menu_option == 1)
    {
        active_menue = sell;
    }
    else if (menu_option == 2)
    {
        active_menue = add;
    }
    else if (menu_option == 3)
    {
        active_menue = restock;
    }
    else if (menu_option == 4)
    {
        active_menue = update;
    }
    else if (menu_option == 5)
    {
        active_menue = view;
    }
    else
    {
        std::cout << "No Option chosen....";
    }

    std::cout << active_menue << std::endl;
}
int Menue::showMenu()
{

    int menu;
    std::cout << " Stock Managment System"
         << "\n\n"
         << std::endl;
    std::cout << " Sell Item--------------- >1" << std::endl;
    std::cout << " Add new item------------ >2" << std::endl;
    std::cout << " Restock Product--------- >3" << std::endl;
    std::cout << " Update Stock------------ >4" << std::endl;
    std::cout << " View Reports------------ >5" << std::endl;
    std::cout << " Quit Program------------ >6" << std::endl;
    std::cout << " Choose an Option > ";
    std::cin >> menu;

    return menu;
}
