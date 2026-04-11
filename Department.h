#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"

class Department
{
private:
    char departmentName[100];
    Product* products;
    int totalProducts;

public:
    Department();
    Department(const char* name);
    Department(const Department& other);
    Department& operator=(const Department& other);
    ~Department();

    void setDepartmentName(const char* name);
    const char* getDepartmentName() const;

    int getTotalProducts() const;
    Product* getProducts() const;

    void addProduct(const Product& newProduct);
    void listProducts() const;
};

#endif
