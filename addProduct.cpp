#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "addProduct.h"

/**
 * addProduct.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 02/01/2021
 * Updated: 08/01/2021
 * 
*/


using namespace std;

 AddProduct::AddProduct()
{
     
};
    /**
     * reads user input for product info such as
     * prodocut ID,Type,Name,Price and Quantity.
     * then stores these in a vector of strings
    */
    void  AddProduct::product_info()
    {

        // storing info of new item into a vector
        cout << " Enter Item Code     : " << endl;
        cin >> itemCode;

        // checking if input is not an integer
        if (!cin)
        {
            valid = false;
            cout << '\n'
                 << "Item Code must be an Integer" << '\n'
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // checking if ID is not 4 digits long
        else if (to_string(itemCode).length() != 4)
        {
            cout << "ID Must be 4 digits...." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else
        {

            item_data.push_back(to_string(itemCode));

            cout << " Enter Item Name     : " << endl;
            cin >> itemName;
            item_data.push_back(itemName);

            cout << " Enter Item Type     : " << endl;
            cin >> itemType;
            itemType = stringToUpper(itemType);
            // checking if type is either CD DVD Book or Magazine
            if (!valid_Type(itemType))
            {
                cout << "not found" << endl;
                cin.clear();
                item_data.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {

                item_data.push_back(itemType);

                cout << " Enter Item Price    : " << endl;
                cin >> itemPrice;
                tmp = to_string(itemPrice);
                item_data.push_back(tmp.substr(0, 5));

                cout << " Enter Item Quantity : " << endl;
                cin >> quantity;
                item_data.push_back(to_string(quantity));
                item_data.push_back("nl");
            }
        }
        // looping through vector and writing new item data into a file
    }
    /**
     * opens a text file in append mode,
     * then loops through item_data vector and writes
     * each elment in the vector into the text file
    */
    void AddProduct::store_product()
    {
        outfile.open("Inventory.txt", std::ios_base::app);
        for (size_t i = 0; i < item_data.size(); i++)
        {
            if (item_data[i] == "nl")
            {
                outfile << '\n';
            }
            else
            {

                outfile << item_data[i] << ':';
                
            }
        }
        outfile.close();
    }
    /**
     * checks if prduct type entered by user
     * matches any of the four below
     * @param type
     * @returns boolean value
    */
    bool AddProduct::valid_Type(string type)
    {
        if (type == "CD" ||
            type == "DVD" ||
            type == "BOOK" ||
            type == "MAGAZINE")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    /**
     * converts product type entered by the user to upper case
     * for easier string comparison.
     * @param str
     * @returns uppercase string
    */
    string AddProduct::stringToUpper(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]);
        }
        return str;
    }
