#ifndef CART_H
#define CART_H

#include "Product.h"

class Cart
{
private:
    Product*items;
    int*qty;
    int count;

public:
   Cart();
   ~Cart();

   void addToCart(const Product&,int);
   void showCart() const;
};

#endif
