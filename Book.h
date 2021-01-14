#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/**
 * Book.h
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 08/01/2021
 * Updated: 08/01/2021
 * 
*/

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