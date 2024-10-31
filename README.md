# Inventory-Management-System
This C++ code is an Inventory Management System for Turbo C++. It manages Regular, Perishable, and Electronic products, allowing users to add, display, update, and search inventory. It uses classes and inheritance to handle each product type, a menu-driven interface for easy navigation, and uses conio.h for clrscr() and getch().
Author: Rakesh Jena

This repository contains an Inventory Management System, implemented in C++, designed to handle different types of products, manage stock, and provide search capabilities for efficient inventory control. This program was built by Rakesh Jena with the help of AI to ensure a structurally organized, user-friendly, and easily modifiable solution for general inventory tasks.

Program Overview
This C++ program is a console-based application that allows users to add, update, and manage an inventory of different types of products. It supports three main product types:

Regular Products - General products with basic information like name, ID, quantity, price, and category.
Perishable Products - Products with an expiry date and shelf life, which are useful for items that require close expiration monitoring.
Electronic Products - Items with attributes specific to electronics, like brand name and warranty period.
The program is structured with a base class, Product, which contains fundamental attributes, and two derived classes, PerishableProduct and ElectronicProduct, that add product-specific attributes and methods.

Key Functionalities
1. Add New Product
This option allows users to add new products to the inventory.
Users can select the type of product they wish to add and input details accordingly. Each product type captures different data, ensuring all relevant information is stored accurately.
2. Display All Products
This functionality displays the details of all products in the inventory.
For each product, the program outputs information such as Product ID, name, price, quantity, category, and additional fields specific to perishable and electronic products (like expiry date or warranty period).
3. Update Stock
Users can update the stock quantity for a specific product by entering its Product ID.
The system locates the product and prompts the user to enter the amount of stock to add to the current quantity.
4. Search Product
Users can search for a specific product by entering its Product ID.
If found, the program displays all information related to the product.
5. Exit
Terminates the program safely, ensuring all dynamically allocated memory is released.
How to Run
Compile and Run: Use a C++ compiler to compile and run the code. You can use g++ as follows:
bash
Copy code
g++ inventory_management.cpp -o inventory_management
./inventory_management
User Interaction: Follow the menu-driven prompts to interact with the inventory system.
