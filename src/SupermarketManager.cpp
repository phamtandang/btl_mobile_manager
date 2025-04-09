#include "../include/SupermarketManager.h"
#include "../include/Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

// Constructor
SupermarketManager::SupermarketManager() {
    currentDate = Utils::getCurrentDate();
    
    // Ensure data directory exists
    #ifdef __cpp_lib_filesystem
    namespace fs = std::filesystem;
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }
    #else
    // Simple fallback for older compilers without C++17 filesystem
    system("mkdir -p data");
    #endif
}

// File operations for products
bool SupermarketManager::saveProducts() {
    ofstream file(PRODUCTS_FILE);
    if (!file) {
        return false;
    }

    for (const auto& product : products) {
        file << product.toString() << endl;
    }

    return true;
}

bool SupermarketManager::loadProducts() {
    ifstream file(PRODUCTS_FILE);
    if (!file) {
        return false;
    }

    products.clear();
    string line;
    while (getline(file, line)) {
        Product product;
        product.fromString(line);
        products.push_back(product);
    }

    return true;
}

// File operations for customers
bool SupermarketManager::saveCustomers() {
    ofstream file(CUSTOMERS_FILE);
    if (!file) {
        return false;
    }

    for (const auto& customer : customers) {
        file << customer.toString() << endl;
    }

    return true;
}

bool SupermarketManager::loadCustomers() {
    ifstream file(CUSTOMERS_FILE);
    if (!file) {
        return false;
    }

    customers.clear();
    string line;
    while (getline(file, line)) {
        Customer customer;
        customer.fromString(line);
        customers.push_back(customer);
    }

    return true;
}

// File operations for invoices
bool SupermarketManager::saveInvoices() {
    ofstream file(INVOICES_FILE);
    if (!file) {
        return false;
    }

    for (const auto& invoice : invoices) {
        file << invoice.headerToString() << endl;
        
        // Save items
        for (const auto& item : invoice.getItems()) {
            file << item.toString() << endl;
        }
    }

    return true;
}

bool SupermarketManager::loadInvoices() {
    ifstream file(INVOICES_FILE);
    if (!file) {
        return false;
    }

    invoices.clear();
    string line;
    
    while (getline(file, line)) {
        Invoice invoice;
        invoice.headerFromString(line);
        
        // Extract number of items from the last part of header
        stringstream ss(line);
        string token;
        int itemCount = 0;
        
        // Skip to the last token
        while (getline(ss, token, ',')) {}
        itemCount = stoi(token);
        
        // Read items
        for (int i = 0; i < itemCount; i++) {
            if (getline(file, line)) {
                InvoiceItem item;
                item.fromString(line);
                invoice.addItem(item);
            }
        }
        
        invoices.push_back(invoice);
    }

    return true;
}

// Load and save all data
bool SupermarketManager::saveAllData() {
    bool success = true;
    
    if (!saveProducts()) {
        cerr << "Warning: Failed to save products data." << endl;
        success = false;
    }
    
    if (!saveCustomers()) {
        cerr << "Warning: Failed to save customers data." << endl;
        success = false;
    }
    
    if (!saveInvoices()) {
        cerr << "Warning: Failed to save invoices data." << endl;
        success = false;
    }
    
    return success;
}

bool SupermarketManager::loadAllData() {
    bool success = true;
    
    if (!loadProducts()) {
        cerr << "Warning: Failed to load products data." << endl;
        success = false;
    }
    
    if (!loadCustomers()) {
        cerr << "Warning: Failed to load customers data." << endl;
        success = false;
    }
    
    if (!loadInvoices()) {
        cerr << "Warning: Failed to load invoices data." << endl;
        success = false;
    }
    
    return success;
}

