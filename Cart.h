#ifndef CART_H
#define CART_H

#include "Product.h"

class Cart
{
private:
    Product* items;
    int* quantities;
    int totalItems;

public:
    Cart();
    Cart(const Cart& other);
    Cart& operator=(const Cart& other);
    ~Cart();

    void addToCart(const Product& product, int qty);
    void showCart() const;
    void checkout();
    bool isEmpty() const;
};

#endif
