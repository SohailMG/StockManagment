#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>

class DVD : public Product
{
private:
    std::string year_released,title,dvd_type;

public:
    DVD();
    void add_DVD_details();
    void store_DVD_details();
    void sell_DVD(int id);
    void restock_DVD(int id);
    void show_inventory();
};