// Product management
void SupermarketManager::addProduct() {
    string id, name, category, manufacturer, importDate;
    double price;
    int quantity;

    cout << "\n=== Add New Product ===\n";
    
    // Generate ID
    id = Utils::generateId("P", products.size() + 1);
    cout << "Product ID: " << id << " (auto-generated)" << endl;
    
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter category: ";
    getline(cin, category);
    
    cout << "Enter price: ";
    cin >> price;
    
    cout << "Enter quantity: ";
    cin >> quantity;
    
    cout << "Enter manufacturer: ";
    cin.ignore();
    getline(cin, manufacturer);
    
    cout << "Enter import date (DD/MM/YYYY) or leave empty for today: ";
    getline(cin, importDate);
    if (importDate.empty()) {
        importDate = currentDate;
    }
    
    // Create and add the product
    Product product(id, name, category, price, quantity, manufacturer, importDate);
    products.push_back(product);
    
    cout << "Product added successfully!" << endl;
    
    // Save products to file
    saveProducts();
}

void SupermarketManager::editProduct() {
    string idToEdit;
    cout << "\n=== Edit Product ===\n";
    
    // Display all products for reference
    displayAllProducts();
    
    cout << "Enter product ID to edit: ";
    cin >> idToEdit;
    
    // Find the product
    auto it = find_if(products.begin(), products.end(), 
        [&idToEdit](const Product& p) { return p.getId() == idToEdit; });
    
    if (it != products.end()) {
        int choice;
        string strValue;
        double dblValue;
        int intValue;
        
        cout << "\nProduct found. What would you like to edit?\n";
        cout << "1. Name\n";
        cout << "2. Category\n";
        cout << "3. Price\n";
        cout << "4. Quantity\n";
        cout << "5. Manufacturer\n";
        cout << "6. Import Date\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, strValue);
                it->setName(strValue);
                break;
            case 2:
                cout << "Enter new category: ";
                cin.ignore();
                getline(cin, strValue);
                it->setCategory(strValue);
                break;
            case 3:
                cout << "Enter new price: ";
                cin >> dblValue;
                it->setPrice(dblValue);
                break;
            case 4:
                cout << "Enter new quantity: ";
                cin >> intValue;
                it->setQuantity(intValue);
                break;
            case 5:
                cout << "Enter new manufacturer: ";
                cin.ignore();
                getline(cin, strValue);
                it->setManufacturer(strValue);
                break;
            case 6:
                cout << "Enter new import date (DD/MM/YYYY): ";
                cin.ignore();
                getline(cin, strValue);
                it->setImportDate(strValue);
                break;
            default:
                cout << "Invalid choice!" << endl;
                return;
        }
        
        cout << "Product updated successfully!" << endl;
        
        // Save changes
        saveProducts();
    } else {
        cout << "Product not found!" << endl;
    }
}

void SupermarketManager::deleteProduct() {
    string idToDelete;
    cout << "\n=== Delete Product ===\n";
    
    // Display all products for reference
    displayAllProducts();
    
    cout << "Enter product ID to delete: ";
    cin >> idToDelete;
    
    // Find the product
    auto it = find_if(products.begin(), products.end(), 
        [&idToDelete](const Product& p) { return p.getId() == idToDelete; });
    
    if (it != products.end()) {
        char confirm;
        cout << "Are you sure you want to delete this product? (y/n): ";
        cin >> confirm;
        
        if (tolower(confirm) == 'y') {
            products.erase(it);
            cout << "Product deleted successfully!" << endl;
            
            // Save changes
            saveProducts();
        } else {
            cout << "Deletion cancelled." << endl;
        }
    } else {
        cout << "Product not found!" << endl;
    }
}

