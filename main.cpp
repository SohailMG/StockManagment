#include "Product.h"
#include "book.h"
#include "CD.h"
#include "Magazines.h"
#include "DVD.h"
#include <iostream>
#include <string>

int check_catagory()
{
    int catagory;

    std::cout << "\n"
              << std::endl;
    std::cout << " CD           >1" << std::endl;
    std::cout << " DVD          >2" << std::endl;
    std::cout << " BOOKs        >3" << std::endl;
    std::cout << " MAGAZINEs    >4" << std::endl;

    std::cout << "Choose Catagory > ";
    std::cin >> catagory;

    return catagory;
}

int main()
{
    Product product;
    Books books;
    CDs CDs;
    DVD DVDs;
    Magazines magazines;

    int menu;
    bool user_quits = false;

    while (!user_quits)
    {

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

        // checking if user chooses to sell items
        if (menu == 1)
        {
            // checking which catagory user chooses CD DVD BOOKS or MAGAZINEs
            int catg = check_catagory();
            if (catg == 1)
            {
                CDs.show_inventory();
                CDs.sell_CD(product.sell_product());
                product.update_stock("CDs.txt");
                CDs.show_inventory();
            }
            // if user chooses DVD catgory
            else if (catg == 2)
            {
                DVDs.show_inventory();
                DVDs.sell_DVD(product.sell_product());
                product.update_stock("DVDs.txt");
                DVDs.show_inventory();
            }
            // if user chooses Books catagory
            else if (catg == 3)
            {
                books.show_inventory();
                books.sell_book(product.sell_product());
                product.update_stock("Books.txt");
                books.show_inventory();
            }
            // if user chooses magazines
            else if (catg == 4)
            {
                magazines.show_inventory();
                magazines.sell_Magazine(product.sell_product());
                product.update_stock("Magazines.txt");
                magazines.show_inventory();
            }
            // if user chooses an invalid option
            else
            {
                std::cout << catg << " is out of range" << std::endl;
            }
        }
        // checking if user choose to add an item
        else if (menu == 2)
        {
            int catg = check_catagory();
            if (catg == 1)
            {
                CDs.add_CD_details();
            }
            else if (catg == 2)
            {
                DVDs.add_DVD_details();
            }
            else if (catg == 3)
            {
                books.add_book_details();
            }
            else if (catg == 4)
            {
                magazines.add_Magazine_details();
            }

            else
            {
                std::cout << "Invalid" << std::endl;
            }
        }
        // checkin if user chooses to restock an item
        else if (menu == 3)
        {
            int catg = check_catagory();
            if (catg == 1)
            {
                CDs.show_inventory();
                CDs.restock_CD(product.restock_product());
                product.update_stock("CDs.txt");
                CDs.show_inventory();
            }
            else if (catg == 2)
            {
                DVDs.show_inventory();
                DVDs.restock_DVD(product.restock_product());
                product.update_stock("DVDs.txt");
                DVDs.show_inventory();
            }
            else if (catg == 3)
            {
                books.show_inventory();
                books.restock_book(product.restock_product());
                product.update_stock("Books.txt");
                books.show_inventory();
            }
            else if (catg == 4)
            {
                magazines.show_inventory();
                magazines.restock_magazines(product.restock_product());
                product.update_stock("Magazines.txt");
                magazines.show_inventory();
            }

            else
            {
                std::cout << "Catagory " << catg << " Is unrecognised" << std::endl;
            }
        }
        // checking if user chooses to update stock levels
        else if (menu == 4)
        {
            std::cout << "\n"
                      << "\t\t"
                      << "**Stock has been updated**" << std::endl;
        }
        // checking if user chooses to view sales report
        else if (menu == 5)
        {
            product.view_sales();
        }
        // checking if user decides to quite program
        else if (menu == 6)
        {
            user_quits = true;
        }
        // checking if user inputs an out of range option
        else
        {
            std::cout << "\n"
                      << std::endl;
            std::cout << menu << "Is out of range" << std::endl;
        }
    }

    return 0;
}
