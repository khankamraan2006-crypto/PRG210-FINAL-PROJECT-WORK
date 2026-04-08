#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
private:
      char name[100];
      double price;
      int quanity;
public:
      Product();
      Product(const char*,double,int);

     void setProduct(const char*,double,int);

    const char* getName() const;
    double getPrice() const;
    int getQuantity() const;

   void setQuantity(int);
};
#endif
