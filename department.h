#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"

class Department
{
private:
    char name[100];
    Product* products;
    int count;

public:
    Department();
    ~Department();
    
    void setDepartmentName(const char*);
    const char* getDepartmentName() const;

    void addProduct(const Product&);
    void listProducts() const;

    Product* getProducts() const;
    int getTotalProducts() const;
};    

#endif
