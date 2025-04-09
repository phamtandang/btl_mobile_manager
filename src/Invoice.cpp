#include "../include/Invoice.h"
#include <sstream>

using namespace std;

// Constructor
Invoice::Invoice() : totalAmount(0), discountPercent(0), finalAmount(0) {}

Invoice::Invoice(string invoiceId, string customerId, string customerName,
        string date, string paymentMethod, double discountPercent)
    : invoiceId(invoiceId), customerId(customerId), customerName(customerName),
      date(date), totalAmount(0), discountPercent(discountPercent), finalAmount(0),
      paymentMethod(paymentMethod) {}

// Getters
string Invoice::getInvoiceId() const { return invoiceId; }
string Invoice::getCustomerId() const { return customerId; }
string Invoice::getCustomerName() const { return customerName; }
string Invoice::getDate() const { return date; }
double Invoice::getTotalAmount() const { return totalAmount; }
double Invoice::getDiscountPercent() const { return discountPercent; }
double Invoice::getFinalAmount() const { return finalAmount; }
string Invoice::getPaymentMethod() const { return paymentMethod; }
const vector<InvoiceItem>& Invoice::getItems() const { return items; }

// Setters
void Invoice::setInvoiceId(string id) { this->invoiceId = id; }
void Invoice::setCustomerId(string id) { this->customerId = id; }
void Invoice::setCustomerName(string name) { this->customerName = name; }
void Invoice::setDate(string date) { this->date = date; }
void Invoice::setDiscountPercent(double discount) { 
    this->discountPercent = discount; 
    calculateFinalAmount();
}
void Invoice::setPaymentMethod(string method) { this->paymentMethod = method; }

// Add item to invoice
void Invoice::addItem(const InvoiceItem& item) {
    items.push_back(item);
    calculateTotalAmount();
}

// Calculate total amount
void Invoice::calculateTotalAmount() {
    totalAmount = 0;
    for (const auto& item : items) {
        totalAmount += item.getSubtotal();
    }
    calculateFinalAmount();
}

// Calculate final amount after discount
void Invoice::calculateFinalAmount() {
    finalAmount = totalAmount * (1 - discountPercent / 100.0);
}

// Display invoice header
void Invoice::displayHeader() const {
    cout << "\n======================= INVOICE =======================\n";
    cout << "Invoice ID: " << invoiceId << endl;
    cout << "Date: " << date << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Payment Method: " << paymentMethod << endl;
    cout << "-------------------------------------------------------\n";
    
    // Display item header
    cout << left << setw(10) << "Product ID"
         << setw(30) << "Product Name"
         << right << setw(10) << "Unit Price"
         << setw(10) << "Quantity"
         << setw(15) << "Subtotal" << endl;
    cout << string(75, '-') << endl;
}

// Display invoice details
void Invoice::display() const {
    displayHeader();
    
    // Display items
    for (const auto& item : items) {
        item.display();
    }
    
    cout << string(75, '-') << endl;
    cout << right << setw(50) << "Total Amount: " << setw(15) << fixed << setprecision(2) << totalAmount << endl;
    cout << right << setw(50) << "Discount (" << discountPercent << "%): " << setw(15) << fixed << setprecision(2) << (totalAmount - finalAmount) << endl;
    cout << right << setw(50) << "Final Amount: " << setw(15) << fixed << setprecision(2) << finalAmount << endl;
    cout << "=======================================================\n";
}

// Display brief info for invoice list
void Invoice::displayBrief() const {
    cout << left << setw(15) << invoiceId
         << setw(15) << date
         << setw(15) << customerId
         << setw(25) << customerName
         << right << setw(15) << fixed << setprecision(2) << totalAmount
         << setw(10) << discountPercent << "%"
         << setw(15) << finalAmount
         << left << setw(15) << paymentMethod << endl;
}

// Static method to display brief header
void Invoice::displayBriefHeader() {
    cout << left << setw(15) << "Invoice ID"
         << setw(15) << "Date"
         << setw(15) << "Customer ID"
         << setw(25) << "Customer Name"
         << right << setw(15) << "Total Amount"
         << setw(10) << "Discount"
         << setw(15) << "Final Amount"
         << left << setw(15) << "Payment Method" << endl;
    cout << string(125, '-') << endl;
}

// For file I/O - header
string Invoice::headerToString() const {
    ostringstream oss;
    oss << invoiceId << "," << customerId << "," << customerName << ","
        << date << "," << totalAmount << "," << discountPercent << ","
        << finalAmount << "," << paymentMethod << "," << items.size();
    return oss.str();
}

// For file I/O - from header string
void Invoice::headerFromString(const string& str) {
    stringstream ss(str);
    string token;

    getline(ss, token, ','); invoiceId = token;
    getline(ss, token, ','); customerId = token;
    getline(ss, token, ','); customerName = token;
    getline(ss, token, ','); date = token;
    getline(ss, token, ','); totalAmount = stod(token);
    getline(ss, token, ','); discountPercent = stod(token);
    getline(ss, token, ','); finalAmount = stod(token);
    getline(ss, token, ','); paymentMethod = token;
    // Số lượng items không cần lưu vào thuộc tính
}