void SupermarketManager::searchProducts() {
    int choice;
    cout << "\n=== Search Products ===\n";
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Category\n";
    cout << "4. Price Range\n";
    cout << "5. Manufacturer\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    vector<Product> searchResults;
    string strCriteria;
    double minPrice, maxPrice;
    
    switch (choice) {
        case 1: // ID
            cout << "Enter ID: ";
            cin >> strCriteria;
            for (const auto& p : products) {
                if (p.getId() == strCriteria) {
                    searchResults.push_back(p);
                }
            }
            break;
            
        case 2: // Name
            cout << "Enter name (or part of name): ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& p : products) {
                if (p.getName().find(strCriteria) != string::npos) {
                    searchResults.push_back(p);
                }
            }
            break;
            
        case 3: // Category
            cout << "Enter category: ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& p : products) {
                if (p.getCategory() == strCriteria) {
                    searchResults.push_back(p);
                }
            }
            break;
            
        case 4: // Price Range
            cout << "Enter minimum price: ";
            cin >> minPrice;
            cout << "Enter maximum price: ";
            cin >> maxPrice;
            for (const auto& p : products) {
                if (p.getPrice() >= minPrice && p.getPrice() <= maxPrice) {
                    searchResults.push_back(p);
                }
            }
            break;
            
        case 5: // Manufacturer
            cout << "Enter manufacturer: ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& p : products) {
                if (p.getManufacturer() == strCriteria) {
                    searchResults.push_back(p);
                }
            }
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    // Display results
    if (searchResults.empty()) {
        cout << "No products found matching your criteria." << endl;
    } else {
        cout << "\n=== Search Results (" << searchResults.size() << " products found) ===\n";
        Product::displayHeader();
        for (const auto& p : searchResults) {
            p.display();
        }
    }
}

void SupermarketManager::sortProducts() {
    int choice;
    cout << "\n=== Sort Products ===\n";
    cout << "Sort by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Category\n";
    cout << "4. Price (low to high)\n";
    cout << "5. Price (high to low)\n";
    cout << "6. Quantity (low to high)\n";
    cout << "7. Quantity (high to low)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: // ID
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getId() < b.getId(); });
            break;
            
        case 2: // Name
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getName() < b.getName(); });
            break;
            
        case 3: // Category
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getCategory() < b.getCategory(); });
            break;
            
        case 4: // Price (low to high)
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getPrice() < b.getPrice(); });
            break;
            
        case 5: // Price (high to low)
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getPrice() > b.getPrice(); });
            break;
            
        case 6: // Quantity (low to high)
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getQuantity() < b.getQuantity(); });
            break;
            
        case 7: // Quantity (high to low)
            sort(products.begin(), products.end(), 
                [](const Product& a, const Product& b) { return a.getQuantity() > b.getQuantity(); });
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    cout << "Products sorted successfully!" << endl;
}

void SupermarketManager::displayAllProducts() {
    if (products.empty()) {
        cout << "No products available." << endl;
        return;
    }
    
    cout << "\n=== All Products (" << products.size() << ") ===\n";
    Product::displayHeader();
    for (const auto& product : products) {
        product.display();
    }
}

void SupermarketManager::displayProductStatistics() {
    if (products.empty()) {
        cout << "No products available for statistics." << endl;
        return;
    }
    
    // Calculate statistics
    double totalValue = 0;
    int totalQuantity = 0;
    double maxPrice = 0;
    double minPrice = numeric_limits<double>::max();
    int maxQuantity = 0;
    int minQuantity = numeric_limits<int>::max();
    string maxPriceProduct, minPriceProduct;
    string maxQuantityProduct, minQuantityProduct;
    
    // Map to count products by category
    map<string, int> categoryCount;
    
    for (const auto& p : products) {
        // Total value and quantity
        totalValue += p.getPrice() * p.getQuantity();
        totalQuantity += p.getQuantity();
        
        // Price statistics
        if (p.getPrice() > maxPrice) {
            maxPrice = p.getPrice();
            maxPriceProduct = p.getName();
        }
        if (p.getPrice() < minPrice) {
            minPrice = p.getPrice();
            minPriceProduct = p.getName();
        }
        
        // Quantity statistics
        if (p.getQuantity() > maxQuantity) {
            maxQuantity = p.getQuantity();
            maxQuantityProduct = p.getName();
        }
        if (p.getQuantity() < minQuantity) {
            minQuantity = p.getQuantity();
            minQuantityProduct = p.getName();
        }
        
        // Category count
        categoryCount[p.getCategory()]++;
    }
    
    // Display statistics
    cout << "\n=== Product Statistics ===\n";
    cout << "Total number of products: " << products.size() << endl;
    cout << "Total inventory value: $" << fixed << setprecision(2) << totalValue << endl;
    cout << "Total inventory quantity: " << totalQuantity << " items" << endl;
    cout << "Average product price: $" << fixed << setprecision(2) << (products.empty() ? 0 : totalValue / totalQuantity) << endl;
    cout << "\nPrice Statistics:" << endl;
    cout << "Most expensive product: " << maxPriceProduct << " ($" << maxPrice << ")" << endl;
    cout << "Least expensive product: " << minPriceProduct << " ($" << minPrice << ")" << endl;
    cout << "\nQuantity Statistics:" << endl;
    cout << "Product with most stock: " << maxQuantityProduct << " (" << maxQuantity << " units)" << endl;
    cout << "Product with least stock: " << minQuantityProduct << " (" << minQuantity << " units)" << endl;
    
    cout << "\nProducts by Category:" << endl;
    for (const auto& category : categoryCount) {
        cout << category.first << ": " << category.second << " products" << endl;
    }
}

