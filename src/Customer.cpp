#include "../include/Customer.h"
#include <sstream>

using namespace std;

// Constructors
Customer::Customer() : totalPurchases(0) {}

Customer::Customer(string id, string name, string phone, string address, 
         string email, string membershipLevel, string registrationDate, int totalPurchases)
    : id(id), name(name), phone(phone), address(address),
      email(email), membershipLevel(membershipLevel), 
      registrationDate(registrationDate), totalPurchases(totalPurchases) {}

// Getters
string Customer::getId() const { return id; }
string Customer::getName() const { return name; }
string Customer::getPhone() const { return phone; }
string Customer::getAddress() const { return address; }
string Customer::getEmail() const { return email; }
string Customer::getMembershipLevel() const { return membershipLevel; }
string Customer::getRegistrationDate() const { return registrationDate; }
int Customer::getTotalPurchases() const { return totalPurchases; }

// Setters
void Customer::setId(string id) { this->id = id; }
void Customer::setName(string name) { this->name = name; }
void Customer::setPhone(string phone) { this->phone = phone; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setEmail(string email) { this->email = email; }
void Customer::setMembershipLevel(string level) { this->membershipLevel = level; }
void Customer::setRegistrationDate(string date) { this->registrationDate = date; }
void Customer::setTotalPurchases(int purchases) { this->totalPurchases = purchases; }

// Increment purchases
void Customer::incrementPurchases(int amount) {
    totalPurchases += amount;
    updateMembershipLevel();
}

// Update membership level based on purchases
void Customer::updateMembershipLevel() {
    if (totalPurchases >= 100) {
        membershipLevel = "Platinum";
    } else if (totalPurchases >= 50) {
        membershipLevel = "Gold";
    } else if (totalPurchases >= 20) {
        membershipLevel = "Silver";
    } else {
        membershipLevel = "Basic";
    }
}

// Display customer information
void Customer::display() const {
    cout << left << setw(10) << id
         << setw(25) << name
         << setw(15) << phone
         << setw(25) << address
         << setw(25) << email
         << setw(15) << membershipLevel
         << setw(15) << registrationDate
         << right << setw(10) << totalPurchases << endl;
}

// Static method to display header
void Customer::displayHeader() {
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(15) << "Phone"
         << setw(25) << "Address"
         << setw(25) << "Email"
         << setw(15) << "Membership"
         << setw(15) << "Reg. Date"
         << right << setw(10) << "Purchases" << endl;
    cout << string(140, '-') << endl;
}

// For file I/O
string Customer::toString() const {
    ostringstream oss;
    oss << id << "," << name << "," << phone << "," << address << ","
        << email << "," << membershipLevel << "," << registrationDate << "," << totalPurchases;
    return oss.str();
}

// Read from CSV format string
void Customer::fromString(const string& str) {
    stringstream ss(str);
    string token;

    getline(ss, token, ','); id = token;
    getline(ss, token, ','); name = token;
    getline(ss, token, ','); phone = token;
    getline(ss, token, ','); address = token;
    getline(ss, token, ','); email = token;
    getline(ss, token, ','); membershipLevel = token;
    getline(ss, token, ','); registrationDate = token;
    getline(ss, token, ','); totalPurchases = stoi(token);
}