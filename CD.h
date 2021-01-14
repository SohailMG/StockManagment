#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/**
 * CD.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

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
