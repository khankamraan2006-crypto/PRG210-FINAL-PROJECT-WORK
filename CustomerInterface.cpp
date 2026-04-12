#include "CustomerInterface.h"
#include "Department.h"
#include <iostream>
using namespace std;

extern Department* StoreDepartments;
extern int TotalDepartments;

void showDepartmentsToCustomer()
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

void CustomerInterface::showMenu()
{
    int mainChoice;

    do
    {
        cout << "\n--- Customer Menu ---" << endl;
        cout << "1. Show Cart" << endl;
        cout << "2. Browse Departments" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";

        while (true)
        {
            cin >> mainChoice;

            if (cin.fail() || mainChoice < 1 || mainChoice > 3)
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

        if (mainChoice == 1)
        {
            int cartChoice;

            do
            {
                cout << "\n--- Show Cart Menu ---" << endl;
                cout << "1. List Items" << endl;
                cout << "2. Checkout" << endl;
                cout << "3. Return to Main Menu" << endl;
                cout << "Enter your choice [1, 2, 3]: ";

                while (true)
                {
                    cin >> cartChoice;

                    if (cin.fail() || cartChoice < 1 || cartChoice > 3)
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

                if (cartChoice == 1)
                {
                    shoppingCart.showCart();
                }
                else if (cartChoice == 2)
                {
                    shoppingCart.checkout();
                }

            } while (cartChoice != 3);
        }
        else if (mainChoice == 2)
        {
            int browseChoice;

            do
            {
                cout << "\n--- Browse Departments ---" << endl;
                showDepartmentsToCustomer();
                cout << "1. List Items of a Department" << endl;
                cout << "2. Go Back to Main Menu" << endl;
                cout << "Enter your choice [1, 2]: ";

                while (true)
                {
                    cin >> browseChoice;

                    if (cin.fail() || browseChoice < 1 || browseChoice > 2)
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

                if (browseChoice == 1)
                {
                    if (TotalDepartments == 0)
                    {
                        cout << "No departments available." << endl;
                        continue;
                    }

                    int depNumber;
                    cout << "Enter department number [0 to go back]: ";

                    while (true)
                    {
                        cin >> depNumber;

                        if (cin.fail() || depNumber < 0 || depNumber > TotalDepartments)
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

                    if (depNumber == 0)
                    {
                        continue;
                    }

                    Department& selectedDepartment = StoreDepartments[depNumber - 1];
                    selectedDepartment.listProducts();

                    int itemMenuChoice;
                    cout << "1. Add to Cart an Item" << endl;
                    cout << "2. Go Back to Browse Departments Menu" << endl;
                    cout << "Enter your choice [1, 2]: ";

                    while (true)
                    {
                        cin >> itemMenuChoice;

                        if (cin.fail() || itemMenuChoice < 1 || itemMenuChoice > 2)
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

                    if (itemMenuChoice == 1)
                    {
                        int itemNumber;
                        cout << "Enter item number to buy [0 to go back]: ";

                        while (true)
                        {
                            cin >> itemNumber;

                            if (cin.fail() || itemNumber < 0 || itemNumber > selectedDepartment.getTotalProducts())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid item number. Enter again: ";
                            }
                            else
                            {
                                cin.ignore(1000, '\n');
                                break;
                            }
                        }

                        if (itemNumber == 0)
                        {
                            continue;
                        }

                        int buyQty;
                        cout << "Enter quantity to buy: ";

                        while (true)
                        {
                            cin >> buyQty;

                            if (cin.fail() || buyQty <= 0)
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

                        Product* items = selectedDepartment.getProducts();

                        if (buyQty > items[itemNumber - 1].getQuantity())
                        {
                            cout << "Not enough stock available." << endl;
                        }
                        else
                        {
                            shoppingCart.addToCart(items[itemNumber - 1], buyQty);

                            int remainingQty = items[itemNumber - 1].getQuantity() - buyQty;
                            items[itemNumber - 1].setQuantity(remainingQty);

                            cout << "Item added to cart" << endl;
                        }
                    }
                }

            } while (browseChoice != 2);
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting customer interface..." << endl;
        }

    } while (mainChoice != 3);
}
