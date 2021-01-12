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
/*
testing if user input is stored correctly given that
when user is storing details in the following way:
id       = 1234
name     = test
type     = CD
price    = 12.99
quantity = 10
*/
TEST_CASE("test adding new product","[product_info] "){
    AddProduct a = AddProduct();
    a.product_info();
    REQUIRE(a.get_product_id() == 1234);
    REQUIRE(a.get_product_name() == "test");
    REQUIRE(a.get_product_type() == "CD");
    REQUIRE(a.get_product_price() == 12.99);
    REQUIRE(a.get_product_quantity() == 10);
}
/*
testing item_exits function by passing it an id of 
an existing item and check value of exists
then calling it with a new id and checking value of exists
*/
TEST_CASE("test checking for dublicate id","[product_info] "){
    AddProduct a = AddProduct();
    // passing already stored id
    a.item_exists("1010");
    REQUIRE(a.exists == true);
    // passing new id
    a.item_exists("6744");
    REQUIRE(a.exists == false);
}
