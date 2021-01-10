#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "updateStock.h"
#include "addProduct.h"
#include "sellProduct.h"
#include "RestockProduct.h"
#include "Product.h"
#include "menu.h"


TEST_CASE("test type","[valid_type] "){
    AddProduct a = AddProduct();
    REQUIRE(a.valid_Type("DVD") == true);
    REQUIRE(a.valid_Type("CD") == true);
    REQUIRE(a.valid_Type("BOOK") == true);
    REQUIRE(a.valid_Type("MAGAZINE") == true);
    REQUIRE(a.valid_Type("k") == false);

}
TEST_CASE("test upper","[stringToUpper] "){
    AddProduct a = AddProduct();
    REQUIRE(a.stringToUpper("dvd") == "DVD");
    CHECK_FALSE(a.stringToUpper("dvd") == "dvd");

}
TEST_CASE("test menu","[stringToUpper] "){
    Menue m = Menue();
    int menu = m.showMenu();
    REQUIRE(menu == 1);

}
