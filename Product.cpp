#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
/**
 * Product.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 02/01/2021
 * Updated: 08/01/2021
 * 
*/




Product::Product()
{
}

    int Product::getProductID(int itemCode)
    {

        std::cout << "Enter Product ID: ";
        std::cin >> itemCode;
        return itemCode;
    }
    

