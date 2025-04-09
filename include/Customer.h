#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Customer {
private:
    std::string id;
    std::string name;
    std::string phone;
    std::string address;
    std::string email;
    std::string membershipLevel;  // Basic, Silver, Gold, Platinum
    std::string registrationDate;
    int totalPurchases;

public:
    // Constructors
    Customer();
    Customer(std::string id, std::string name, std::string phone, std::string address, 
             std::string email, std::string membershipLevel, std::string registrationDate, 
             int totalPurchases);

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getAddress() const;
    std::string getEmail() const;
    std::string getMembershipLevel() const;
    std::string getRegistrationDate() const;
    int getTotalPurchases() const;

    // Setters
    void setId(std::string id);
    void setName(std::string name);
    void setPhone(std::string phone);
    void setAddress(std::string address);
    void setEmail(std::string email);
    void setMembershipLevel(std::string level);
    void setRegistrationDate(std::string date);
    void setTotalPurchases(int purchases);

    // Other methods
    void incrementPurchases(int amount = 1);
    void updateMembershipLevel();
    void display() const;
    static void displayHeader();
    std::string toString() const;
    void fromString(const std::string& str);
};

#endif // CUSTOMER_H