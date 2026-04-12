#include "Interface.h"
#include <iostream>
#include <cstring>
using namespace std;

Interface::~Interface()
{
}

int Interface::readIntInRange(int min, int max)
{
    int value;

    while (true)
    {
        cin >> value;

        if (cin.fail() || value < min || value > max)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter again: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

int Interface::readPositiveInt()
{
    int value;

    while (true)
    {
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a positive integer: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

double Interface::readPositiveDouble()
{
    double value;

    while (true)
    {
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a positive number: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

void Interface::readNonEmptyString(char* text, int size)
{
    while (true)
    {
        cin.getline(text, size);

        if (strlen(text) == 0)
        {
            cout << "Input cannot be empty. Enter again: ";
        }
        else
        {
            return;
        }
    }
}
