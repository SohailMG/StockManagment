#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Books : public Product
{
private:
    std::string author,title,genre;


public:
    Books();
    void add_book_details();
    void store_book_details();
    void sell_book(int id);
    void restock_book(int id);

    void show_inventory();
};