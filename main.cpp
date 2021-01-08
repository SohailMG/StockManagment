#include <iostream>
#include <string>
#include "updateStock.h"
#include "addProduct.h"
#include "sellProduct.h"
#include "RestockProduct.h"
#include "Product.h"
#include "menu.h"

using namespace std;

// abstract class Product with methods and attributes to be inherited

int main()
{
    // instantiating class objects
    SellProduct sell;
    Product product;
    Menue menue;
    AddProduct add;
    RestockProduct restock_item;
    UpdateStock update_stock;

    bool isvalid, invalid_entry;
    int user_quits;

    isvalid = true;

    while (isvalid)
    {
        int menueOption = menue.showMenu();
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
            cout << "\n"
                 << "Exited Program...." << endl;
            isvalid = false;
        }

        // adding an option to check if user wants to quit program
        if (menueOption != 6)
        {
            invalid_entry = true;
            while (invalid_entry)
            {
                cout << '\n'
                     << "Continue..... 0 > " << endl;
                cout << "Quit......... 1 > " << endl;
                cout << "> ";
                cin >> user_quits;

                // checking if input is not an integer
                if (!cin)
                {
                    cout << "Invalid Input try again " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    invalid_entry = true;
                }
                else
                {
                    // checking if input is 0 then user continues else program ends
                    switch (user_quits)
                    {
                    case 0:
                        invalid_entry = false;
                        isvalid = true;
                        break;
                    case 1:
                        invalid_entry = false;
                        isvalid = false;
                        break;

                    default:
                        invalid_entry = true;
                        cout << user_quits << " is Out of range choose 1 or 0" << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
