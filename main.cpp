#include <iostream>
#include <fstream>
#include "Department.h"
#include "Product.h"
#include "Interface.h"
#include "ManagerInterface.h"
#include "CustomerInterface.h"
using namespace std;

Department* StoreDepartments = 0;
int TotalDepartments = 0;
const char* csvFile = "store.csv";

void loadDataFromCSV()
{
    ifstream fin(csvFile);

    if (!fin)
    {
        return;
    }

    fin >> TotalDepartments;
    fin.ignore();

    if (TotalDepartments > 0)
    {
        StoreDepartments = new Department[TotalDepartments];
    }

    for (int i = 0; i < TotalDepartments; i++)
    {
        char depName[100];
        int itemCount;

        fin.getline(depName, 100, ',');
        fin >> itemCount;
        fin.ignore();

        StoreDepartments[i].setDepartmentName(depName);

        for (int j = 0; j < itemCount; j++)
        {
            char itemName[100];
            double price;
            int quantity;

            fin.getline(itemName, 100, ',');
            fin >> price;
            fin.ignore();
            fin >> quantity;
            fin.ignore();

            Product temp(itemName, price, quantity);
            StoreDepartments[i].addProduct(temp);
        }
    }

    fin.close();
}

int main()
{
    loadDataFromCSV();

    int choice;
    Interface* userInterface = 0;

    do
    {
        cout << "\n=== Grocery Store Management System ===" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Manager" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";

        while (true)
        {
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 3)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice. Enter again: ";
            }
            else
            {
                cin.ignore(1000, '\n');
                break;
            }
        }

        if (choice == 1)
        {
            userInterface = new CustomerInterface();
            userInterface->showMenu();
            delete userInterface;
            userInterface = 0;
        }
        else if (choice == 2)
        {
            userInterface = new ManagerInterface();
            userInterface->showMenu();
            delete userInterface;
            userInterface = 0;
        }

    } while (choice != 3);

    delete[] StoreDepartments;
    StoreDepartments = 0;

    cout << "Program ended." << endl;
    return 0;
}
