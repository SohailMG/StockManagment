#include <iostream>
#include <string>

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
        cout << " View Reports------------ >4" << endl;
        cout << " Choose an Option > ";
        cin >> menu;

        return menu;
    }
};
class Menue:public Product
{
    public:
        string ActiveMenue;
        string MENUE     = "----Main Menue----";
        string SELL      = "----Sell Item----";
        string ADD       = "----Add Item----";
        string RESTOCK   = "----Restock Item----";
        string UPDATE    = "----Update Item----";
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

int main(void)
{

    SellProduct p;
    Product P;
    Menue M;


    int menueOption = P.showMenu();
    cout << "\n\n"<<endl;
    M.currentMenu(menueOption);
    int ID = p.getProductID(p.itemCode);
    p.sellProduct(ID);

    return 0;
}
