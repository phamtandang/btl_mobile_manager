#include "Utils.h"
#include <ctime>
#include <algorithm>
#include <locale>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <regex>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

namespace Utils {
    // Hàm chuyển đổi chuỗi thành số nguyên
    int stringToInt(const std::string& str) {
        try {
            return std::stoi(str);
        } catch (const std::exception& e) {
            return 0;
        }
    }
    
    // Hàm chuyển đổi chuỗi thành số thực
    double stringToDouble(const std::string& str) {
        try {
            return std::stod(str);
        } catch (const std::exception& e) {
            return 0.0;
        }
    }
    
    // Hàm chuyển đổi số nguyên thành chuỗi
    std::string intToString(int value) {
        return std::to_string(value);
    }
    
    // Hàm chuyển đổi số thực thành chuỗi
    std::string doubleToString(double value, int precision) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << value;
        return oss.str();
    }
    
    // Hàm lấy ngày hiện tại theo định dạng "dd/mm/yyyy"
    std::string getNgayHienTai() {
        std::time_t now = std::time(nullptr);
        std::tm* ltm = std::localtime(&now);
        
        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << ltm->tm_mday << "/"
            << std::setw(2) << (ltm->tm_mon + 1) << "/"
            << (ltm->tm_year + 1900);
        
        return oss.str();
    }
    
    // Hàm kiểm tra chuỗi có phải là số hay không
    bool isNumber(const std::string& str) {
        // Cho phép dấu chấm thập phân trong số
        if (str.empty()) return false;
        
        for (char c : str) {
            if (!std::isdigit(c) && c != '.') {
                return false;
            }
        }
        
        // Chỉ được có một dấu chấm thập phân
        return std::count(str.begin(), str.end(), '.') <= 1;
    }
    
    // Hàm kiểm tra định dạng ngày (dd/mm/yyyy)
    bool isValidDate(const std::string& date) {
        // Kiểm tra định dạng bằng regex
        std::regex datePattern("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");
        if (!std::regex_match(date, datePattern)) {
            return false;
        }
        
        // Tách ngày, tháng, năm
        std::vector<std::string> parts = split(date, '/');
        int day = stringToInt(parts[0]);
        int month = stringToInt(parts[1]);
        int year = stringToInt(parts[2]);
        
        // Kiểm tra năm hợp lệ (năm phải >= 1900)
        if (year < 1900) {
            return false;
        }
        
        // Kiểm tra tháng 2 và năm nhuận
        if (month == 2) {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (isLeapYear && day > 29) {
                return false;
            }
            if (!isLeapYear && day > 28) {
                return false;
            }
        }
        
        // Kiểm tra tháng có 30 ngày
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            return false;
        }
        
        return true;
    }
    
    // Hàm tách chuỗi thành vector các chuỗi con dựa vào ký tự phân cách
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        
        return tokens;
    }
    
    // Hàm nhập chuỗi với thông báo
    std::string inputString(const std::string& message) {
        std::string input;
        std::cout << message;
        std::getline(std::cin, input);
        return input;
    }
    
    // Hàm nhập số nguyên với kiểm tra hợp lệ
    int inputInt(const std::string& message, int minValue, int maxValue) {
        int input;
        std::string inputStr;
        bool valid = false;
        
        do {
            std::cout << message;
            std::getline(std::cin, inputStr);
            
            try {
                input = std::stoi(inputStr);
                if (input >= minValue && input <= maxValue) {
                    valid = true;
                } else {
                    std::cout << "Giá trị nhập phải trong khoảng [" << minValue << ", " << maxValue << "]. Vui lòng nhập lại.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Không phải số nguyên hợp lệ. Vui lòng nhập lại.\n";
            }
        } while (!valid);
        
        return input;
    }
    
    // Hàm nhập số thực với kiểm tra hợp lệ
    double inputDouble(const std::string& message, double minValue, double maxValue) {
        double input;
        std::string inputStr;
        bool valid = false;
        
        do {
            std::cout << message;
            std::getline(std::cin, inputStr);
            
            try {
                input = std::stod(inputStr);
                if (input >= minValue && input <= maxValue) {
                    valid = true;
                } else {
                    std::cout << "Giá trị nhập phải trong khoảng [" << minValue << ", " << maxValue << "]. Vui lòng nhập lại.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Không phải số thực hợp lệ. Vui lòng nhập lại.\n";
            }
        } while (!valid);
        
        return input;
    }
    
    // Hàm nhập ngày với kiểm tra hợp lệ
    std::string inputDate(const std::string& message) {
        std::string date;
        bool valid = false;
        
        do {
            std::cout << message;
            std::getline(std::cin, date);
            
            if (isValidDate(date)) {
                valid = true;
            } else {
                std::cout << "Định dạng ngày không hợp lệ. Vui lòng nhập lại (dd/mm/yyyy).\n";
            }
        } while (!valid);
        
        return date;
    }
    
    // Hàm tính khoảng cách giữa hai ngày (số ngày)
    int daysBetween(const std::string& date1, const std::string& date2) {
        // Tạo cấu trúc tm từ chuỗi ngày
        auto stringToTm = [](const std::string& dateStr) -> std::tm {
            std::vector<std::string> parts = split(dateStr, '/');
            std::tm tm = {};
            tm.tm_mday = stringToInt(parts[0]);
            tm.tm_mon = stringToInt(parts[1]) - 1;
            tm.tm_year = stringToInt(parts[2]) - 1900;
            return tm;
        };
        
        std::tm tm1 = stringToTm(date1);
        std::tm tm2 = stringToTm(date2);
        
        // Chuyển thành time_t
        std::time_t time1 = std::mktime(&tm1);
        std::time_t time2 = std::mktime(&tm2);
        
        // Tính khoảng cách theo giây và chuyển thành số ngày
        constexpr int SECONDS_PER_DAY = 60 * 60 * 24;
        return std::abs(static_cast<int>(std::difftime(time2, time1) / SECONDS_PER_DAY));
    }
    
    // Hàm trích xuất tháng từ chuỗi ngày (dd/mm/yyyy)
    int extractMonth(const std::string& date) {
        std::vector<std::string> parts = split(date, '/');
        if (parts.size() >= 2) {
            return stringToInt(parts[1]);
        }
        return 0;
    }
    
    // Hàm trích xuất quý từ chuỗi ngày (dd/mm/yyyy)
    int extractQuarter(const std::string& date) {
        int month = extractMonth(date);
        if (month >= 1 && month <= 3) return 1;
        if (month >= 4 && month <= 6) return 2;
        if (month >= 7 && month <= 9) return 3;
        if (month >= 10 && month <= 12) return 4;
        return 0;
    }
    
    // Hàm format tiền tệ
    std::string formatCurrency(double value) {
        // Lưu trữ dấu của số
        bool isNegative = (value < 0);
        
        // Làm việc với giá trị tuyệt đối
        std::string str = std::to_string(std::abs(value));
        
        // Loại bỏ các số 0 thừa sau dấu thập phân
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        if (str.back() == '.') str.pop_back();
        
        // Thêm dấu phẩy phân tách hàng nghìn
        std::string::size_type pos = str.find('.');
        if (pos == std::string::npos) pos = str.length();
        
        // Chèn dấu phẩy từ phải qua trái, mỗi 3 chữ số
        while (pos > 3) {
            pos -= 3;
            str.insert(pos, ",");
        }
        
        // Thêm dấu trừ vào đầu nếu là số âm
        if (isNegative) {
            str = "-" + str;
        }
        
        return str + " VND";
    }
    
    // Hàm vẽ đường kẻ ngang
    void drawLine(int length, char c) {
        std::cout << std::string(length, c) << std::endl;
    }
    
    // Hàm xóa màn hình
    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    
    // Hàm tạm dừng chương trình và chờ người dùng nhấn phím bất kỳ
    void pause() {
        std::cout << "\nNhấn Enter để tiếp tục...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}