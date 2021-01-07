#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"

class UpdateStock : public Product
{

public:
    string line;
    ofstream outfile;
    ifstream temp;
    bool deleted_old;

    void delete_old()
    {

        outfile.open("Inventory.txt", std::ios_base::app);
        if (remove("Inventory.txt"))
            deleted_old = true;
        else
            deleted_old = false;
    }
    void update_inventory()
    {
        ifstream temp("temp.txt");
        string lines;
        while (getline(temp, lines))
        {
            ofstream outfile("Inventory.txt", std::ios_base::app);
            outfile << lines;
            outfile << '\n';
        }
        outfile.close();
    }
};