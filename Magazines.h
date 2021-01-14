#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
/**
 * Magazines.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

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