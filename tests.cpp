#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "updateStock.h"
#include "addProduct.h"
#include "sellProduct.h"
#include "RestockProduct.h"
#include "Product.h"
#include "menu.h"

Product p = Product();
AddProduct a = AddProduct();
Menue m = Menue();
TEST_CASE("test type", "[valid_type] ")
{
    REQUIRE(a.valid_Type("DVD") == true);
    REQUIRE(a.valid_Type("CD") == true);
    REQUIRE(a.valid_Type("BOOK") == true);
    REQUIRE(a.valid_Type("MAGAZINE") == true);
    REQUIRE(a.valid_Type("k") == false);
}
TEST_CASE("test upper", "[stringToUpper] ")
{

    REQUIRE(a.stringToUpper("dvd") == "DVD");
    CHECK_FALSE(a.stringToUpper("dvd") == "dvd");
}
/*
testing item_exits function by passing it an id of 
an existing item and check value of exists
then calling it with a new id and checking value of exists
*/
SCENARIO("test checking for dublicate id", "[id_mismatch] ")
{
    GIVEN("product id =  1010 ")
    {
        // passing already stored id
        WHEN("id matches an exisiting one")
        {
            a.item_exists("1010");
            THEN("boolean exists should be set to true")
            {
                REQUIRE(a.exists == false);
            }
        }
    }

    // case when id is not matching
    GIVEN("product id = 6744")
    {
        // passing new id
        WHEN(" id is not matching an existing one")
        {
            a.item_exists("6744");
            THEN("exists should be set to false")
            {
                REQUIRE(a.exists == true);
            }
        }
    }
}