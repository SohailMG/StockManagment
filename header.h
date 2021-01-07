#pragma once
#include "Product.cpp"
#include "addProduct.cpp"
#include "sellProduct.cpp"
#include "RestockProduct.cpp"
#include "updateStock.cpp"


int getProductID(int itemCode);

int showMenue();

void currentMenu(int menueOption);

int sellProduct();

void product_info();

void show_added();

void readInventory();


bool valid_Type(string type);

string stringToUpper(string oString);

void store_product();

void update_inventory();

void delete_old();
    