// Customer management functions
void SupermarketManager::addCustomer() {
    string id, name, phone, address, email, membershipLevel, registrationDate;
    int totalPurchases = 0;
    
    cout << "\n=== Add New Customer ===\n";
    
    // Generate ID
    id = Utils::generateId("C", customers.size() + 1);
    cout << "Customer ID: " << id << " (auto-generated)" << endl;
    
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter phone number: ";
    getline(cin, phone);
    
    cout << "Enter address: ";
    getline(cin, address);
    
    cout << "Enter email: ";
    getline(cin, email);
    
    membershipLevel = "Basic"; // Default membership level
    
    cout << "Enter registration date (DD/MM/YYYY) or leave empty for today: ";
    getline(cin, registrationDate);
    if (registrationDate.empty()) {
        registrationDate = currentDate;
    }
    
    // Create and add the customer
    Customer customer(id, name, phone, address, email, membershipLevel, registrationDate, totalPurchases);
    customers.push_back(customer);
    
    cout << "Customer added successfully!" << endl;
    
    // Save customers to file
    saveCustomers();
}

void SupermarketManager::editCustomer() {
    string idToEdit;
    cout << "\n=== Edit Customer ===\n";
    
    // Display all customers for reference
    displayAllCustomers();
    
    cout << "Enter customer ID to edit: ";
    cin >> idToEdit;
    
    // Find the customer
    auto it = find_if(customers.begin(), customers.end(), 
        [&idToEdit](const Customer& c) { return c.getId() == idToEdit; });
    
    if (it != customers.end()) {
        int choice;
        string strValue;
        int intValue;
        
        cout << "\nCustomer found. What would you like to edit?\n";
        cout << "1. Name\n";
        cout << "2. Phone\n";
        cout << "3. Address\n";
        cout << "4. Email\n";
        cout << "5. Total Purchases\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, strValue);
                it->setName(strValue);
                break;
            case 2:
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, strValue);
                it->setPhone(strValue);
                break;
            case 3:
                cout << "Enter new address: ";
                cin.ignore();
                getline(cin, strValue);
                it->setAddress(strValue);
                break;
            case 4:
                cout << "Enter new email: ";
                cin.ignore();
                getline(cin, strValue);
                it->setEmail(strValue);
                break;
            case 5:
                cout << "Enter new total purchases: ";
                cin >> intValue;
                it->setTotalPurchases(intValue);
                it->updateMembershipLevel();
                break;
            default:
                cout << "Invalid choice!" << endl;
                return;
        }
        
        cout << "Customer updated successfully!" << endl;
        
        // Save changes
        saveCustomers();
    } else {
        cout << "Customer not found!" << endl;
    }
}

