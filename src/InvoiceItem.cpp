#include "../include/InvoiceItem.h"
#include <sstream>

using namespace std;

// Constructor
InvoiceItem::InvoiceItem() : unitPrice(0), quantity(0), subtotal(0) {}

InvoiceItem::InvoiceItem(string productId, string productName, double unitPrice, int quantity)
    : productId(productId), productName(productName), unitPrice(unitPrice), quantity(quantity) {
    calculateSubtotal();
}

// Getters
string InvoiceItem::getProductId() const { return productId; }
string InvoiceItem::getProductName() const { return productName; }
double InvoiceItem::getUnitPrice() const { return unitPrice; }
int InvoiceItem::getQuantity() const { return quantity; }
double InvoiceItem::getSubtotal() const { return subtotal; }

// Setters
void InvoiceItem::setProductId(string id) { this->productId = id; }
void InvoiceItem::setProductName(string name) { this->productName = name; }
void InvoiceItem::setUnitPrice(double price) { 
    this->unitPrice = price; 
    calculateSubtotal();
}
void InvoiceItem::setQuantity(int qty) { 
    this->quantity = qty; 
    calculateSubtotal();
}

// Calculate subtotal
void InvoiceItem::calculateSubtotal() {
    subtotal = unitPrice * quantity;
}

// Display invoice item
void InvoiceItem::display() const {
    cout << left << setw(10) << productId
         << setw(30) << productName
         << right << setw(10) << fixed << setprecision(2) << unitPrice
         << setw(10) << quantity
         << setw(15) << subtotal << endl;
}

// For file I/O
string InvoiceItem::toString() const {
    ostringstream oss;
    oss << productId << "," << productName << "," << unitPrice << "," << quantity;
    return oss.str();
}

// Read from CSV format string
void InvoiceItem::fromString(const string& str) {
    stringstream ss(str);
    string token;

    getline(ss, token, ','); productId = token;
    getline(ss, token, ','); productName = token;
    getline(ss, token, ','); unitPrice = stod(token);
    getline(ss, token, ','); quantity = stoi(token);
    
    calculateSubtotal(); // Calculate subtotal after loading data
}