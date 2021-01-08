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
    view    = "-------Sales Report----";
};

void Menue::currentMenu(int menueOption)
{

    if (menueOption == 1)
    {
        active_menue = sell;
    }
    else if (menueOption == 2)
    {
        active_menue = add;
    }
    else if (menueOption == 3)
    {
        active_menue = restock;
    }
    else if (menueOption == 4)
    {
        active_menue = update;
    }
    else if (menueOption == 5)
    {
        active_menue = view;
    }
    else
    {
        cout << "No Option chosen....";
    }

    cout << active_menue << endl;
}
int Menue::showMenu()
{

    int menu;
    cout << " Stock Managment System"
         << "\n\n"
         << endl;
    cout << " Sell Item--------------- >1" << endl;
    cout << " Add new item------------ >2" << endl;
    cout << " Restock Product--------- >3" << endl;
    cout << " Update Stock------------ >4" << endl;
    cout << " View Reports------------ >5" << endl;
    cout << " Quit Program------------ >6" << endl;
    cout << " Choose an Option > ";
    cin >> menu;

    return menu;
}