void SupermarketManager::deleteCustomer() {
    string idToDelete;
    cout << "\n=== Delete Customer ===\n";
    
    // Display all customers for reference
    displayAllCustomers();
    
    cout << "Enter customer ID to delete: ";
    cin >> idToDelete;
    
    // Find the customer
    auto it = find_if(customers.begin(), customers.end(), 
        [&idToDelete](const Customer& c) { return c.getId() == idToDelete; });
    
    if (it != customers.end()) {
        char confirm;
        cout << "Are you sure you want to delete this customer? (y/n): ";
        cin >> confirm;
        
        if (tolower(confirm) == 'y') {
            customers.erase(it);
            cout << "Customer deleted successfully!" << endl;
            
            // Save changes
            saveCustomers();
        } else {
            cout << "Deletion cancelled." << endl;
        }
    } else {
        cout << "Customer not found!" << endl;
    }
}

void SupermarketManager::searchCustomers() {
    int choice;
    cout << "\n=== Search Customers ===\n";
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Phone\n";
    cout << "4. Email\n";
    cout << "5. Membership Level\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    vector<Customer> searchResults;
    string strCriteria;
    
    switch (choice) {
        case 1: // ID
            cout << "Enter ID: ";
            cin >> strCriteria;
            for (const auto& c : customers) {
                if (c.getId() == strCriteria) {
                    searchResults.push_back(c);
                }
            }
            break;
            
        case 2: // Name
            cout << "Enter name (or part of name): ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& c : customers) {
                if (c.getName().find(strCriteria) != string::npos) {
                    searchResults.push_back(c);
                }
            }
            break;
            
        case 3: // Phone
            cout << "Enter phone number: ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& c : customers) {
                if (c.getPhone().find(strCriteria) != string::npos) {
                    searchResults.push_back(c);
                }
            }
            break;
            
        case 4: // Email
            cout << "Enter email: ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& c : customers) {
                if (c.getEmail().find(strCriteria) != string::npos) {
                    searchResults.push_back(c);
                }
            }
            break;
            
        case 5: // Membership Level
            cout << "Enter membership level (Basic, Silver, Gold, Platinum): ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& c : customers) {
                if (c.getMembershipLevel() == strCriteria) {
                    searchResults.push_back(c);
                }
            }
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    // Display results
    if (searchResults.empty()) {
        cout << "No customers found matching your criteria." << endl;
    } else {
        cout << "\n=== Search Results (" << searchResults.size() << " customers found) ===\n";
        Customer::displayHeader();
        for (const auto& c : searchResults) {
            c.display();
        }
    }
}

void SupermarketManager::sortCustomers() {
    int choice;
    cout << "\n=== Sort Customers ===\n";
    cout << "Sort by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. Registration Date\n";
    cout << "4. Total Purchases (low to high)\n";
    cout << "5. Total Purchases (high to low)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: // ID
            sort(customers.begin(), customers.end(), 
                [](const Customer& a, const Customer& b) { return a.getId() < b.getId(); });
            break;
            
        case 2: // Name
            sort(customers.begin(), customers.end(), 
                [](const Customer& a, const Customer& b) { return a.getName() < b.getName(); });
            break;
            
        case 3: // Registration Date (assuming format DD/MM/YYYY)
            sort(customers.begin(), customers.end(), 
                [](const Customer& a, const Customer& b) { return a.getRegistrationDate() < b.getRegistrationDate(); });
            break;
            
        case 4: // Total Purchases (low to high)
            sort(customers.begin(), customers.end(), 
                [](const Customer& a, const Customer& b) { return a.getTotalPurchases() < b.getTotalPurchases(); });
            break;
            
        case 5: // Total Purchases (high to low)
            sort(customers.begin(), customers.end(), 
                [](const Customer& a, const Customer& b) { return a.getTotalPurchases() > b.getTotalPurchases(); });
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    cout << "Customers sorted successfully!" << endl;
}

void SupermarketManager::displayAllCustomers() {
    if (customers.empty()) {
        cout << "No customers available." << endl;
        return;
    }
    
    cout << "\n=== All Customers (" << customers.size() << ") ===\n";
    Customer::displayHeader();
    for (const auto& customer : customers) {
        customer.display();
    }
}

