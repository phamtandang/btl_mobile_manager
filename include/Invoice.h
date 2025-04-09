#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "InvoiceItem.h"

class Invoice {
private:
    std::string invoiceId;
    std::string customerId;
    std::string customerName;
    std::string date;
    std::vector<InvoiceItem> items;
    double totalAmount;
    double discountPercent;
    double finalAmount;
    std::string paymentMethod;
    
public:
    // Constructors
    Invoice();
    Invoice(std::string invoiceId, std::string customerId, std::string customerName,
            std::string date, std::string paymentMethod, double discountPercent = 0);

    // Getters
    std::string getInvoiceId() const;
    std::string getCustomerId() const;
    std::string getCustomerName() const;
    std::string getDate() const;
    double getTotalAmount() const;
    double getDiscountPercent() const;
    double getFinalAmount() const;
    std::string getPaymentMethod() const;
    const std::vector<InvoiceItem>& getItems() const;

    // Setters
    void setInvoiceId(std::string id);
    void setCustomerId(std::string id);
    void setCustomerName(std::string name);
    void setDate(std::string date);
    void setDiscountPercent(double discount);
    void setPaymentMethod(std::string method);

    // Other methods
    void addItem(const InvoiceItem& item);
    void calculateTotalAmount();
    void calculateFinalAmount();
    void displayHeader() const;
    void display() const;
    void displayBrief() const;
    static void displayBriefHeader();
    std::string headerToString() const;
    void headerFromString(const std::string& str);
};

#endif // INVOICE_H