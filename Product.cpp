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

using namespace std;


Product::Product()
{
}

    int Product::getProductID(int itemCode)
    {

        cout << "Enter Product ID: ";
        cin >> itemCode;
        return itemCode;
    }
    

