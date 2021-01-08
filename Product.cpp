#include <iostream>
#include <string>
#include <vector>
#include "header.h"
#include "Product.h"


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
    

