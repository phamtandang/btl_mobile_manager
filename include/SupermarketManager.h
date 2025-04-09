#ifndef SUPERMARKET_MANAGER_H
#define SUPERMARKET_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Product.h"
#include "Customer.h"
#include "Invoice.h"
#include "Utils.h"

class SupermarketManager {
private:
    std::vector<Product> products;
    std::vector<Customer> customers;
    std::vector<Invoice> invoices;
    std::string currentDate;

    // File paths
    const std::string PRODUCTS_FILE = "data/products.csv";
    const std::string CUSTOMERS_FILE = "data/customers.csv";
    const std::string INVOICES_FILE = "data/invoices.csv";

    // File operations
    bool saveProducts();
    bool saveCustomers();
    bool saveInvoices();
    bool loadProducts();
    bool loadCustomers();
    bool loadInvoices();

public:
    // Constructor
    SupermarketManager();

    // Load and save all data
    bool saveAllData();
    bool loadAllData();

    // Product management
    void addProduct();
    void editProduct();
    void deleteProduct();
    void searchProducts();
    void sortProducts();
    void displayAllProducts();
    void displayProductStatistics();

    // Customer management
    void addCustomer();
    void editCustomer();
    void deleteCustomer();
    void searchCustomers();
    void sortCustomers();
    void displayAllCustomers();
    void displayCustomerStatistics();

    // Invoice management
    void createInvoice();
    void displayInvoice();
    void displayAllInvoices();
    void searchInvoices();
    void sortInvoices();
    void displayInvoiceStatistics();

    // Get product and customer by ID
    Product* getProductById(const std::string& id);
    Customer* getCustomerById(const std::string& id);
};

#endif // SUPERMARKET_MANAGER_H