void SupermarketManager::displayCustomerStatistics() {
    if (customers.empty()) {
        cout << "No customers available for statistics." << endl;
        return;
    }
    
    // Calculate statistics
    int totalPurchases = 0;
    int maxPurchases = 0;
    string maxPurchasesCustomer;
    
    // Map to count customers by membership level
    map<string, int> membershipCount;
    
    for (const auto& c : customers) {
        // Total purchases
        totalPurchases += c.getTotalPurchases();
        
        // Max purchases
        if (c.getTotalPurchases() > maxPurchases) {
            maxPurchases = c.getTotalPurchases();
            maxPurchasesCustomer = c.getName();
        }
        
        // Membership count
        membershipCount[c.getMembershipLevel()]++;
    }
    
    // Display statistics
    cout << "\n=== Customer Statistics ===\n";
    cout << "Total number of customers: " << customers.size() << endl;
    cout << "Total purchases across all customers: " << totalPurchases << endl;
    cout << "Average purchases per customer: " << fixed << setprecision(2) 
         << (customers.empty() ? 0 : static_cast<double>(totalPurchases) / customers.size()) << endl;
    cout << "Customer with most purchases: " << maxPurchasesCustomer << " (" << maxPurchases << " purchases)" << endl;
    
    cout << "\nCustomers by Membership Level:" << endl;
    for (const auto& level : membershipCount) {
        cout << level.first << ": " << level.second << " customers" << endl;
    }
}

// Invoice management functions
void SupermarketManager::createInvoice() {
    string invoiceId, customerId, customerName, date, paymentMethod;
    double discountPercent;
    
    cout << "\n=== Create New Invoice ===\n";
    
    // Generate invoice ID
    invoiceId = Utils::generateId("INV", invoices.size() + 1);
    cout << "Invoice ID: " << invoiceId << " (auto-generated)" << endl;
    
    // Set current date
    date = currentDate;
    cout << "Date: " << date << endl;
    
    // Display all customers for reference
    displayAllCustomers();
    
    // Select customer
    cout << "Enter customer ID: ";
    cin >> customerId;
    
    // Find customer
    Customer* customer = getCustomerById(customerId);
    if (!customer) {
        cout << "Customer not found! Creating invoice for anonymous customer." << endl;
        customerId = "ANON";
        customerName = "Anonymous Customer";
    } else {
        customerName = customer->getName();
        cout << "Selected customer: " << customerName << endl;
    }
    
    // Payment method
    cout << "Enter payment method (Cash/Card/Transfer): ";
    cin.ignore();
    getline(cin, paymentMethod);
    
    // Discount
    cout << "Enter discount percentage (0-100): ";
    cin >> discountPercent;
    
    // Create invoice
    Invoice invoice(invoiceId, customerId, customerName, date, paymentMethod, discountPercent);
    
    // Add items to invoice
    char addMoreItems;
    do {
        // Display all products for reference
        displayAllProducts();
        
        string productId;
        int quantity;
        
        cout << "Enter product ID to add to invoice: ";
        cin >> productId;
        
        // Find product
        Product* product = getProductById(productId);
        if (!product) {
            cout << "Product not found!" << endl;
        } else {
            cout << "Selected product: " << product->getName() << endl;
            cout << "Available quantity: " << product->getQuantity() << endl;
            cout << "Enter quantity to purchase: ";
            cin >> quantity;
            
            if (quantity <= 0) {
                cout << "Invalid quantity!" << endl;
            } else if (quantity > product->getQuantity()) {
                cout << "Not enough stock available!" << endl;
            } else {
                // Add item to invoice
                InvoiceItem item(product->getId(), product->getName(), product->getPrice(), quantity);
                invoice.addItem(item);
                
                // Update product quantity
                product->decreaseQuantity(quantity);
                
                cout << "Item added to invoice!" << endl;
            }
        }
        
        cout << "Add more items? (y/n): ";
        cin >> addMoreItems;
        
    } while (tolower(addMoreItems) == 'y');

    // Add invoice to list
    invoices.push_back(invoice);
    
    // Update customer purchases if not anonymous
    if (customerId != "ANON" && customer) {
        customer->incrementPurchases();
        saveCustomers();
    }
    
    // Save changes
    saveProducts();
    saveInvoices();
    
    // Display the invoice
    cout << "\nInvoice created successfully!" << endl;
    invoice.display();
}

