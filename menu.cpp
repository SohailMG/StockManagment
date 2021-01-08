#include <iostream>
#include <string>
#include "header.h"
#include "menu.h"


Menue::Menue()
{

    
    MENUE   = "-------Main Menue--------";
    SELL    = "-------Sell Item---------";
    ADD     = "--------Add Item---------";
    RESTOCK = "------Restock Item-------";
    UPDATE  = "-------Update Item-------";
    VIEW    = "-------Sales Report----";
};

    void Menue::currentMenu(int menueOption)
    {

        switch (menueOption)
        {
        case 1:
            ActiveMenue = SELL;
            break;
        case 2:
            ActiveMenue = ADD;
            break;
        case 3:
            ActiveMenue = RESTOCK;
            break;
        case 4:
            ActiveMenue = UPDATE;
            break;
        case 5:
            ActiveMenue = VIEW;
            break;

        default:
            break;
        }

        cout << ActiveMenue << endl;
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