#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CDs : public Product
{
private:
    std::string artist,title;

public:
    CDs();
    void add_CD_details();
    void store_CD_details();
    void sell_CD(int id);
    void restock_CD(int id);
    void show_inventory();
};