void SupermarketManager::displayInvoice() {
    string invoiceId;
    cout << "\n=== Display Invoice ===\n";
    
    // Display all invoices briefly
    displayAllInvoices();
    
    cout << "Enter invoice ID to display: ";
    cin >> invoiceId;
    
    // Find the invoice
    auto it = find_if(invoices.begin(), invoices.end(), 
        [&invoiceId](const Invoice& inv) { return inv.getInvoiceId() == invoiceId; });
    
    if (it != invoices.end()) {
        it->display();
    } else {
        cout << "Invoice not found!" << endl;
    }
}

void SupermarketManager::displayAllInvoices() {
    if (invoices.empty()) {
        cout << "No invoices available." << endl;
        return;
    }
    
    cout << "\n=== All Invoices (" << invoices.size() << ") ===\n";
    Invoice::displayBriefHeader();
    for (const auto& invoice : invoices) {
        invoice.displayBrief();
    }
}

void SupermarketManager::searchInvoices() {
    int choice;
    cout << "\n=== Search Invoices ===\n";
    cout << "Search by:\n";
    cout << "1. Invoice ID\n";
    cout << "2. Customer ID\n";
    cout << "3. Customer Name\n";
    cout << "4. Date\n";
    cout << "5. Payment Method\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    vector<Invoice> searchResults;
    string strCriteria;
    
    switch (choice) {
        case 1: // Invoice ID
            cout << "Enter invoice ID: ";
            cin >> strCriteria;
            for (const auto& inv : invoices) {
                if (inv.getInvoiceId() == strCriteria) {
                    searchResults.push_back(inv);
                }
            }
            break;
            
        case 2: // Customer ID
            cout << "Enter customer ID: ";
            cin >> strCriteria;
            for (const auto& inv : invoices) {
                if (inv.getCustomerId() == strCriteria) {
                    searchResults.push_back(inv);
                }
            }
            break;
            
        case 3: // Customer Name
            cout << "Enter customer name (or part of name): ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& inv : invoices) {
                if (inv.getCustomerName().find(strCriteria) != string::npos) {
                    searchResults.push_back(inv);
                }
            }
            break;
            
        case 4: // Date
            cout << "Enter date (DD/MM/YYYY): ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& inv : invoices) {
                if (inv.getDate() == strCriteria) {
                    searchResults.push_back(inv);
                }
            }
            break;
            
        case 5: // Payment Method
            cout << "Enter payment method: ";
            cin.ignore();
            getline(cin, strCriteria);
            for (const auto& inv : invoices) {
                if (inv.getPaymentMethod() == strCriteria) {
                    searchResults.push_back(inv);
                }
            }
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    // Display results
    if (searchResults.empty()) {
        cout << "No invoices found matching your criteria." << endl;
    } else {
        cout << "\n=== Search Results (" << searchResults.size() << " invoices found) ===\n";
        Invoice::displayBriefHeader();
        for (const auto& inv : searchResults) {
            inv.displayBrief();
        }
    }
}

