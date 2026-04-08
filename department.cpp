#include "department.h"
#include <iosteam>
#include <cstring>
using namespace std;

Department::Department()
{
  name[0]='\0';
  product=0;
  count=0;
}
Department::~Department()
{
  delete[] products;
}
void Department::setDepartmentName(const char*n)
{
  strncpy(name,n,99);
  name[99]='\0'
}
const char* Department::getDepartmentName() const
{
  return name;
}
void Department::addProduct(const Product& p)
{
  Product* temp=new Product[count+1];
  for (int i=0;i<count;i++)
    temp[i]=product[i];
  temp[count]=p;
  delete[] products;
  products=temp;
  count++;
}
void Department::listProducts() const
{
  for(int i=0;i<count;i++)
    {
      cout<<i+1<<"."<<
    }
}
