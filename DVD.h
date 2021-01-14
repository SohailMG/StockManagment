#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
/**
 * DVD.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

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