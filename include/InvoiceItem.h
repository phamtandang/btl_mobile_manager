#ifndef INVOICE_ITEM_H
#define INVOICE_ITEM_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class InvoiceItem {
private:
    std::string productId;
    std::string productName;
    double unitPrice;
    int quantity;
    double subtotal;

public:
    // Constructors
    InvoiceItem();
    InvoiceItem(std::string productId, std::string productName, double unitPrice, int quantity);

    // Getters
    std::string getProductId() const;
    std::string getProductName() const;
    double getUnitPrice() const;
    int getQuantity() const;
    double getSubtotal() const;

    // Setters
    void setProductId(std::string id);
    void setProductName(std::string name);
    void setUnitPrice(double price);
    void setQuantity(int qty);

    // Other methods
    void calculateSubtotal();
    void display() const;
    std::string toString() const;
    void fromString(const std::string& str);
};

#endif // INVOICE_ITEM_H