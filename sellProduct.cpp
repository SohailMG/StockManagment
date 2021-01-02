#include <iostream>
#include <string>
#include "header.h"





class SellProduct : public Product
{

public:
    int sellProduct(int ID)
    {

        cout << " Item Sold : " << ID << endl;
    }
};