#include <iostream>
#include <string>
#include <header.h>

using namespace std;

// abstract class Product with methods and attributes to be inherited
class Product
{
public:
    string itemName;
    string itemType;
    int itemCode;
    double itemPrice;
    int quantity;

    int getProductID(int itemCode)
    {

        cout << "Enter Product ID: ";
        cin >> itemCode;
        return itemCode;
    }
    int showMenu()
    {

        int menu;
        cout << " Stock Managment System"
             << "\n\n"
             << endl;
        cout << " Sell Item--------------- >1" << endl;
        cout << " Add new item------------ >2" << endl;
        cout << " Restock Product--------- >3" << endl;
        cout << " Update Stock------------ >4" << endl;
        cout << " View Reports------------ >5" << endl;
        cout << " Choose an Option > ";
        cin >> menu;

        return menu;
    }
};

class Menue:public Product
{
    
    public:
        string ActiveMenue;
        string MENUE     = "-------Main Menue--------";
        string SELL      = "-------Sell Item---------";
        string ADD       = "--------Add Item---------";
        string RESTOCK   = "------Restock Item-------";
        string UPDATE    = "-------Update Item-------";
        string VIEW      = "----View Sales Report----";

        void currentMenu(int menueOption){
            
            switch (menueOption)
            {
            case 1:
                ActiveMenue = SELL;
                break;
            case 2:
                ActiveMenue = ADD;
                break;
            case 3:
                ActiveMenue = RESTOCK;
                break;
            case 4:
                ActiveMenue = UPDATE;
                break;
            case 5:
                ActiveMenue = VIEW;
                break;
            
            default:
                break;
            }

            cout << ActiveMenue << endl;

        }

};

class SellProduct : public Product
{

public:
    int sellProduct(int ID)
    {

        cout << " Item Sold : " << ID << endl;
    }
};

class AddProduct : public Product
{
    public:
    void product_info()
    {

        cout << " Enter Item Code     : " << endl;
        cin >> itemCode;
        cout << " Enter Item Name     : " << endl;
        cin >> itemName;
        cout << " Enter Item Type     : " << endl;
        cin >> itemType;
        cout << " Enter Item Price    : " << endl;
        cin >> itemPrice;
        cout << " Enter Item Quantity : " << endl;
        cin >> quantity;
        
    }

    void show_added(){

        cout << "New Product added" << endl;
        cout << "ID       : "<< itemCode << endl;
        cout << "Name     : "<< itemName << endl;
        cout << "Type     : "<< itemType << endl;
        cout << "Price    : "<< itemPrice << endl;
        cout << "quantity : "<< quantity << endl;

    }
    
    

};

int main(void)
{

    SellProduct p;
    Product P;
    Menue M;
    AddProduct A;


    int menueOption = P.showMenu();
    cout << "\n\n"<<endl;
    

    switch (menueOption)
    {
    case 1:
    {
        M.currentMenu(menueOption);
        int ID = p.getProductID(p.itemCode);
        p.sellProduct(ID);
        break;
    }

    {
    case 2:
        M.currentMenu(menueOption);
        A.product_info();
        A.show_added();
        break;
    }
    default:
        break;
    }


    

    return 0;
}
