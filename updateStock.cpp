#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "updateStock.h"
/**
 * updateStock.cpp
 * @author M00716650 <sg1498@live.mdx.ac.uk>
 * Created: 06/01/2021
 * Updated: 08/01/2021
 * 
*/
UpdateStock::UpdateStock()
{

};

    void UpdateStock::delete_old()
    {

        outfile.open("Inventory.txt", std::ios_base::app);
        if (remove("Inventory.txt"))
            deleted_old = true;
        else
            deleted_old = false;
    }
    void UpdateStock::update_inventory()
    {
        std::ifstream temp("temp.txt");
        std::string lines;
        while (getline(temp, lines))
        {
            
            std::ofstream outfile("Inventory.txt", std::ios_base::app);
            outfile << lines;
            outfile << '\n';
        }
        outfile.close();
    }
