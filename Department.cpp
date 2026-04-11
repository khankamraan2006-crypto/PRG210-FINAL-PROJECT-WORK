#include "Department.h"
#include <iostream>
#include <cstring>
using namespace std;

Department::Department()
{
    departmentName[0] = '\0';
    products = 0;
    totalProducts = 0;
}

Department::Department(const char* name)
{
    products = 0;
    totalProducts = 0;
    setDepartmentName(name);
}

Department::Department(const Department& other)
{
    strcpy(departmentName, other.departmentName);
    totalProducts = other.totalProducts;

    if (totalProducts > 0)
    {
        products = new Product[totalProducts];
        for (int i = 0; i < totalProducts; i++)
        {
            products[i] = other.products[i];
        }
    }
    else
    {
        products = 0;
    }
}

Department& Department::operator=(const Department& other)
{
    if (this != &other)
    {
        delete[] products;

        strcpy(departmentName, other.departmentName);
        totalProducts = other.totalProducts;

        if (totalProducts > 0)
        {
            products = new Product[totalProducts];
            for (int i = 0; i < totalProducts; i++)
            {
                products[i] = other.products[i];
            }
        }
        else
        {
            products = 0;
        }
    }

    return *this;
}

Department::~Department()
{
    delete[] products;
}

void Department::setDepartmentName(const char* name)
{
    if (name != 0)
    {
        strncpy(departmentName, name, 99);
        departmentName[99] = '\0';
    }
    else
    {
        departmentName[0] = '\0';
    }
}

const char* Department::getDepartmentName() const
{
    return departmentName;
}

int Department::getTotalProducts() const
{
    return totalProducts;
}

Product* Department::getProducts() const
{
    return products;
}

void Department::addProduct(const Product& newProduct)
{
    Product* temp = new Product[totalProducts + 1];

    for (int i = 0; i < totalProducts; i++)
    {
        temp[i] = products[i];
    }

    temp[totalProducts] = newProduct;

    delete[] products;
    products = temp;
    totalProducts++;
}

void Department::listProducts() const
{
    if (totalProducts == 0)
    {
        cout << "No items in this department." << endl;
        return;
    }

    for (int i = 0; i < totalProducts; i++)
    {
        cout << i + 1 << ". "
             << products[i].getName()
             << " - $" << products[i].getPrice()
             << " - Stock: " << products[i].getQuantity()
             << endl;
    }
}
