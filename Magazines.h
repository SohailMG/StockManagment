#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>

class Magazines : public Product
{
private:
    std::string cover_person,company,genre;

public:
    Magazines();
    void add_Magazine_details();
    void store_Magazine_details();
    void sell_Magazine(int id);
    void restock_magazines(int id);
    void show_inventory();
};