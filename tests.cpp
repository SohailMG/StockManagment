#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CD.h"
#include "BOOK.h"
#include "DVD.h"
#include "Product.h"

Product product = Product();
CDs CD = CDs();

SCENARIO("testing if files update correctly, [update_stock]")
{
    CD.show_inventory();
    GIVEN(" user sells an item ")
    {
        CD.sell_CD(product.sell_product());
        WHEN("calling update_stock should update old file")
        {
            product.update_stock("CDs.txt");
        }
        THEN("displaying inventory should show changes")
        {
            CD.show_inventory();
        }
    }
}
SCENARIO("testing sales report displaying sales only", "[view_sales]")
{
    GIVEN(" report of current sales")
    {
        product.view_sales();
        WHEN("user makes a sale")
        {
            CD.sell_CD(product.sell_product());
        }
        AND_THEN(" sale was succesfull ")
        {
            product.update_stock("CDs.txt");
        }
        THEN("viewing sales report should display most recent sale")
        {
            product.view_sales();
        }
    }
}
