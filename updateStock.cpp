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

    
    
    //  deletes the Inventory file after a change has been made
    void UpdateStock::delete_old()
    {

        outfile.open("Inventory.txt", std::ios_base::app);
        if (remove("Inventory.txt"))
            deleted_old = true;
        else
            deleted_old = false;
        
        outfile.close();
    }

    /**
     * opens temp file that has updated stock.
     * checks if Inventory has been deleted then recreates it in append mode
     *  and reads temp file content into Inventory file
    */
    void UpdateStock::update_inventory()
    {

        std::ifstream temp("temp.txt");
        std::string lines;
        if(deleted_old){
            outfile.open("Inventory.txt", std::ios_base::app);
        }
        while (getline(temp, lines))
        {
            
            std::ofstream outfile("Inventory.txt", std::ios_base::app);
            outfile << lines;
            outfile << '\n';
        }
        outfile.close();
        std::cout << "\n\n" << std::endl;
        std::cout << "\t"<< " *Stock Has been Update*" << std::endl;
    }
