#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_PRODUCTS = 100;

// Utility function to clear input buffer
void clearInputBuffer() {
    char ch;
    while((ch = cin.get()) != '\n' && ch != EOF);
}

// Base Product class
class Product {
protected:
    int productID;
    char productName[50];
    float price;
    int quantity;
    char category[30];
    static int totalProducts;

public:
    Product() {
        productID = 0;
        strcpy(productName, "");
        price = 0.0;
        quantity = 0;
        strcpy(category, "");
    }

    Product(int id, const char* name, float p, int q, const char* cat) {
        productID = id;
        strcpy(productName, name);
        price = p;
        quantity = q;
        strcpy(category, cat);
        totalProducts++;
    }

    virtual ~Product() {
        cout << "\nProduct " << productName << " destroyed";
    }

    // Simple inline getters
    int getID() const { return productID; }
    const char* getName() const { return productName; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    const char* getCategory() const { return category; }

    void setPrice(float p) { price = p; }
    void setQuantity(int q) { quantity = q; }

    static int getTotalProducts() { return totalProducts; }

    virtual void display() const {
        cout << "\n----------------------------";
        cout << "\nProduct ID: " << productID;
        cout << "\nName: " << productName;
        cout << "\nPrice: $" << price;
        cout << "\nQuantity: " << quantity;
        cout << "\nCategory: " << category;
    }

    virtual void input() {
        cout << "\nEnter Product Details:";
        cout << "\nID: ";
        cin >> productID;
        clearInputBuffer();  // Clear buffer after number input
        
        cout << "Name: ";
        cin.getline(productName, 50);
        
        cout << "Price: $";
        cin >> price;
        clearInputBuffer();
        
        cout << "Quantity: ";
        cin >> quantity;
        clearInputBuffer();
        
        cout << "Category: ";
        cin.getline(category, 30);
    }
};

int Product::totalProducts = 0;

// Derived class for Perishable Products
class PerishableProduct : public Product {
private:
    char expiryDate[11];
    int shelfLife;

public:
    PerishableProduct() : Product() {
        strcpy(expiryDate, "");
        shelfLife = 0;
    }

    void display() const {
        Product::display();
        cout << "\nExpiry Date: " << expiryDate;
        cout << "\nShelf Life: " << shelfLife << " days";
        cout << "\n----------------------------";
    }

    void input() {
        Product::input();
        cout << "Expiry Date (YYYY-MM-DD): ";
        cin.getline(expiryDate, 11);
        
        cout << "Shelf Life (days): ";
        cin >> shelfLife;
        clearInputBuffer();
    }
};

// Derived class for Electronics
class ElectronicProduct : public Product {
private:
    char brand[30];
    int warrantyPeriod;

public:
    ElectronicProduct() : Product() {
        strcpy(brand, "");
        warrantyPeriod = 0;
    }

    void display() const {
        Product::display();
        cout << "\nBrand: " << brand;
        cout << "\nWarranty Period: " << warrantyPeriod << " months";
        cout << "\n----------------------------";
    }

    void input() {
        Product::input();
        cout << "Brand: ";
        cin.getline(brand, 30);
        
        cout << "Warranty Period (months): ";
        cin >> warrantyPeriod;
        clearInputBuffer();
    }
};

// Inventory System class
class InventorySystem {
private:
    Product* inventory[MAX_PRODUCTS];
    int productCount;

public:
    InventorySystem() : productCount(0) {
        for(int i = 0; i < MAX_PRODUCTS; i++) {
            inventory[i] = NULL;
        }
    }

    ~InventorySystem() {
        for(int i = 0; i < productCount; i++) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }

    void addProduct() {
        if (productCount >= MAX_PRODUCTS) {
            cout << "\nInventory is full!";
            return;
        }

        int type;
        cout << "\nSelect Product Type:";
        cout << "\n1. Regular Product";
        cout << "\n2. Perishable Product";
        cout << "\n3. Electronic Product";
        cout << "\nEnter choice: ";
        cin >> type;
        clearInputBuffer();

        switch(type) {
            case 1:
                inventory[productCount] = new Product();
                break;
            case 2:
                inventory[productCount] = new PerishableProduct();
                break;
            case 3:
                inventory[productCount] = new ElectronicProduct();
                break;
            default:
                cout << "\nInvalid choice!";
                return;
        }

        inventory[productCount]->input();
        productCount++;
        cout << "\nProduct added successfully!";
    }

    void displayAllProducts() {
        if (productCount == 0) {
            cout << "\nNo products in inventory!";
            return;
        }

        for (int i = 0; i < productCount; i++) {
            inventory[i]->display();
        }
    }

    void updateStock() {
        int id, quantity;
        cout << "\nEnter Product ID: ";
        cin >> id;
        clearInputBuffer();

        for (int i = 0; i < productCount; i++) {
            if (inventory[i]->getID() == id) {
                cout << "Enter quantity to add: ";
                cin >> quantity;
                clearInputBuffer();
                inventory[i]->setQuantity(inventory[i]->getQuantity() + quantity);
                cout << "\nStock updated successfully!";
                return;
            }
        }
        cout << "\nProduct not found!";
    }

    void searchProduct() {
        int id;
        cout << "\nEnter Product ID to search: ";
        cin >> id;
        clearInputBuffer();

        for (int i = 0; i < productCount; i++) {
            if (inventory[i]->getID() == id) {
                inventory[i]->display();
                return;
            }
        }
        cout << "\nProduct not found!";
    }
};

void main() {
    clrscr();
    InventorySystem system;
    int choice;

    do {
        cout << "\n\nSTORE INVENTORY MANAGEMENT SYSTEM";
        cout << "\n1. Add New Product";
        cout << "\n2. Display All Products";
        cout << "\n3. Update Stock";
        cout << "\n4. Search Product";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        
        cin >> choice;
        clearInputBuffer();  // Clear buffer after reading choice

        switch(choice) {
            case 1:
                system.addProduct();
                break;
            case 2:
                system.displayAllProducts();
                break;
            case 3:
                system.updateStock();
                break;
            case 4:
                system.searchProduct();
                break;
            case 5:
                cout << "\nExiting...";
                break;
            default:
                cout << "\nInvalid choice!";
        }
    } while (choice != 5);

    getch();
}