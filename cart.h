#ifndef CART_H
#define CART_H

#include "product.h"

class Cart
{
private:
    product*items;
    int*qty;
    int count;

public:
   Cart();
   ~Cart();

   void addToCart(const product&,int);
   void showCart() const;
};

#endif
