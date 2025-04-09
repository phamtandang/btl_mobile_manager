#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Product {
private:
    std::string id;
    std::string name;
    std::string category;
    double price;
    int quantity;
    std::string manufacturer;
    std::string importDate;

public:
    // Constructors
    Product();
    Product(std::string id, std::string name, std::string category, double price, 
            int quantity, std::string manufacturer, std::string importDate);

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getQuantity() const;
    std::string getManufacturer() const;
    std::string getImportDate() const;

    // Setters
    void setId(std::string id);
    void setName(std::string name);
    void setCategory(std::string category);
    void setPrice(double price);
    void setQuantity(int quantity);
    void setManufacturer(std::string manufacturer);
    void setImportDate(std::string importDate);

    // Other methods
    bool decreaseQuantity(int amount);
    void display() const;
    static void displayHeader();
    std::string toString() const;
    void fromString(const std::string& str);
};

#endif // PRODUCT_H