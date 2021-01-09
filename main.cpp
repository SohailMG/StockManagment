#include <iostream>
#include <string>
#include "updateStock.h"
#include "addProduct.h"
#include "sellProduct.h"
#include "RestockProduct.h"
#include "Product.h"
#include "menu.h"





int main()
{
    // instantiating class objects
    Product product;
    Menue menue;
    SellProduct sell;
    AddProduct add;
    RestockProduct restock_item;
    UpdateStock update_stock;

    bool isvalid, invalid_entry;
    int user_quits;

    isvalid = true;

    while (isvalid)
    {
        // displaying menue to the console
        std::cout << '\n' << std::endl;
        int menu_option = menue.showMenu();
        std::cout << "\n\n"
             << std::endl;

        // checking menue option chosen by the user
        if (menu_option == 1)
        {
            menue.currentMenu(menu_option);
            sell.readInventory();
            update_stock.delete_old();
            update_stock.update_inventory();
        }
        else if (menu_option == 2)
        {

            menue.currentMenu(menu_option);
            add.product_info();

            add.store_product();
            add.item_data.clear();
        }
        else if (menu_option == 3)
        {
            menue.currentMenu(menu_option);
            restock_item.readInventory();
            update_stock.delete_old();
            update_stock.update_inventory();
        }
        else if (menu_option == 5)
        {
            menue.currentMenu(menu_option);
            sell.view_sales();
        }
        else if (menu_option == 6)
        {
            std::cout << "\n"
                 << "Exited Program...." << std::endl;
            isvalid = false;
        }

        // adding an option to check if user wants to quit program
        if (menu_option != 6)
        {
            invalid_entry = true;
            while (invalid_entry)
            {
                std::cout << '\n'
                     << "Continue..... 0 > " << std::endl;
                std::cout << "Quit......... 1 > " << std::endl;
                std::cout << "> ";
                std::cin >> user_quits;

                // checking if input is not an integer
                if (!std::cin)
                {
                    std::cout << "Invalid Input try again " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                        std::cout << user_quits << " is Out of range choose 1 or 0" << std::endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