void SupermarketManager::sortInvoices() {
    int choice;
    cout << "\n=== Sort Invoices ===\n";
    cout << "Sort by:\n";
    cout << "1. Invoice ID\n";
    cout << "2. Date\n";
    cout << "3. Customer Name\n";
    cout << "4. Total Amount (low to high)\n";
    cout << "5. Total Amount (high to low)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: // Invoice ID
            sort(invoices.begin(), invoices.end(), 
                [](const Invoice& a, const Invoice& b) { return a.getInvoiceId() < b.getInvoiceId(); });
            break;
            
        case 2: // Date
            sort(invoices.begin(), invoices.end(), 
                [](const Invoice& a, const Invoice& b) { return a.getDate() < b.getDate(); });
            break;
            
        case 3: // Customer Name
            sort(invoices.begin(), invoices.end(), 
                [](const Invoice& a, const Invoice& b) { return a.getCustomerName() < b.getCustomerName(); });
            break;
            
        case 4: // Total Amount (low to high)
            sort(invoices.begin(), invoices.end(), 
                [](const Invoice& a, const Invoice& b) { return a.getTotalAmount() < b.getTotalAmount(); });
            break;
            
        case 5: // Total Amount (high to low)
            sort(invoices.begin(), invoices.end(), 
                [](const Invoice& a, const Invoice& b) { return a.getTotalAmount() > b.getTotalAmount(); });
            break;
            
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    cout << "Invoices sorted successfully!" << endl;
}

void SupermarketManager::displayInvoiceStatistics() {
    if (invoices.empty()) {
        cout << "No invoices available for statistics." << endl;
        return;
    }
    
    // Calculate statistics
    double totalSales = 0;
    double totalDiscount = 0;
    double highestInvoice = 0;
    double lowestInvoice = numeric_limits<double>::max();
    string highestInvoiceId, lowestInvoiceId;
    
    // Map to count invoices by date and payment method
    map<string, int> dateCount;
    map<string, int> paymentMethodCount;
    map<string, double> paymentMethodTotal;
    
    for (const auto& inv : invoices) {
        // Total sales
        totalSales += inv.getFinalAmount();
        
        // Total discount
        totalDiscount += (inv.getTotalAmount() - inv.getFinalAmount());
        
        // Highest/lowest invoice
        if (inv.getFinalAmount() > highestInvoice) {
            highestInvoice = inv.getFinalAmount();
            highestInvoiceId = inv.getInvoiceId();
        }
        if (inv.getFinalAmount() < lowestInvoice) {
            lowestInvoice = inv.getFinalAmount();
            lowestInvoiceId = inv.getInvoiceId();
        }
        
        // Count by date and payment method
        dateCount[inv.getDate()]++;
        paymentMethodCount[inv.getPaymentMethod()]++;
        paymentMethodTotal[inv.getPaymentMethod()] += inv.getFinalAmount();
    }
    
    // Display statistics
    cout << "\n=== Sales Statistics ===\n";
    cout << "Total number of invoices: " << invoices.size() << endl;
    cout << "Total sales: $" << fixed << setprecision(2) << totalSales << endl;
    cout << "Total discount given: $" << fixed << setprecision(2) << totalDiscount << endl;
    cout << "Average invoice amount: $" << fixed << setprecision(2) 
         << (invoices.empty() ? 0 : totalSales / invoices.size()) << endl;
    
    cout << "\nHighest invoice: #" << highestInvoiceId << " ($" << highestInvoice << ")" << endl;
    cout << "Lowest invoice: #" << lowestInvoiceId << " ($" << lowestInvoice << ")" << endl;
    
    cout << "\nInvoices by Date:" << endl;
    for (const auto& date : dateCount) {
        cout << date.first << ": " << date.second << " invoices" << endl;
    }
    
    cout << "\nInvoices by Payment Method:" << endl;
    for (const auto& method : paymentMethodCount) {
        cout << method.first << ": " << method.second << " invoices, $" 
             << fixed << setprecision(2) << paymentMethodTotal[method.first] << " total" << endl;
    }
}

// Helper functions to get products and customers by ID
Product* SupermarketManager::getProductById(const string& id) {
    auto it = find_if(products.begin(), products.end(), 
        [&id](const Product& p) { return p.getId() == id; });
    
    if (it != products.end()) {
        return &(*it);
    }
    
    return nullptr;
}

Customer* SupermarketManager::getCustomerById(const string& id) {
    auto it = find_if(customers.begin(), customers.end(), 
        [&id](const Customer& c) { return c.getId() == id; });
    
    if (it != customers.end()) {
        return &(*it);
    }
    
    return nullptr;
}



            