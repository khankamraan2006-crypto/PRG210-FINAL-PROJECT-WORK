# PRG210-FINAL-PROJECT-WORK
#This project focuses on implementing a simple grocery store management system
# Grocery Store Management System

## Overview
This project is a basic grocery store management system made in C++.
It has two interfaces:
- Manager
- Customer

The project uses object-oriented programming concepts like classes, inheritance, polymorphism, dynamic memory, and file handling.

## Features

### Manager
- List departments
- Add department
- Add item to a department
- Save changes to CSV

### Customer
- Show cart
- Browse departments
- View products
- Add item to cart
- Checkout

## Files
- Product.h / Product.cpp
- Department.h / Department.cpp
- Cart.h / Cart.cpp
- Interface.h / Interface.cpp
- ManagerInterface.h / ManagerInterface.cpp
- CustomerInterface.h / CustomerInterface.cpp
- main.cpp
- store.csv

## Compile
g++ main.cpp Product.cpp Department.cpp Cart.cpp Interface.cpp ManagerInterface.cpp CustomerInterface.cpp -o grocery

## Run
./grocery
