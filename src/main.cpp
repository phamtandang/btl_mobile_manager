#include <iostream>
#include <string>
#include "../include/SupermarketManager.h"
#include "../include/Utils.h"

using namespace std;

// Function declarations
void displayMainMenu();
void productManagementMenu(SupermarketManager& manager);
void customerManagementMenu(SupermarketManager& manager);
void invoiceManagementMenu(SupermarketManager& manager);
void statisticsMenu(SupermarketManager& manager);

int main() {
    // Create manager instance
    SupermarketManager manager;
    
    // Load data from files
    bool dataLoaded = manager.loadAllData();
    if (!dataLoaded) {
        cout << "Warning: Could not load all data files. Starting with empty data." << endl;
        Utils::pause();
    }
    
    bool running = true;
    while (running) {
        Utils::clearScreen();
        displayMainMenu();
        
        int choice = Utils::getIntInput(0, 4);
        
        switch (choice) {
            case 1:
                productManagementMenu(manager);
                break;
            case 2:
                customerManagementMenu(manager);
                break;
            case 3:
                invoiceManagementMenu(manager);
                break;
            case 4:
                statisticsMenu(manager);
                break;
            case 0:
                if (Utils::confirm("Save all data before exiting?")) {
                    manager.saveAllData();
                }
                running = false;
                break;
        }
    }
    
    cout << "\nThank you for using Supermarket Management System!" << endl;
    return 0;
}

// Display main menu
void displayMainMenu() {
    Utils::displayHeader("SUPERMARKET MANAGEMENT SYSTEM");
    cout << "1. Product Management" << endl;
    cout << "2. Customer Management" << endl;
    cout << "3. Invoice Management" << endl;
    cout << "4. Statistics & Reports" << endl;
    cout << "0. Exit" << endl;
    cout << "\nEnter your choice: ";
}

// Product management menu
void productManagementMenu(SupermarketManager& manager) {
    bool back = false;
    
    while (!back) {
        Utils::clearScreen();
        Utils::displayHeader("PRODUCT MANAGEMENT");
        
        cout << "1. Display All Products" << endl;
        cout << "2. Add New Product" << endl;
        cout << "3. Edit Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Search Products" << endl;
        cout << "6. Sort Products" << endl;
        cout << "0. Back to Main Menu" << endl;
        
        cout << "\nEnter your choice: ";
        int choice = Utils::getIntInput(0, 6);
        
        switch (choice) {
            case 1:
                Utils::clearScreen();
                manager.displayAllProducts();
                Utils::pause();
                break;
            case 2:
                Utils::clearScreen();
                manager.addProduct();
                Utils::pause();
                break;
            case 3:
                Utils::clearScreen();
                manager.editProduct();
                Utils::pause();
                break;
            case 4:
                Utils::clearScreen();
                manager.deleteProduct();
                Utils::pause();
                break;
            case 5:
                Utils::clearScreen();
                manager.searchProducts();
                Utils::pause();
                break;
            case 6:
                Utils::clearScreen();
                manager.sortProducts();
                manager.displayAllProducts();
                Utils::pause();
                break;
            case 0:
                back = true;
                break;
        }
    }
}

// Customer management menu
void customerManagementMenu(SupermarketManager& manager) {
    bool back = false;
    
    while (!back) {
        Utils::clearScreen();
        Utils::displayHeader("CUSTOMER MANAGEMENT");
        
        cout << "1. Display All Customers" << endl;
        cout << "2. Add New Customer" << endl;
        cout << "3. Edit Customer" << endl;
        cout << "4. Delete Customer" << endl;
        cout << "5. Search Customers" << endl;
        cout << "6. Sort Customers" << endl;
        cout << "0. Back to Main Menu" << endl;
        
        cout << "\nEnter your choice: ";
        int choice = Utils::getIntInput(0, 6);
        
        switch (choice) {
            case 1:
                Utils::clearScreen();
                manager.displayAllCustomers();
                Utils::pause();
                break;
            case 2:
                Utils::clearScreen();
                manager.addCustomer();
                Utils::pause();
                break;
            case 3:
                Utils::clearScreen();
                manager.editCustomer();
                Utils::pause();
                break;
            case 4:
                Utils::clearScreen();
                manager.deleteCustomer();
                Utils::pause();
                break;
            case 5:
                Utils::clearScreen();
                manager.searchCustomers();
                Utils::pause();
                break;
            case 6:
                Utils::clearScreen();
                manager.sortCustomers();
                manager.displayAllCustomers();
                Utils::pause();
                break;
            case 0:
                back = true;
                break;
        }
    }
}

// Invoice management menu
void invoiceManagementMenu(SupermarketManager& manager) {
    bool back = false;
    
    while (!back) {
        Utils::clearScreen();
        Utils::displayHeader("INVOICE MANAGEMENT");
        
        cout << "1. Display All Invoices" << endl;
        cout << "2. Create New Invoice" << endl;
        cout << "3. Display Invoice Details" << endl;
        cout << "4. Search Invoices" << endl;
        cout << "5. Sort Invoices" << endl;
        cout << "0. Back to Main Menu" << endl;
        
        cout << "\nEnter your choice: ";
        int choice = Utils::getIntInput(0, 5);
        
        switch (choice) {
            case 1:
                Utils::clearScreen();
                manager.displayAllInvoices();
                Utils::pause();
                break;
            case 2:
                Utils::clearScreen();
                manager.createInvoice();
                Utils::pause();
                break;
            case 3:
                Utils::clearScreen();
                manager.displayInvoice();
                Utils::pause();
                break;
            case 4:
                Utils::clearScreen();
                manager.searchInvoices();
                Utils::pause();
                break;
            case 5:
                Utils::clearScreen();
                manager.sortInvoices();
                manager.displayAllInvoices();
                Utils::pause();
                break;
            case 0:
                back = true;
                break;
        }
    }
}

// Statistics menu
void statisticsMenu(SupermarketManager& manager) {
    bool back = false;
    
    while (!back) {
        Utils::clearScreen();
        Utils::displayHeader("STATISTICS & REPORTS");
        
        cout << "1. Product Statistics" << endl;
        cout << "2. Customer Statistics" << endl;
        cout << "3. Sales Statistics" << endl;
        cout << "0. Back to Main Menu" << endl;
        
        cout << "\nEnter your choice: ";
        int choice = Utils::getIntInput(0, 3);
        
        switch (choice) {
            case 1:
                Utils::clearScreen();
                manager.displayProductStatistics();
                Utils::pause();
                break;
            case 2:
                Utils::clearScreen();
                manager.displayCustomerStatistics();
                Utils::pause();
                break;
            case 3:
                Utils::clearScreen();
                manager.displayInvoiceStatistics();
                Utils::pause();
                break;
            case 0:
                back = true;
                break;
        }
    }
}