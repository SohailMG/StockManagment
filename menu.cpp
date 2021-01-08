#include <iostream>
#include <string>
#include "header.h"


class Menue : public Product
{

public:
    string ActiveMenue;
    string MENUE   = "-------Main Menue--------";
    string SELL    = "-------Sell Item---------";
    string ADD     = "--------Add Item---------";
    string RESTOCK = "------Restock Item-------";
    string UPDATE  = "-------Update Item-------";
    string VIEW    = "------Sales Report-------";

    void currentMenu(int menueOption)
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
};