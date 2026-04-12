#include "ManagerInterface.h"
#include "Department.h"
#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;

extern Department* StoreDepartments;
extern int TotalDepartments;
extern const char* csvFile;

void listDepartmentsForManager()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available." << endl;
        return;
    }

    for (int i = 0; i < TotalDepartments; i++)
    {
        cout << i + 1 << ". " << StoreDepartments[i].getDepartmentName() << endl;
    }
}

void addDepartmentToStore()
{
    char depName[100];
    cout << "Enter department name: ";
    cin.getline(depName, 100);

    while (depName[0] == '\0')
    {
        cout << "Enter department name: ";
        cin.getline(depName, 100);
    }

    Department* temp = new Department[TotalDepartments + 1];

    for (int i = 0; i < TotalDepartments; i++)
    {
        temp[i] = StoreDepartments[i];
    }

    temp[TotalDepartments].setDepartmentName(depName);

    delete[] StoreDepartments;
    StoreDepartments = temp;
    TotalDepartments++;

    cout << "Department added successfully." << endl;
}

void addItemIntoDepartment()
{
    if (TotalDepartments == 0)
    {
        cout << "No departments available." << endl;
        return;
    }

    listDepartmentsForManager();
    cout << "Enter department number [0 to go back]: ";

    int depChoice;
    while (true)
    {
        cin >> depChoice;

        if (cin.fail() || depChoice < 0 || depChoice > TotalDepartments)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid department number. Enter again: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    if (depChoice == 0)
    {
        return;
    }

    char itemName[100];
    double itemPrice;
    int itemQty;

    cout << "Enter item name: ";
    cin.getline(itemName, 100);

    while (itemName[0] == '\0')
    {
        cout << "Enter item name: ";
        cin.getline(itemName, 100);
    }

    cout << "Enter item price: ";
    while (true)
    {
        cin >> itemPrice;

        if (cin.fail() || itemPrice <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid price. Enter again: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << "Enter item quantity: ";
    while (true)
    {
        cin >> itemQty;

        if (cin.fail() || itemQty <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid quantity. Enter again: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    Product newProduct(itemName, itemPrice, itemQty);
    StoreDepartments[depChoice - 1].addProduct(newProduct);

    cout << "Item added successfully." << endl;
}

void saveStoreData()
{
    ofstream fout(csvFile);

    if (!fout)
    {
        cout << "Could not open file." << endl;
        return;
    }

    fout << TotalDepartments << endl;

    for (int i = 0; i < TotalDepartments; i++)
    {
        fout << StoreDepartments[i].getDepartmentName() << ","
             << StoreDepartments[i].getTotalProducts() << endl;

        Product* items = StoreDepartments[i].getProducts();

        for (int j = 0; j < StoreDepartments[i].getTotalProducts(); j++)
        {
            fout << items[j].getName() << ","
                 << items[j].getPrice() << ","
                 << items[j].getQuantity() << endl;
        }
    }

    fout.close();
    cout << "Changes saved successfully." << endl;
}

void ManagerInterface::showMenu()
{
    int choice;

    do
    {
        cout << "\n--- Manager Menu ---" << endl;
        cout << "1. List Departments" << endl;
        cout << "2. Add Department" << endl;
        cout << "3. Add Item to Department" << endl;
        cout << "4. Save Changes to CSV" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice [1, 2, 3, 4, 5]: ";

        while (true)
        {
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 5)
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

        switch (choice)
        {
        case 1:
            listDepartmentsForManager();
            break;
        case 2:
            addDepartmentToStore();
            break;
        case 3:
            addItemIntoDepartment();
            break;
        case 4:
            saveStoreData();
            break;
        case 5:
            cout << "Exiting manager interface..." << endl;
            break;
        }
    } while (choice != 5);
}
