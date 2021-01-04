#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

class AddProduct : public Product
{
public:
    ofstream outfile;
    string tmp;
    bool valid;

    void product_info()
    {

        // storing info of new item into a vector
        cout << " Enter Item Code     : " << endl;
        cin >> itemCode;
        if (!cin)
        {
            valid = false;
            cout << '\n' << "Item Code must be an Integer"<<'\n' << endl;

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
        // looping through vector and writing new item data into a file
    }
    void writeToFile()
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
    }
    void InvalidInpt()
    {

        cout << "Invalid Input " << endl;
    };
};