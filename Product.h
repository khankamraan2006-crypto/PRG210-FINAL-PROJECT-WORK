#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
private:
    char name[100];
    double price;
    int quantity;

public:
    Product();
    Product(const char* itemName, double itemPrice, int itemQuantity);

    void setProduct(const char* itemName, double itemPrice, int itemQuantity);

    const char* getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setQuantity(int itemQuantity);
};

#endif
