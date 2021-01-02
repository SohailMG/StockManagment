#pragma once
#include "Product.cpp"
#include "addProduct.cpp"
#include "sellProduct.cpp"


int getProductID(int itemCode);

int showMenue();

void currentMenu(int menueOption);

int sellProduct(int ID);

void product_info();

void show_added();