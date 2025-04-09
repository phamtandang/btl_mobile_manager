#include "../include/Utils.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// Get current date in format DD/MM/YYYY
string Utils::getCurrentDate() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", timeinfo);
    return string(buffer);
}

// Generate ID with format prefix + number (padded with zeros)
string Utils::generateId(const string& prefix, int num) {
    ostringstream oss;
    oss << prefix << setw(4) << setfill('0') << num;
    return oss.str();
}

// Clear screen (cross-platform)
void Utils::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Display application header
void Utils::displayHeader(const string& title) {
    cout << string(60, '=') << endl;
    cout << setw(30 + title.length()/2) << title << endl;
    cout << string(60, '=') << endl << endl;
}

// Pause and wait for user to press Enter
void Utils::pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Read a valid integer input within a range
int Utils::getIntInput(int min, int max) {
    int value;
    while (true) {
        cin >> value;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else if (value < min || value > max) {
            cout << "Please enter a number between " << min << " and " << max << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Read a valid double input within a range
double Utils::getDoubleInput(double min, double max) {
    double value;
    while (true) {
        cin >> value;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else if (value < min || value > max) {
            cout << "Please enter a number between " << min << " and " << max << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Confirm an action (returns true if confirmed)
bool Utils::confirm(const string& message) {
    cout << message << " (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return tolower(choice) == 'y';
}