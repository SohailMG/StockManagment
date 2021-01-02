#pragma once
#include "Product.cpp"
#include "addProduct.cpp"
#include "sellProduct.cpp"


int getProductID(int itemCode);

int showMenue();

void currentMenu(int menueOption);

int sellProduct();

void product_info();

void show_added();
 void readInventory();