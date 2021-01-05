#include <iostream>
#include <string>
#include "header.h"

using namespace std;

// abstract class Product with methods and attributes to be inherited

class Menue : public Product
{

public:
    string ActiveMenue;
    string MENUE = "-------Main Menue--------";
    string SELL = "-------Sell Item---------";
    string ADD = "--------Add Item---------";
    string RESTOCK = "------Restock Item-------";
    string UPDATE = "-------Update Item-------";
    string VIEW = "----View Sales Report----";

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

int main()
{

    SellProduct p;
    Product P;
    Menue M;
    AddProduct A;
    string user_ends;
    bool isvalid;

    isvalid = true;

    while (isvalid)
    {
        int menueOption = P.showMenu();
        cout << "\n\n"
             << endl;

        if (menueOption == 1)
        {
            M.currentMenu(menueOption);
            p.readInventory();
        }
        else if (menueOption == 2)
        {

            M.currentMenu(menueOption);
            A.product_info();

            A.store_product();
            A.outfile.close();
            A.item_data.clear();
        }
        else if (menueOption == 6)      
        {
            cout << "\n" << "Exited Program...." << endl;
            isvalid = false;
        }
        
    }

    return 0;
}
