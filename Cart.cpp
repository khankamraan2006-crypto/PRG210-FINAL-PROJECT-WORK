#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart()
{
    items = 0;
    quantities = 0;
    totalItems = 0;
}

Cart::Cart(const Cart& other)
{
    totalItems = other.totalItems;

    if (totalItems > 0)
    {
        items = new Product[totalItems];
        quantities = new int[totalItems];

        for (int i = 0; i < totalItems; i++)
        {
            items[i] = other.items[i];
            quantities[i] = other.quantities[i];
        }
    }
    else
    {
        items = 0;
        quantities = 0;
    }
}

Cart& Cart::operator=(const Cart& other)
{
    if (this != &other)
    {
        delete[] items;
        delete[] quantities;

        totalItems = other.totalItems;

        if (totalItems > 0)
        {
            items = new Product[totalItems];
            quantities = new int[totalItems];

            for (int i = 0; i < totalItems; i++)
            {
                items[i] = other.items[i];
                quantities[i] = other.quantities[i];
            }
        }
        else
        {
            items = 0;
            quantities = 0;
        }
    }

    return *this;
}

Cart::~Cart()
{
    delete[] items;
    delete[] quantities;
}

void Cart::addToCart(const Product& product, int qty)
{
    Product* tempItems = new Product[totalItems + 1];
    int* tempQty = new int[totalItems + 1];

    for (int i = 0; i < totalItems; i++)
    {
        tempItems[i] = items[i];
        tempQty[i] = quantities[i];
    }

    tempItems[totalItems] = product;
    tempQty[totalItems] = qty;

    delete[] items;
    delete[] quantities;

    items = tempItems;
    quantities = tempQty;
    totalItems++;
}

void Cart::showCart() const
{
    if (totalItems == 0)
    {
        cout << "No items in the cart" << endl;
        return;
    }

    double subtotal = 0.0;

    for (int i = 0; i < totalItems; i++)
    {
        double lineTotal = items[i].getPrice() * quantities[i];
        subtotal += lineTotal;

        cout << i + 1 << ". "
             << items[i].getName()
             << " | Quantity: " << quantities[i]
             << " | Price: $" << items[i].getPrice()
             << endl;
    }

    double totalWithTax = subtotal + (subtotal * 0.13);
    cout << "Total with 13% tax: $" << totalWithTax << endl;
}

void Cart::checkout()
{
    if (totalItems == 0)
    {
        cout << "No items in the cart" << endl;
        return;
    }

    cout << "Thank you for your purchase" << endl;

    delete[] items;
    delete[] quantities;

    items = 0;
    quantities = 0;
    totalItems = 0;
}

bool Cart::isEmpty() const
{
    return totalItems == 0;
// }
