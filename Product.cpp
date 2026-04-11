#include "Product.h"
#include <cstring>

Product::Product()
{
    name[0] = '\0';
    price = 0.0;
    quantity = 0;
}

Product::Product(const char* itemName, double itemPrice, int itemQuantity)
{
    setProduct(itemName, itemPrice, itemQuantity);
}

void Product::setProduct(const char* itemName, double itemPrice, int itemQuantity)
{
    if (itemName != 0)
    {
        strncpy(name, itemName, 99);
        name[99] = '\0';
    }
    else
    {
        name[0] = '\0';
    }

    price = itemPrice;
    quantity = itemQuantity;
}

const char* Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

void Product::setQuantity(int itemQuantity)
{
    quantity = itemQuantity;
}
