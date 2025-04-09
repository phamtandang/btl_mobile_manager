#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

class Utils {
public:
    // Get current date in format DD/MM/YYYY
    static std::string getCurrentDate();
    
    // Generate ID with format prefix + number (padded with zeros)
    static std::string generateId(const std::string& prefix, int num);
    
    // Clear screen (cross-platform)
    static void clearScreen();
    
    // Display application header
    static void displayHeader(const std::string& title);
    
    // Pause and wait for user to press Enter
    static void pause();
    
    // Read a valid integer input within a range
    static int getIntInput(int min, int max);
    
    // Read a valid double input within a range
    static double getDoubleInput(double min, double max);
    
    // Confirm an action (returns true if confirmed)
    static bool confirm(const std::string& message);
};

#endif // UTILS_H