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

// instantiating class objects 
    SellProduct sell;
    Product product;
    Menue menue;
    AddProduct add;
    RestockProduct restock_item;
    UpdateStock update_stock;


    string user_ends;
    bool isvalid;

    isvalid = true;

    while (isvalid)
    {
        int menueOption = product.showMenu();
        cout << "\n\n"
             << endl;

        if (menueOption == 1)
        {
            menue.currentMenu(menueOption);
            sell.readInventory();
            update_stock.delete_old();
            update_stock.update_inventory();
        }
        else if (menueOption == 2)
        {

            menue.currentMenu(menueOption);
            add.product_info();

            add.store_product();
            add.outfile.close();
            add.item_data.clear();
            
        }
        else if (menueOption == 3)
        {
            menue.currentMenu(menueOption);
            restock_item.readInventory();
            update_stock.delete_old();
            update_stock.update_inventory();

        }
        else if (menueOption == 5)      
        {
            menue.currentMenu(menueOption);
            sell.view_sales();
            
        }
        else if (menueOption == 6)      
        {
            cout << "\n" << "Exited Program...." << endl;
            isvalid = false;
        }
        
    }

    return 0;
}
