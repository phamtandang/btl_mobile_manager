#include "../include/Product.h"
#include <sstream>

using namespace std;

// Constructors
Product::Product() : price(0), quantity(0) {}

Product::Product(string id, string name, string category, double price, 
        int quantity, string manufacturer, string importDate)
    : id(id), name(name), category(category), price(price),
      quantity(quantity), manufacturer(manufacturer), importDate(importDate) {}

// Getters
string Product::getId() const { return id; }
string Product::getName() const { return name; }
string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
string Product::getManufacturer() const { return manufacturer; }
string Product::getImportDate() const { return importDate; }

// Setters
void Product::setId(string id) { this->id = id; }
void Product::setName(string name) { this->name = name; }
void Product::setCategory(string category) { this->category = category; }
void Product::setPrice(double price) { this->price = price; }
void Product::setQuantity(int quantity) { this->quantity = quantity; }
void Product::setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
void Product::setImportDate(string importDate) { this->importDate = importDate; }

// Decrease quantity (for sales)
bool Product::decreaseQuantity(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        return true;
    }
    return false;
}

// Display product information
void Product::display() const {
    cout << left << setw(10) << id
         << setw(25) << name
         << setw(15) << category
         << right << setw(10) << fixed << setprecision(2) << price
         << setw(10) << quantity
         << left << setw(20) << manufacturer
         << setw(12) << importDate << endl;
}

// Static method to display header
void Product::displayHeader() {
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Category"
         << right << setw(10) << "Price"
         << setw(10) << "Quantity"
         << left << setw(20) << "Manufacturer"
         << setw(12) << "Import Date" << endl;
    cout << string(100, '-') << endl;
}

// For file I/O
string Product::toString() const {
    ostringstream oss;
    oss << id << "," << name << "," << category << "," << price << ","
        << quantity << "," << manufacturer << "," << importDate;
    return oss.str();
}

// Read from CSV format string
void Product::fromString(const string& str) {
    stringstream ss(str);
    string token;

    getline(ss, token, ','); id = token;
    getline(ss, token, ','); name = token;
    getline(ss, token, ','); category = token;
    getline(ss, token, ','); price = stod(token);
    getline(ss, token, ','); quantity = stoi(token);
    getline(ss, token, ','); manufacturer = token;
    getline(ss, token, ','); importDate = token;
}